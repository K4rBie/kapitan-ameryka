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

class World : public QObject
{ Q_OBJECT
public:
    World(std::array<unsigned int, 2> fightscene_size);
    // pointera używam po to, żeby pożyczać ludziom referencje -- może powinienem przerobić te funkcje w referencje?
    //istnieje możliwość, że nie będę nikomu pożyczał timera, bo o całej symulacji pamiętać będzie world
    QTimer& get_world_timer();
    Field& get_field();
    vector<shared_ptr<Human>> get_fighters();

private:
    // world posiada wszystkie rzeczy, więc będzie co określony timer odpalał kolejny krok symulacji
    QTimer world_timer;
    vector<shared_ptr<Human>> fighters;
    std::array<unsigned int, 2> fieldsize;
    Field field;
    vector<weak_ptr<Human>> convert_ptr_vec(vector<shared_ptr<Human>> shared_ptr_vec);

public slots:
    void run_simulation();

};

#endif // WORLD_H
