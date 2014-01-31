#include "carta.h"

int Carta::getNumero()
{
    return this->numero;
}

string Carta::getColor()
{
    return this->color;
}

string Carta::getPalo()
{
    return this->getPalo();
}

Carta::Carta(int numero, string color, string palo)
{
    this->numero=numero;
    this->color=color;
    this->palo=palo;
}

