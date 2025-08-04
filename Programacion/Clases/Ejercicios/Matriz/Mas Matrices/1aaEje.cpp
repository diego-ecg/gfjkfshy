#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int NUM_VENDEDORES = 3;
    const int NUM_TRIMESTRES = 4;
    double ventas[NUM_VENDEDORES][NUM_TRIMESTRES];
    double totalVentas[NUM_VENDEDORES] = {0.0};

    // Entrada de datos
    cout << "Ingrese las ventas de cada vendedor por trimestre:" << endl;
    for (int vendedor = 0; vendedor < NUM_VENDEDORES; vendedor++) {
        for (int trimestre = 0; trimestre < NUM_TRIMESTRES; trimestre++) {
            cout << "Vendedor " << vendedor + 1 << ", Trimestre " << trimestre + 1 << ": ";
            cin >> ventas[vendedor][trimestre];
            totalVentas[vendedor] += ventas[vendedor][trimestre]; // Acumula las ventas
        }
    }

    // Salida de resultados
    cout << "\nTotal de Ventas por Vendedor:" << endl;
    cout << fixed << setprecision(2); // Formato de salida a 2 decimales
    for (int vendedor = 0; vendedor < NUM_VENDEDORES; vendedor++) {
        cout << "Vendedor " << vendedor + 1 << ": " << totalVentas[vendedor] << endl;
    }
    
    return 0;
}