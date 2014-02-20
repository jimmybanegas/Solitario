#include "milabel.h"

miLabel::miLabel(QWidget *parent) :
    QLabel(parent)
{
   // this->acceptDrops(true);
  //  this->move
}

void miLabel::mouseMoveEvent(QMouseEvent *ev)
{

}

void miLabel::mousePressEvent(QMouseEvent *ev)
{
    emit Mouse_Pressed();
}

void miLabel::leaveEvent(QMouseEvent *ev)
{
   cout<<"Mouse deja el evento"<<endl;
}


