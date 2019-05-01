#ifndef SUPERHERO_H
#define SUPERHERO_H

#include <QObject>
#include "human.h"

class SuperHero : public virtual Human
{
public:
    SuperHero(unsigned int _HP, unsigned int _MP, Position _pos);

    void attack();
    void super_attack(); // wewnątrz protected?
};

#endif // SUPERHERO_H
