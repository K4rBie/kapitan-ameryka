#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}


/* RZECZY DO ZROBIENIA ŻEBY ROZDZIELIĆ GRAFIKĘ OD LOGIKI: */
/* zamienić Qtimer na coś innego, ael nie wiem jeszcze co
 *
 *
 */

/* jak ma działać ta cała logika?
 * obraz świata znajduje się w world i stamtąd zaczynają się obliczenia
 * klasa GraphicObject ma zawierać wskaźniki do wszystkich obiektów, co daje możliwość klasie graficznej pobieranie przydatnych jej właściwości.
 * co to będzie za klasa graficzna?
 * jak GraphicObject będzie przekazywany tej klasie?
 *      będzie go posiadała, jakoś zaczynała symulację i otrzymywała obiekty? get_all_objects?
 *
 */

// obawiam się, czy jeśli zrobiłem wszystko logicobjectem, to teraz muszę się odnosić do cech charakterystycznych dla humana i pytać o to nawet np fielda, co powoduje, że de facto wszystko staje się humanem??
