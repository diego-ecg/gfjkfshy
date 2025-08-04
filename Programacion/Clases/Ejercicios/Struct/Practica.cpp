#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Estructura para almacenar la información de los candidatos
struct Candidato {
    string priNombre;
    string priApellido;
    int totalVotos = 0;
};

// Estructura para almacenar los votos por región
struct VotosRegion {
    string nombreRegion;
    vector<int> votosPorCandidato;
};

int main() {
    const int NUM_CANDIDATOS = 3;
    const int NUM_REGIONES = 2;

    vector<Candidato> candidatos(NUM_CANDIDATOS);
    vector<VotosRegion> regiones(NUM_REGIONES);

    cout << "--- Sistema de Votacion ---" << endl;

    // Ingreso de datos de los candidatos
    cout << "\nIngrese los datos de los " << NUM_CANDIDATOS << " candidatos:" << endl;
    for (int i = 0; i < NUM_CANDIDATOS; ++i) {
        cout << "Candidato " << i + 1 << " Primer Nombre: ";
        getline(cin, candidatos[i].priNombre);
        cout << "Candidato " << i + 1 << " Primer Apellido: ";
        getline(cin, candidatos[i].priApellido);
    }

    // Ingreso de votos por región
    cout << "\nIngrese los votos para cada region:" << endl;
    for (int i = 0; i < NUM_REGIONES; ++i) {
        cout << "Nombre de la Region " << i + 1 << ": ";
        getline(cin, regiones[i].nombreRegion);
        regiones[i].votosPorCandidato.resize(NUM_CANDIDATOS);
        for (int j = 0; j < NUM_CANDIDATOS; ++j) {
            cout << "  Votos para " << candidatos[j].priNombre << " en " << regiones[i].nombreRegion << ": ";
            cin >> regiones[i].votosPorCandidato[j];
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
    }

    // Calcular el total de votos por candidato
    for (int i = 0; i < NUM_REGIONES; ++i) {
        for (int j = 0; j < NUM_CANDIDATOS; ++j) {
            candidatos[j].totalVotos += regiones[i].votosPorCandidato[j];
        }
    }

    // Determinar el candidato ganador
    int maxVotos = 0;
    int indiceGanador = -1;
    for (int i = 0; i < NUM_CANDIDATOS; ++i) {
        if (candidatos[i].totalVotos > maxVotos) {
            maxVotos = candidatos[i].totalVotos;
            indiceGanador = i;
        }
    }

    // Imprimir los resultados
    cout << "\n--- Resultados de la Votacion ---" << endl;
    cout << "Total de votos por candidato:" << endl;
    for (int i = 0; i < NUM_CANDIDATOS; ++i) {
        cout << "  " << candidatos[i].priNombre << " " << candidatos[i].priApellido << ": " << candidatos[i].totalVotos << " votos" << endl;
    }

    if (indiceGanador != -1) {
        cout << "\nCandidato Ganador: " << candidatos[indiceGanador].priNombre << " " << candidatos[indiceGanador].priApellido << " con " << maxVotos << " votos." << endl;
    } else {
        cout << "\nNo se pudo determinar un ganador." << endl;
    }

    return 0;
}