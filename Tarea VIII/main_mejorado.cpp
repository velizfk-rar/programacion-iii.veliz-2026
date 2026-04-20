#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

void insertarInicio(Nodo*& head, Nodo*& tail, int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = head;
    nuevo->anterior = NULL;

    if (head == NULL) {
        head = tail = nuevo;
    } else {
        head->anterior = nuevo;
        head = nuevo;
    }
}

void insertarFinal(Nodo*& head, Nodo*& tail, int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    nuevo->anterior = tail;

    if (head == NULL) {
        head = tail = nuevo;
    } else {
        tail->siguiente = nuevo;
        tail = nuevo;
    }
}

void mostrarAdelante(Nodo* head) {
    if (head == NULL) {
        cout << "Lista vacia\n";
        return;
    }

    Nodo* temp = head;
    cout << "\nLista hacia adelante: ";
    while (temp != NULL) {
        cout << temp->dato << " <-> ";
        temp = temp->siguiente;
    }
    cout << "NULL\n";
}

void mostrarAtras(Nodo* tail) {
    if (tail == NULL) {
        cout << "Lista vacia\n";
        return;
    }

    Nodo* temp = tail;
    cout << "\nLista hacia atras: ";
    while (temp != NULL) {
        cout << temp->dato << " <-> ";
        temp = temp->anterior;
    }
    cout << "NULL\n";
}

bool buscar(Nodo* head, int valor) {
    Nodo* temp = head;

    while (temp != NULL) {
        if (temp->dato == valor) {
            return true;
        }
        temp = temp->siguiente;
    }

    return false;
}

void eliminar(Nodo*& head, Nodo*& tail, int valor) {
    if (head == NULL) {
        cout << "La lista esta vacia.\n";
        return;
    }

    Nodo* actual = head;

    while (actual != NULL && actual->dato != valor) {
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        cout << "Dato no encontrado.\n";
        return;
    }

    // Si solo hay un nodo
    if (head == tail && actual == head) {
        head = NULL;
        tail = NULL;
        delete actual;
        cout << "Nodo eliminado correctamente.\n";
        return;
    }

    // Si se elimina el primero
    if (actual == head) {
        head = head->siguiente;
        head->anterior = NULL;
        delete actual;
        cout << "Nodo eliminado correctamente.\n";
        return;
    }

    // Si se elimina el ultimo
    if (actual == tail) {
        tail = tail->anterior;
        tail->siguiente = NULL;
        delete actual;
        cout << "Nodo eliminado correctamente.\n";
        return;
    }

    // Si se elimina uno en medio
    actual->anterior->siguiente = actual->siguiente;
    actual->siguiente->anterior = actual->anterior;

    delete actual;
    cout << "Nodo eliminado correctamente.\n";
}

int contarNodos(Nodo* head) {
    int contador = 0;
    Nodo* temp = head;

    while (temp != NULL) {
        contador++;
        temp = temp->siguiente;
    }

    return contador;
}

void liberarLista(Nodo*& head, Nodo*& tail) {
    Nodo* temp = head;

    while (temp != NULL) {
        Nodo* aux = temp;
        temp = temp->siguiente;
        delete aux;
    }

    head = NULL;
    tail = NULL;
}

int main() {
    Nodo* head = NULL;
    Nodo* tail = NULL;
    int opcion, valor;

    cout << "Jose Daniel Veliz Velasquez\n9941-24-12576\nVersion con tail";

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insertar al inicio\n";
        cout << "2. Insertar al final\n";
        cout << "3. Mostrar hacia adelante\n";
        cout << "4. Mostrar hacia atras\n";
        cout << "5. Buscar dato\n";
        cout << "6. Eliminar dato\n";
        cout << "7. Contar nodos\n";
        cout << "8. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese valor: ";
                cin >> valor;
                insertarInicio(head, tail, valor);
                cout << "Dato insertado al inicio.\n";
                break;

            case 2:
                cout << "Ingrese valor: ";
                cin >> valor;
                insertarFinal(head, tail, valor);
                cout << "Dato insertado al final.\n";
                break;

            case 3:
                mostrarAdelante(head);
                break;

            case 4:
                mostrarAtras(tail);
                break;

            case 5:
                cout << "Ingrese valor a buscar: ";
                cin >> valor;
                if (buscar(head, valor)) {
                    cout << "El valor SI existe en la lista.\n";
                } else {
                    cout << "El valor NO existe en la lista.\n";
                }
                break;

            case 6:
                cout << "Ingrese valor a eliminar: ";
                cin >> valor;
                eliminar(head, tail, valor);
                break;

            case 7:
                cout << "Total de nodos: " << contarNodos(head) << endl;
                break;

            case 8:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion invalida.\n";
        }

    } while (opcion != 8);

    liberarLista(head, tail);

    return 0;
}
