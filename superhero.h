#ifndef SUPERHERO_H
#define SUPERHERO_H

#include "human.h"

class SuperHero : public Human
{
public:
    SuperHero(unsigned int HP_, unsigned int MP_, PointF pos_); // ostatecznie nie może być unsigned, bo jak dostanie
    // dmg albo zużyje manę za więcej niż ma, to się zrobi overflow
    // można też testować czy przekroczy, a nie czy przekroczył i wtedy wszystko jest w porzadku
    void run_simulation(std::vector<std::weak_ptr<Human>> everyone);
//    array<unsigned int, 2> get_size();
//    unsigned int get_radius();

protected:
    void attack(TargetedHuman target);
    void super_attack();
    void move(PointF target_pos, double dist_sqr);
    //std::weak_ptr<Human> find_closest_enemy(std::vector<std::weak_ptr<Human>> everyone);
};

#endif // SUPERHERO_H
