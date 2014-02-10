#include "elementosgraficos.h"
#include <QtWidgets>

ElementosGraficos::ElementosGraficos(QGraphicsItem *parent):QGraphicsItem(parent)
{
    x=0;
    y=0;
    ancho=0;
    alto=0;
    imagen=NULL;
}

/*ElementosGraficos::ElementosGraficos(QPixmap *imagen,QGraphicsScene *escenaPadre, QGraphicsItem *parent)
:QGraphicsItem(parent,escenaPadre)
{
    x=0;
    y=0;
    ancho=imagen->width();
    alto=imagen->height();
    anchoPadre=escenaPadre->width();
    altoPadre=escenaPadre->height();
    imagen=imagen;
    padreEscena=escenaPadre;
}
void ElementosGraficos::pintar(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(imagen)
    {
        painter->drawPixmap(x,y,ancho,alto,*imagen);
    }
}

QRectF ElementosGraficos::boundingRect()const
{
    return QRectF(x,y,ancho,alto);
}

QPainterPath ElementosGraficos::shape() const
{
    QPainterPath path;

    path.addRect(x,y,ancho,alto);
    return path;
}

void ElementosGraficos::setVelocidad(float velx, float vely, float aclx, float acly)
{
    this->vx=velx;
    this->vy=vely;
    this->acx=aclx;
    this->acy=acly;
}

void ElementosGraficos::nuevaPosicion(float tiempo)
{
    x=x+vx*tiempo;
    y=y+vy*tiempo;
    vx=vx+acx*tiempo;
    vy=vy+acy*tiempo;
    //No queremos que el objeto se salga de la pantalla
    if(x<0 || x>anchoPadre-ancho)
    {
        vx=-vx;
        x=x+vx*tiempo;
    }
    if(y<0 || y>altoPadre-alto)
    {
        vy=-vy;
        y=y+vy*tiempo;
    }
}
*/
