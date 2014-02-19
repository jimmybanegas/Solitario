#include "carta.h"

QString Carta::getRango()
{
    return this->rango;
}

QString Carta::getColor()
{
    return this->color;
}

QString Carta::getPalo()
{
    return this->palo;
}

bool Carta::isCaraAbajo()
{
    return caraAbajo;
}

bool Carta::isUsada()
{
    return usada;
}

QString Carta::nombre()
{
    QString nombre=this->palo+""+rango;
    return nombre;
}

QPixmap Carta::getImagen()
{
    return imagen;
}

void Carta::setPixmap(QPixmap imagen)
{
   this->imagen=imagen;
}

Carta::Carta(QString rango, char color, char palo)
{
    this->rango=rango;
    this->color=color;
    this->palo=palo;
    this->caraAbajo=true;
    this->usada=false;
}

