#include "ENEMIGOS.h"
#define ANCHO 500
#define ALTO  450

void ENEMIGOS::inicia(char* ruta_nave, char* ruta_bala, int _ancho_b, int _alto_b,int _ancho_p, int _alto_p, int _x, int _y, int _dir_bala, int _tipo, int _vida)
{
    x = _x; y = _y;
    n_disp = 0 ; max_disp =2;
    imp_nav = load_bitmap(ruta_nave,NULL);
    imp_bala = load_bitmap(ruta_bala,NULL);
    ancho_b = _ancho_b;
    alto_b = _alto_b;
    ancho_p = _ancho_p;
    alto_p = _alto_p;
    dir_bala = _dir_bala;
    tipo = _tipo;
    vida = _vida;
    tick = 0;
    exp_enem = load_bitmap("Recursos/pum_enemigo.bmp", NULL);
}
void ENEMIGOS::pinta(BITMAP* buffer, int ix, int iy)
{
    masked_blit(imp_nav,buffer,ix*ancho_p,iy*alto_p,x,y,25,20);
}
void ENEMIGOS::dispara(struct Balas disparos[], BITMAP* buffer)
{
    crear_bala(n_disp,max_disp,disparos,x,y, dir_bala);
    pintar_bala(n_disp,max_disp,disparos,buffer,imp_bala, ancho_b,alto_b);
    elimina_bala(n_disp,max_disp,disparos,ANCHO,ALTO);
}

