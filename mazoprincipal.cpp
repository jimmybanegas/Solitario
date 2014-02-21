#include "mazoprincipal.h"

void MazoPrincipal::generarCartas()
{
    QString rangos[] = {"1","2","3","4","5","6","7","8","9","10","J","Q","K"};

    for(int i=0;i<13;i++)
    {
        Nodo *d=new Nodo(rangos[i],'R','D');
        insertar(i,d);
    }
    for(int i=0;i<13;i++)
    {
        Nodo *t=new Nodo(rangos[i],'N','T');
        insertar(i+13,t);
    }
    for(int i=0;i<13;i++)
    {
        Nodo *e = new Nodo(rangos[i],'N','E');
        insertar(i+26,e);
    }
    for(int i=0;i<13;i++)
    {
        Nodo *c = new Nodo(rangos[i],'R','C');
        insertar(i+39,c);
    }
}



bool MazoPrincipal::insertar(int pos, Nodo *nodo)
{
    if(pos<0  || pos>cont )
            return false;

        if(pos==0)
        {
           Nodo *tem=inicio;
           nodo->siguiente=tem;
           inicio=nodo;
        }
        else
        {
           int i=0;
            Nodo *tem=inicio;
            while(i!=pos-1){
                tem=tem->siguiente;
                i++;
            }
            nodo->siguiente=tem->siguiente;
            tem->siguiente=nodo;
        }
        cont++;
        return true;
}

Nodo *MazoPrincipal::fin()
{
    return recuperar(cont-1);
}

Nodo *MazoPrincipal::siguiente(int pos)
{
    if(pos>=cont-1 || pos<0)
         return NULL;

    return recuperar(pos)->siguiente;
}

Nodo *MazoPrincipal::recuperar(int pos)
{
    if(pos>=cont || pos<0)
           return NULL;

    Nodo *tem=inicio;

    for(int i=0;i<pos;i++){
        if(tem==NULL)
            return NULL;

        tem=tem->siguiente;
    }
    return tem;
}

bool MazoPrincipal::eliminar(int pos)
{
    if(pos<0 || pos>=cont)
            return false;
        if(pos==0)
        {
            Nodo *temp=inicio;
            inicio=temp->siguiente;
        }
        else
        {
            Nodo *temp=recuperar(pos);
            if(temp!=NULL)
            {
               Nodo *temp2=recuperar(pos-1);
               temp2->siguiente=temp->siguiente;
            }
        }
        cont--;
        return true;
}

bool MazoPrincipal::mover(int to, int from)
{
    Nodo *temp=recuperar(from);

       if(temp!=NULL)
       {
           if(eliminar(from))
             if(insertar(to,temp))
                return true;
       }

       return false;
}

void MazoPrincipal::imprimir()
{
    cout<<"\nContador: "<<cont<<endl;
      Nodo *tem=inicio;
      for(int i=0;i<cont;i++){
        cout<<tem->carta->nombre().toStdString()<<endl;
        tem=tem->siguiente;
      }
}

void MazoPrincipal::ponerPixmap()
{
      Nodo *tem=inicio;
      for(int i=0;i<cont;i++){
        tem->carta->setPixmap(imagenes[i]);
        tem=tem->siguiente;
      }
}


MazoPrincipal::MazoPrincipal()
{
     this->cont=0;
     inicio=NULL;

     imagenes[0]= QPixmap(":/images/cards/DA.png");
     imagenes[1]= QPixmap(":/images/cards/D2.png");
     imagenes[2]= QPixmap(":/images/cards/D3.png");
     imagenes[3]= QPixmap(":/images/cards/D4.png");
     imagenes[4]= QPixmap(":/images/cards/D5.png");
     imagenes[5]= QPixmap(":/images/cards/D6.png");
     imagenes[6]= QPixmap(":/images/cards/D7.png");
     imagenes[7]= QPixmap(":/images/cards/D8.png");
     imagenes[8]= QPixmap(":/images/cards/D9.png");
     imagenes[9]= QPixmap(":/images/cards/D0.png");
     imagenes[10]= QPixmap(":/images/cards/DJ.png");
     imagenes[11]= QPixmap(":/images/cards/DQ.png");
     imagenes[12]= QPixmap(":/images/cards/DK.png");

     imagenes[13]= QPixmap(":/images/cards/TA.png");
     imagenes[14]= QPixmap(":/images/cards/T2.png");
     imagenes[15]= QPixmap(":/images/cards/T3.png");
     imagenes[16]= QPixmap(":/images/cards/T4.png");
     imagenes[17]= QPixmap(":/images/cards/T5.png");
     imagenes[18]= QPixmap(":/images/cards/T6.png");
     imagenes[19]= QPixmap(":/images/cards/T7.png");
     imagenes[20]= QPixmap(":/images/cards/T8.png");
     imagenes[21]= QPixmap(":/images/cards/T9.png");
     imagenes[22]= QPixmap(":/images/cards/T0.png");
     imagenes[23]= QPixmap(":/images/cards/TJ.png");
     imagenes[24]= QPixmap(":/images/cards/TQ.png");
     imagenes[25]= QPixmap(":/images/cards/TK.png");

     imagenes[26]= QPixmap(":/images/cards/EA.png");
     imagenes[27]= QPixmap(":/images/cards/E2.png");
     imagenes[28]= QPixmap(":/images/cards/E3.png");
     imagenes[29]= QPixmap(":/images/cards/E4.png");
     imagenes[30]= QPixmap(":/images/cards/E5.png");
     imagenes[31]= QPixmap(":/images/cards/E6.png");
     imagenes[32]= QPixmap(":/images/cards/E7.png");
     imagenes[33]= QPixmap(":/images/cards/E8.png");
     imagenes[34]= QPixmap(":/images/cards/E9.png");
     imagenes[35]= QPixmap(":/images/cards/E0.png");
     imagenes[36]= QPixmap(":/images/cards/EJ.png");
     imagenes[37]= QPixmap(":/images/cards/EQ.png");
     imagenes[38]= QPixmap(":/images/cards/EK.png");

     imagenes[39]= QPixmap(":/images/cards/CA.png");
     imagenes[40]= QPixmap(":/images/cards/C2.png");
     imagenes[41]= QPixmap(":/images/cards/C3.png");
     imagenes[42]= QPixmap(":/images/cards/C4.png");
     imagenes[43]= QPixmap(":/images/cards/C5.png");
     imagenes[44]= QPixmap(":/images/cards/C6.png");
     imagenes[45]= QPixmap(":/images/cards/C7.png");
     imagenes[46]= QPixmap(":/images/cards/C8.png");
     imagenes[47]= QPixmap(":/images/cards/C9.png");
     imagenes[48]= QPixmap(":/images/cards/C0.png");
     imagenes[49]= QPixmap(":/images/cards/CJ.png");
     imagenes[50]= QPixmap(":/images/cards/CQ.png");
     imagenes[51]= QPixmap(":/images/cards/CK.png");

}
