#include <iostream>

using namespace std;

const int NUM_PISOS = 3;
const int HABITACIONES_POR_PISO = 5;

// La matriz almacena 0 para disponible y 1 para reservada
int hotel[NUM_PISOS][HABITACIONES_POR_PISO] = {0};

void mostrarEstadoHotel() {
    cout << "--- Estado del Hotel ---" << endl;
    for (int i = 0; i < NUM_PISOS; i++) {
        cout << "Piso " << i + 1 << ": ";
        for (int j = 0; j < HABITACIONES_POR_PISO; j++) {
            cout << "[Hab " << j + 1 << ":" << (hotel[i][j] == 0 ? "D" : "R") << "] ";
        }
        cout << endl;
    }
    cout << "-------------------------" << endl;
}

void realizarReserva(int piso, int habitacion) {
    if (piso >= 1 && piso <= NUM_PISOS && habitacion >= 1 && habitacion <= HABITACIONES_POR_PISO) {
        if (hotel[piso - 1][habitacion - 1] == 0) {
            hotel[piso - 1][habitacion - 1] = 1;
            cout << "Reserva exitosa para la habitacion " << habitacion << " del piso " << piso << "." << endl;
        } else {
            cout << "La habitacion " << habitacion << " del piso " << piso << " ya esta reservada." << endl;
        }
    } else {
        cout << "Habitacion o piso no valido." << endl;
    }
}

void cancelarReserva(int piso, int habitacion) {
    if (piso >= 1 && piso <= NUM_PISOS && habitacion >= 1 && habitacion <= HABITACIONES_POR_PISO) {
        if (hotel[piso - 1][habitacion - 1] == 1) {
            hotel[piso - 1][habitacion - 1] = 0;
            cout << "Reserva cancelada para la habitacion " << habitacion << " del piso " << piso << "." << endl;
        } else {
            cout << "La habitacion " << habitacion << " del piso " << piso << " no estaba reservada." << endl;
        }
    } else {
        cout << "Habitacion o piso no valido." << endl;
    }
}

int main() {
    mostrarEstadoHotel();

    realizarReserva(1, 3);
    mostrarEstadoHotel();

    realizarReserva(1, 3); // Intentar reservar la misma habitación
    mostrarEstadoHotel();

    cancelarReserva(1, 3);
    mostrarEstadoHotel();

    realizarReserva(2, 5);
    mostrarEstadoHotel();

    return 0;
}