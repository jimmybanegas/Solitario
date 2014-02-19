#ifndef NODO_H
#define NODO_H
#include "carta.h"

class Nodo
{
public:
    Carta *carta;
    Nodo *siguiente;
    Nodo(QString rango, char color, char palo);
    Nodo();
};

#endif // NODO_H
