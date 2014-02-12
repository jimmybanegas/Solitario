#include "mainwindow.h"
#include <QApplication>
#include "mazoprincipal.h"
#include "mazoordenado.h"
#include "mazomovimientos.h"
#include "juego.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(application);
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/images/SolitaireMCE.png"));
    MainWindow w;
    w.setWindowIcon(QIcon(":/images/SolitaireMCE.png"));

     Juego solitario;

     w.setMazo(&solitario.mazo,&solitario.barajear);
     w.setJuego(solitario);

     solitario.distribuir();
     solitario.mazo.imprimir();

     solitario.diamante.imprimir();
     solitario.trebol.imprimir();
     solitario.corazon.imprimir();
     solitario.espada.imprimir();

     solitario.uno.imprimir();
     solitario.dos.imprimir();
     solitario.tres.imprimir();
     solitario.cuatro.imprimir();
     solitario.cinco.imprimir();
     solitario.seis.imprimir();
     solitario.siete.imprimir();

      w.crearCartasVisuales2(solitario.mazo,20,41,0);

      w.crearCartasVisuales(solitario.diamante,350,41,0,0);
      w.crearCartasVisuales(solitario.corazon,460,41,0,0);
      w.crearCartasVisuales(solitario.espada,570,41,0,0);
      w.crearCartasVisuales(solitario.trebol,680,41,0,0);

      w.crearCartasVisuales(solitario.uno,20,190,15,0);
      w.crearCartasVisuales(solitario.dos,130,190,15,0);
      w.crearCartasVisuales(solitario.tres,240,190,15,0);
      w.crearCartasVisuales(solitario.cuatro,350,190,15,0);
      w.crearCartasVisuales(solitario.cinco,460,190,15,0);
      w.crearCartasVisuales(solitario.seis,570,190,15,0);
      w.crearCartasVisuales(solitario.siete,680,190,15,0);



     w.show();
    return a.exec();
}
