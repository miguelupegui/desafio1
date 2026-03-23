#ifndef TABLERO_H
#define TABLERO_H

#include "pieza.h"

struct Tablero {
    int ancho;
    int alto;
    int bytesPorFila;
    unsigned char** matriz;
};

void iniciarTablero(Tablero &t);
void imprimir(Tablero &t, Pieza &p);
bool colision(Tablero &t, Pieza &p, int nx, int ny);
void fijarPieza(Tablero &t, Pieza &p);

#endif
