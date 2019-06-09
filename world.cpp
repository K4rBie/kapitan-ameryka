#include "world.h"

World::World(std::array<unsigned int, 2> fightscene_size) :
    fieldsize(fightscene_size) // to właściwie dość śmiesznie działa, bo chyba nie muszę wtedy w każdej klasie robić specjalnej zmiennej rozmiaru, jeśli tylko używam jej w konstruktorze
    //field(fightscene_size)
{
    double distance = fightscene_size[0] * 9 / 4 / 10;
    double bottom = fightscene_size[1] * 3 / 4;

    for(int i=0; i<4; i++) {
        fighters.push_back(make_shared<SuperHero>(200, 100, PointF{60 + i*distance * 0.7, 10}));
    }

    for(int i=0; i<4; i++) {
        fighters.push_back(make_shared<SuperVillain>(200, 100, PointF{20 + i*distance * 1.3, bottom}));
    }

}


Field &World::get_field()
{
    return field;
}

vector<shared_ptr<Human>> World::get_fighters()
{
    return fighters;
}

vector<shared_ptr<LogicObject> > World::get_all_objects() /* nie wiem, czy nie wystarczyłby unique_ptr*/
{
    vector<shared_ptr<LogicObject> > all_objects;
    //shared_ptr<Field> field_ptr = make_shared<Field>(field);

    all_objects.push_back(make_shared<Field>(field));

    for (auto fighter : fighters) {
        all_objects.push_back(fighter);
    }
    return all_objects;
}

void World::run_simulation()
{
    for (auto fighter : fighters) {
        fighter->run_simulation(convert_ptr_vec(fighters));
    }
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
