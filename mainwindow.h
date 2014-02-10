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
#include <QPainter>

namespace Ui {
   class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MazoPrincipal mazo;

    void crearCartasVisuales(MazoPrincipal mazo, int x, int y, int crecer);
    void barajear(MazoPrincipal mazo);
    void setMazo(MazoPrincipal mazo);
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

    void on_pushButton_clicked();

};

#endif // MAINWINDOW_H
