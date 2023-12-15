#include "npc.hpp"
#include "robber.hpp"
#include "wolf.hpp"
#include "bear.hpp"

#include <sstream>
#include <thread>
#include <mutex>
#include <chrono>
#include <queue>
#include <optional>
#include <array>

using namespace std::chrono_literals;
std::mutex print_mutex;

// Text Observer
class TextObserver : public IFightObserver
{
private:
    TextObserver(){};

public:
    static std::shared_ptr<IFightObserver> get()
    {
        static TextObserver instance;
        return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver *) {});
    }

    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override
    {
        if (win)
        {
            std::cout << std::endl
                      << "Murder -------- 👊" << std::endl;
            attacker->print();
            defender->print();
        }
    }
};

class F_Observer : public IFightObserver
{
private:
    std::ofstream file;

    F_Observer()
    {
        file.open("log.txt");
    }

public:
    static std::shared_ptr<IFightObserver> get()
    {
        static std::shared_ptr<IFightObserver> instance(new F_Observer());
        return instance;
    }

    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override
    {
        if (win)
        {
            file << std::endl
                 << "Murder -------- 👊" << std::endl;
            attacker->print(file);
            defender->print(file);
        }
    }
};




// Фабрики -----------------------------------
std::shared_ptr<NPC> factory(std::istream &is)
{
    std::shared_ptr<NPC> result;
    int type{0};
    if (is >> type)
    {
        switch (type)
        {
        case RobberType:
            result = std::make_shared<Robber>(is);
            break;
        case WolfType:
            result = std::make_shared<Wolf>(is);
            break;
        case BearType:
            result = std::make_shared<Bear>(is);
            break;
        }
    }
    else
        std::cerr << "unexpected NPC type:" << type << std::endl;

    if (result){
        result->subscribe(TextObserver::get());
        result->subscribe(F_Observer::get());
    }
    return result;
}

std::shared_ptr<NPC> factory(NpcType type, int x, int y)
{
    std::shared_ptr<NPC> result;
    switch (type)
    {
    case RobberType:
        result = std::make_shared<Robber>(x, y);
        break;
    case WolfType:
        result = std::make_shared<Wolf>(x, y);
        break;
    case BearType:
        result = std::make_shared<Bear>(x, y);
        break;
    default:
        break;
    }
    if (result){
        result->subscribe(TextObserver::get());
        result->subscribe(F_Observer::get());
    }
    return result;
}

// save array to file
void save(const set_t &array, const std::string &filename)
{
    std::ofstream fs(filename);
    fs << array.size() << std::endl;
    for (auto &n : array)
        n->save(fs);
    fs.flush(); //все данные, находящиеся в буфере, будут записаны в файл
    fs.close();
}

set_t load(const std::string &filename)
{
    set_t result;
    std::ifstream is(filename);
    if (is.good() && is.is_open())
    {
        int count;
        is >> count;
        for (int i = 0; i < count; ++i)
            result.insert(factory(is));
        is.close();
    }
    else
        std::cerr << "Error: " << std::strerror(errno) << std::endl;
    return result;
}

// print to screen
std::ostream &operator<<(std::ostream &os, const set_t &array)
{
    for (auto &n : array)
        n->print();
    return os;
}


set_t fight(const set_t &array, size_t distance)
{
    set_t dead_list;

    for (const auto &attacker : array)
        for (const auto &defender : array)
            if ((attacker != defender) && (attacker->is_close(defender, distance)))
            {
                bool success{false};
                // if (defender->is_robber())
                //     success = attacker->fight(std::dynamic_pointer_cast<Robber>(defender));
                // if (defender->is_wolf())
                //     success = attacker->fight(std::dynamic_pointer_cast<Wolf>(defender));
                // if (defender->is_bear())
                //     success = attacker->fight(std::dynamic_pointer_cast<Bear>(defender));
                
                success = defender->accept(attacker);
                
                if (success)
                    dead_list.insert(defender);
            }

    return dead_list;
}


struct print : std::stringstream
{
    ~print()
    {
        static std::mutex mtx;
        std::lock_guard<std::mutex> lck(print_mutex);
        std::cout << this->str();
        std::cout.flush();
    }
};


struct FightEvent
{
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};


class FightManager
{
private:
    std::queue<FightEvent> events;
    std::shared_mutex mtx;

