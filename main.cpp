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

    imprimir(t, actual);

    return 0;
}
