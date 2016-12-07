#ifndef PERSONAJES_H_INCLUDED
#define PERSONAJES_H_INCLUDED
#include <allegro.h>
#include "ENEMIGOS.h"

void acomoda_enemigos(class ENEMIGOS E[]);
void pintar_enemigos(class ENEMIGOS E[], BITMAP* buffer, int mov);
void explosion1(class ENEMIGOS E, BITMAP* buffer);
void explosion2(class NAVE N, BITMAP* buffer, BITMAP* fondo);

#endif // PERSONAJES_H_INCLUDED
