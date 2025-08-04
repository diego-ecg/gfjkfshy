#include <iostream>
#include <iomanip>

using namespace std;

const int NUM_CIUDADES = 3;
const int NUM_DIAS = 7;

void calcularEstadisticas(int temperaturas[NUM_CIUDADES][NUM_DIAS]) {
    string ciudades[NUM_CIUDADES] = {"Caracas", "Barquisimeto", "Maracay"};
    float promedios[NUM_CIUDADES] = {0.0};
    int maximos[NUM_CIUDADES] = {0};
    int minimos[NUM_CIUDADES] = {0};

    cout << "--- Analisis de Datos Meteorologicos ---" << endl;

    for (int i = 0; i < NUM_CIUDADES; i++) {
        int suma = 0;
        int maxTemp = temperaturas[i][0];
        int minTemp = temperaturas[i][0];

        for (int j = 0; j < NUM_DIAS; j++) {
            suma += temperaturas[i][j];
            if (temperaturas[i][j] > maxTemp) {
                maxTemp = temperaturas[i][j];
            }
            if (temperaturas[i][j] < minTemp) {
                minTemp = temperaturas[i][j];
            }
        }
        
        promedios[i] = (float)suma / NUM_DIAS;
        maximos[i] = maxTemp;
        minimos[i] = minTemp;

        cout << "Ciudad: " << ciudades[i] << endl;
        cout << "  Temperatura Promedio: " << fixed << setprecision(2) << promedios[i] << " C" << endl;
        cout << "  Temperatura Maxima: " << maximos[i] << " C" << endl;
        cout << "  Temperatura Minima: " << minimos[i] << " C" << endl;
    }
    
    int indiceMaxPromedio = 0;
    for (int i = 1; i < NUM_CIUDADES; i++) {
        if (promedios[i] > promedios[indiceMaxPromedio]) {
            indiceMaxPromedio = i;
        }
    }
    
    cout << "La ciudad con la temperatura promedio mas alta es " << ciudades[indiceMaxPromedio] << " con " << fixed << setprecision(2) << promedios[indiceMaxPromedio] << " C." << endl;
}

int main() {
    int temperaturas[NUM_CIUDADES][NUM_DIAS] = {
        {28, 29, 30, 29, 31, 30, 28}, // Temperaturas de Caracas
        {25, 26, 27, 26, 28, 27, 25}, // Temperaturas de Barquisimeto
        {29, 30, 31, 30, 32, 31, 29}  // Temperaturas de Maracay
    };

    calcularEstadisticas(temperaturas);

    return 0;
}