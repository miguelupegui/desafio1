#include <iostream>
#include "tablero.h"
#include "pieza.h"

using namespace std;

int main() {

    Tablero t;

    cout << "Ancho: ";
    cin >> t.ancho;

    cout << "Alto: ";
    cin >> t.alto;

    iniciarTablero(t);

    Pieza actual = nuevaPieza(t.ancho);

    while (true) {

        imprimir(t, actual);

        char op;
        cin >> op;

        if (op == 'a') {
            if (!colision(t, actual, actual.x - 1, actual.y))
                actual.x--;
        }

        if (op == 'd') {
            if (!colision(t, actual, actual.x + 1, actual.y))
                actual.x++;
        }

        if (op == 's') {
            if (!colision(t, actual, actual.x, actual.y + 1)) {
                actual.y++;
            } else {
                fijarPieza(t, actual);
                actual = nuevaPieza(t.ancho);
            }
        }

        if (op == 'w') {
            Pieza temp = actual;
            rotar(temp);

            if (!colision(t, temp, temp.x, temp.y)) {
                actual = temp;
            }
        }
    }

    return 0;
}
