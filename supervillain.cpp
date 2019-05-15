#include "supervillain.h"

SuperVillain::SuperVillain(unsigned int _HP, unsigned int _MP, QPointF loc_pos) : Human(_HP, _MP, loc_pos)
{
    setRect(loc_pos.rx(), loc_pos.ry(), 2*radius, 2*radius); //mogę mieć wyjebane na pozycję środka koła
    setBrush(Qt::red);
    //body.setPen(Qt::darkRed, 3); //V1
    QPen pen(Qt::darkRed, 3);
    setPen(pen);

    team = 1;
    speed = 10;
    DMG = 10;
}

void SuperVillain::run_simulation(std::vector<std::weak_ptr<Human> > everyone)
{
    this->find_closest_enemy(everyone);
}

void SuperVillain::attack()
{

}

void SuperVillain::super_attack()
{

}

std::weak_ptr<Human> SuperVillain::find_closest_enemy(std::vector<std::weak_ptr<Human> > everyone)
{
    std::optional<int> smallest_sqr_dist;
    std::shared_ptr<Human> closest;

    double dist_sqr;

    for (auto human_ptr : everyone) {
        std::shared_ptr<Human> human = human_ptr.lock(); // może jakiś test czy jeszcze można?
        if (this->team == human->get_team()) continue;

        QPointF test = human.get()->pos();
        dist_sqr = QPointF::dotProduct(this->pos(), human.get()->pos());
        //qDebug( "square distance: " + QString::number(dist_sqr).toLatin1());
        qDebug( "this pos: " + QString::number(test.x()).toLatin1());


        if (smallest_sqr_dist.has_value()) {
            if (dist_sqr < smallest_sqr_dist) {
                smallest_sqr_dist = dist_sqr; // liczysz ten dystans w dwóch miejscach -- warto by jakoś to powiązać
                closest = human;
            }
        } else {
            smallest_sqr_dist = dist_sqr;
            closest = human; // jeśli odwala to tutaj
        }
        // powinien zwracać pozycję albo obiekt.
        // pozycję, bo to mało danych a tylko tyle lokalnie potrzeba
        // obiekt, bo ostatecznie, jeśli będzie atakował, to i tak potrzebuje się do niego odnieść.
        // weak pointer, bo 2 humany walczące ze sobą zawsze będą miały pointery siebie nawzajem

        // zapisz pointer najbliższego przeciwnika?
        // pointery są małe, nie ma co się zastanawiać, można kopiować co turę
    }
    qDebug( "Smallest square distance: " + QString::number(smallest_sqr_dist.value()).toLatin1());



    return closest; // albo tutaj: dlaczego to działa?
}
