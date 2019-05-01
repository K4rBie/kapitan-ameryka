#include "world.h"

World::World(std::tuple<unsigned int, unsigned int> fightscene_size) :
    fieldsize(fightscene_size), // to właściwie dość śmiesznie działa, bo chyba nie muszę wtedy w każdej klasie robić specjalnej zmiennej rozmiaru, jeśli tylko używam jej w konstruktorze
    field(fightscene_size)
{
    for(int i=0; i<4; i++) {
        fighters.push_back(std::make_shared<SuperHero>(200,100,Position{30 + i*70, 50}));
        qDebug( "X coordinate: " + QString::number( fighters.at(i).get()->get_pos().X ).toLatin1());
    }

    for(int i=0; i<4; i++) {
        fighters.push_back(std::make_shared<SuperVillain>(200,100,Position{30 + i*70, 150}));
        qDebug( "X coordinate: " + QString::number( fighters.at(i).get()->get_pos().X ).toLatin1());
    }
    world_timer.start(20);
}

QTimer* World::get_world_timer()
{
    return &world_timer;
}

Field* World::get_field()
{
    return &field;
}

vector<shared_ptr<Human> > World::get_fighters()
{
    return fighters;
}
