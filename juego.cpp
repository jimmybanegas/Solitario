#include "juego.h"



void Juego::distribuir()
{
    this->mazo.generarCartas();

    int random;

    srand (time(NULL));

     /* generate secret number between 1 and 10: */

   for(int i=0;i<1;i++)
   {
    random = rand() % (mazo.cont);
    Nodo *sel=mazo.recuperar(random);
    mazo.eliminar(random);
    uno.insertar(i,sel);
   }

   for(int i=0;i<2;i++)
   {
    random = rand() % (mazo.cont);
    Nodo *sel=mazo.recuperar(random);
    mazo.eliminar(random);

    if(i==1)
        sel->carta->caraAbajo=false;

    dos.insertar(i,sel);
   }

   for(int i=0;i<3;i++)
   {
    random = rand() % (mazo.cont);
    Nodo *sel=mazo.recuperar(random);
    mazo.eliminar(random);

    if(i==2)
         sel->carta->caraAbajo=false;

    tres.insertar(i,sel);
   }

   for(int i=0;i<4;i++)
   {
    random = rand() % (mazo.cont);
    Nodo *sel=mazo.recuperar(random);
    mazo.eliminar(random);

    if(i==3)
         sel->carta->caraAbajo=false;

    cuatro.insertar(i,sel);
   }

   for(int i=0;i<5;i++)
   {
    random = rand() % (mazo.cont);
    Nodo *sel=mazo.recuperar(random);
    mazo.eliminar(random);

    if(i==4)
         sel->carta->caraAbajo=false;

    cinco.insertar(i,sel);
   }

   for(int i=0;i<6;i++)
   {
    random = rand() % (mazo.cont);
    Nodo *sel=mazo.recuperar(random);
    mazo.eliminar(random);

    if(i==5)
         sel->carta->caraAbajo=false;

    seis.insertar(i,sel);
   }

   for(int i=0;i<7;i++)
   {
    random = rand() % (mazo.cont);
    Nodo *sel=mazo.recuperar(random);
    mazo.eliminar(random);

    if(i==6)
         sel->carta->caraAbajo=false;

    siete.insertar(i,sel);
   }

   cout<<mazo.cont<<endl;


}

Juego::Juego()
{

}
