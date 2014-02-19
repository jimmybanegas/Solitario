#ifndef MILABEL_H
#define MILABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
#include <iostream>
#include "nodo.h"
#include "mazoprincipal.h"

using namespace  std;

class miLabel : public QLabel
{
    Q_OBJECT
public:
    Nodo *nodo;
    MazoPrincipal *pertenece;
    explicit miLabel(QWidget *parent = 0);
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void leaveEvent(QMouseEvent *ev);

    int x,y;

signals:
     void Mouse_Pressed();

public slots:


};

#endif // MILABEL_H
