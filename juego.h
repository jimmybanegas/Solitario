#ifndef JUEGO_H
#define JUEGO_H
#include "carta.h"
#include "mazoprincipal.h"
#include "mazoordenado.h"
#include "mazomovimientos.h"

class Juego
{
public:
    MazoPrincipal mazo;

    MazoOrdenado diamante;
    MazoOrdenado trebol;
    MazoOrdenado corazon;
    MazoOrdenado espada;

    MazoMovimientos uno;
    MazoMovimientos dos;
    MazoMovimientos tres;
    MazoMovimientos cuatro;
    MazoMovimientos cinco;
    MazoMovimientos seis;
    MazoMovimientos siete;


    void distribuir();
    void barajear();

    Juego();
};

#endif // JUEGO_H
