#ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include <vector>
#include <memory>
#include <cmath>

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QPainter>
#include <QString>
#include <QDebug>


//struct Position { int X; int Y; };

struct State
{
    bool in_move = false;
    bool attacking = false;
    bool attacked_lately = false;
    bool blocking = false;
    bool backing = false;
    bool alive = true;
};

// istnieje niezerowa szansa, że przez to, że wszyscy wszystkim się dają, to stosowanie shared_ptr będzie cykliczne
// i nigdy się nie usuną. jeśli obiekt dostaje weak pointer do siebie i przez niego pyta o shared ptry do swoich cech
// to dopóki obiekt żyje to shared_ptr nie zostanie usunięty, a
class Human : public QObject, public QGraphicsEllipseItem
{ Q_OBJECT
public:
    Human(unsigned int _HP, unsigned int _MP, QPointF loc_pos);
    unsigned int get_HP();
    unsigned int get_MP();
    unsigned int get_team();

    State* get_state();
    virtual void run_simulation(std::vector<std::weak_ptr<Human>> everyone) = 0;

    unsigned int radius = 15;



protected:
    ~Human(){}
    virtual void attack() = 0;
    virtual void super_attack() = 0;
    virtual std::weak_ptr<Human> find_closest_enemy(std::vector<std::weak_ptr<Human>> everyone) = 0; // czy musi być wirtualny?
    void move(QPointF target_pos);
    QPointF loc_pos;
    unsigned int team;
    unsigned int HP;
    unsigned int MP;
    unsigned int DMG;
    unsigned int speed;
    State state;

};

#endif // HUMAN_H
