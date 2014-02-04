#include "nodo.h"

Nodo::Nodo(char rango, char color, char palo)
{
    this->carta =  new Carta(rango,color,palo);
    this->siguiente=NULL;
}
