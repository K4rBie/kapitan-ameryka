#include "supervillain.h"

SuperVillain::SuperVillain(unsigned int _HP, unsigned int _MP, Position _pos) : Human(_HP, _MP, _pos)
{
    body.setRect(pos.X-40, pos.Y-40, 50, 50);
    body.setBrush(Qt::red);
    //body.setPen(Qt::darkRed, 3); //V1
    QPen pen(Qt::darkRed, 3);
    body.setPen(pen);
}

void SuperVillain::attack()
{

}

void SuperVillain::super_attack()
{

}
