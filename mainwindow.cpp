#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QLayoutItem>

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);

}


void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
  event->accept();
}

void MainWindow::dragLeaveEvent(QDragLeaveEvent *event)
{
   event->accept();
}

void MainWindow::dragMoveEvent(QDragMoveEvent *event)
{
    event->accept();
}

void MainWindow::dropEvent(QDropEvent *event)
{
  event->accept();
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
 event->accept();
}

void MainWindow::crearCartasVisuales(MazoPrincipal mazo, int x ){

//int y=190;
   for(int i=0; i<mazo.cont; i++){

    QString path = ":/images/cards/"+mazo.recuperar(i)->carta->nombre()+".png";
   // QPushButton* button = new QPushButton;
     QLabel *labe = new QLabel;
   // button->setGeometry(QRect(x, y, 99, 135));

      labe->setStyleSheet("background-image: url("+path+");");
 //   button->setIcon(QIcon(path));
      ui->verticalLayout->addWidget(labe);

      labe->show();

  }

}

void MainWindow::crearCartasVisuales2(MazoPrincipal mazo, int x ){

//int y=190;
   for(int i=0; i<mazo.cont; i++){

    QString path = ":/images/cards/"+mazo.recuperar(i)->carta->nombre()+".png";
     QLabel *labe = new QLabel;
      labe->setStyleSheet("background-image: url("+path+");");
      ui->verticalLayout_2->addWidget(labe);
     labe->show();
  }
}
void MainWindow::crearCartasVisuales3(MazoPrincipal mazo, int x ){

//int y=190;
   for(int i=0; i<mazo.cont; i++){

    QString path = ":/images/cards/"+mazo.recuperar(i)->carta->nombre()+".png";
     QLabel *labe = new QLabel;
      labe->setStyleSheet("background-image: url("+path+");");
      ui->verticalLayout_3->addWidget(labe);
     labe->show();
  }
}
void MainWindow::crearCartasVisuales4(MazoPrincipal mazo, int x ){

//int y=190;
   for(int i=0; i<mazo.cont; i++){

    QString path = ":/images/cards/"+mazo.recuperar(i)->carta->nombre()+".png";
     QLabel *labe = new QLabel;
      labe->setStyleSheet("background-image: url("+path+");");
      ui->verticalLayout_4->addWidget(labe);
     labe->show();
  }
}
void MainWindow::crearCartasVisuales5(MazoPrincipal mazo, int x ){

//int y=190;
   for(int i=0; i<mazo.cont; i++){

    QString path = ":/images/cards/"+mazo.recuperar(i)->carta->nombre()+".png";
     QLabel *labe = new QLabel;
      labe->setStyleSheet("background-image: url("+path+");");
      ui->verticalLayout_5->addWidget(labe);
     labe->show();
  }
}
void MainWindow::crearCartasVisuales6(MazoPrincipal mazo, int x ){

//int y=190;
   for(int i=0; i<mazo.cont; i++){

    QString path = ":/images/cards/"+mazo.recuperar(i)->carta->nombre()+".png";
     QLabel *labe = new QLabel;
      labe->setStyleSheet("background-image: url("+path+");");
      ui->verticalLayout_6->addWidget(labe);
     labe->show();
  }
}
void MainWindow::crearCartasVisuales7(MazoPrincipal mazo, int x ){

//int y=190;
   for(int i=0; i<mazo.cont; i++){

    QString path = ":/images/cards/"+mazo.recuperar(i)->carta->nombre()+".png";
     QLabel *labe = new QLabel;
      labe->setStyleSheet("background-image: url("+path+");");
      ui->verticalLayout_7->addWidget(labe);
     labe->show();
   }
}

void MainWindow::barajear(MazoPrincipal mazo)
{
    int random;
    srand (time(NULL));

    for(int i=0; i<3; i++){
          random = rand() % (mazo.cont);
          QString path = ":/images/cards/"+mazo.recuperar(i)->carta->nombre()+".png";
          QLabel *labe = new QLabel;
          labe->setStyleSheet("background-image: url("+path+");");
          ui->horizontalLayout->addWidget(labe);
          labe->show();
     }
}

void MainWindow::setMazo(MazoPrincipal mazo)
{
    this->mazo=mazo;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//    if ( ui->horizontalLayout!= NULL )
 //   {

       // delete ui->horizontalLayout;
  //  }

    QLayoutItem* child;
    while ((child = ui->horizontalLayout->takeAt(0)) != 0)
    {
        if (child->widget() != NULL)
        {
            delete (child->widget());
        }
        delete child;
    }

        cout<<"has dado click"<<endl;
        this->barajear(this->mazo);


}
