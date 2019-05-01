#include "field.h"

Field::Field(std::tuple<unsigned int, unsigned int> size)
{
    this->setRect(0, 0, std::get<0>(size), std::get<1>(size));
    this->setBrush(Qt::green);
}
