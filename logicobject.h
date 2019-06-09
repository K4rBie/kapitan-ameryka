#ifndef LOGICOBJECT_H
#define LOGICOBJECT_H

#include <cmath>
#include <array>
#include <iostream>

using namespace std;

class PointF
{
public:
    double x;
    double y;

    PointF operator+(const PointF& b);
    void operator+=(const PointF& b);
    void operator-=(const PointF& b);
    PointF operator-(const PointF& b);
    PointF operator/(const double& d);

    static double dot_product(PointF p1, PointF p2);

};

using Position = PointF;
using LineVector = PointF;

class LogicObject
{
public:
    LogicObject();
    const Position& get_pos(); // czy zwracanie referencji jest spoko, czy ma to być wskaźnik?
    const double& x();
    const double& y();
    // tak właśnie działa referencja że daje ci adres do prawdziwej zmiennej, więc chyba jest ok
    double distance_squared(PointF p1, PointF p2);
    virtual unsigned int get_radius() = 0;
    virtual array<unsigned int, 2> get_size() = 0;

protected:
    Position pos;

};

#endif // LOGICOBJECT_H
