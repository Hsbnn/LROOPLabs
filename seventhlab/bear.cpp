#include "wolf.hpp"
#include "bear.hpp"
#include "robber.hpp"

Bear::Bear(int x, int y) : NPC(BearType, x, y) {}
Bear::Bear(std::istream &is) : NPC(BearType, is) {}

void Bear::print()
{
    std::cout << *this;
}

void Bear::print(std::ostream &outfs) {
    outfs << *this;
}

bool Bear::accept(std::shared_ptr<NPC> visitor) {
    return visitor->fight(std::shared_ptr<Bear>(this,[](Bear*){}));
}


void Bear::save(std::ostream &os) 
{
    os << BearType << std::endl;
    NPC::save(os);
}


bool Bear::fight(std::shared_ptr<Bear> other) 
{
    fight_notify(other, false);
    return false;
}

bool Bear::fight(std::shared_ptr<Robber> other) 
{
    fight_notify(other, false);
    return false;
}

bool Bear::fight(std::shared_ptr<Wolf> other) 
{
    fight_notify(other, true);
    return true;
}

std::ostream &operator<<(std::ostream &os, Bear &bear)
{
    os << "Bear 🐻: " << *static_cast<NPC *>(&bear) << std::endl;
    return os;
}
