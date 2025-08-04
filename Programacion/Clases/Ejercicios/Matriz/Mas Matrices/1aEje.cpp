#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int NUM_ESTUDIANTES = 5;
    const int NUM_EXAMENES = 3;
    double calificaciones[NUM_ESTUDIANTES][NUM_EXAMENES];
    double promedios[NUM_ESTUDIANTES] = {0.0};

    // Entrada de datos
    cout << "Ingrese las calificaciones de los estudiantes:" << endl;
    for (int estudiante = 0; estudiante < NUM_ESTUDIANTES; estudiante++) {
        double suma = 0.0;
        for (int examen = 0; examen < NUM_EXAMENES; examen++) {
            cout << "Estudiante " << estudiante + 1 << ", Examen " << examen + 1 << ": ";
            cin >> calificaciones[estudiante][examen];
            suma += calificaciones[estudiante][examen];
        }
        promedios[estudiante] = suma / NUM_EXAMENES;
    }
    
    // Salida de resultados
    cout << "\nPromedio de calificaciones por estudiante:" << endl;
    cout << fixed << setprecision(2);
    for (int estudiante = 0; estudiante < NUM_ESTUDIANTES; estudiante++) {
        cout << "Estudiante " << estudiante + 1 << ": " << promedios[estudiante] << endl;
    }
    
    return 0;
}