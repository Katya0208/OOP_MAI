#include "../input/princess.hpp"
#include "../input/dragon.hpp"
#include "../input/knight.hpp"

Princess::Princess(int x, int y) : NPC(PrincessType, x, y) {}
Princess::Princess(std::istream &is) : NPC(PrincessType, is) {}

bool Princess::accept(std::shared_ptr<NPC> visitor){
    return visitor->fight(std::shared_ptr<Princess>(this,[](Princess*){}));
}

void Princess::print()
{
    std::cout << *this;
}

void Princess::save(std::ostream &os)
{
    os << PrincessType << std::endl;
    NPC::save(os);
}


bool Princess::fight(std::shared_ptr<Dragon> other)
{
    fight_notify(other, false);
    return true;
}

bool Princess::fight(std::shared_ptr<Knight> other)
{
    fight_notify(other, false);
    return true;
}

bool Princess::fight(std::shared_ptr<Princess> other)
{
    fight_notify(other, false);
    return true;
}

std::ostream &operator<<(std::ostream &os, Princess &princess)
{
    os << "princess: " << *static_cast<NPC *>(&princess) << std::endl;
    return os;
}