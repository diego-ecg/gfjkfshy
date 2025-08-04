#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    const int NUM_PROYECTOS = 3;
    const int NUM_FASES = 4;

    string nombresProyectos[NUM_PROYECTOS] = {"Plataforma de Cursos", "Automatización de Nomina", "Sistematizacion de Inventarios"};
    string nombresFases[NUM_FASES] = {"Planificacion", "Desarrollo", "Pruebas", "Entrega"};

    int duraciones[NUM_PROYECTOS][NUM_FASES] = {
        {10, 20, 15, 5},
        {15, 25, 10, 10},
        {20, 30, 20, 15}
    };

    int totalDias[NUM_PROYECTOS] = {0};

    // Calcular el total de días por proyecto
    for (int i = 0; i < NUM_PROYECTOS; ++i) {
        for (int j = 0; j < NUM_FASES; ++j) {
            totalDias[i] += duraciones[i][j];
        }
    }

    // Encontrar el proyecto con la mayor cantidad de días
    int maxDias = 0;
    int indiceProyectoMayor = -1;
    for (int i = 0; i < NUM_PROYECTOS; ++i) {
        if (totalDias[i] > maxDias) {
            maxDias = totalDias[i];
            indiceProyectoMayor = i;
        }
    }

    // Encontrar el primer proyecto que podrá ser entregado (menor cantidad de días)
    int minDias = totalDias[0];
    int indiceProyectoMenor = 0;
    for (int i = 1; i < NUM_PROYECTOS; ++i) {
        if (totalDias[i] < minDias) {
            minDias = totalDias[i];
            indiceProyectoMenor = i;
        }
    }

    cout << "--- Planificacion de Proyectos ---" << endl;
    cout << "Proyecto con mayor cantidad de dias para su entrega: " << nombresProyectos[indiceProyectoMayor] << " con " << maxDias << " dias." << endl;
    cout << "Primer proyecto que podra ser entregado: " << nombresProyectos[indiceProyectoMenor] << " con " << minDias << " dias." << endl;

    return 0;
}