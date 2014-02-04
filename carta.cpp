#include "carta.h"

char Carta::getRango()
{
    return this->rango;
}

char Carta::getColor()
{
    return this->color;
}

char Carta::getPalo()
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

Carta::Carta(char rango, char color, char palo)
{
    this->rango=rango;
    this->color=color;
    this->palo=palo;
    this->caraAbajo=true;
    this->usada=false;
}

