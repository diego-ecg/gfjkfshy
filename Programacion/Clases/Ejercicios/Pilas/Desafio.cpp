#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Estructura para representar una página
struct Pagina {
    string id;
    string url;
};

// Pila global para almacenar el historial de páginas visitadas
stack<Pagina> paginasVisitadas;

// Función para simular la visita a una página
void visitarPagina(const Pagina& paginaActual) {
    cout << "Visitando: " << paginaActual.url << endl;
    paginasVisitadas.push(paginaActual);
}

// Función para retroceder a la página anterior
void retroceder() {
    if (!paginasVisitadas.empty()) {
        paginasVisitadas.pop(); // Sacar la página actual
        if (!paginasVisitadas.empty()) {
            Pagina paginaAnterior = paginasVisitadas.top();
            cout << "Retrocediendo a: " << paginaAnterior.url << endl;
        } else {
            cout << "Retrocediendo a: Inicio" << endl;
        }
    } else {
        cout << "No hay mas historial de navegacion." << endl;
    }
}

int main() {
    cout << "--- Control de Navegacion (Paginas Visitadas) ---" << endl;

    // Simulación de la navegación
    visitarPagina({ "dash", "/dashboard" });
    visitarPagina({ "list", "/productos/lista" });
    visitarPagina({ "detail", "/productos/detalle/101" });

    cout << "\nRealizando retrocesos:" << endl;
    retroceder();
    retroceder();
    retroceder(); // Retrocede al "Inicio"
    retroceder(); // Pila vacía
    
    return 0;
}