#include "NAVE.h"
#define ANCHO 500
#define ALTO  450

NAVE& NAVE::Instancia()
{
    static NAVE s_instancia;
    return s_instancia;
}

void NAVE::inicia(char* ruta_nave, char* ruta_bala, int _ancho_b, int _alto_b, int _ancho_p, int _alto_p, int _x, int _y, int _dir_bala, int _vida)
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
    vida = _vida;
    tick = 0;
}
bool NAVE::temporizador(int tiempo)
{
    tick++;
    if(tick ==tiempo)
    {
        tick =0;
        return true;
    }
    return false;
}
void NAVE::pinta(BITMAP* buffer)
{
    masked_blit(imp_nav,buffer,40*dir,0,x,y,40,47);
}
void NAVE::mueve()
{
    if(key[KEY_LEFT]) {x -=3; dir = 0;}
    else if(key[KEY_RIGHT]) {x +=3; dir = 2;}
    else dir = 1;
}
void NAVE::dispara(struct Balas disparos[], BITMAP* buffer)
{
    if(key[KEY_SPACE] && temporizador(5))
    {
        crear_bala(n_disp,max_disp,disparos,x,y, dir_bala);
    }
    pintar_bala(n_disp,max_disp,disparos,buffer,imp_bala, ancho_b,alto_b);
    elimina_bala(n_disp,max_disp,disparos,ANCHO,ALTO);
}
