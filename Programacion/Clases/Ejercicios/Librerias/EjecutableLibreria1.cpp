#include <iostream> 
#include <vector> 
#include <string> // Necesario si se usan strings directamente aquí 
#include <limits> // Para std::numeric_limits

// Incluir el archivo de la librería directamente
#include "Libreria1.cpp"

// Función auxiliar para limpiar el buffer de entrada
void limpiarBufferEntrada() { 
 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}

int main() { 
std::vector<Empleado> misEmpleados; // Vector para almacenar a los empleados 
inicializarEmpleados(misEmpleados); 
// Agregando algunos empleados 
std::cout << "\n--- Agregando empleados ---" << std::endl; 
agregarEmpleado(misEmpleados, 101, "Ana", "Gomez", 35000.0, "Ventas"); 
agregarEmpleado(misEmpleados, 102, "Luis", "Perez", 42000.0, "Marketing"); 
agregarEmpleado(misEmpleados, 103, "Maria", "Lopez", 50000.0, "Recursos Humanos"); 
agregarEmpleado(misEmpleados, 101, "Pedro", "Diaz", 30000.0, "IT"); // Intento de agregar ID duplicado 


// Listar todos los empleados 
listarEmpleados(misEmpleados);

// Buscar un empleado por ID 
std::cout << "\n--- Buscando empleado por ID ---" << std::endl; 
int idABuscar = 102; 
int indiceEncontrado = buscarEmpleadoPorld(misEmpleados, idABuscar); 
if (indiceEncontrado != -1) { 
    std::cout << "Empleado con ID " << idABuscar << " encontrado: "; 
	mostrarEmpleado(misEmpleados[indiceEncontrado]); 
	} else { 
	std::cout << "Empleado con ID " << idABuscar << " no encontrado." << std::endl;
	} 
		
	idABuscar = 999; // ID que no existe 
	indiceEncontrado = buscarEmpleadoPorld(misEmpleados, idABuscar); 
if (indiceEncontrado != -1) { 
	std::cout << "Empleado con ID " << idABuscar << " encontrado: "; 
	mostrarEmpleado(misEmpleados[indiceEncontrado]); 
	} else { 
	std::cout << "Empleado con ID " << idABuscar << " no encontrado." << std::endl; } 

// Ejemplo de interacción con el usuario 
std::cout << "\n--- Interaccion con el usuario ---" << std::endl; 
int nuevoId; 
std::string nuevoNombre, nuevoApellido, nuevoDepartamento;

double nuevoSalario;

std::cout << "Ingrese ID del nuevo empleado: "; 
std::cin >> nuevoId; 
limpiarBufferEntrada(); // Limpiar el buffer después de leer int 

std::cout << "Ingrese Nombre del nuevo empleado: "; 
std::getline(std::cin, nuevoNombre); 

std::cout << "Ingrese Apellido del nuevo empleado: "; 
std::getline(std::cin, nuevoApellido); 

std::cout << "Ingrese Salario del nuevo empleado: "; 
std::cin >> nuevoSalario; limpiarBufferEntrada(); // Limpiar el buffer después de leer double 

std::cout << "Ingrese Departamento del nuevo empleado: "; 
std::getline(std::cin, nuevoDepartamento); 

agregarEmpleado(misEmpleados, nuevoId, nuevoNombre, nuevoApellido, nuevoSalario, nuevoDepartamento); 

listarEmpleados(misEmpleados); // Listar nuevamente para ver el nuevo empleado 
return 0; 
}




















