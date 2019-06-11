#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H

#include <QObject>

#include <vector>
#include <memory>

#include <logicobject.h>
#include <world.h>

using namespace std;

class GraphicObject : public QObject
{ Q_OBJECT
public:
    GraphicObject();
    vector<shared_ptr<LogicObject>> everything;
    void reset_world();
    ~GraphicObject();

private:
    World *world;


public slots:
    void run_simulation();
};

#endif // GRAPHICOBJECT_H
