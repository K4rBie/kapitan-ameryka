#include "supervillain.h"

SuperVillain::SuperVillain(unsigned int HP_, unsigned int MP_, PointF pos_) : Human(HP_, MP_, pos_)
{
    /* To wszystko powinno trafić do graficznej części */
    //setRect(pos_.x, pos_.y, 2*radius, 2*radius);
    //setBrush(Qt::blue);
    //QPen pen(Qt::darkBlue, 3);
    //setPen(pen);

    team = 1;
    speed = 6;
    DMG = 20;
    attack_cooldown = 20;
}

void SuperVillain::run_simulation(std::vector<std::weak_ptr<Human> > everyone)
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


void SuperVillain::attack(TargetedHuman target)
{
    if (state.fleeing) return;

    if (attack_counter != attack_cooldown){
        attack_counter++;
    } else if (target.squared_distance <= 1600){
        target.pointer.value().lock()->receive_dmg(DMG);
        attack_counter = 0;
    }
}

void SuperVillain::super_attack()
{

}

void SuperVillain::move(PointF target_pos, double dist_sqr)
{    
    if (pos.x < radius || pos.x > 500 - radius || pos.y < radius || pos.y > 500 - radius) return;
    state.in_move = true;

    PointF motion_vector = target_pos - this->pos;
    double vec_length = sqrt(dist_sqr);

    if (this->HP > 100) {
        if (vec_length <= (2 * this->radius)) {
            return;
        }
        this->LogicObject::pos += motion_vector / ( double(vec_length) / double(speed) * 10);
    } else {
        state.fleeing = true;
        this->LogicObject::pos -= motion_vector / ( double(vec_length) / double(speed) * 8);
    }
}
