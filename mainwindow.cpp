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
<<<<<<< HEAD
    this->mazo=&mazo;
    //this->barajear=&barajear;
=======
   /* this->mazo=mazo;
    this->barajear=barajear;*/
>>>>>>> 390fd8aeb1a8c3bfb3d9b7c5065c4e8a5dca7684
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
    if (!child)
        return;

    QPixmap pixmap = *child->pixmap();

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << pixmap << QPoint(event->pos() - child->pos());
//! [1]

//! [2]
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

void MainWindow::Mouse_Pressed()
{
<<<<<<< HEAD
      int random;
      srand (time(NULL));

      random = rand() % (mazo->cont);
      Nodo *sel=mazo->recuperar(random);

      QPixmap actual=sel->carta->getImagen();

      Label *a = new Label(this);
      a->setPixmap(actual);
      a->setGeometry(130,41,99,135);
     // connect(a, SIGNAL( Mouse_Pressed() ), this, SLOT(Mouse_Pressed()));
      a->raise();
      a->show();
      //  sel->carta->caraAbajo=false;
      // mazo.eliminar(random);
      // barajear->insertar(i,sel);
 //   }
  // barajear->imprimir();
   // crearCartasVisuales(barajear,130,41,0,10);
      cout<<"La has barajeado"<<endl;
=======
    //int random ;
    srand (time(NULL));
    int randoms[3];

    cout<<juego.mazo.cont;

    cout<<juego.barajear.cont;

     if(juego.barajear.cont!=0)
     {
         for(int i=0;i<3;i++)
         {
             Nodo *t2=juego.barajear.recuperar(i);
             juego.mazo.insertar(i,t2);
             juego.barajear.eliminar(i);
         }
     }


    for(int i=0;i<3;i++)
    {
        randoms[i]=rand() % (juego.mazo.cont);
    }


    for(int i=0;i<3;i++)
    {
        Nodo *sel=juego.mazo.recuperar(randoms[i]);
        cout<<"RAMDOM: "<<randoms[i];
        juego.mazo.eliminar(randoms[i]);
        juego.barajear.insertar(i,sel);
    }

      cout<<"BARAJEAR CONT: "<<&juego.barajear.cont<<endl;
      cout<<"PRINCIPA CONT: "<<&juego.mazo.cont<<endl;

      juego.barajear.imprimir();

      int x=130;
      for(int i=0;i<3;i++)
     {
         Nodo *temp=juego.barajear.recuperar(i);
         QPixmap ac = temp->carta->getImagen();

         Label *a = new Label(this);
         a->setPixmap(ac);
         a->setGeometry(x,41,99,135);
         a->raise();
         a->show();
         x+=10;
     }

  //  this->mazo->imprimir();
   cout<<"La has barajeado"<<endl;
>>>>>>> 390fd8aeb1a8c3bfb3d9b7c5065c4e8a5dca7684
}

void MainWindow::cc()
{

}
