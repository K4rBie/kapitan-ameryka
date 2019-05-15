#ifndef FIELD_H
#define FIELD_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QPainter>

class Field : public QObject, public QGraphicsRectItem
{ Q_OBJECT
public:
    Field(std::array<unsigned int, 2>  size);
};

#endif // FIELD_H
