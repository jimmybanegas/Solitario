#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mazoprincipal.h"
#include "mazomovimientos.h"
#include "mazoordenado.h"
#include "juego.h"
#include <QMainWindow>
#include <QPixmap>
#include "elementosgraficos.h"
#include "qlabel.h"
#include "QtCore"
#include "QVBoxLayout"
#include <stdlib.h>
#include <time.h>


namespace Ui {
   class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    //QGraphicsView *vista;
    QGraphicsScene *escena;
    QTimer *timer;
    QWidget *widgetCentral;

public:
  //  Ui::MainWindow *ui;
    MazoPrincipal mazo;

    void crearCartasVisuales(MazoPrincipal mazo, int x);
    void crearCartasVisuales2(MazoPrincipal mazo, int x);
    void crearCartasVisuales3(MazoPrincipal mazo, int x);
    void crearCartasVisuales4(MazoPrincipal mazo, int x);
    void crearCartasVisuales5(MazoPrincipal mazo, int x);
    void crearCartasVisuales6(MazoPrincipal mazo, int x);
    void crearCartasVisuales7(MazoPrincipal mazo, int x);

    void barajear(MazoPrincipal mazo);
    void setMazo(MazoPrincipal mazo);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
       Ui::MainWindow *ui;
     //QGraphicsScene *scene;

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *event);


private slots:

    void on_pushButton_clicked();

};

#endif // MAINWINDOW_H
