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

void MainWindow::setMazo(MazoPrincipal *mazo,MazoPrincipal *barajear,MazoPrincipal *uno,MazoPrincipal *dos,
                         MazoPrincipal *tres,MazoPrincipal *cuatro,MazoPrincipal *cinco,MazoPrincipal *seis,
                         MazoPrincipal *siete)
{
    this->mazo=mazo;
    this->uno=uno;
    this->dos=dos;
    this->tres=tres;
    this->cuatro=cuatro;
    this->cinco=cinco;
    this->seis=seis;
    this->siete=siete;
}

void MainWindow::setJuego(Juego *juego)
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

        newIcon->setAttribute(Qt::WA_DeleteOnClose);

        bool tirar = false;
        int rmov;
        int rult;
        QString rango1;
        QString rango2;

        newIcon->nodo=moviendo->nodo;
        newIcon->pertenece=moviendo->pertenece;

        if(newIcon->pos().rx()>15 && newIcon->pos().rx() <25)
        {
           Nodo *ultimo= uno->recuperar(uno->cont-1);
           rmov=moviendo->nodo->carta->getRango().toInt();

           rango1 = ultimo->carta->getRango();
           rango2 = moviendo->nodo->carta->getRango();

           if(rango1=="0")
              rmov=10;
           if(rango1=="J")
               rmov=11;
           if(rango1=="Q")
               rmov=12;
           if(rango1=="K")
               rmov=13;

           rult=ultimo->carta->getRango().toInt();

           if(rango2=="0")
              rult=10;
           if(rango2=="J")
               rult=11;
           if(rango2=="Q")
               rult=12;
           if(rango2=="K")
               rult=13;

           if(ultimo->carta->getColor() != moviendo->nodo->carta->getColor()
                   &&  rmov == rult-1)
           {
               cout<<"Si Pasa"<<endl;
               tirar=true;
               cout<<"RMOV: "<<rmov<<"RULT: "<<rult;
           }
           else
           {
               cout<<"No Pasa"<<endl;
               cout<<"RMOV: "<<rmov<<"RULT: "<<rult;
           }

        }

        if(newIcon->pos().rx()>125 && newIcon->pos().rx() <135)
        {
           Nodo *ultimo = dos->recuperar(dos->cont-1);

           rmov=moviendo->nodo->carta->getRango().toInt();

           rango1 = ultimo->carta->getRango();
           rango2 = moviendo->nodo->carta->getRango();

           if(rango1=="0")
              rmov=10;
           if(rango1=="J")
               rmov=11;
            if(rango1=="Q")
               rmov=12;
           if(rango1=="K")
               rmov=13;

            rult=ultimo->carta->getRango().toInt();

            if(rango2=="0")
               rult=10;
            if(rango2=="J")
                rult=11;
             if(rango2=="Q")
                rult=12;
            if(rango2=="K")
                rult=13;

           if(ultimo->carta->getColor() != moviendo->nodo->carta->getColor()
                   &&  rmov == rult-1)
           {
               cout<<"Si Pasa"<<endl;
               tirar=true;
               cout<<"RMOV: "<<rmov<<"RULT: "<<rult;
           }
           else
           {
               cout<<"No Pasa"<<endl;
               cout<<"RMOV: "<<rmov<<"RULT: "<<rult;
           }

        }

        if(newIcon->pos().rx()>235 && newIcon->pos().rx() <245)
        {
           Nodo *ultimo= tres->recuperar(tres->cont-1);
           rmov=moviendo->nodo->carta->getRango().toInt();

           rango1 = ultimo->carta->getRango();
           rango2 = moviendo->nodo->carta->getRango();

           if(rango1=="0")
              rmov=10;
           if(rango1=="J")
               rmov=11;
           if(rango1=="Q")
               rmov=12;
           if(rango1=="K")
               rmov=13;

           rult=ultimo->carta->getRango().toInt();

           if(rango2=="0")
              rult=10;
           if(rango2=="J")
               rult=11;
           if(rango2=="Q")
               rult=12;
           if(rango2=="K")
               rult=13;

           if(ultimo->carta->getColor() != moviendo->nodo->carta->getColor()
                   &&  rmov == rult-1)
           {
               cout<<"Si Pasa"<<endl;
               tirar=true;
               cout<<"RMOV: "<<rmov<<"RULT: "<<rult;
           }
           else
           {
               cout<<"No Pasa"<<endl;
               cout<<"RMOV: "<<rmov<<"RULT: "<<rult;
           }

        }

        if(newIcon->pos().rx()>345 && newIcon->pos().rx() <355)
        {
           Nodo *ultimo= cuatro->recuperar(cuatro->cont-1);

           rmov=moviendo->nodo->carta->getRango().toInt();

           rango1 = ultimo->carta->getRango();
           rango2 = moviendo->nodo->carta->getRango();

            if(rango1=="0")
               rmov=10;
            if(rango1=="J")
                rmov=11;
            if(rango1=="Q")
                rmov=12;
            if(rango1=="K")
                rmov=13;

           rult=ultimo->carta->getRango().toInt();

           if(rango2=="0")
              rult=10;
           if(rango2=="J")
               rult=11;
           if(rango2=="Q")
               rult=12;
           if(rango2=="K")
               rult=13;

           if(ultimo->carta->getColor() != moviendo->nodo->carta->getColor()
                   &&  rmov == rult-1)
           {
               cout<<"Si Pasa"<<endl;
               tirar=true;
               cout<<"RMOV: "<<rmov<<"RULT: "<<rult;
           }
           else
           {
               cout<<"No Pasa"<<endl;
               cout<<"RMOV: "<<rmov<<"RULT: "<<rult;
           }

        }

        if(newIcon->pos().rx()>455 && newIcon->pos().rx() <465)
        {
           Nodo *ultimo= cinco->recuperar(cinco->cont-1);

           rmov=moviendo->nodo->carta->getRango().toInt();

           rango1 = ultimo->carta->getRango();
           rango2 = moviendo->nodo->carta->getRango();

           if(rango1=="0")
              rmov=10;
           if(rango1=="J")
               rmov=11;
           if(rango1=="Q")
               rmov=12;
           if(rango1=="K")
               rmov=13;

           rult=ultimo->carta->getRango().toInt();

           if(rango2=="0")
              rult=10;
           if(rango2=="J")
               rult=11;
           if(rango2=="Q")
               rult=12;
           if(rango2=="K")
               rult=13;

           if(ultimo->carta->getColor() != moviendo->nodo->carta->getColor()
                   &&  rmov == rult-1)
           {
               cout<<"Si Pasa"<<endl;
               tirar=true;
               cout<<"RMOV: "<<rmov<<"RULT: "<<rult;
           }
           else
           {
               cout<<"No Pasa"<<endl;
               cout<<"RMOV: "<<rmov<<"RULT: "<<rult;
           }

        }

        if(newIcon->pos().rx()>565 && newIcon->pos().rx() <575)
        {
           Nodo *ultimo= seis->recuperar(seis->cont-1);

           rmov=moviendo->nodo->carta->getRango().toInt();

           rango1 = ultimo->carta->getRango();
           rango2 = moviendo->nodo->carta->getRango();

           if(rango1=="0")
              rmov=10;
           if(rango1=="J")
               rmov=11;
           if(rango1=="Q")
               rmov=12;
           if(rango1=="K")
               rmov=13;

           rult=ultimo->carta->getRango().toInt();

           if(rango2=="0")
              rult=10;
           if(rango2=="J")
               rult=11;
           if(rango2=="Q")
               rult=12;
           if(rango2=="K")
               rult=13;

           if(ultimo->carta->getColor() != moviendo->nodo->carta->getColor()
                   &&  rmov== rult-1)
           {
               cout<<"Si Pasa"<<endl;
               tirar=true;
               cout<<"RMOV: "<<rmov<<"RULT: "<<rult;
           }
           else
           {
               cout<<"No Pasa"<<endl;
               cout<<"RMOV: "<<rmov<<"RULT: "<<rult;
           }

        }

        if(newIcon->pos().rx()>675 && newIcon->pos().rx() <685)
        {
           Nodo *ultimo= siete->recuperar(siete->cont-1);

           rmov=moviendo->nodo->carta->getRango().toInt();

           rango1 = ultimo->carta->getRango();
           rango2 = moviendo->nodo->carta->getRango();

           if(rango1=="0")
              rmov=10;
           if(rango1=="J")
               rmov=11;
           if(rango1=="Q")
               rmov=12;
           if(rango1=="K")
               rmov=13;

           rult=ultimo->carta->getRango().toInt();

           if(rango2=="0")
              rult=10;
           if(rango2=="J")
               rult=11;
           if(rango2=="Q")
               rult=12;
           if(rango2=="K")
               rult=13;

           if(ultimo->carta->getColor() != moviendo->nodo->carta->getColor()
                   &&  rmov == rult-1)
           {
               cout<<"Si Pasa"<<endl;
               tirar=true;
               cout<<"RMOV: "<<rmov<<"RULT: "<<rult;
           }
           else
           {
               cout<<"No Pasa"<<endl;
               cout<<"RMOV: "<<rmov<<"RULT: "<<rult;
           }

        }

        if (event->source() == this && tirar) {
            event->setDropAction(Qt::MoveAction);
            event->accept();

            cout<<newIcon->nodo->carta->getColor().toStdString()<<endl;
            cout<<newIcon->nodo->carta->getPalo().toStdString()<<endl;

            cout<< newIcon->pos().rx()<<"HE SIDO ARROJADO"<<endl;
            newIcon->show();

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

    moviendo=new Label(this);
    moviendo->nodo=child->nodo;
    moviendo->pertenece=child->pertenece;

   //cout<<moviendo->nodo->carta->getColor().toStdString();


   cout<<"\n"<<event->pos().rx()<<" "<<event->pos().ry()<<endl;

    if (!child)
     return;

    QPixmap pixmap = *child->pixmap();


    QByteArray itemData;

    QDataStream dataStream(&itemData, QIODevice::WriteOnly);

    dataStream << pixmap << QPoint(event->pos() - child->pos());

    QMimeData * mimeData = new QMimeData;
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
