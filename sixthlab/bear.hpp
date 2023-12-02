#pragma once
#include "npc.hpp"

struct Bear : public NPC
{
    Bear(int x, int y);
    Bear(std::istream &is);

    void print() override;
    void print(std::ostream &os) override; //печать куда-то в файл или не

    //bool is_bear() const override;
    bool accept(std::shared_ptr<NPC> visitor) override;
    bool fight(std::shared_ptr<Robber> other) override;
    bool fight(std::shared_ptr<Wolf> other) override;
    bool fight(std::shared_ptr<Bear> other) override;

    void save(std::ostream &os) override;

    friend std::ostream &operator<<(std::ostream &os, Bear &bear);
};