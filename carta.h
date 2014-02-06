#ifndef CARTA_H
#define CARTA_H
#include <iostream>
#include <qstring.h>
using namespace std;

class Carta
{
private:
    QString rango;
    QString color;
    QString palo;
    bool usada;
public:
    bool caraAbajo;
    QString getRango();
    QString getColor();
    QString getPalo();
    bool isCaraAbajo();
    bool isUsada();
    QString nombre();
    Carta(char rango, char color, char palo);
};

#endif // CARTA_H
