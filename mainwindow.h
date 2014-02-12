#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mazoprincipal.h"
#include "mazomovimientos.h"
#include "mazoordenado.h"
#include "juego.h"
#include <QMainWindow>
#include <QPixmap>
#include "qlabel.h"
#include "QtCore"
#include "QVBoxLayout"
#include <stdlib.h>
#include <time.h>
#include <QPainter>
#include "label.h"

namespace Ui {
   class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
<<<<<<< HEAD
    MazoPrincipal *mazo;
    //MazoPrincipal *barajear;

    void crearCartasVisuales(MazoPrincipal mazo, int x, int y, int crecer,int crecerx);
    void crearCartasVisuales2(MazoPrincipal mazo, int x, int y, int crecer);
    void setMazo(MazoPrincipal mazo,MazoPrincipal barajear);
=======
    Juego juego;
   // MazoPrincipal *mazo;
    //MazoPrincipal *barajear;

    void crearCartasVisuales(MazoPrincipal mazox, int x, int y, int crecer,int crecerx);
    void crearCartasVisuales2(MazoPrincipal mazox, int x, int y, int crecer);
    void setMazo(MazoPrincipal *mazo,MazoPrincipal *barajear);
    void setJuego(Juego juego);
    void cc();
>>>>>>> 390fd8aeb1a8c3bfb3d9b7c5065c4e8a5dca7684
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
       Ui::MainWindow *ui;

protected:
    void dragEnterEvent(QDragEnterEvent *event);
   // void dragLeaveEvent(QDragLeaveEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *event);


private slots:
    void Mouse_Pressed();

};

#endif // MAINWINDOW_H
