#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    fightscene_size({500, 500})
    //world(fightscene_size)
{
    ui->setupUi(this);

    fightscene = new QGraphicsScene;
    fightscene->setSceneRect(0,0,fightscene_size[0], fightscene_size[1]);

    ui->battleGraphicsView->setScene(fightscene);

    setup_styles();

    qreal width = graphic_world.everything.at(0).get()->get_size().at(0);
    qreal height = graphic_world.everything.at(0).get()->get_size().at(1);
    qreal x = graphic_world.everything.at(0).get()->get_pos().x;
    qreal y = graphic_world.everything.at(0).get()->get_pos().y;
    QGraphicsRectItem* field = new QGraphicsRectItem(x, y, width, height);

    field->setBrush(Qt::green);

    fightscene->addItem(field);

    setup_fighters();

    connect(&graphic_timer, SIGNAL(timeout()), &graphic_world, SLOT(run_simulation()) );
    connect(&graphic_timer, SIGNAL(timeout()), this, SLOT(run_simulation()) );

    graphic_timer.start(15);
}

MainWindow::~MainWindow()
{
    delete ui;
    for (auto fighter : g_fighters) {
        delete fighter;
    }
}

void MainWindow::setup_styles()
{
    good_pen.setColor(Qt::darkCyan);
    good_pen.setWidth(3);
    QBrush good_temp(Qt::cyan);
    good_brush = good_temp;

    bad_pen.setColor(Qt::darkYellow);
    bad_pen.setWidth(3);
    QBrush bad_temp(Qt::yellow);
    bad_brush = bad_temp;

    dead_pen.setColor(Qt::darkRed);
    dead_pen.setWidth(3);
    QBrush dead_temp(Qt::black);
    dead_brush = dead_temp;
}

void MainWindow::setup_fighters()
{
    for (unsigned long i = 1; i < graphic_world.everything.size(); i++ ){

        auto log_fighter = graphic_world.everything.at(i).get();

        auto* fighter = new QGraphicsEllipseItem(0, 0,
                        log_fighter->get_size()[0], log_fighter->get_size()[1]);

        if (static_cast<Human*>(log_fighter)->get_team() == 0) {
            fighter->setPen(good_pen);
            fighter->setBrush(good_brush);
        } else {
            fighter->setBrush(bad_brush);
            fighter->setPen(bad_pen);
        }

        g_fighters.push_back(fighter);

        fightscene->addItem(fighter);
    }
}

void MainWindow::run_simulation()
{
    unsigned long i = 1;
    for (auto fighter : g_fighters) {
        auto logic_figther = static_cast<Human*>(graphic_world.everything.at(i).get());
        if (!logic_figther->get_state()->alive) {
            fighter->setBrush(Qt::black);
            fighter->setPen(QPen{Qt::darkRed, 3});
            i++;
            continue;
        }

        if (logic_figther->get_state()->damaged_lately) {
            fighter->setBrush(Qt::red);
        } else {
            if (logic_figther->get_team() == 0) {
                fighter->setBrush(good_brush);
            } else {
                fighter->setBrush(bad_brush);
            }
        }

        qreal radius = graphic_world.everything.at(i).get()->get_radius();
        qreal x = graphic_world.everything.at(i).get()->get_pos().x;
        qreal y = graphic_world.everything.at(i).get()->get_pos().y;
        fighter->setPos(x - radius, y - radius);

        i++;
    }
}
