#include "npc.hpp"

NPC::NPC(NpcType t, int _x, int _y) : type(t), x(_x), y(_y) {}
NPC::NPC(NpcType t, std::istream &is) : type(t) {
    is >> x;
    is >> y;
}

bool NPC::visit(std::shared_ptr<Robber> robber) {
    return this->fight(robber);
}
bool NPC::visit(std::shared_ptr<Wolf> wolf) {
    return this->fight(wolf);
}
bool NPC::visit(std::shared_ptr<Bear> bear) {
    return this->fight(bear);
}

void NPC::subscribe(std::shared_ptr<IFightObserver> observer) {
    observers.push_back(observer);
}

void NPC::fight_notify(const std::shared_ptr<NPC> defender, bool win) {
    for (auto &o : observers)
        o->on_fight(std::shared_ptr<NPC>(this, [](NPC *) {}), defender, win);
}

bool NPC::is_close(const std::shared_ptr<NPC> &other, size_t distance) {
    auto [other_x, other_y] = other->position();
    std::lock_guard<std::mutex> lck(mtx);

    if (this -> type == RobberType){
        distance = 10;
    } else if (this -> type == WolfType){
        distance = 5;
    } else if (this -> type == BearType){
        distance = 10;
    }

    if ((std::pow(x - other_x, 2) + std::pow(y - other_y, 2)) <= std::pow(distance, 2)) // по теореме Пифагора
        return true;
    else
        return false;
}

NpcType NPC::get_type() {
    std::lock_guard<std::mutex> lck(mtx);
    return type;
}

std::pair<int, int> NPC::position() {
    std::lock_guard<std::mutex> lck(mtx);
    return {x, y};
}

void NPC::save(std::ostream &os) {
    os << x << std::endl;
    os << y << std::endl;
}

std::ostream &operator<<(std::ostream &os, NPC &npc) {
    os << "{ x:" << npc.x << ", y:" << npc.y << "} ";
    return os;
}

void NPC::move(int shift_x, int shift_y, int max_x, int max_y) {
    std::lock_guard<std::mutex> lck(mtx);
    int move_distance = 0;

    if (this -> type == RobberType){
        move_distance = 10;
    } else if (this -> type == WolfType){
        move_distance = 40;
    } else if (this -> type == BearType){
        move_distance = 5;
    }

    if (shift_y % 2 == 0) {
        shift_x = move_distance * pow(-1, shift_x);
        shift_y = move_distance * pow(-1, shift_y);
    } else {
        shift_x = move_distance * pow(-1, shift_x);
        shift_y = move_distance * pow(-1, shift_y);
    }

    if ((x + shift_x >= 0) && (x + shift_x <= max_x))
        x += shift_x;
    if ((y + shift_y >= 0) && (y + shift_y <= max_y))
        y += shift_y;
}

bool NPC::is_alive() {
    std::lock_guard<std::mutex> lck(mtx);
    return alive;
}

void NPC::must_die() {
    std::lock_guard<std::mutex> lck(mtx);
    alive = false;
}
