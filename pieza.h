#ifndef PIEZA_H
#define PIEZA_H

struct Pieza {
    int forma[4];
    int x;
    int y;
};

Pieza nuevaPieza(int ancho);

#endif
