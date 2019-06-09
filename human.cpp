#include "human.h"

Human::Human(unsigned int _HP, unsigned int _MP, PointF loc_pos) : HP(_HP), MP(_MP)
{
    LogicObject::pos = loc_pos;
}

unsigned int Human::get_HP()
{
    return HP;
}

unsigned int Human::get_MP()
{
    return MP;
}

unsigned int Human::get_team()
{
    return team;
}

unsigned int Human::get_radius()
{
    return  radius;
}

array<unsigned int, 2> Human::get_size()
{
    return {2 * radius, 2* radius};
}

void Human::receive_dmg(unsigned int dmg)
{
    if (HP > dmg) {
        HP -= dmg;
        state.damaged_lately = true; // get_hurt()
    } else {
        HP = 0;
        die();
    }
}

State *Human::get_state() // popraw
{
    return &state;
}

void Human::die()
{
    state.alive = false;
}

double Human::distance_squared(PointF p1, PointF p2)
{
    PointF vector = p1 - p2;
    return PointF::dot_product(vector, vector);
}

TargetedHuman Human::find_closest_enemy(std::vector<std::weak_ptr<Human> > everyone)
{
    optional<double> smallest_sqr_dist;
    optional<weak_ptr<Human>> closest;
    double dist_sqr;

    for (std::weak_ptr<Human> human_ptr : everyone) {
        std::shared_ptr<Human> human = human_ptr.lock();
        if (this->team == human->get_team()) continue;
        if (!human->state.alive) continue;

        dist_sqr = distance_squared(human->get_pos(), this->get_pos());

        if (smallest_sqr_dist.has_value()) {
            if (dist_sqr < smallest_sqr_dist) {
                smallest_sqr_dist = dist_sqr; // liczysz ten dystans w dwóch miejscach -- warto by jakoś to powiązać
                closest = human_ptr;
            }
        } else {
            smallest_sqr_dist = dist_sqr;
            closest = human_ptr;
        }
    }
    /* to nie do końca rozwiązuje problem bo closest nie istnieje */
    /* nieprawda: funkcja, która to odbiera sprawdza czy closest ma wartość */
    if (!smallest_sqr_dist.has_value()) return {closest, 0};
    return {closest, smallest_sqr_dist.value()};
}
