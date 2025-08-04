#include <iostream>

using namespace std;

const int TAMANIO = 5;

int main() {
    int matriz[TAMANIO][TAMANIO];
    int numeroBuscar;
    bool encontrado = false;
    int filaEncontrada, columnaEncontrada;

    // Pedir al usuario que ingrese los elementos de la matriz
    cout << "Ingrese los elementos de la matriz de " << TAMANIO << "x" << TAMANIO << ":" << endl;
    for (int i = 0; i < TAMANIO; i++) {
        for (int j = 0; j < TAMANIO; j++) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz[i][j];
        }
    }
    
    // Pedir el número a buscar
    cout << "\nIngrese el número a buscar en la matriz: ";
    cin >> numeroBuscar;

    // Buscar el número en la matriz
    for (int i = 0; i < TAMANIO; i++) {
        for (int j = 0; j < TAMANIO; j++) {
            if (matriz[i][j] == numeroBuscar) {
                encontrado = true;
                filaEncontrada = i + 1;
                columnaEncontrada = j + 1;
                break; // Terminar la búsqueda una vez encontrado
            }
        }
        if (encontrado) {
            break;
        }
    }

    // Imprimir el resultado de la búsqueda
    if (encontrado) {
        cout << "El número " << numeroBuscar << " se encontró en la posición (" << filaEncontrada << ", " << columnaEncontrada << ")." << endl;
    } else {
        cout << "El número " << numeroBuscar << " no se encuentra en la matriz." << endl;
    }

    return 0;
}