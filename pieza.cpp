#include "pieza.h"
#include <random>

int piezas[2][4] = {
    {0x0F, 0x00, 0x00, 0x00}, // I
    {0x06, 0x06, 0x00, 0x00}  // O
};

Pieza nuevaPieza(int ancho) {

    Pieza p;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    int r = dis(gen);

    for (int i = 0; i < 4; i++) {
        p.forma[i] = piezas[r][i];
    }

    p.x = ancho / 2 - 2;
    p.y = 0;

    return p;
}
