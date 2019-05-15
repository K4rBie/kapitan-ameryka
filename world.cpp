#include "world.h"

World::World(std::array<unsigned int, 2> fightscene_size) :
    fieldsize(fightscene_size), // to właściwie dość śmiesznie działa, bo chyba nie muszę wtedy w każdej klasie robić specjalnej zmiennej rozmiaru, jeśli tylko używam jej w konstruktorze
    field(fightscene_size)
{
    double distance = fightscene_size[0] * 9 / 4 / 10;
    double bottom = fightscene_size[1] * 3 / 4;

    for(int i=0; i<4; i++) {
        fighters.push_back(std::make_shared<SuperHero>(200, 100, QPointF{30 + i*distance, 50}));
        //qDebug( "X coordinate: " + QString::number( fighters.at(i).get()->get_pos().X ).toLatin1());
    }

    for(int i=0; i<4; i++) {
        fighters.push_back(std::make_shared<SuperVillain>(200, 100, QPointF{30 + i*distance, bottom}));
        //qDebug( "X coordinate: " + QString::number( fighters.at(i).get()->get_pos().X ).toLatin1());
    }    

    connect(&world_timer, SIGNAL(timeout()), this, SLOT(run_simulation()) );
    world_timer.start(17);

}

QTimer &World::get_world_timer()
{
    return world_timer;
}

Field &World::get_field()
{
    return field;
}

vector<shared_ptr<Human>> World::get_fighters()
{
    return fighters;
}

void World::run_simulation()
{
    fighters.at(2)->run_simulation(convert_ptr_vec(fighters));
}

vector<weak_ptr<Human>> World::convert_ptr_vec(vector<shared_ptr<Human>> shared_ptr_vec)
{
    vector<weak_ptr<Human>> weak_ptr_vec;
    weak_ptr_vec.reserve(shared_ptr_vec.size());

    for (shared_ptr<Human> shared_ptr : shared_ptr_vec) {
        weak_ptr elem = shared_ptr;
        weak_ptr_vec.push_back(elem);
    }

    return weak_ptr_vec;
}
