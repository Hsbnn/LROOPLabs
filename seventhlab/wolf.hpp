#pragma once
#include "npc.hpp"

struct Wolf : public NPC
{
    Wolf(int x, int y);
    Wolf(std::istream &is);

    void print() override;
    void print(std::ostream &os) override;

    //bool is_wolf() const override;
    bool accept(std::shared_ptr<NPC> other) override;

    bool fight(std::shared_ptr<Wolf> other) override;
    bool fight(std::shared_ptr<Robber> other) override;
    bool fight(std::shared_ptr<Bear> other) override;

    void save(std::ostream &os) override;

    friend std::ostream &operator<<(std::ostream &os, Wolf &wolf);
};