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

void MainWindow::crearCartasVisualesB(MazoPrincipal *mazox, int x ,int y, int crecery, int crecerx){

    for(int i=0; i<mazox->cont; i++){
       QPixmap actual =  QPixmap(":/images/cards/Back.png");

       if(i==mazox->cont-1)
       {
        actual = mazox->recuperar(i)->carta->getImagen();
       }

    cout<<"REPINTANDO"<<endl;

    Label *a = new Label(this);
    a->nodo =mazox->recuperar(i);
    a->pertenece=mazox;
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
    //Label *a = new Label(this);
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
                         MazoPrincipal *siete, MazoPrincipal *ord1, MazoPrincipal *ord2, MazoPrincipal *ord3,
                         MazoPrincipal *ord4)
{
    this->mazo=mazo;
    this->uno=uno;
    this->dos=dos;
    this->tres=tres;
    this->cuatro=cuatro;
    this->cinco=cinco;
    this->seis=seis;
    this->siete=siete;
    this->ord1=ord1;
    this->ord2=ord2;
    this->ord3=ord3;
    this->ord4=ord4;
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

        newIcon->setAttribute(Qt::WA_DeleteOnClose);

        bool tirar = false;
        int rmov;
        int rult;
        QString rango1;
        QString rango2;

        newIcon->nodo=moviendo->nodo;

            int x1=uno->cont;
            int x2=dos->cont;
            int x3=tres->cont;
            int x4=cuatro->cont;
            int x5=cinco->cont;
            int x6=seis->cont;
            int x7=siete->cont;

        if(newIcon->pos().rx()>15 && newIcon->pos().rx() <25 && uno->cont >= 1)
        {
            Nodo *ultimo = uno->recuperar(x1-1);

            if(ultimo==NULL)
                     return;

           rmov=moviendo->nodo->carta->getRango().toInt();
           newIcon->pertenece=uno;

           rango1 = ultimo->carta->getRango();
           rango2 = moviendo->nodo->carta->getRango();

           if(rango1=="J")
               rmov=11;
           if(rango1=="Q")
               rmov=12;
           if(rango1=="K")
               rmov=13;

           rult=ultimo->carta->getRango().toInt();

           if(rango2=="J")
               rult=11;
           if(rango2=="Q")
               rult=12;
           if(rango2=="K")
               rult=13;

           if(ultimo->carta->getColor() != moviendo->nodo->carta->getColor()
                   &&  rmov == rult-1 || (rmov==13) && (rult==0))
           {
               tirar=true;
           }
        }

        if(newIcon->pos().rx()>125 && newIcon->pos().rx() <135 && dos->cont >= 1)
        {
           Nodo *ultimo = dos->recuperar(x2-1);

                if(ultimo==NULL)
                    return;

           rmov=moviendo->nodo->carta->getRango().toInt();
           newIcon->pertenece=dos;

           rango1 = ultimo->carta->getRango();
           rango2 = moviendo->nodo->carta->getRango();

           if(rango1=="J")
               rmov=11;
            if(rango1=="Q")
               rmov=12;
           if(rango1=="K")
               rmov=13;

            rult=ultimo->carta->getRango().toInt();

            if(rango2=="J")
                rult=11;
             if(rango2=="Q")
                rult=12;
            if(rango2=="K")
                rult=13;

           if(ultimo->carta->getColor() != moviendo->nodo->carta->getColor()
                   &&  rmov == rult-1 || (rmov==13) && (rult==0))
           {
               tirar=true;
           }
        }

        if(newIcon->pos().rx()>235 && newIcon->pos().rx() <245 && tres->cont >= 1)
        {
            Nodo *ultimo = tres->recuperar(x3-1);

            if(ultimo==NULL)
                     return;

           rmov=moviendo->nodo->carta->getRango().toInt();
           newIcon->pertenece=tres;

           rango1 = ultimo->carta->getRango();
           rango2 = moviendo->nodo->carta->getRango();

           if(rango1=="J")
               rmov=11;
           if(rango1=="Q")
               rmov=12;
           if(rango1=="K")
               rmov=13;

           rult=ultimo->carta->getRango().toInt();

           if(rango2=="J")
               rult=11;
           if(rango2=="Q")
               rult=12;
           if(rango2=="K")
               rult=13;

           if((ultimo->carta->getColor() != moviendo->nodo->carta->getColor()
                   &&  rmov == rult-1) || (rmov==13) && (rult==0))
           {
               tirar=true;
           }
        }

        if(newIcon->pos().rx()>345 && newIcon->pos().rx() <355 && cuatro->cont >= 1)
        {
            Nodo *ultimo = cuatro->recuperar(x4-1);
                 if(ultimo==NULL)
                     return;

           rmov=moviendo->nodo->carta->getRango().toInt();
           newIcon->pertenece=cuatro;

           rango1 = ultimo->carta->getRango();
           rango2 = moviendo->nodo->carta->getRango();

            if(rango1=="J")
                rmov=11;
            if(rango1=="Q")
                rmov=12;
            if(rango1=="K")
                rmov=13;

           rult=ultimo->carta->getRango().toInt();

           if(rango2=="J")
               rult=11;
           if(rango2=="Q")
               rult=12;
           if(rango2=="K")
               rult=13;

           if(ultimo->carta->getColor() != moviendo->nodo->carta->getColor()
                   &&  (rmov == rult-1)  || (rmov==13) && (rult==0) )
           {
               tirar=true;
           }
        }

        if(newIcon->pos().rx()>455 && newIcon->pos().rx() <465 && cinco->cont >=1)
        {
            Nodo *ultimo = cinco->recuperar(x5-1);
                if(ultimo==NULL)
                    return;

           newIcon->pertenece=cinco;

           rmov=moviendo->nodo->carta->getRango().toInt();

           rango1 = ultimo->carta->getRango();
           rango2 = moviendo->nodo->carta->getRango();

           if(rango1=="J")
               rmov=11;
           if(rango1=="Q")
               rmov=12;
           if(rango1=="K")
               rmov=13;

           rult=ultimo->carta->getRango().toInt();

           if(rango2=="J")
               rult=11;
           if(rango2=="Q")
               rult=12;
           if(rango2=="K")
               rult=13;

           if((ultimo->carta->getColor() != moviendo->nodo->carta->getColor()
                   &&  rmov == rult-1) || (rmov==13) && (rult==0))
           {
               tirar=true;
           }
        }

        if(newIcon->pos().rx()>565 && newIcon->pos().rx() <575 && seis->cont >=1)
        {
            Nodo *ultimo = seis->recuperar(x6-1);

            if(ultimo==NULL)
                     return;


           newIcon->pertenece=seis;

           rmov=moviendo->nodo->carta->getRango().toInt();

           rango1 = ultimo->carta->getRango();
           rango2 = moviendo->nodo->carta->getRango();

           if(rango1=="J")
               rmov=11;
           if(rango1=="Q")
               rmov=12;
           if(rango1=="K")
               rmov=13;

           rult=ultimo->carta->getRango().toInt();

           if(rango2=="J")
               rult=11;
           if(rango2=="Q")
               rult=12;
           if(rango2=="K")
               rult=13;

           if((ultimo->carta->getColor() != moviendo->nodo->carta->getColor()
                   &&  rmov== rult-1) || (rmov==13) && (rult==0))
           {
                 tirar=true;
           }

        }

        if(newIcon->pos().rx()>675 && newIcon->pos().rx() <685 && siete->cont >=1)
        {
            Nodo *ultimo= siete->recuperar(x7-1);
                 if(ultimo==NULL)
                     return;

           newIcon->pertenece=siete;

           rmov=moviendo->nodo->carta->getRango().toInt();

           rango1 = ultimo->carta->getRango();
           rango2 = moviendo->nodo->carta->getRango();

           if(rango1=="J")
               rmov=11;
           if(rango1=="Q")
               rmov=12;
           if(rango1=="K")
               rmov=13;

           rult=ultimo->carta->getRango().toInt();

           if(rango2=="J")
               rult=11;
           if(rango2=="Q")
               rult=12;
           if(rango2=="K")
               rult=13;

           if((ultimo->carta->getColor() != moviendo->nodo->carta->getColor()
                   &&  rmov == rult-1) || (rmov==13) && (rult==0))
           {
              tirar=true;
           }
        }

        if(newIcon->pos().rx()>350 && newIcon->pos().rx() <360 && newIcon->pos().ry() > 35 && newIcon->pos().ry() < 45)
        {
          if(ord1->cont==0 && newIcon->nodo->carta->getRango()=="A")
          {
             tirar=true;
          }
          else
          {
              Nodo *ultimo = ord1->recuperar((ord1->cont)-1);

              if(ultimo==NULL)
                    return;

              newIcon->pertenece=ord1;

              rmov=moviendo->nodo->carta->getRango().toInt();

              rango1 = ultimo->carta->getRango();
              rango2 = moviendo->nodo->carta->getRango();

              if(rango1=="J")
                  rmov=11;
              if(rango1=="Q")
                  rmov=12;
              if(rango1=="K")
                  rmov=13;

              rult=ultimo->carta->getRango().toInt();

              if(rango2=="J")
                  rult=11;
              if(rango2=="Q")
                  rult=12;
              if(rango2=="K")
                  rult=13;

              if(ultimo->carta->getColor() == moviendo->nodo->carta->getColor()
                      &&  rmov == rult+1)
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
        }

        if(newIcon->pos().rx()>460 && newIcon->pos().rx() <470 && newIcon->pos().ry() > 35 && newIcon->pos().ry() < 45)
        {
          if(ord2->cont==0 &&  moviendo->nodo->carta->getRango()=="A")
          {
             tirar=true;
          }
          else
          {
             cout<<moviendo->nodo->carta->getRango().toStdString()<<endl;

              Nodo *ultimo= ord2->recuperar((ord1->cont)-1);
              newIcon->pertenece=ord2;

              rmov=moviendo->nodo->carta->getRango().toInt();

              rango1 = ultimo->carta->getRango();
              rango2 = moviendo->nodo->carta->getRango();

              if(rango1=="J")
                  rmov=11;
              if(rango1=="Q")
                  rmov=12;
              if(rango1=="K")
                  rmov=13;

              rult=ultimo->carta->getRango().toInt();

              if(rango2=="J")
                  rult=11;
              if(rango2=="Q")
                  rult=12;
              if(rango2=="K")
                  rult=13;

              if(ultimo->carta->getColor() == moviendo->nodo->carta->getColor()
                      &&  rmov == rult+1)
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
        }

        if(newIcon->pos().rx()>570 && newIcon->pos().rx() <580 && newIcon->pos().ry() > 35 && newIcon->pos().ry() < 45)
        {
          if(ord3->cont==0 && newIcon->nodo->carta->getRango()=="A")
          {
             tirar=true;
          }
          else
          {
              Nodo *ultimo= ord3->recuperar((ord3->cont)-1);
              newIcon->pertenece=ord3;

              rmov=moviendo->nodo->carta->getRango().toInt();

              rango1 = ultimo->carta->getRango();
              rango2 = moviendo->nodo->carta->getRango();

              if(rango1=="J")
                  rmov=11;
              if(rango1=="Q")
                  rmov=12;
              if(rango1=="K")
                  rmov=13;

              rult=ultimo->carta->getRango().toInt();

              if(rango2=="J")
                  rult=11;
              if(rango2=="Q")
                  rult=12;
              if(rango2=="K")
                  rult=13;

              if(ultimo->carta->getColor() == moviendo->nodo->carta->getColor()
                      &&  rmov == rult+1)
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
        }

        if(newIcon->pos().rx()>680 && newIcon->pos().rx() <690 && newIcon->pos().ry() > 35 && newIcon->pos().ry() < 45)
        {
          if(ord4->cont==0 && newIcon->nodo->carta->getRango()=="A")
          {
             tirar=true;
          }
          else
          {
              Nodo *ultimo= ord4->recuperar((ord4->cont)-1);
              newIcon->pertenece=ord4;

              rmov=moviendo->nodo->carta->getRango().toInt();

              rango1 = ultimo->carta->getRango();
              rango2 = moviendo->nodo->carta->getRango();

              if(rango1=="J")
                  rmov=11;
              if(rango1=="Q")
                  rmov=12;
              if(rango1=="K")
                  rmov=13;

              rult=ultimo->carta->getRango().toInt();

              if(rango2=="J")
                  rult=11;
              if(rango2=="Q")
                  rult=12;
              if(rango2=="K")
                  rult=13;

              if(ultimo->carta->getColor() == moviendo->nodo->carta->getColor()
                      &&  rmov == rult+1)
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
        }

        if (event->source() == this && tirar) {
            event->setDropAction(Qt::MoveAction);
            event->accept();

            cout<<newIcon->nodo->carta->getColor().toStdString()<<endl;
            cout<<newIcon->nodo->carta->getPalo().toStdString()<<endl;

           cout<<"ANTES: mov"<<moviendo->pertenece->cont<<" "<<newIcon->pertenece->cont<<endl;

           moviendo->pertenece->eliminar(moviendo->pertenece->cont-1);
           newIcon->pertenece->insertar(newIcon->pertenece->cont,newIcon->nodo);

            if(moviendo->pertenece!=mazo)
            {
                 crearCartasVisualesB(moviendo->pertenece,redi,190,15,0);
            }

            cout<< newIcon->pos().rx()<<"  HE SIDO ARROJADO"<<endl;
            cout<<"DESPUES: mov"<<moviendo->pertenece->cont<<" "<<newIcon->pertenece->cont<<endl;
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

     redi=event->pos().rx();

     if(redi>=20 && redi<=119)
         redi=20;
     if(redi>=130 && redi<=229)
         redi=130;
     if(redi>=240 && redi<=339)
         redi=240;
     if(redi>=350 && redi<=449)
         redi=350;
     if(redi>=460 && redi<=559)
         redi=460;
     if(redi>=570 && redi<=669)
         redi=570;
     if(redi>=680 && redi<=779)
         redi=680;

    cout<<"LA POS EN X: "<<redi;

    moviendo=new Label(this);
    moviendo->nodo=child->nodo;
    moviendo->pertenece=child->pertenece;

    if (!child)
     return;

    if (child==centralWidget() )
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

      if(sel==NULL)
      {
          mazo->recuperar(0);
          return;
      }

          QPixmap actual=sel->carta->getImagen();
          Label *a = new Label(this);
          a->setPixmap(actual);
          a->nodo=sel;
          a->pertenece=mazo;
          a->setGeometry(130,41,99,135);
          a->show();

          cout<<"La has barajeado"<<endl;
}
