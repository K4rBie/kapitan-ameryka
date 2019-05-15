#ifndef SUPERHERO_H
#define SUPERHERO_H

#include "human.h"

class SuperHero : public virtual Human
{   Q_OBJECT
public:
    SuperHero(unsigned int _HP, unsigned int _MP, QPointF loc_pos); // ostatecznie nie może być unsigned, bo jak dostanie
    // dmg albo zużyje manę za więcej niż ma, to się zrobi overflow
    // można też testować czy przekroczy, a nie czy przekroczył i wtedy wszystko jest w porzadku
    void run_simulation(std::vector<std::weak_ptr<Human>> everyone);

protected:
    void attack();
    void super_attack();
    std::weak_ptr<Human> find_closest_enemy(std::vector<std::weak_ptr<Human>> everyone);
};

#endif // SUPERHERO_H
