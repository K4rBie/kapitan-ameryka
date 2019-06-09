#ifndef FIELD_H
#define FIELD_H

#include <logicobject.h>

using namespace std;

class Field : public LogicObject
{
public:
    Field();
    array<unsigned int, 2> get_size();
    unsigned int get_radius();

private:
    array<unsigned int, 2>  size = {500, 500};
};

#endif // FIELD_H
