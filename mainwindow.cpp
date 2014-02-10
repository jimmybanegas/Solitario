#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QLabel>
#include <QPixmap>
#include "milabel.h"

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
}

void MainWindow::crearCartasVisuales(MazoPrincipal mazo, int x ,int y, int crecer){

   for(int i=0; i<mazo.cont; i++){
    QPixmap actual =  QPixmap(":/images/cards/Back.png");
    if(!mazo.recuperar(i)->carta->isCaraAbajo())
    {
     actual = mazo.recuperar(i)->carta->getImagen();
    }

    miLabel *a = new miLabel(this);
    a->setPixmap(actual);
    a->setGeometry(x,y,99,135);
    a->setAcceptDrops(true);
    a->raise();
    a->show();
    y+=crecer;
  }
}

void MainWindow::barajear(MazoPrincipal mazo)
{
 /* int random;
    srand (time(NULL));

    for(int i=0; i<3; i++){
          random = rand() % (mazo.cont);
          QString path = ":/images/cards/"+mazo.recuperar(i)->carta->nombre()+".png";
          QLabel *labe = new QLabel;
          labe->setStyleSheet("background-image: url("+path+");");
          ui->horizontalLayout->addWidget(labe);
          labe->show();
     }*/
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

   /* QLayoutItem* child;
    while ((child = ui->horizontalLayout->takeAt(0)) != 0)
    {
        if (child->widget() != NULL)
        {
            delete (child->widget());
        }
        delete child;
    }

        cout<<"has dado click"<<endl;
        this->barajear(this->mazo);*/


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

        miLabel *newIcon = new miLabel(this);
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
    miLabel *child = static_cast<miLabel*>(childAt(event->pos()));
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
