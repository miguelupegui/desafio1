#include "tablero.h"
#include <iostream>

using namespace std;

void iniciarTablero(Tablero &t) {

    t.bytesPorFila = t.ancho / 8;

    t.matriz = new unsigned char*[t.alto];

    for (int i = 0; i < t.alto; i++) {
        t.matriz[i] = new unsigned char[t.bytesPorFila];

        for (int j = 0; j < t.bytesPorFila; j++) {
            t.matriz[i][j] = 0;
        }
    }
}

void imprimir(Tablero &t, Pieza &p) {

    for (int i = 0; i < t.alto; i++) {
        for (int j = 0; j < t.ancho; j++) {

            bool lleno = false;

            int byte = j / 8;
            int bit = j % 8;

            if (t.matriz[i][byte] & (1 << bit)) {
                lleno = true;
            }

            int px = j - p.x;
            int py = i - p.y;

            if (px >= 0 && px < 4 && py >= 0 && py < 4) {
                if (p.forma[py] & (1 << px)) {
                    lleno = true;
                }
            }

            cout << (lleno ? '#' : '.');
        }
        cout << endl;
    }
}
