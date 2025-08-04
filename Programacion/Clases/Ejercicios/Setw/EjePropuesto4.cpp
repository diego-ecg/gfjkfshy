/*Desafío Práctico Propuesto.
Almacenamiento de Puntos 2D
Escribe un programa en C++ que permita almacenar las coordenadas (x, y) de un máximo de 8 puntos en un plano bidimensional. 
Define una estructura llamada Punto con dos miembros de tipo entero para las coordenadas x e y. 
Utiliza un arreglo estático de esta estructura. 
El programa debe solicitar al usuario las coordenadas de cada punto mediante un bucle do-while que continúe hasta que se hayan
ingresado los 8 puntos o el usuario decida detenerse. Finalmente, muestra en la consola las coordenadas de cada punto registrado,
formateando la salida para que la coordenada x ocupe un campo de 5 caracteres a la izquierda y la coordenada y un campo de 5 caracteres a la derecha,
utilizando setw().*/

#include <iostream>
#include <iomanip> // Necesario para setw()
#include <limits> // Necesario para numeric_limits

using namespace std;

// Definición de la estructura Punto
struct Punto {
    int x;
    int y;
};

int main() {
    const int MAX_PUNTOS = 8;
    Punto puntos[MAX_PUNTOS];
    int numPuntos = 0;
    char continuar;

    cout << "Registro de Puntos 2D (maximo " << MAX_PUNTOS << ")" << endl;

    do {
        cout << "Ingrese la coordenada X del punto " << numPuntos + 1 << ": ";
        cin >> puntos[numPuntos].x;

        cout << "Ingrese la coordenada Y del punto " << numPuntos + 1 << ": ";
        cin >> puntos[numPuntos].y;
        
        // Limpiar el buffer de entrada
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        numPuntos++;

        if (numPuntos < MAX_PUNTOS) {
            cout << "Desea ingresar otro punto? (s/n): ";
            cin >> continuar;
            // Limpiar el buffer de entrada
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            continuar = 'n';
        }

    } while (continuar == 's' || continuar == 'S' && numPuntos < MAX_PUNTOS);

    cout << endl << "Coordenadas de los Puntos Registrados:" << endl;
    cout << left << setw(5) << "X" << right << setw(5) << "Y" << endl;
    cout << setfill('-') << setw(10) << "" << setfill(' ') << endl;
    
    for (int i = 0; i < numPuntos; i++) {
        cout << left << setw(5) << puntos[i].x << right << setw(5) << puntos[i].y << endl;
    }

    return 0;
}