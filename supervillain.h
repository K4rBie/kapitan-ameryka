#ifndef SUPERVILLAIN_H
#define SUPERVILLAIN_H

#include "human.h"

class SuperVillain : public Human
{
public:
    SuperVillain(unsigned int HP_, unsigned int MP_, PointF pos_);
    void run_simulation(std::vector<std::weak_ptr<Human>> everyone);
//    array<unsigned int, 2> get_size();
//    unsigned int get_radius();

protected:
    void attack(TargetedHuman target);
    void super_attack(); // wewnątrz protected?
    void move(PointF target_pos, double dist_sqr);

};

#endif // SUPERVILLAIN_H
