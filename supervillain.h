#ifndef SUPERVILLAIN_H
#define SUPERVILLAIN_H

#include "human.h"

class SuperVillain : public virtual Human
{   Q_OBJECT
public:
    SuperVillain(unsigned int _HP, unsigned int _MP, QPointF loc_pos);
    void run_simulation(std::vector<std::weak_ptr<Human>> everyone);

protected:
    void attack();
    void super_attack(); // wewnątrz protected?
    std::weak_ptr<Human> find_closest_enemy(std::vector<std::weak_ptr<Human>> everyone);

};

#endif // SUPERVILLAIN_H
