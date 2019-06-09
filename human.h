#ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include <vector>
#include <memory>
#include <cmath>
#include <optional>

#include "logicobject.h"


using namespace std;

struct State
{
    bool in_move = false;
    bool attacking = false;
    bool attacked_lately = false;
    bool blocking = false;
    bool backing = false;
    bool alive = true;
    bool damaged_lately = false;
    bool fleeing = false;
};

class Human;

struct TargetedHuman
{
    optional<weak_ptr<Human>> pointer;
    double squared_distance;
};

// istnieje niezerowa szansa, że przez to, że wszyscy wszystkim się dają, to stosowanie shared_ptr będzie cykliczne
// i nigdy się nie usuną. jeśli obiekt dostaje weak pointer do siebie i przez niego pyta o shared ptry do swoich cech
// to dopóki obiekt żyje to shared_ptr nie zostanie usunięty, a
class Human : public LogicObject
{
public:
    Human(unsigned int _HP, unsigned int _MP, PointF loc_pos);
    unsigned int get_HP();
    unsigned int get_MP();
    unsigned int get_team();
    unsigned int get_radius();
    array<unsigned int, 2> get_size();
    void receive_dmg(unsigned int dmg);

    State* get_state();
    virtual void run_simulation(vector<weak_ptr<Human>> everyone) = 0;



protected:
    ~Human(){}
    virtual void attack(TargetedHuman target) = 0;
    virtual void super_attack() = 0;
    TargetedHuman find_closest_enemy(vector<weak_ptr<Human>> everyone);
    virtual void move(PointF target_pos, double dist_sqr) = 0;
    unsigned int team; // te wszystkie rzeczy można ustawiać w konstruktorze
    unsigned int HP;
    unsigned int MP;
    unsigned int DMG;
    unsigned int speed;
    unsigned int radius = 15;
    unsigned int attack_cooldown = 5;
    unsigned int attack_counter = 0; //warto odejmować do zera zamiast dodawać, bo dzięki temu klasa graficzna będzie potrzebowała wyłącznie stanu countera a nie jeszcze cooldowna
    unsigned int damaged_cooldown = 3;
    unsigned int damaged_counter = 0;
    State state;
    void die();

private:
    double distance_squared(PointF p1, PointF p2);
    void damaged_counter_reset();
    void attack_counter_reset();

};

#endif // HUMAN_H
