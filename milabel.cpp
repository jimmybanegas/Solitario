#include "milabel.h"

miLabel::miLabel(QWidget *parent) :
    QLabel(parent)
{
   // this->acceptDrops(true);
  //  this->move
}

void miLabel::mouseMoveEvent(QMouseEvent *ev)
{
    this->x=ev->x();
    this->y=ev->y();

    cout<<"Posicion: "<<x<<" "<<y<<endl;
}

void miLabel::mousePressEvent(QMouseEvent *ev)
{
    cout<<"Mouse presionado"<<endl;
}

void miLabel::leaveEvent(QMouseEvent *ev)
{
   cout<<"Mouse deja el evento"<<endl;
}


