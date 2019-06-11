#include "graphicobject.h"

GraphicObject::GraphicObject()
{
    world = new World({500, 500});
    everything = world->get_all_objects();
}

void GraphicObject::reset_world()
{
    delete world;
    world = new World({500, 500});
    everything = world->get_all_objects();
}

GraphicObject::~GraphicObject()
{
    delete world;
}

void GraphicObject::run_simulation()
{
    world->run_simulation();
}
