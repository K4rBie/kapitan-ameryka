#include "logicobject.h"

LogicObject::LogicObject()
{

}

const Position &LogicObject::get_pos()
{
    return pos;
}

const double &LogicObject::y()
{
    return pos.y;
}

const double &LogicObject::x()
{
    return pos.x;
}

PointF PointF::operator+(const PointF &b)
{
    PointF c;
    c.x = this->x + b.x;
    c.y = this->y + b.y;
    return c;
}

void PointF::operator+=(const PointF &b)
{
    *this = *this + b;
}

void PointF::operator-=(const PointF &b)
{
    *this = *this - b;
}

PointF PointF::operator-(const PointF &b)
{
    PointF c;
    c.x = this->x - b.x;
    c.y = this->y - b.y;
    return c;
}

PointF PointF::operator/(const double &d)
{
    PointF c;
    c.x = this->x / d;
    c.y = this->y / d;
    return c;
}

double PointF::dot_product(PointF p1, PointF p2)
{
    return p1.x * p2.x + p1.y * p2.y;
}

double LogicObject::distance_squared(PointF p1, PointF p2)
{
    PointF vector = p1 - p2;
    return PointF::dot_product(vector, vector);
}
