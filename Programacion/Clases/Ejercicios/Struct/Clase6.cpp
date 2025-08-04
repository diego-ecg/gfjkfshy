#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <limits>

using namespace std;

// Definición de la estructura Fecha
struct Fecha {
    int dia;
    int mes;
    int anio;
};

// Definición de la estructura DatosPers
struct DatosPers {
    string priNombre;
    string secNombre;
    string priApellido;
    string secApellido;
    int edad;
    Fecha fecNac;
    string direccion;
    string telefono;
};

// Definición de la estructura Estudiante
struct Estudiante {
    DatosPers datos;
    Fecha fecInscrip;
    string nroExpediente;
    string especialidad;
};

int main() {
    const int NUM_ESTUDIANTES = 50;
    Estudiante estudiantes[NUM_ESTUDIANTES];

    // Especialidades disponibles
    vector<string> especialidades = {"Ingenieria de Sistemas", "Ingenieria Civil", "Medicina", "Derecho", "Administracion"};
    Fecha fechaInscripcion = {1, 9, 2024};

    cout << "--- Ingrese los datos de " << NUM_ESTUDIANTES << " estudiantes ---" << endl;

    // Cargar los registros de los estudiantes con datos ingresados por el usuario
    for (int i = 0; i < NUM_ESTUDIANTES; ++i) {
        cout << "\nEstudiante " << i + 1 << ":" << endl;
        
        cout << "  Primer Nombre: ";
        getline(cin, estudiantes[i].datos.priNombre);

        cout << "  Segundo Nombre: ";
        getline(cin, estudiantes[i].datos.secNombre);

        cout << "  Primer Apellido: ";
        getline(cin, estudiantes[i].datos.priApellido);

        cout << "  Segundo Apellido: ";
        getline(cin, estudiantes[i].datos.secApellido);

        cout << "  Edad: ";
        cin >> estudiantes[i].datos.edad;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer

        cout << "  Fecha de Nacimiento (dd mm aaaa): ";
        cin >> estudiantes[i].datos.fecNac.dia >> estudiantes[i].datos.fecNac.mes >> estudiantes[i].datos.fecNac.anio;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer

        cout << "  Direccion: ";
        getline(cin, estudiantes[i].datos.direccion);

        cout << "  Telefono: ";
        getline(cin, estudiantes[i].datos.telefono);
        
        cout << "  Especialidades disponibles: " << endl;
        for (int j = 0; j < especialidades.size(); ++j) {
            cout << "    " << j + 1 << ". " << especialidades[j] << endl;
        }
        cout << "  Ingrese el numero de la especialidad: ";
        int especialidadIndice;
        cin >> especialidadIndice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
        if (especialidadIndice > 0 && especialidadIndice <= especialidades.size()) {
            estudiantes[i].especialidad = especialidades[especialidadIndice - 1];
        } else {
            estudiantes[i].especialidad = "No especificada";
        }
        
        // Datos automáticos
        estudiantes[i].fecInscrip = fechaInscripcion;
        estudiantes[i].nroExpediente = "EXP-" + to_string(1000 + i);
    }

    cout << "\n--- Datos de los 50 Estudiantes ---" << endl;
    for (int i = 0; i < NUM_ESTUDIANTES; ++i) {
        cout << "\nEstudiante " << i + 1 << ":" << endl;
        cout << "  Nro. de Expediente: " << estudiantes[i].nroExpediente << endl;
        cout << "  Nombre Completo: " << estudiantes[i].datos.priNombre << " " << estudiantes[i].datos.secNombre << " " << estudiantes[i].datos.priApellido << " " << estudiantes[i].datos.secApellido << endl;
        cout << "  Edad: " << estudiantes[i].datos.edad << " anios" << endl;
        cout << "  Fecha de Nacimiento: " << estudiantes[i].datos.fecNac.dia << "/" << estudiantes[i].datos.fecNac.mes << "/" << estudiantes[i].datos.fecNac.anio << endl;
        cout << "  Dirección: " << estudiantes[i].datos.direccion << endl;
        cout << "  Teléfono: " << estudiantes[i].datos.telefono << endl;
        cout << "  Fecha de Inscripción: " << estudiantes[i].fecInscrip.dia << "/" << estudiantes[i].fecInscrip.mes << "/" << estudiantes[i].fecInscrip.anio << endl;
        cout << "  Especialidad: " << estudiantes[i].especialidad << endl;
    }

    // Encontrar la especialidad con mayor cantidad de estudiantes
    string especialidadMasPopular;
    int maxEstudiantes = 0;
    
    for (int i = 0; i < especialidades.size(); ++i) {
        int contador = 0;
        for (int j = 0; j < NUM_ESTUDIANTES; ++j) {
            if (estudiantes[j].especialidad == especialidades[i]) {
                contador++;
            }
        }
        if (contador > maxEstudiantes) {
            maxEstudiantes = contador;
            especialidadMasPopular = especialidades[i];
        }
    }

    // Encontrar el estudiante con menos edad
    int minEdad = estudiantes[0].datos.edad;
    int indiceEstudianteMenor = 0;
    for (int i = 1; i < NUM_ESTUDIANTES; ++i) {
        if (estudiantes[i].datos.edad < minEdad) {
            minEdad = estudiantes[i].datos.edad;
            indiceEstudianteMenor = i;
        }
    }
    
    cout << "\n--- Resumen de Datos ---" << endl;
    cout << "Especialidad con mayor cantidad de estudiantes: " << especialidadMasPopular << " con " << maxEstudiantes << " estudiantes." << endl;
    cout << "Estudiante con menos edad: " << estudiantes[indiceEstudianteMenor].datos.priNombre << " " << estudiantes[indiceEstudianteMenor].datos.priApellido << " con " << minEdad << " anios." << endl;

    return 0;
}