#include "field.h"

Field::Field(std::array<unsigned int, 2> size)
{
    this->setRect(0, 0, size[0], size[0]);
    this->setBrush(Qt::green);
}
