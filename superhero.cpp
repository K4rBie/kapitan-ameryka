#include "superhero.h"

// CLASS-READY
SuperHero::SuperHero(unsigned int HP_, unsigned int MP_, PointF pos_) : Human(HP_, MP_, pos_)
{
    /* To wszystko powinno trafić do graficznej części */
    //setRect(pos_.x, pos_.y, 2*radius, 2*radius);
    //setBrush(Qt::cyan);
    //QPen pen(Qt::darkCyan, 3);
    //setPen(pen);

    team = 0;
    speed = 11;
    DMG = 10;
    attack_cooldown = 40;
}

void SuperHero::run_simulation(std::vector<std::weak_ptr<Human> > everyone)
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

void SuperHero::attack(TargetedHuman target)
{
    if (attack_counter != attack_cooldown){
        attack_counter++;
    } else if (target.squared_distance <= 1600){
        target.pointer.value().lock()->receive_dmg(DMG);
        attack_counter = 0;
    }

}

void SuperHero::super_attack()
{

}

void SuperHero::move(PointF target_pos, double dist_sqr)
{
    state.in_move = true;

    PointF motion_vector = target_pos - this->pos;
    double vec_length = sqrt(dist_sqr);

    if (vec_length <= (2 * this->radius)) {
        return;
    }

    this->LogicObject::pos += motion_vector / ( double(vec_length) / double(speed) * 10);
}
