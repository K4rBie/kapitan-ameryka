#include "human.h"

Human::Human(unsigned int _HP, unsigned int _MP, Position _pos) : HP(_HP), MP(_MP), pos(_pos)
{

}

unsigned int Human::get_HP()
{
    return HP;
}

unsigned int Human::get_MP()
{
    return MP;
}

Position Human::get_pos()
{
    return pos;
}

State *Human::get_state()
{
    return &state;
}

QGraphicsEllipseItem *Human::get_body()
{
    return &body;
}
