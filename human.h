#ifndef HUMAN_H
#define HUMAN_H

#include <string>

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QPainter>


struct Position { int X; int Y; };

struct State
{
    bool in_move = false;
    bool attacking = false;
    bool attacked_lately = false;
    bool blocking = false;
    bool backing = false;
};

class Human
{
public:
    Human(unsigned int _HP, unsigned int _MP, Position _pos);
    unsigned int get_HP();
    unsigned int get_MP();

    Position get_pos();
    State *get_state();
    QGraphicsEllipseItem *get_body();

    virtual void attack() = 0;
    virtual void super_attack() = 0; // wewnątrz protected?

protected: //protected, bo chcesz,
    unsigned int HP;
    unsigned int MP;
    unsigned int DMG;
    Position pos;
    State state;
    QGraphicsEllipseItem body;

};

#endif // HUMAN_H
