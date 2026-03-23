#include "pieza.h"
#include <random>

int piezas[5][4] = {
    {0x0F, 0x00, 0x00, 0x00}, // I
    {0x06, 0x06, 0x00, 0x00}, // O
    {0x07, 0x02, 0x00, 0x00}, // T
    {0x03, 0x06, 0x00, 0x00}, // S
    {0x06, 0x03, 0x00, 0x00}  // Z
};

void copiarForma(int origen[4], int destino[4]) {
    for (int i = 0; i < 4; i++) {
        destino[i] = origen[i];
    }
}

void rotar(Pieza &p) {
    int temp[4] = {0,0,0,0};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (p.forma[i] & (1 << j)) {
                temp[j] |= (1 << (3 - i));
            }
        }
    }

    copiarForma(temp, p.forma);
}

Pieza nuevaPieza(int ancho) {
    Pieza p;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 4);

    int r = dis(gen);

    copiarForma(piezas[r], p.forma);

    p.x = ancho / 2 - 2;
    p.y = 0;

    return p;
}
