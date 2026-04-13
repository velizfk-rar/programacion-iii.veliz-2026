#include <iostream>
using namespace std;


struct Nodo {
    int dato;
    Nodo* siguiente;
};


Nodo* pila = NULL;

void push(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = pila;
    pila = nuevo;
}

void pop() {
    if (pila == NULL) {
        cout << "⚠️ Pila vacía\n";
        return;
    }
    Nodo* temp = pila;
    pila = pila->siguiente;
    delete temp;
}

void peekPila() {
    if (pila == NULL) {
        cout << "⚠️ Pila vacía\n";
    } else {
        cout << "Tope de la pila: " << pila->dato << endl;
    }
}

void mostrarPila() {
    Nodo* temp = pila;
    cout << "Pila (impares): ";
    while (temp != NULL) {
        cout << temp->dato << " -> ";
        temp = temp->siguiente;
    }
    cout << "NULL\n";
}

// ====== COLA ======
Nodo* frente = NULL;
Nodo* fin = NULL;

void enqueue(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (fin == NULL) {
        frente = fin = nuevo;
    } else {
        fin->siguiente = nuevo;
        fin = nuevo;
    }
}

void dequeue() {
    if (frente == NULL) {
        cout << "⚠️ Cola vacía\n";
        return;
    }
    Nodo* temp = frente;
    frente = frente->siguiente;

    if (frente == NULL)
        fin = NULL;

    delete temp;
}

void peekCola() {
    if (frente == NULL) {
        cout << "⚠️ Cola vacía\n";
    } else {
        cout << "Frente de la cola: " << frente->dato << endl;
    }
}

void mostrarCola() {
    Nodo* temp = frente;
    cout << "Cola (pares): ";
    while (temp != NULL) {
        cout << temp->dato << " -> ";
        temp = temp->siguiente;
    }
    cout << "NULL\n";
}

// ====== LISTA ENLAZADA ======
Nodo* lista = NULL;

void insertarLista(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = lista;
    lista = nuevo;
}

void mostrarLista() {
    Nodo* temp = lista;
    cout << "Lista (negativos): ";
    while (temp != NULL) {
        cout << temp->dato << " -> ";
        temp = temp->siguiente;
    }
    cout << "NULL\n";
}

// ====== ORDENAR LISTA (BONUS) ======
void ordenarLista() {
    if (lista == NULL) return;

    Nodo* i;
    Nodo* j;
    int temp;

    for (i = lista; i != NULL; i = i->siguiente) {
        for (j = i->siguiente; j != NULL; j = j->siguiente) {
            if (i->dato > j->dato) {
                temp = i->dato;
                i->dato = j->dato;
                j->dato = temp;
            }
        }
    }
}

// ====== LIMPIAR MEMORIA ======
void liberarMemoria() {
    while (pila != NULL) pop();
    while (frente != NULL) dequeue();

    Nodo* temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->siguiente;
        delete temp;
    }
}

// ====== MAIN ======
int main() {
    int opcion, num;

    int pares = 0, impares = 0;

    cout << "Jose Daniel Veliz Velasquez\n 9941-24-12576\n";

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Ingresar numero\n";
        cout << "2. Mostrar pila\n";
        cout << "3. Mostrar cola\n";
        cout << "4. Mostrar lista\n";
        cout << "5. Eliminar de pila\n";
        cout << "6. Eliminar de cola\n";
        cout << "7. Ver tope pila\n";
        cout << "8. Ver frente cola\n";
        cout << "9. Estadisticas\n";
        cout << "10. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada inválida\n";
            continue;
        }

        switch (opcion) {
            case 1:
                cout << "Ingrese número (-1 para terminar): ";
                cin >> num;

                if (num == -1) break;

                if (num < 0) {
                    insertarLista(num);
                } else if (num % 2 == 0) {
                    enqueue(num);
                    pares++;
                } else {
                    push(num);
                    impares++;
                }
                break;

            case 2:
                mostrarPila();
                break;

            case 3:
                mostrarCola();
                break;

            case 4:
                ordenarLista(); 
                mostrarLista();
                break;

            case 5:
                pop();
                break;

            case 6:
                dequeue();
                break;

            case 7:
                peekPila();
                break;

            case 8:
                peekCola();
                break;

            case 9:
                cout << "Pares: " << pares << endl;
                cout << "Impares: " << impares << endl;
                break;

            case 10:
                liberarMemoria();
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opción inválida\n";
        }

    } while (opcion != 10);

    return 0;
}
