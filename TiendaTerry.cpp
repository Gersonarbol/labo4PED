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
// Funcion insertar al inicio 
void insertarInicio(int id, string dest, float peso) {
    if (buscarPorId(id)) {
        cout << "Error: El ID ya existe." << endl;
        return;
    }
    Paquete* nuevo = new Paquete{id, dest, peso, head, NULL};
    if (head != NULL) head->ant = nuevo;
    head = nuevo;
    if (tail == NULL) tail = nuevo; 
    cout << "Paquete insertado al inicio." << endl;
}

// Funcion insertar al final 
void insertarFinal(int id, string dest, float peso) {
    if (buscarPorId(id)) {
        cout << "Error: El ID ya existe." << endl;
        return;
    }
    Paquete* nuevo = new Paquete{id, dest, peso, NULL, tail};
    if (tail != NULL) tail->sig = nuevo;
    tail = nuevo;
    if (head == NULL) head = nuevo;
    cout << "Paquete insertado al final." << endl;
}