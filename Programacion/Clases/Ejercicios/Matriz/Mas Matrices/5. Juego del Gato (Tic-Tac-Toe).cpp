#include <iostream>

using namespace std;

const int TAMANIO = 3;

void imprimirTablero(char tablero[TAMANIO][TAMANIO]) {
    cout << "\n--- Tablero ---" << endl;
    for (int i = 0; i < TAMANIO; i++) {
        for (int j = 0; j < TAMANIO; j++) {
            cout << " " << tablero[i][j];
            if (j < TAMANIO - 1) {
                cout << " |";
            }
        }
        cout << endl;
        if (i < TAMANIO - 1) {
            cout << "---+---+---" << endl;
        }
    }
    cout << "---------------" << endl;
}

bool verificarGanador(char tablero[TAMANIO][TAMANIO], char jugador) {
    // Verificar filas y columnas
    for (int i = 0; i < TAMANIO; i++) {
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) {
            return true;
        }
        if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador) {
            return true;
        }
    }
    // Verificar diagonales
    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) {
        return true;
    }
    if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador) {
        return true;
    }
    return false;
}

bool tableroLleno(char tablero[TAMANIO][TAMANIO]) {
    for (int i = 0; i < TAMANIO; i++) {
        for (int j = 0; j < TAMANIO; j++) {
            if (tablero[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char tablero[TAMANIO][TAMANIO];
    for (int i = 0; i < TAMANIO; i++) {
        for (int j = 0; j < TAMANIO; j++) {
            tablero[i][j] = ' '; // Inicializar el tablero vacío
        }
    }

    char jugadorActual = 'X';
    int fila, columna;
    bool juegoTerminado = false;

    while (!juegoTerminado) {
        imprimirTablero(tablero);
        
        cout << "Jugador " << jugadorActual << ", ingrese su movimiento (fila y columna): ";
        cin >> fila >> columna;

        if (fila >= 1 && fila <= TAMANIO && columna >= 1 && columna <= TAMANIO && tablero[fila - 1][columna - 1] == ' ') {
            tablero[fila - 1][columna - 1] = jugadorActual;
            
            if (verificarGanador(tablero, jugadorActual)) {
                imprimirTablero(tablero);
                cout << "¡El jugador " << jugadorActual << " ha ganado!" << endl;
                juegoTerminado = true;
            } else if (tableroLleno(tablero)) {
                imprimirTablero(tablero);
                cout << "¡Empate! El tablero está lleno." << endl;
                juegoTerminado = true;
            } else {
                jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Movimiento no válido. Intente de nuevo." << endl;
        }
    }

    return 0;
}