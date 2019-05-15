#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    fightscene_size({400, 400}),
    world(fightscene_size)
{
    ui->setupUi(this);

    QGraphicsScene *fightscene = new QGraphicsScene;
    fightscene->setSceneRect(0,0,fightscene_size[0], fightscene_size[1]); //wtf ja to napisałem?

    ui->battleGraphicsView->setMinimumSize(fightscene_size[0], fightscene_size[1]);
    ui->battleGraphicsView->setScene(fightscene);

    QGraphicsItem* field = &world.get_field();
    fightscene->addItem(field);

    for (auto fighter : world.get_fighters()) {
        fightscene->addItem(fighter.get());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
