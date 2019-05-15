#include "superhero.h"

// wstawiasz w niego obiekt Human, czy to nie oznacza, że on nie jest kompletnie abstrakcyjny??? -- chyba nie
SuperHero::SuperHero(unsigned int _HP, unsigned int _MP, QPointF _loc_pos) : Human(_HP, _MP, _loc_pos)
{
    setRect(_loc_pos.rx(), _loc_pos.ry(), 2*radius, 2*radius); //lepiej tu czy w humanie? -- tutaj, bo rozmiar
    setBrush(Qt::cyan);
    //body.setPen(Qt::darkCyan, 3); //V1
    QPen pen(Qt::darkCyan, 3);
    setPen(pen);
    //_loc_pos = this->boundingRect().topLeft(); // co z tym? potrzebne? loc_pos tak, to nie
    qDebug( "loc_pos: " + QString::number(_loc_pos.x()).toLatin1());
    team = 0;
    speed = 2;
    DMG = 10;
}

void SuperHero::run_simulation(std::vector<std::weak_ptr<Human> > everyone)
{
    if (!this->state.alive) return;
    std::weak_ptr<Human> closest_target = this->find_closest_enemy(everyone);
    this->move(closest_target.lock()->boundingRect().topLeft());
}

void SuperHero::attack()
{

}

void SuperHero::super_attack()
{

}

// to chyba może być w humanie
std::weak_ptr<Human> SuperHero::find_closest_enemy(std::vector<std::weak_ptr<Human> > everyone)
{
    std::optional<double> smallest_sqr_dist;
    std::shared_ptr<Human> closest; // zastanów się, czy jeśli to jest shared, to one się ładnie usunął

    double dist_sqr;

    for (std::weak_ptr<Human> human_ptr : everyone) {
//        if(std::shared_ptr<Human> human = human_ptr.lock()){
//            qDebug("pointer jest");
//        } // może jakiś test czy jeszcze można?
        std::shared_ptr<Human> human = human_ptr.lock();
        if (this->team == human->get_team()) continue;

        QPointF dist_vec = human->sceneBoundingRect().topLeft() - sceneBoundingRect().topLeft();
        dist_sqr = QPointF::dotProduct(dist_vec, dist_vec);

        //qDebug( "this X: " + QString::number(sceneBoundingRect().topLeft().rx()).toLatin1());
        //qDebug( "this pos: " + QString::number(test.x()).toLatin1());


        if (smallest_sqr_dist.has_value()) {
            if (dist_sqr < smallest_sqr_dist) {
                smallest_sqr_dist = dist_sqr; // liczysz ten dystans w dwóch miejscach -- warto by jakoś to powiązać
                closest = human;
            }
        } else {
            smallest_sqr_dist = dist_sqr;
            closest = human;
        }
        // powinien zwracać pozycję albo obiekt.
        // pozycję, bo to mało danych a tylko tyle lokalnie potrzeba
        // obiekt, bo ostatecznie, jeśli będzie atakował, to i tak potrzebuje się do niego odnieść.
        // weak pointer, bo 2 humany walczące ze sobą zawsze będą miały pointery siebie nawzajem

        // zapisz pointer najbliższego przeciwnika?
        // pointery są małe, nie ma co się zastanawiać, można kopiować co turę
    }
    qDebug( "Smallest square distance: " + QString::number(smallest_sqr_dist.value()).toLatin1());

    return closest; // dlaczego to działa? -- pewnie dlatego, że shared, ale chgw
}
