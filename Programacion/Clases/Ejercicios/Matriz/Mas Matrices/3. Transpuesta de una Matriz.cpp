#include <iostream>

using namespace std;

const int FILAS = 3;
const int COLUMNAS = 2;

int main() {
    int matriz[FILAS][COLUMNAS];
    int transpuesta[COLUMNAS][FILAS];

    // Pedir al usuario que ingrese los elementos de la matriz original
    cout << "Ingrese los elementos de la matriz original de " << FILAS << "x" << COLUMNAS << ":" << endl;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Calcular la matriz transpuesta
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            transpuesta[j][i] = matriz[i][j];
        }
    }

    // Imprimir la matriz original
    cout << "\n--- Matriz Original ---" << endl;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    // Imprimir la matriz transpuesta
    cout << "\n--- Matriz Transpuesta ---" << endl;
    for (int i = 0; i < COLUMNAS; i++) {
        for (int j = 0; j < FILAS; j++) {
            cout << transpuesta[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}