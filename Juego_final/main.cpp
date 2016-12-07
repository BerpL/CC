#include <allegro.h>
#include "inicia.h"
#include "disparos.h"
#include "NAVE.h"
#include "ENEMIGOS.h"
#include <stdlib.h>
#include <time.h>
#include "personajes.h"
#include "diseno.h"
#include <vector>
#include <algorithm>

#define ANCHO 500
#define ALTO  450

using namespace std;

int main(){

    srand(time(NULL));

    inicia_allegro(ANCHO,ALTO); // fuciones del include inicia.h
	inicia_audio(70,70);        //

    BITMAP *buffer = create_bitmap(ANCHO, ALTO);;
    BITMAP *nube = load_bitmap("nube.bmp", NULL);
    BITMAP *portada = load_bitmap("Recursos/portada.bmp", NULL);
    BITMAP *fondo = load_bitmap("Recursos/fondo.bmp", NULL);

    PORTADA(portada);


    NAVE N;
    N.inicia("nave.bmp","Bala2.bmp",6,12,30,20,ANCHO/2, ALTO-50, -4,3);
    ENEMIGOS E[60];
    acomoda_enemigos(E);

    int i = 450;
    Balas disparos[N.max_disp];
    Balas disp_E[E[0].max_disp];

    int azar = rand()%55;
    int mov = 0;

    while(!key[KEY_ESC])
    {
        blit(nube,buffer,0,--i,0,0,500,450);  if(i == 0) i=450;
        N.pinta(buffer);
        N.mueve();
        N.dispara(disparos,buffer);

        for(int i=0;i<55;i++)
        if(elimina_bala_objeto(N,E[i],disparos))
            explosion1(E[i],buffer);

        pintar_enemigos(E,buffer,mov);
        if(E[azar].n_disp==0) azar = rand()%55;
        E[azar].dispara(disp_E,buffer);
        if(E[0].temporizador(10)) if(++mov==2) mov =0;

        if(elimina_bala_objeto2(E[azar],N,disp_E))
            explosion2(N,buffer,fondo);

        //imprimir_fondo(fondo,buffer);
        blit(buffer,screen,0,0,0,0,500,450);
        rest(20);
    }
	return 0;
}
END_OF_MAIN();

