#ifndef WORLD_H
#define WORLD_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <string>
#include <vector>
#include <memory>

#include "superhero.h"
#include "supervillain.h"
#include "field.h"


using namespace std;

class World
{
public:
    World(std::tuple<unsigned int, unsigned int> fightscene_size);
    QTimer* get_world_timer();
    Field* get_field();
    vector<shared_ptr<Human> > get_fighters();

private:
    QTimer world_timer;
    vector<shared_ptr<Human> > fighters;
    std::tuple<unsigned int, unsigned int> fieldsize;
    Field field;
};

#endif // WORLD_H
