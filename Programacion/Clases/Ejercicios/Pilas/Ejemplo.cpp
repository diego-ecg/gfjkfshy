#include <iostream>
#include <stack>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

// Función auxiliar para obtener la hora actual
string obtenerHoraActual() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%H:%M:%S", ltm);
    return string(buffer);
}

// Pila global para almacenar los registros de entrada
stack<string> visitantesRecientes;

// Función para registrar la entrada de un nuevo visitante
void registrarEntrada(const string& nombreVisitante) {
    string registro = "Entrada de " + nombreVisitante + " a las " + obtenerHoraActual();
    visitantesRecientes.push(registro);
    cout << "Registrado: " << registro << endl;
}

// Función para ver el último visitante sin eliminarlo
void verUltimoVisitante() {
    if (!visitantesRecientes.empty()) {
        cout << "Ultimo registro de entrada: " << visitantesRecientes.top() << endl;
    } else {
        cout << "No hay registros de visitas recientes." << endl;
    }
}

// Función para despachar al último visitante
void despacharUltimoVisitante() {
    if (!visitantesRecientes.empty()) {
        string registroDespachado = visitantesRecientes.top();
        visitantesRecientes.pop();
        cout << "Despachado: " << registroDespachado << endl;
    } else {
        cout << "No hay visitantes para despachar." << endl;
    }
}

int main() {
    cout << "--- Ejercicio 1: Registro de Visitas Recientes (Sin Clases) ---" << endl;

    // Registramos algunos entradas de visitantes.
    registrarEntrada("Juan Perez");
    registrarEntrada("Maria Lopez");
    registrarEntrada("Carlos Garcia");

    cout << "\n--- Verificando y Despachando ---" << endl;
    
    // Verificamos quién fue el último en entrar.
    verUltimoVisitante();
    
    // Despachamos al último.
    despacharUltimoVisitante();
    
    // Verificamos quién es el nuevo último (Maria Lopez).
    verUltimoVisitante();
    
    // Despachamos el siguiente.
    despacharUltimoVisitante();
    
    // Intentamos despachar cuando la pila está vacía.
    despacharUltimoVisitante();
    
    // Intentamos ver al último cuando la pila está vacía.
    verUltimoVisitante();

    cout << "\n-----------------------------------" << endl;
    
    return 0;
}