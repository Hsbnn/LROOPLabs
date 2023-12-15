#include "npc.hpp"

NPC::NPC(NpcType t, int _x, int _y) : type(t), x(_x), y(_y) {}
NPC::NPC(NpcType t, std::istream &is) : type(t)
{
    is >> x;
    is >> y;
}

void NPC::subscribe(std::shared_ptr<IFightObserver> observer)
{
   observers.push_back(observer);
   //std::cout << "добавили  " << observer << std::endl;
}

void NPC::fight_notify(const std::shared_ptr<NPC> defender, bool win)
{
    for (auto &o : observers)
        o->on_fight(shared_from_this(), defender, win);
}

bool NPC::is_close(const std::shared_ptr<NPC> &other, size_t distance) const
{
    auto [other_x, other_y] = other->position();
    std::lock_guard<std::mutex> lck(mtx);
    if (std::pow(x - other->x, 2) + std::pow(y - other->y, 2) <= std::pow(distance, 2)) // по теореме Пифагора
        return true;
    else
        return false;
}

NpcType NPC::get_type()
{
    std::lock_guard<std::mutex> lck(mtx);
    return type;
}

std::pair<int, int> NPC::position()
{
    std::lock_guard<std::mutex> lck(mtx);
    return {x, y};
}

// bool NPC::is_robber() const
// {
//     return false;
// }
// bool NPC::is_wolf() const
// {
//     return false;
// }
// bool NPC::is_bear() const
// {
//     return false;
// }

bool NPC::visit(std::shared_ptr<Robber> robber) {
    return this->fight(robber);
}
bool NPC::visit(std::shared_ptr<Wolf> wolf) {
    return this->fight(wolf);
}
bool NPC::visit(std::shared_ptr<Bear> bear) {
    return this->fight(bear);
}

void NPC::save(std::ostream &os)
{
    os << x << std::endl;
    os << y << std::endl;
}

std::ostream &operator<<(std::ostream &os, NPC &npc)
{
    os << "{ x:" << npc.x << ", y:" << npc.y << "} ";
    return os;
}

void NPC::move(int shift_x, int shift_y, int max_x, int max_y)
{
    std::lock_guard<std::mutex> lck(mtx);

    if ((x + shift_x >= 0) && (x + shift_x <= max_x))
        x += shift_x;
    if ((y + shift_y >= 0) && (y + shift_y <= max_y))
        y += shift_y;
}

bool NPC::is_alive()
{
    std::lock_guard<std::mutex> lck(mtx);
    return alive;
}

void NPC::must_die()
{
    std::lock_guard<std::mutex> lck(mtx);
    alive = false;
}