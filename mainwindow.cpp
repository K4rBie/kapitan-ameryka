#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    fightscene_size(tuple(400, 400)),
    world(fightscene_size)
{
    ui->setupUi(this);

    //world(fightscene_size);
    QGraphicsScene *fightscene = new QGraphicsScene;
    fightscene->setSceneRect(0,0,std::get<0>(fightscene_size),std::get<1>(fightscene_size)); //wtf ja to napisałem?

    ui->battleGraphicsView->setMinimumSize(std::get<0>(fightscene_size),std::get<1>(fightscene_size));
    ui->battleGraphicsView->setScene(fightscene);
    QGraphicsItem* field = world.get_field();
    fightscene->addItem(field); // w og

    //std::unique_ptr<Human> Adam = std::move(world.get_fighters()[0]);

    for (auto fighter : world.get_fighters()) {
        fightscene->addItem(fighter->get_body());
    }
    //fightscene->addItem(world.get_fighters().at(0).get()->get_body()); //TODO wypisz wszystkich humanów

    //Adam_ptr.get()->get_pos().X
    //unique_ptr<vector<shared_ptr<Human>>> test;
}

MainWindow::~MainWindow()
{
    delete ui;
}
