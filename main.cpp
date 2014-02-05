#include "mainwindow.h"
#include <QApplication>
#include "mazoprincipal.h"
#include "mazoordenado.h"
#include "mazomovimientos.h"
#include "juego.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(application);
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/images/SolitaireMCE.png"));
    MainWindow w;
    w.setWindowIcon(QIcon(":/images/SolitaireMCE.png"));
    w.show();

    Juego solitario;

    solitario.distribuir();

    solitario.uno.imprimir();
    solitario.dos.imprimir();
    solitario.tres.imprimir();
    solitario.cuatro.imprimir();
    solitario.cinco.imprimir();
    solitario.seis.imprimir();
    solitario.siete.imprimir();

    return a.exec();
}
