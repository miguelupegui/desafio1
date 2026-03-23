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

    cout << "A Izq | D Der | S Baja | W Rota | Q Salir\n";
}

bool colision(Tablero &t, Pieza &p, int nx, int ny) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

            if (!(p.forma[i] & (1 << j))) continue;

            int x = nx + j;
            int y = ny + i;

            if (x < 0 || x >= t.ancho || y >= t.alto) {
                return true;
            }

            if (y >= 0) {
                int byte = x / 8;
                int bit = x % 8;

                if (t.matriz[y][byte] & (1 << bit)) {
                    return true;
                }
            }
        }
    }
    return false;
}

void fijarPieza(Tablero &t, Pieza &p) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

            if (!(p.forma[i] & (1 << j))) continue;

            int x = p.x + j;
            int y = p.y + i;

            if (y >= 0) {
                int byte = x / 8;
                int bit = x % 8;

                t.matriz[y][byte] |= (1 << bit);
            }
        }
    }
}

void limpiarFilas(Tablero &t) {
    for (int i = 0; i < t.alto; i++) {

        bool llena = true;

        for (int j = 0; j < t.bytesPorFila; j++) {
            if (t.matriz[i][j] != 0xFF) {
                llena = false;
                break;
            }
        }

        if (llena) {
            for (int k = i; k > 0; k--) {
                for (int j = 0; j < t.bytesPorFila; j++) {
                    t.matriz[k][j] = t.matriz[k-1][j];
                }
            }

            for (int j = 0; j < t.bytesPorFila; j++) {
                t.matriz[0][j] = 0;
            }
        }
    }
}
