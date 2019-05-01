#ifndef FIELD_H
#define FIELD_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QPainter>

class Field : public QObject, public QGraphicsRectItem
{ Q_OBJECT
public:
    Field(std::tuple<unsigned int, unsigned int> size);
};

#endif // FIELD_H
