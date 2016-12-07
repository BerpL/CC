#include "personajes.h"
#define ANCHO 500
#define ALTO  450

void acomoda_enemigos(class ENEMIGOS E[])
{
    int indice = -1;
    int _tipo = 0;
    for (int i = 0; i<5; i++)
    {
        _tipo++;
        if(_tipo == 4) _tipo = 1;
        for(int j = 0;j<11;j++)
        {
            indice++;
            E[indice].inicia("Recursos/enemigos.bmp","Recursos/Bala_enem.bmp",6,12,25,20,90+j*30,50+i*24,8,_tipo,1);
        }

    }
}
void pintar_enemigos(class ENEMIGOS E[], BITMAP* buffer, int mov)
{
    int indice = -1;
    for (int i = 0; i<5; i++)
    {
        for(int j = 0;j<11;j++)
        {
            indice++;
            if(E[indice].vida>0)
            E[indice].pinta(buffer,mov,E[indice].tipo-1);
        }

    }
}

void explosion1(class ENEMIGOS E, BITMAP* buffer)
{
    BITMAP* parche = create_bitmap(25,20);
    clear_to_color(parche,0x000000);
    blit(parche,buffer,0,0,E.x,E.y,25,20);
    masked_blit(E.exp_enem,buffer,0,0,E.x-10,E.y,41,34);

}

void explosion2(class NAVE N, BITMAP* buffer, BITMAP* fondo)
{
    BITMAP* parche = create_bitmap(25,20);
    clear_to_color(parche,0x000000);
    for(int j=0; j<6;j++)
    {
        for(int i = 0;i<=2;i++)
        {
            blit(parche,buffer,0,0,N.x,N.y,30,20);
            masked_blit(N.imp_nav,buffer,i*40,0,N.x,N.y,47,40);
            blit(buffer,screen,0,0,0,0,ANCHO,ALTO);
            rest(50);
        }
    }
}

