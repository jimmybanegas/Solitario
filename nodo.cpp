#include "nodo.h"

Nodo::Nodo(QString rango, char color, char palo)
{
    this->carta =  new Carta(rango,color,palo);
    this->siguiente=NULL;
}

Nodo::Nodo()
{

}
