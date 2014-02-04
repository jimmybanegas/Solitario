#include "mainwindow.h"
#include <QApplication>
#include "mazoprincipal.h"
#include "mazoordenado.h"
#include "mazomovimientos.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(application);
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/images/SolitaireMCE.png"));
    MainWindow w;
    w.setWindowIcon(QIcon(":/images/SolitaireMCE.png"));
    w.show();

    MazoPrincipal mazo;
    MazoOrdenado diamantes;

    mazo.generarCartas();
    diamantes.insertar(0, new Nodo('A','N','D'));
    diamantes.imprimir();

    mazo.imprimir();

    return a.exec();
}
