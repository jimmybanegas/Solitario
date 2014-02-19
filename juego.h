#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include "carta.h"
#include "mazoprincipal.h"
#include "mazoordenado.h"
#include "mazomovimientos.h"
#include <stdlib.h>
#include <time.h>
#include "label.h"
#include "milabel.h"
using namespace std;

class Juego
{
public:
    MazoPrincipal mazo;

    MazoPrincipal barajear;

    MazoOrdenado ord1;
    MazoOrdenado ord2;
    MazoOrdenado ord3;
    MazoOrdenado ord4;

    MazoMovimientos uno;
    MazoMovimientos dos;
    MazoMovimientos tres;
    MazoMovimientos cuatro;
    MazoMovimientos cinco;
    MazoMovimientos seis;
    MazoMovimientos siete;

    void distribuir();
    void crearCartasVisuales(MazoPrincipal mazox, int x, int y, int crecer,int crecerx);

    Juego();
};

#endif // JUEGO_H
