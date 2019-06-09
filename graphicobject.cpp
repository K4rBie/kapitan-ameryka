#include "graphicobject.h"

GraphicObject::GraphicObject() : world({500, 500}) // to dalej można powiązać z oknem
{
    // to powinno jakoś zbierać wszystkie logiczne elementy w jedną kupę
    everything = world.get_all_objects();
}

void GraphicObject::run_simulation()
{
    world.run_simulation();
}
