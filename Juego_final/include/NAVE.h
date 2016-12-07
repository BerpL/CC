#include <allegro.h>
#include "../disparos.h"
#ifndef NAVE_H
#define NAVE_H



class NAVE
{
private:
    NAVE()=default;
public:
    int x,y, dir;
    int n_disp;
    int max_disp;
    int tick;
    int ancho_b, alto_b;
    int ancho_p, alto_p;
    int dir_bala;
    int vida;
    static NAVE& Instancia();
    NAVE(const NAVE&)=delete;
    NAVE& operator=(const NAVE&) = delete;


    BITMAP* imp_nav;
    BITMAP* imp_bala;
    BITMAP* exp_enem;

    virtual void inicia(char* ruta_nave, char* ruta_bala, int _ancho_b, int _alto_b, int _ancho_p, int _alto_p, int _x, int _y, int _dir_bala, int _vida);
    bool temporizador(int tiempo);
    virtual void pinta(BITMAP* buffer);
    void mueve();
    void dispara(struct Balas disparos[], BITMAP* buffer);
};


#endif // NAVE_H
