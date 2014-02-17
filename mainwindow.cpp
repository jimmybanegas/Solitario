#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QLabel>
#include <QPixmap>
#include "milabel.h"
#include "label.h"

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
}

void MainWindow::crearCartasVisuales(MazoPrincipal mazox, int x ,int y, int crecery, int crecerx){

   for(int i=0; i<mazox.cont; i++){
    QPixmap actual =  QPixmap(":/images/cards/Back.png");
    if(!mazox.recuperar(i)->carta->isCaraAbajo())
    {
     actual = mazox.recuperar(i)->carta->getImagen();
    }

    Label *a = new Label(this);
    a->nodo=mazox.recuperar(i);
    a->pertenece=&mazox;
    a->setPixmap(actual);
    a->setGeometry(x,y,99,135);
    a->setAcceptDrops(true);
    a->raise();
    a->show();
    y+=crecery;
    x+=crecerx;
  }
}


void MainWindow::crearCartasVisuales2(MazoPrincipal mazox, int x ,int y, int crecer){

   for(int i=0; i<mazox.cont; i++){
    QPixmap actual =  QPixmap(":/images/cards/Back.png");
    if(!mazox.recuperar(i)->carta->isCaraAbajo())
    {
     actual = mazox.recuperar(i)->carta->getImagen();
    }

    miLabel *a = new miLabel(this);
    a->nodo=mazox.recuperar(i);
    a->pertenece=&mazox;
    a->setPixmap(actual);
    a->setGeometry(x,y,99,135);
    connect(a, SIGNAL( Mouse_Pressed() ), this, SLOT(Mouse_Pressed()));
    a->raise();
    a->show();
    y+=crecer;
  }
}

void MainWindow::setMazo(MazoPrincipal *mazo, MazoPrincipal *barajear)
{
    this->mazo=mazo;
    //this->barajear=&barajear;
   /* this->mazo=mazo;
    this->barajear=barajear;*/

}

void MainWindow::setJuego(Juego juego)
{
    juego=juego;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void MainWindow::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;

        Label *newIcon = new Label(this);
        newIcon->setPixmap(pixmap);
        newIcon->move(event->pos() - offset);
        newIcon->adjustSize();
        newIcon->show();

       // cout<<offset.rx()<<" "<<offset.ry()<<endl;

         newIcon->setAttribute(Qt::WA_DeleteOnClose);

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

//! [1]
void MainWindow::mousePressEvent(QMouseEvent *event)
{

   Label *child = static_cast<Label*>(childAt(event->pos()));
   int x=event->pos().rx();

   //event->pos().setX(x+15);

   //QPoint dos= event->pos();

  // Label *child2= static_cast<Label*>(childAt(dos));

   cout<<event->pos().rx()<<" "<<event->pos().ry()<<endl;

    if (!child)
     return;

    QPixmap pixmap = *child->pixmap();

    QByteArray itemData;

    QDataStream dataStream(&itemData, QIODevice::WriteOnly);

    dataStream << pixmap << QPoint(event->pos() - child->pos());

    dataStream<<

    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);
//! [2]

//! [3]
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos() - child->pos());

//! [3]

    QPixmap tempPixmap = pixmap;

    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();

    child->setPixmap(tempPixmap);

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
        child->close();
    } else {
        child->show();
        child->setPixmap(pixmap);
    }
}

//Para barajear la lista de arriba e ir mostrando uno a la vez

void MainWindow::Mouse_Pressed()
{

      int random;
      srand (time(NULL));

      random = rand() % (mazo->cont);
      Nodo *sel=mazo->recuperar(random);

      QPixmap actual=sel->carta->getImagen();

      Label *a = new Label(this);
      a->setPixmap(actual);
      a->setGeometry(130,41,99,135);
      a->raise();
      a->show();

   cout<<"La has barajeado"<<endl;

}

void MainWindow::cc()
{

}
