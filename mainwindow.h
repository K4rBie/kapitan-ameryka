#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>

#include "world.h"
#include <graphicobject.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    std::array<unsigned int, 2> fightscene_size;
    //World world; // zbędne w przyszłości
    GraphicObject graphic_world;
    QTimer graphic_timer;
    vector<QGraphicsEllipseItem*> g_fighters;
    QGraphicsScene *fightscene;
    QBrush good_brush;
    QBrush bad_brush;
    QBrush dead_brush;

    QPen good_pen;
    QPen bad_pen;
    QPen dead_pen;

    void setup_styles();
    void setup_fighters();

public slots:
    void run_simulation();
private slots:
    void on_resetButton_clicked();
    void on_quitButton_clicked();
};

#endif // MAINWINDOW_H
