#include <iostream>
#include <string>

using namespace std;

// Estructura del Nodo para el Paquete 
struct Paquete {
    int id;
    string destinatario;
    float peso;
    Paquete* sig;
    Paquete* ant;
};

// Punteros para manejar la lista
Paquete* head = NULL;
Paquete* tail = NULL;

// Buscar paquete por id 
Paquete* buscarPorId(int id) {
    Paquete* aux = head;
    while (aux != NULL) {
        if (aux->id == id) return aux;
        aux = aux->sig;
    }
    return NULL;
}