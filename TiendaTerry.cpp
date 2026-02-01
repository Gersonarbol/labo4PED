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

// Funcion mostrar lista adelante 
void mostrarAdelante() {
    if (head == NULL) { cout << "Lista vacia." << endl; return; }
    Paquete* aux = head;
    while (aux != NULL) {
        cout << "[" << aux->id << " | " << aux->destinatario << "] <-> ";
        aux = aux->sig;
    }
    cout << "NULL\n";
}

// Funcion mostrar lista atras
void mostrarAtras() {
    if (tail == NULL) { 
        cout << "La lista de Terry esta vacia. No hay paquetes que mostrar." << endl;
        return;
    }

    Paquete* aux = tail;
    cout << "NULL <- ";
    while (aux != NULL) {
        cout << "[" << aux->id << " | " << aux->destinatario << "]";
        if (aux->ant != NULL) cout << " <-> ";
        aux = aux->ant; 
    }
    cout << " <- HEAD" << endl;
}

// Funcion mostrar cantidad 
void mostrarCantidad() {
    int contador = 0;
    Paquete* aux = head;
    while (aux != NULL) {
        contador++;
        aux = aux->sig;
    }
    cout << "Total de paquetes: " << contador << endl;
}

// Funcion eliminar paquete por id
void eliminarPorId(int id) {
    Paquete* act = buscarPorId(id);
    if (!act) { cout << "ID no encontrado." << endl; return; }

    if (act == head) {
        head = head->sig;
        if (head) head->ant = NULL;
        else tail = NULL;
    } else if (act == tail) {
        tail = tail->ant;
        if (tail) tail->sig = NULL;
    } else {
        act->ant->sig = act->sig;
        act->sig->ant = act->ant;
    }
    delete act;
    cout << "Paquete eliminado." << endl;
}

// Funcion para liberar memoria al salir 
void liberarLista() {
    Paquete* aux = head;
    while (aux != NULL) {
        Paquete* borrar = aux;
        aux = aux->sig;
        delete borrar;
    }
    head = tail = NULL;
}

//Funcion para editar (OPCION EXTRA B)
void editarPaquete(int id) {
    Paquete* p = buscarPorId(id);
    if (p) {
        cout << "Nuevo destinatario: "; cin.ignore(); getline(cin, p->destinatario);
        cout << "Nuevo peso: "; cin >> p->peso;
        cout << "Paquete actualizado." << endl;
    } else {
        cout << "Paquete no encontrado." << endl;
    }
}

int main() {
    int opcion, id;
    string dest;
    float peso;

    do {
        cout << "SISTEMA DE TIENDA DE TERRY" << endl;
        cout << "1) Insertar paquete al final" << endl; 
        cout << "2) Insertar paquete al inicio" << endl; 
        cout << "3) Mostrar lista adelante" << endl;  
        cout << "4) Mostrar lista atras" << endl;  
        cout << "5) Buscar paquete por ID" << endl;  
        cout << "6) Eliminar paquete por ID" << endl; 
        cout << "7) Mostrar cantidad total de paquetes" << endl;  
        cout << "8) Editar paquete " << endl; 
        cout << "0) Salir y liberar memoria" << endl; 
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Ingrese ID: "; cin >> id;
                cout << "Destinatario: "; cin.ignore(); getline(cin, dest);
                cout << "Peso: "; cin >> peso;
                insertarFinal(id, dest, peso); 
                break;

            case 2:
                cout << "Ingrese ID: "; cin >> id;
                cout << "Destinatario: "; cin.ignore(); getline(cin, dest);
                cout << "Peso: "; cin >> peso;
                insertarInicio(id, dest, peso);
                break;

            case 3:
                cout << "\nLista hacia adelante " << endl;
                mostrarAdelante(); 
                break;

            case 4:
                cout << "\nLista hacia atras " << endl;
                mostrarAtras(); 
                break;

            case 5:
                cout << "Ingrese ID para buscar: "; cin >> id;
                if (buscarPorId(id)) {
                    Paquete* p = buscarPorId(id);
                    cout << "Paquete encontrado: " << p->destinatario << " (" << p->peso << "kg)" << endl;
                } else {
                    cout << "Paquete no existe." << endl;
                }
                break;

            case 6:
                cout << "Ingrese ID para eliminar: "; cin >> id;
                eliminarPorId(id); 
                break;

            case 7:
                mostrarCantidad(); 
                break;

            case 8:
                cout << "Ingrese ID del paquete que quiere editar: "; cin >> id;
                editarPaquete(id);
                break;

            case 0:
                cout << "Liberando memoria y saliendo..." << endl;
                liberarLista(); 
                break;

            default:
                cout << "Opcion no valida." << endl;
        }
    } while (opcion != 0);

    return 0;
}