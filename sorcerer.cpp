#include "sorcerer.h"

Sorcerer::Sorcerer(unsigned int HP_, unsigned int MP_, PointF pos_, unsigned int team_) : Human(HP_, MP_, pos_)
{
    this->team = team_;

    speed = 11;
    DMG = 2;
    attack_cooldown = 40;
}

void Sorcerer::run_simulation(std::vector<std::weak_ptr<Human> > everyone)
{
    if (!this->state.alive) return;

    if (state.damaged_lately) {
        if (damaged_counter != damaged_cooldown) {
            damaged_counter++;
        } else {
            state.damaged_lately = false;
            damaged_counter = 0;
        }
    }

    TargetedHuman closest_target = this->find_closest_enemy(everyone);
    if (!closest_target.pointer.has_value()) {
        return;
    }

    PointF enemy_pos = closest_target.pointer.value().lock()->get_pos();

    this->state.in_move = false; // na razie niepotrzebne, ale jak move będzie w warunku to się przyda
    this->move(enemy_pos, closest_target.squared_distance);

    attack(closest_target);
}

void Sorcerer::attack(TargetedHuman target)
{
    if (attack_counter != attack_cooldown){
        attack_counter++;
    } else {
        target.pointer.value().lock()->receive_dmg(DMG);
        attack_counter = 0;
    }

}

void Sorcerer::super_attack()
{

}

void Sorcerer::move(PointF target_pos, double dist_sqr)
{
    state.in_move = true;

    int x = rand() % (500 - 2 * radius - 1) + radius + 1;
    int y = rand() % (500 - 2 * radius - 1) + radius + 1;

    if (dist_sqr < 4 * radius * radius + radius) {
        this->pos = {double(x), double(y)};
        return;
    }

    PointF motion_vector = target_pos - this->pos;
    double vec_length = sqrt(dist_sqr);

    if (vec_length <= (2 * this->radius)) {
        return;
    }

    this->LogicObject::pos += motion_vector / ( double(vec_length) / double(speed) * 10);
}
