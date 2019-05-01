#ifndef SUPERVILLAIN_H
#define SUPERVILLAIN_H

#include <QObject>
#include "human.h"

class SuperVillain : public virtual Human
{
public:
    SuperVillain(unsigned int _HP, unsigned int _MP, Position _pos);

    void attack();
    void super_attack(); // wewnątrz protected?
};

#endif // SUPERVILLAIN_H
