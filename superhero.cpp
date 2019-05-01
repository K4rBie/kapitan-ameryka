#include "superhero.h"

SuperHero::SuperHero(unsigned int _HP, unsigned int _MP, Position _pos) : Human(_HP, _MP, _pos)
{
    body.setRect(pos.X-40, pos.Y-40, 50, 50);
    body.setBrush(Qt::cyan);
    //body.setPen(Qt::darkCyan, 3); //V1
    QPen pen(Qt::darkCyan, 3);
    body.setPen(pen);
}

void SuperHero::attack()
{

}

void SuperHero::super_attack()
{

}
