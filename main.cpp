#include <iostream>
#include "tablero.h"
#include "pieza.h"

using namespace std;

int main() {

    Tablero t;

    cout << "Ancho (multiplo de 8): ";
    cin >> t.ancho;

    cout << "Alto (>=8): ";
    cin >> t.alto;

    if (t.ancho < 8 || t.alto < 8 || t.ancho % 8 != 0) {
        cout << "Dimensiones invalidas\n";
        return 0;
    }

    iniciarTablero(t);

    Pieza actual = nuevaPieza(t.ancho);

    while (true) {

        imprimir(t, actual);

        char op;
        cin >> op;

        if (op == 'q') break;

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
                limpiarFilas(t);

                actual = nuevaPieza(t.ancho);

                if (colision(t, actual, actual.x, actual.y)) {
                    cout << "GAME OVER\n";
                    break;
                }
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
