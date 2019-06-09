#include "field.h"

// LOGIC-READY
Field::Field()
{
}

array<unsigned int, 2> Field::get_size()
{
    return size;
}

unsigned int Field::get_radius()
{
    cout << "ktoś odniósł się do radiusa w kwadracie, bo może, bo chujowo napisany kod";
    cerr << "ktoś odniósł się do radiusa w kwadracie, bo może, bo chujowo napisany kod";
    return size[0];
}