    FightManager() {}

public:
    static FightManager &get()
    {
        static FightManager instance;
        return instance;
    }

    void add_event(FightEvent &&event)
    {
        std::lock_guard<std::shared_mutex> lock(mtx);
        events.push(event);
    }

    void operator()()
    {
        while (true)
        {
            {
                std::optional<FightEvent> event;

                {
                    std::lock_guard<std::shared_mutex> lock(mtx);
                    if (!events.empty())
                    {
                        event = events.back();
                        events.pop();
                    }
                }

                if (event)
                {
                    try
                    {
                        if (event->attacker->is_alive())     // no zombie fighting!
                            if (event->defender->is_alive()) // already dead!
                                if (event->defender->accept(event->attacker))
                                    event->defender->must_die();
                    }
                    catch (...)
                    {
                        std::lock_guard<std::shared_mutex> lock(mtx);
                        events.push(*event);
                    }
                }
                else
                    std::this_thread::sleep_for(100ms);
            }
        }
    }
};




int main()
{
    set_t array; // монстры

    const int MAX_X{100};
    const int MAX_Y{100};
    const int DISTANCE{40};

    // Генерируем начальное распределение монстров
    std::cout << "Generating ... 😲 " << std::endl;
    for (size_t i = 0; i < 10; ++i)
        array.insert(factory(NpcType(std::rand() % 3 + 1),
                             std::rand() % 500,
                             std::rand() % 500)); // х и у до 500


    // std::cout << "Saving ... 😍 " << std::endl;


    // save(array, "npc.txt");

    // std::cout << "Loading ... " << std::endl;

    // array = load("npc.txt");

    std::cout << "Starting list:" << std::endl
              << array;

    std::thread fight_thread(std::ref(FightManager::get()));

    std::thread move_thread([&array, MAX_X, MAX_Y, DISTANCE]()
     {
            while (true)
            {
                // move phase
                for (std::shared_ptr<NPC> npc : array)
                {
                        if(npc->is_alive()){
                            int shift_x = std::rand() % 20 - 10;
                            int shift_y = std::rand() % 20 - 10;
                            npc->move(shift_x, shift_y, MAX_X, MAX_Y);
                        }
                }
                // lets fight
                for (std::shared_ptr<NPC> npc : array)
                    for (std::shared_ptr<NPC> other : array)
                        if (other != npc)
                            if (npc->is_alive())
                            if (other->is_alive())
                            if (npc->is_close(other, DISTANCE))
                                FightManager::get().add_event({npc, other});

                std::this_thread::sleep_for(1s);
            } });

while (true)
    {
        const int grid{20}, step_x{MAX_X / grid}, step_y{MAX_Y / grid};
        {
            std::array<char, grid * grid> fields{0};
            for (std::shared_ptr<NPC> npc : array)
            {
                auto [x, y] = npc->position();
                int i = x / step_x;
                int j = y / step_y;

                if (npc->is_alive())
                {
                    switch (npc->get_type())
                    {
                    case WolfType:
                        fields[i + grid * j] = 'W';
                        break;
                    case RobberType:
                        fields[i + grid * j] = 'R';
                        break;
                    case BearType:
                        fields[i + grid * j] = 'B';
                        break;

                    default:
                        break;
                    }
                }
                else
                    fields[i + grid * j] = '.';
            }

            std::lock_guard<std::mutex> lck(print_mutex);
            for (int j = 0; j < grid; ++j)
            {
                for (int i = 0; i < grid; ++i)
                {
                    char c = fields[i + j * grid];
                    if (c != 0)
                        std::cout << "[" << c << "]";
                    else
                        std::cout << "[ ]";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
        std::this_thread::sleep_for(1s);
    };

    move_thread.join();
    fight_thread.join();

    return 0;
}
    
    // std::cout << "Fighting ... 😲" << std::endl << array;

    // for (size_t distance = 20; (distance <= 300) && !array.empty(); distance += 50)
    // {
    //     auto dead_list = fight(array, distance);
    //     for (auto &d : dead_list)
    //         array.erase(d);
    //     std::cout << "Fight stats ----------" << std::endl
    //               << "distance: " << distance << std::endl
    //               << "killed ☠️ : " << dead_list.size() << std::endl
    //               << std::endl << std::endl;

    // }

    // std::cout << "Survivors 🎉❤️ : " << array;

    // return 0;
