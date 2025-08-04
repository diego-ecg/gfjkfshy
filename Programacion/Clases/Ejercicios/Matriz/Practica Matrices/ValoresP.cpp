#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    const int NUM_MESES = 3;
    const int NUM_PRODUCTOS = 4;

    string nombresMeses[NUM_MESES] = {"Enero", "Febrero", "Marzo"};
    string nombresProductos[NUM_PRODUCTOS] = {"Producto A", "Producto B", "Producto C", "Producto D"};

    int ventas[NUM_MESES][NUM_PRODUCTOS] = {
        {100, 150, 200, 250},
        {120, 130, 210, 240},
        {110, 140, 220, 230}
    };

    // Calcular el promedio de ventas por mes
    cout << "--- Analisis de Ventas ---" << endl;
    cout << "Promedio de Ventas por mes:" << endl;
    for (int i = 0; i < NUM_MESES; ++i) {
        int sumaVentasMes = 0;
        for (int j = 0; j < NUM_PRODUCTOS; ++j) {
            sumaVentasMes += ventas[i][j];
        }
        cout << nombresMeses[i] << ": " << (double)sumaVentasMes / NUM_PRODUCTOS << endl;
    }

    // Encontrar el mes con mayores ventas
    int totalVentasMes[NUM_MESES] = {0};
    int maxVentasMes = 0;
    int indiceMesMayor = -1;
    for (int i = 0; i < NUM_MESES; ++i) {
        for (int j = 0; j < NUM_PRODUCTOS; ++j) {
            totalVentasMes[i] += ventas[i][j];
        }
        if (totalVentasMes[i] > maxVentasMes) {
            maxVentasMes = totalVentasMes[i];
            indiceMesMayor = i;
        }
    }
    cout << "Mes con mayores ventas: " << nombresMeses[indiceMesMayor] << " con " << maxVentasMes << " ventas totales." << endl;

    // Encontrar el producto más vendido
    int totalVentasProducto[NUM_PRODUCTOS] = {0};
    int maxVentasProducto = 0;
    int indiceProductoMayor = -1;
    for (int j = 0; j < NUM_PRODUCTOS; ++j) {
        for (int i = 0; i < NUM_MESES; ++i) {
            totalVentasProducto[j] += ventas[i][j];
        }
        if (totalVentasProducto[j] > maxVentasProducto) {
            maxVentasProducto = totalVentasProducto[j];
            indiceProductoMayor = j;
        }
    }
    cout << "Producto mas vendido: " << nombresProductos[indiceProductoMayor] << " con " << maxVentasProducto << " unidades vendidas." << endl;

    return 0;
}