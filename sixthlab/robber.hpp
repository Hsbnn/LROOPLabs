#pragma once
#include "npc.hpp"

struct Robber : public NPC
{
    Robber(int x, int y);
    Robber(std::istream &is);

    void print() override;
    void print(std::ostream &os) override;

    //bool is_robber() const override;
    bool accept(std::shared_ptr<NPC> visitor) override;

    bool fight(std::shared_ptr<Robber> other) override;
    bool fight(std::shared_ptr<Wolf> other) override;
    bool fight(std::shared_ptr<Bear> other) override;

    void save(std::ostream &os) override;

    friend std::ostream &operator<<(std::ostream &os, Robber &robber);
};