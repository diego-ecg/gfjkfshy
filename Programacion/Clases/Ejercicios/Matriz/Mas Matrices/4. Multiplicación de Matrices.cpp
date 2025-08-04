#include <iostream>

using namespace std;

const int TAMANIO = 2;

int main() {
    int matrizA[TAMANIO][TAMANIO];
    int matrizB[TAMANIO][TAMANIO];
    int resultado[TAMANIO][TAMANIO] = {0};

    // Pedir al usuario que ingrese los elementos de la matriz A
    cout << "Ingrese los elementos de la primera matriz (" << TAMANIO << "x" << TAMANIO << "):" << endl;
    for (int i = 0; i < TAMANIO; i++) {
        for (int j = 0; j < TAMANIO; j++) {
            cout << "Matriz A [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrizA[i][j];
        }
    }

    // Pedir al usuario que ingrese los elementos de la matriz B
    cout << "\nIngrese los elementos de la segunda matriz (" << TAMANIO << "x" << TAMANIO << "):" << endl;
    for (int i = 0; i < TAMANIO; i++) {
        for (int j = 0; j < TAMANIO; j++) {
            cout << "Matriz B [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrizB[i][j];
        }
    }

    // Realizar la multiplicación de matrices
    for (int i = 0; i < TAMANIO; i++) {
        for (int j = 0; j < TAMANIO; j++) {
            for (int k = 0; k < TAMANIO; k++) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    // Imprimir la matriz resultante
    cout << "\n--- Matriz Resultante (A * B) ---" << endl;
    for (int i = 0; i < TAMANIO; i++) {
        for (int j = 0; j < TAMANIO; j++) {
            cout << resultado[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}