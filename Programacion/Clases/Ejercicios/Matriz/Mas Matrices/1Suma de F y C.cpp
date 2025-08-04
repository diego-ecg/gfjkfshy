#include <iostream>

using namespace std;

const int FILAS = 4;
const int COLUMNAS = 4;

int main() {
    int matriz[FILAS][COLUMNAS];
    int sumaFilas[FILAS] = {0};
    int sumaColumnas[COLUMNAS] = {0};

    // Pedir al usuario que ingrese los elementos de la matriz
    cout << "Ingrese los elementos de la matriz de " << FILAS << "x" << COLUMNAS << ":" << endl;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Calcular la suma de cada fila y columna
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            sumaFilas[i] += matriz[i][j];
            sumaColumnas[j] += matriz[i][j];
        }
    }

    // Imprimir las sumas
    cout << "\n--- Suma de Filas ---" << endl;
    for (int i = 0; i < FILAS; i++) {
        cout << "Fila " << i + 1 << ": " << sumaFilas[i] << endl;
    }

    cout << "\n--- Suma de Columnas ---" << endl;
    for (int j = 0; j < COLUMNAS; j++) {
        cout << "Columna " << j + 1 << ": " << sumaColumnas[j] << endl;
    }

    return 0;
}