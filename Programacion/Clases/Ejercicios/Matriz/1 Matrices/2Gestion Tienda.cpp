#include <iostream>
using namespace std;

const int NUM_PRODUCTOS = 5;

void mostrarInventario(int inventario[NUM_PRODUCTOS]) {
    cout << "--- Inventario Actual ---" << endl;
    for (int i = 0; i < NUM_PRODUCTOS; i++) {
        cout << "Producto " << i + 1 << ": " << inventario[i] << " unidades" << endl;
    }
    cout << "-------------------------" << endl;
}

void agregarProducto(int inventario[NUM_PRODUCTOS], int producto, int cantidad) {
    if (producto >= 1 && producto <= NUM_PRODUCTOS) {
        inventario[producto - 1] += cantidad;
        cout << "Se agregaron " << cantidad << " unidades al Producto " << producto << "." << endl;
    } else {
        cout << "Producto no válido." << endl;
    }
}

void eliminarProducto(int inventario[NUM_PRODUCTOS], int producto, int cantidad) {
    if (producto >= 1 && producto <= NUM_PRODUCTOS) {
        if (inventario[producto - 1] >= cantidad) {
            inventario[producto - 1] -= cantidad;
            cout << "Se eliminaron " << cantidad << " unidades del Producto " << producto << "." << endl;
        } else {
            cout << "Cantidad insuficiente para eliminar." << endl;
        }
    } else {
        cout << "Producto no válido." << endl;
    }
}

int main() {
    int inventario[NUM_PRODUCTOS] = {10, 20, 15, 30, 25};
    
    mostrarInventario(inventario);

    agregarProducto(inventario, 2, 5);
    mostrarInventario(inventario);

    eliminarProducto(inventario, 4, 10);
    mostrarInventario(inventario);

    return 0;
}