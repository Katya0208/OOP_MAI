#pragma once
#include "npc.hpp"

struct Princess : public NPC
{
    Princess(int x, int y);
    Princess(std::istream &is);

    void print() override;
    void save(std::ostream &os) override;
    bool fight(std::shared_ptr<Dragon> other) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Princess> other) override;
    bool accept(std::shared_ptr<NPC> visitor) override;

    friend std::ostream &operator<<(std::ostream &os, Princess &knight);
};