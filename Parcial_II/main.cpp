#include <iostream>
using namespace std;


struct NodoSimple {
    int valor;
    NodoSimple* sig;
};

struct NodoDoble {
    int valor;
    string tipo;
    int orden;
    NodoDoble* ant;
    NodoDoble* sig;
};

struct NodoBST {
    int valor;
    NodoBST* izq;
    NodoBST* der;
};


NodoSimple* pila = NULL;
NodoSimple* frente = NULL;
NodoSimple* finCola = NULL;
NodoSimple* negativos = NULL;

NodoDoble* historialInicio = NULL;
NodoDoble* historialFin = NULL;

NodoBST* raiz = NULL;

int pares = 0, impares = 0, negativosCant = 0, ceros = 0;
int validos = 0, ordenIngreso = 0;
int mayorValor, menorValor;
bool hayValores = false;


void insertarPila(int valor) {
    NodoSimple* nuevo = new NodoSimple{valor, pila};
    pila = nuevo;
}

void insertarCola(int valor) {
    NodoSimple* nuevo = new NodoSimple{valor, NULL};

    if (frente == NULL) {
        frente = nuevo;
        finCola = nuevo;
    } else {
        finCola->sig = nuevo;
        finCola = nuevo;
    }
}

void insertarListaSimple(NodoSimple*& lista, int valor) {
    NodoSimple* nuevo = new NodoSimple{valor, NULL};

    if (lista == NULL) {
        lista = nuevo;
    } else {
        NodoSimple* aux = lista;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void insertarHistorial(int valor, string tipo) {
    NodoDoble* nuevo = new NodoDoble;
    nuevo->valor = valor;
    nuevo->tipo = tipo;
    nuevo->orden = ++ordenIngreso;
    nuevo->ant = historialFin;
    nuevo->sig = NULL;

    if (historialInicio == NULL) {
        historialInicio = nuevo;
        historialFin = nuevo;
    } else {
        historialFin->sig = nuevo;
        historialFin = nuevo;
    }
}

NodoBST* insertarBST(NodoBST* nodo, int valor) {
    if (nodo == NULL) {
        NodoBST* nuevo = new NodoBST{valor, NULL, NULL};
        return nuevo;
    }

    if (valor < nodo->valor) {
        nodo->izq = insertarBST(nodo->izq, valor);
    } else {
        nodo->der = insertarBST(nodo->der, valor);
    }

    return nodo;
}


void mostrarListaSimple(NodoSimple* lista) {
    if (lista == NULL) {
        cout << "La estructura esta vacia.\n";
        return;
    }

    NodoSimple* aux = lista;
    while (aux != NULL) {
        cout << aux->valor << " -> ";
        aux = aux->sig;
    }
    cout << "NULL\n";
}

void mostrarPila() {
    cout << "\n--- PILA ---\n";
    mostrarListaSimple(pila);
}

void mostrarCola() {
    cout << "\n--- COLA ---\n";
    mostrarListaSimple(frente);
}

void mostrarNegativos() {
    cout << "\n--- LISTA DE NEGATIVOS ---\n";
    mostrarListaSimple(negativos);
}

void mostrarHistorial() {
    cout << "\n--- HISTORIAL ---\n";

    if (historialInicio == NULL) {
        cout << "No hay historial.\n";
        return;
    }

    NodoDoble* aux = historialInicio;
    while (aux != NULL) {
        cout << aux->orden << ". "
             << aux->valor << " -> "
             << aux->tipo << endl;
        aux = aux->sig;
    }
}


void inOrden(NodoBST* nodo) {
    if (nodo != NULL) {
        inOrden(nodo->izq);
        cout << nodo->valor << " ";
        inOrden(nodo->der);
    }
}

void preOrden(NodoBST* nodo) {
    if (nodo != NULL) {
        cout << nodo->valor << " ";
        preOrden(nodo->izq);
        preOrden(nodo->der);
    }
}

void postOrden(NodoBST* nodo) {
    if (nodo != NULL) {
        postOrden(nodo->izq);
        postOrden(nodo->der);
        cout << nodo->valor << " ";
    }
}

bool buscarBST(NodoBST* nodo, int valor) {
    if (nodo == NULL) {
        return false;
    }

    if (valor == nodo->valor) {
        return true;
    } else if (valor < nodo->valor) {
        return buscarBST(nodo->izq, valor);
    } else {
        return buscarBST(nodo->der, valor);
    }
}

void liberarBST(NodoBST*& nodo) {
    if (nodo != NULL) {
        liberarBST(nodo->izq);
        liberarBST(nodo->der);
        delete nodo;
        nodo = NULL;
    }
}

void construirBSTDesdeHistorial() {
    liberarBST(raiz);

    NodoDoble* aux = historialInicio;

    while (aux != NULL) {
        if (aux->valor > 0) {
            raiz = insertarBST(raiz, aux->valor);
        }
        aux = aux->sig;
    }

    if (raiz == NULL) {
        cout << "No hay valores positivos para construir el BST.\n";
        return;
    }

    cout << "\nBST construido correctamente.\n";

    cout << "InOrden: ";
    inOrden(raiz);

    cout << "\nPreOrden: ";
    preOrden(raiz);

    cout << "\nPostOrden: ";
    postOrden(raiz);

    cout << endl;
}


int eliminarMagnitudMenor10(NodoSimple*& lista) {
    int eliminados = 0;

    while (lista != NULL && abs(lista->valor) < 10) {
        NodoSimple* temp = lista;
        lista = lista->sig;
        delete temp;
        eliminados++;
    }

    NodoSimple* aux = lista;

    while (aux != NULL && aux->sig != NULL) {
        if (abs(aux->sig->valor) < 10) {
            NodoSimple* temp = aux->sig;
            aux->sig = temp->sig;
            delete temp;
            eliminados++;
        } else {
            aux = aux->sig;
        }
    }

    return eliminados;
}

void procesarNegativos() {
    cout << "\nLista original:\n";
    mostrarListaSimple(negativos);

    int eliminados = eliminarMagnitudMenor10(negativos);

    cout << "\nLista resultante:\n";
    mostrarListaSimple(negativos);

    cout << "Nodos eliminados: " << eliminados << endl;
}


void actualizarMayorMenor(int valor) {
    if (!hayValores) {
        mayorValor = valor;
        menorValor = valor;
        hayValores = true;
    } else {
        if (valor > mayorValor) mayorValor = valor;
        if (valor < menorValor) menorValor = valor;
    }
}

void ingresarNumeros() {
    int n, valor;

    do {
        cout << "Ingrese cantidad de numeros: ";
        cin >> n;

        if (n <= 0) {
            cout << "N debe ser mayor que 0.\n";
        }

    } while (n <= 0);

    for (int i = 1; i <= n; i++) {
        cout << "Ingrese numero " << i << ": ";
        cin >> valor;

        if (valor == 0) {
            ceros++;
            cout << "Cero rechazado.\n";
        } else if (valor > 0 && valor % 2 == 0) {
            insertarCola(valor);
            insertarHistorial(valor, "COLA");
            pares++;
            validos++;
            actualizarMayorMenor(valor);
        } else if (valor > 0 && valor % 2 != 0) {
            insertarPila(valor);
            insertarHistorial(valor, "PILA");
            impares++;
            validos++;
            actualizarMayorMenor(valor);
        } else {
            insertarListaSimple(negativos, valor);
            insertarHistorial(valor, "LISTA SIMPLE");
            negativosCant++;
            validos++;
            actualizarMayorMenor(valor);
        }
    }
}


void mostrarEstadisticas() {
    cout << "\n--- ESTADISTICAS ---\n";
    cout << "Pares positivos: " << pares << endl;
    cout << "Impares positivos: " << impares << endl;
    cout << "Negativos: " << negativosCant << endl;
    cout << "Ceros rechazados: " << ceros << endl;
    cout << "Total validos: " << validos << endl;

    if (hayValores) {
        cout << "Mayor valor ingresado: " << mayorValor << endl;
        cout << "Menor valor ingresado: " << menorValor << endl;
    } else {
        cout << "No hay valores validos ingresados.\n";
    }
}


void vaciarEstructuraALista(NodoSimple*& origen, NodoSimple*& destino) {
    while (origen != NULL) {
        NodoSimple* temp = origen;
        origen = origen->sig;

        temp->sig = NULL;

        if (destino == NULL) {
            destino = temp;
        } else {
            NodoSimple* aux = destino;
            while (aux->sig != NULL) {
                aux = aux->sig;
            }
            aux->sig = temp;
        }
    }
}

void reconstruirBSTDesdeLista(NodoSimple* lista) {
    NodoSimple* aux = lista;
    while (aux != NULL) {
        raiz = insertarBST(raiz, aux->valor);
        aux = aux->sig;
    }
}

void reorganizarEstructuras() {
    NodoSimple* listaPila = NULL;
    NodoSimple* listaCola = NULL;

    vaciarEstructuraALista(pila, listaPila);
    vaciarEstructuraALista(frente, listaCola);
    finCola = NULL;

    cout << "\nLista auxiliar desde PILA:\n";
    mostrarListaSimple(listaPila);

    cout << "\nLista auxiliar desde COLA:\n";
    mostrarListaSimple(listaCola);

    liberarBST(raiz);

    reconstruirBSTDesdeLista(listaPila);
    reconstruirBSTDesdeLista(listaCola);

    if (raiz == NULL) {
        cout << "No hay datos para reconstruir el BST.\n";
    } else {
        cout << "\nBST reconstruido con datos reorganizados.\n";
        cout << "InOrden: ";
        inOrden(raiz);
        cout << endl;
    }
}


void liberarListaSimple(NodoSimple*& lista) {
    while (lista != NULL) {
        NodoSimple* temp = lista;
        lista = lista->sig;
        delete temp;
    }
}

void liberarHistorial() {
    while (historialInicio != NULL) {
        NodoDoble* temp = historialInicio;
        historialInicio = historialInicio->sig;
        delete temp;
    }

    historialFin = NULL;
}

int main() {
    int opcion, valorBuscar;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Ingresar N numeros\n";
        cout << "2. Mostrar pila\n";
        cout << "3. Mostrar cola\n";
        cout << "4. Mostrar lista de negativos\n";
        cout << "5. Mostrar historial\n";
        cout << "6. Construir y mostrar BST\n";
        cout << "7. Eliminar negativos segun condicion\n";
        cout << "8. Buscar valor en BST\n";
        cout << "9. Mostrar estadisticas\n";
        cout << "10. Reorganizar estructuras\n";
        cout << "11. Salir\n";
        cout << "Seleccione opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                ingresarNumeros();
                break;

            case 2:
                mostrarPila();
                break;

            case 3:
                mostrarCola();
                break;

            case 4:
                mostrarNegativos();
                break;

            case 5:
                mostrarHistorial();
                break;

            case 6:
                construirBSTDesdeHistorial();
                break;

            case 7:
                procesarNegativos();
                break;

            case 8:
                if (raiz == NULL) {
                    cout << "El BST no ha sido construido o esta vacio.\n";
                } else {
                    cout << "Ingrese valor a buscar: ";
                    cin >> valorBuscar;

                    if (buscarBST(raiz, valorBuscar)) {
                        cout << "Valor encontrado en el BST.\n";
                    } else {
                        cout << "Valor no encontrado en el BST.\n";
                    }
                }
                break;

            case 9:
                mostrarEstadisticas();
                break;

            case 10:
                reorganizarEstructuras();
                break;

            case 11:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion invalida.\n";
        }

    } while (opcion != 11);

    liberarListaSimple(pila);
    liberarListaSimple(frente);
    liberarListaSimple(negativos);
    liberarHistorial();
    liberarBST(raiz);

    return 0;
}
