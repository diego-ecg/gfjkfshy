#include<iostream>
#include<vector>
#include<string>

// Estrucutra para presentar a un empleado 
struct Empleado{
	int id;
	std::string nombre;
	std::string apellido;
	double salario;
	std::string departamento; 
};

//  Procedimientos( funciones void ) 

// Procedimiento para iniciar una lista de empleados
void inicializarEmpleados(std::vector<Empleado>&empleados){
	empleados.clear(); // limpiar cualquier dato existente
	std::cout<<"Lista de empleados inicializada vacia. "<<std::endl;
}

//Procedimiento para mostrar los detalles de un solo empleado 
void mostrarEmpleado(const Empleado&emp){
	std::cout<<"ID :"<<emp.id
	<<", Nombre :"<<emp.nombre
	<<", Apellido :"<<emp.apellido
	<<", Salario :"<<emp.salario
	<<", Departamento :"<<emp.departamento<<std::endl;
}

//Procedimiento para listar todos los empleados 
void listarEmpleados(const std::vector<Empleado>&empleados){
	if(empleados.empty()){
		std::cout<<"No hay Empleados registrados. "<<std::endl;
		return;
	}
	std::cout<<"\n---Lista de Empleados ---"<< std::endl;
	for(size_t i = 0; i<empleados.size(); ++i){
		mostrarEmpleado(empleados[i]);
	}
	std::cout<<"---------------------------" <<std::endl;
}

//Funciones(retornar un valor)---

//funcion parar buscar un empleado por id (declarada antes para que agregarEmpleado pueda usarla)
//Retorna el indice del empleado en el vector, o -1 si no se encuentra
int buscarEmpleadoPorld(const std::vector<Empleado>&empleados, int idBuscado){
	for(size_t i = 0; i<empleados.size(); ++i){
		if(empleados[i].id == idBuscado){
			return static_cast<int>(i); // Retornar el indice si lo encuentra 
		}
	}
	return -1; //Retorna -1 si no lo encuentra 
}

//Funciones para agregar un nuevo empleado
// Retornar true si el empleado fue agregado exitosamente, false en caso contrario
bool agregarEmpleado(std::vector<Empleado>&empleados, int id, const std::string& nombre, const std::string& apellido, double salario, const std::string& departamento){
	//Verificar si el Id ya existe usando la funcion buscarEmpleadoPorld
	if(buscarEmpleadoPorld(empleados, id)!= -1){
		std::cout<<"Error: Ya Existe un empleado con el ID "<< id << std::endl;
		return false;
	}
	Empleado nuevoEmpleado;
	nuevoEmpleado.id = id;
	nuevoEmpleado.nombre = nombre;
	nuevoEmpleado.apellido = apellido;
	nuevoEmpleado.salario = salario;
	nuevoEmpleado.departamento = departamento;
	
	empleados.push_back(nuevoEmpleado);
	std::cout<<"Empleado"<<nombre<<""<<apellido<< "agregado exitosamente."<<std::endl;
	return true;
}
