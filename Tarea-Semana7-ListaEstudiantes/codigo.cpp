#include <iostream>
using namespace std;

struct Nodo {
    int carne;
    string nombre;
    string apellido;
    string carrera;
    Nodo* siguiente;
};

int main() {

    Nodo* head = NULL;

    int opcion;

    cout << "Jose Daniel Veliz Velasquez\n";

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insertar al inicio\n";
        cout << "2. Insertar al final\n";
        cout << "3. Mostrar estudiantes\n";
        cout << "4. Buscar estudiante\n";
        cout << "5. Eliminar estudiante\n";
        cout << "6. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        // INSERTAR AL INICIO
        if(opcion == 1) {

            Nodo* nuevo = new Nodo;

            cout << "Carne: ";
            cin >> nuevo->carne;
            cin.ignore(); 

            cout << "Nombre: ";
            getline(cin, nuevo->nombre);

            cout << "Apellido: ";
            getline(cin, nuevo->apellido);

            cout << "Carrera: ";
            getline(cin, nuevo->carrera);

            nuevo->siguiente = head;
            head = nuevo;
        }

        // INSERTAR AL FINAL
        else if(opcion == 2) {

            Nodo* nuevo = new Nodo;

            cout << "Carne: ";
            cin >> nuevo->carne;
            cin.ignore(); 
            
            cout << "Nombre: ";
            getline(cin, nuevo->nombre);

            cout << "Apellido: ";
            getline(cin, nuevo->apellido);

            cout << "Carrera: ";
            getline(cin, nuevo->carrera);

            nuevo->siguiente = NULL;

            if(head == NULL) {
                head = nuevo;
            } else {

                Nodo* actual = head;

                while(actual->siguiente != NULL) {
                    actual = actual->siguiente;
                }

                actual->siguiente = nuevo;
            }
        }

        // MOSTRAR
        else if(opcion == 3) {

            Nodo* recorrido = head;

            if(recorrido == NULL) {
                cout << "Lista vacia\n";
            }

            while(recorrido != NULL) {
                cout << "\nCarne: " << recorrido->carne << endl;
                cout << "Nombre: " << recorrido->nombre << endl;
                cout << "Apellido: " << recorrido->apellido << endl;
                cout << "Carrera: " << recorrido->carrera << endl;
                cout << "---------------------\n";

                recorrido = recorrido->siguiente;
            }
        }

        // BUSCAR
        else if(opcion == 4) {

            int carneBuscar;
            cout << "Ingrese carne a buscar: ";
            cin >> carneBuscar;

            Nodo* recorrido = head;
            bool encontrado = false;

            while(recorrido != NULL) {

                if(recorrido->carne == carneBuscar) {
                    encontrado = true;

                    cout << "\nEstudiante encontrado:\n";
                    cout << "Nombre: " << recorrido->nombre << endl;
                    cout << "Apellido: " << recorrido->apellido << endl;
                    cout << "Carrera: " << recorrido->carrera << endl;
                    break;
                }

                recorrido = recorrido->siguiente;
            }

            if(!encontrado) {
                cout << "No se encontro el estudiante\n";
            }
        }

        // ELIMINAR
        else if(opcion == 5) {

            int carneEliminar;
            cout << "Ingrese carne a eliminar: ";
            cin >> carneEliminar;

            bool encontrado = false;

            // eliminar al inicio si coincide
            while(head != NULL && head->carne == carneEliminar) {
                Nodo* temp = head;
                head = head->siguiente;
                delete temp;
                encontrado = true;
            }

            Nodo* actual = head;
            Nodo* anterior = NULL;

            while(actual != NULL) {

                if(actual->carne == carneEliminar) {
                    encontrado = true;

                    anterior->siguiente = actual->siguiente;

                    Nodo* temp = actual;
                    actual = actual->siguiente;
                    delete temp;
                } 
                else {
                    anterior = actual;
                    actual = actual->siguiente;
                }
            }

            if(encontrado) {
                cout << "Estudiante eliminado\n";
            } else {
                cout << "No se encontro el estudiante\n";
            }
        }

    }while(opcion != 6);

    return 0;
}
