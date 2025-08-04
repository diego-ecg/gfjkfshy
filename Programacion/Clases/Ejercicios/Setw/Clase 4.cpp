#include <iostream>
#include <string>
#include <iomanip> // Necesario para setw()
#include <limits> // Necesario para numeric_limits

using namespace std;

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[51]; // Hasta 50 caracteres + null terminador
    float promedio;
};

int main() {
    const int MAX_ESTUDIANTES = 5;
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int numEstudiantes = 0;
    char continuar;

    cout << "Registro de Estudiantes (maximo " << MAX_ESTUDIANTES << ")"<<endl;
    do {
        cout << "Ingrese el nombre del estudiante " << numEstudiantes + 1 << ": ";
        cin.getline(estudiantes[numEstudiantes].nombre, 51);

        cout << "Ingrese el promedio academico de " << estudiantes[numEstudiantes].nombre << ": ";
        cin >> estudiantes[numEstudiantes].promedio;
        
        // Limpiar el buffer de entrada en caso de que haya caracteres extra o la tecla Enter
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        numEstudiantes++;

        if (numEstudiantes < MAX_ESTUDIANTES) {
            cout << "Desea ingresar otro estudiante? (s/n): ";
            cin >> continuar;
            // Limpiar el buffer de entrada después de leer el caracter de continuación
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            continuar = 'n'; // No preguntar si ya se alcanzó el máximo
        }
    } while (continuar == 's' || continuar == 'S' && numEstudiantes < MAX_ESTUDIANTES);

    cout << endl << "Informacion de los Estudiantes Registrados:" << endl;
    cout << left << setw(20) << "Nombre" << right << setw(10) << "Promedio" << endl;
    cout << setfill('-') << setw(30) << "" << setfill(' ') << endl; // Línea separadora
    
    for (int i = 0; i < numEstudiantes; i++) {
        cout << left << setw(20) << estudiantes[i].nombre << right << setw(10) << fixed << setprecision(2) << estudiantes[i].promedio << endl;
    }
    
    return 0;
}