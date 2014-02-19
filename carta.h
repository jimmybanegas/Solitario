#ifndef CARTA_H
#define CARTA_H
#include <iostream>
#include <qstring.h>
#include <QPixmap>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneMouseEvent>

using namespace std;

class Carta
{
private:
    QString rango;
    QString color;
    QString palo;
    bool usada;
    QPixmap imagen;
public:
    bool caraAbajo;
    QString getRango();
    QString getColor();
    QString getPalo();
    bool isCaraAbajo();
    bool isUsada();
    QString nombre();
    QPixmap getImagen();
    void setPixmap(QPixmap imagen);
    Carta(QString rango, char color, char palo);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void cancelCardMove();

    QPainterPath shape() const;
    QRectF boundingRect() const;

    void paint(QPainter *painter,  const QStyleOptionGraphicsItem *option,
            QWidget *widget = 0);

};

#endif // CARTA_H
