#include "human.h"

Human::Human(unsigned int _HP, unsigned int _MP, QPointF loc_pos) : HP(_HP), MP(_MP)
{
    //setRect(loc_pos.rx(), loc_pos.ry(), 2*radius, 2*radius);
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

State *Human::get_state() // popraw
{
    return &state;
}


void Human::move(QPointF target_pos)
{
    QPointF motion_vector = target_pos - this->sceneBoundingRect().topLeft();
    double vec_length = sqrt(QPointF::dotProduct(motion_vector, motion_vector));

    if (vec_length <= (2 * this->radius + this->speed)) {
        return;
    } // radius nie powinien być publiczny
    // bo przecież nie chcę, żeby mi go ktoś zmieniał :P
    // dodatkowo, w tym miejscu nie masz dostępu do rozmiaru tego, z czym się stykasz,
    // wygląda na to, że trzeba znaleźć inne miejsce dla tego testu

    this->setPos(this->pos() + motion_vector / vec_length * speed);
}
