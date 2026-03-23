#ifndef PIEZA_H
#define PIEZA_H

struct Pieza {
    int forma[4];
    int x;
    int y;
};

void copiarForma(int origen[4], int destino[4]);
void rotar(Pieza &p);
Pieza nuevaPieza(int ancho);

#endif
