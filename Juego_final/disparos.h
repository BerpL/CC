#include <allegro.h>
#ifndef DISPAROS_H_INCLUDED
#define DISPAROS_H_INCLUDED
#include "NAVE.h"
#include "ENEMIGOS.h"

struct Balas{
    int x , y;
    int dx , dy;

};
bool colision(int x1, int y1, int w1, int h1,
              int x2, int y2, int w2, int h2);

void crear_bala(int& n_disparos, const int max_disparos,struct Balas disparos[],
                const int X, const int Y ,const int dy);

void pintar_bala(int& n_disparos, const int max_disparos,struct Balas disparos[],
                 BITMAP* buffer, BITMAP* bala, int ancho, int alto);

void eliminar(struct Balas disparos[], int& n_disparos, int cont);

void elimina_bala(int& n_disparos, const int max_disparos,struct Balas disparos[],
                  const int ANCHO, const int ALTO);

bool elimina_bala_objeto(class NAVE& N, class ENEMIGOS& E, struct Balas B[]);

bool elimina_bala_objeto2(class ENEMIGOS& E, class NAVE& N, struct Balas B[]);


#endif // DISPAROS_H_INCLUDED
