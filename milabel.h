#ifndef MILABEL_H
#define MILABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
#include <iostream>

using namespace  std;

class miLabel : public QLabel
{
    Q_OBJECT
public:
    explicit miLabel(QWidget *parent = 0);
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void leaveEvent(QMouseEvent *ev);

    int x,y;

signals:

public slots:
   /* void Mouse_Pressed();
    void Mouse_Pos();
    void Mouse_Left();*/

};

#endif // MILABEL_H
