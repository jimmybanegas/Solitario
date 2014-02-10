#ifndef ELEMENTOSGRAFICOS_H
#define ELEMENTOSGRAFICOS_H

#include <QGraphicsItem>
#include <QTimer>

class ElementosGraficos : public QGraphicsItem
{
//Para controlar las posiciones de los elemntos graficos
float x,y,vx,vy,acx,acy;
int ancho, alto, anchoPadre, altoPadre;
QPixmap *imagen;
QGraphicsScene *padreEscena;

public:
    ElementosGraficos();
    ElementosGraficos(QGraphicsItem *parent=0);
    ElementosGraficos(QPixmap *imagen,QGraphicsScene *escenaPadre,QGraphicsItem *parent=0);
    void setVelocidad(float velx, float vely, float aclx, float acly);
    void pintar(QPainter *painter,const QStyleOptionGraphicsItem *item,QWidget *widget);
   //Devuelve el rectangulo en el que está metido nuestro widget, su posicion
    QRectF boundingRect() const;
    QPainterPath shape() const;
    //Encargarda de mover los objetos
    void nuevaPosicion(float tiempo);
};

#endif // ELEMENTOSGRAFICOS_H
