#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Estructura para representar un pedido
struct Pedido {
    int id;
    string cliente;
    string items;
};

int main() {
    queue<Pedido> pedidosPendientes;
    queue<Pedido> pedidosListos;
    int contadorPedidos = 100; // Iniciar con el pedido #100

    // Simulación de la recepción de pedidos
    cout << "--- Restaurante de Comida Rápida ---" << endl;

    // Pedido de Laura
    Pedido p1 = {contadorPedidos++, "Laura", "Hamburguesa, Papas Fritas..."};
    pedidosPendientes.push(p1);
    cout << "Pedido #" << p1.id << " de " << p1.cliente << " recibido." << endl;

    // Pedido de Diego
    Pedido p2 = {contadorPedidos++, "Diego", "Pizza Pequena, Refresco..."};
    pedidosPendientes.push(p2);
    cout << "Pedido #" << p2.id << " de " << p2.cliente << " recibido." << endl;

    // Simulación del proceso de cocinado
    if (!pedidosPendientes.empty()) {
        Pedido cocinando = pedidosPendientes.front();
        cout << "Cocinando pedido #" << cocinando.id << " para " << cocinando.cliente << ". Items: " << cocinando.items << endl;
        pedidosListos.push(cocinando);
        pedidosPendientes.pop();
        cout << "Pedido #" << cocinando.id << " listo para entregar!" << endl;
    }

    // Pedido de Sofia
    Pedido p3 = {contadorPedidos++, "Sofia", "Ensalada Cesar..."};
    pedidosPendientes.push(p3);
    cout << "Pedido #" << p3.id << " de " << p3.cliente << " recibido." << endl;

    // Simulación del proceso de cocinado (segundo pedido)
    if (!pedidosPendientes.empty()) {
        Pedido cocinando = pedidosPendientes.front();
        cout << "Cocinando pedido #" << cocinando.id << " para " << cocinando.cliente << ". Items: " << cocinando.items << endl;
        pedidosListos.push(cocinando);
        pedidosPendientes.pop();
        cout << "Pedido #" << cocinando.id << " listo para entregar!" << endl;
    }

    // Simulación de la entrega de pedidos
    cout << "--- Entregando Pedidos ---" << endl;
    while (!pedidosListos.empty()) {
        Pedido entregando = pedidosListos.front();
        cout << "Entregando pedido #" << entregando.id << " a " << entregando.cliente << "." << endl;
        pedidosListos.pop();
    }
    
    // Simulación del proceso de cocinado (tercer pedido)
    if (!pedidosPendientes.empty()) {
        Pedido cocinando = pedidosPendientes.front();
        cout << "Cocinando pedido #" << cocinando.id << " para " << cocinando.cliente << ". Items: " << cocinando.items << endl;
        pedidosListos.push(cocinando);
        pedidosPendientes.pop();
        cout << "Pedido #" << cocinando.id << " listo para entregar!" << endl;
    }
    
    // Simulación de la entrega del último pedido
    if (!pedidosListos.empty()) {
        Pedido entregando = pedidosListos.front();
        cout << "Entregando pedido #" << entregando.id << " a " << entregando.cliente << "." << endl;
        pedidosListos.pop();
    }
    
    // Verificar si hay pedidos pendientes o listos
    if (pedidosListos.empty() && pedidosPendientes.empty()) {
        cout << "No hay pedidos listos para entregar." << endl;
    }

    return 0;
}