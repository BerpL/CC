#ifndef ENEMIGOS_H
#define ENEMIGOS_H
#include "NAVE.h"


class ENEMIGOS : public NAVE
{
public:
    int x,y;
    int tipo;
    int ancho_p, alto_p;

    ENEMIGOS() = default;
    void inicia(char* ruta_nave, char* ruta_bala, int _ancho_b, int _alto_b, int _ancho_p, int _alto_p, int _x, int _y, int _dir_bala, int _tipo, int _vida);
    void pinta(BITMAP* buffer, int ix, int iy);
    void dispara(struct Balas disparos[], BITMAP* buffer);
};

#endif // ENEMIGOS_H
