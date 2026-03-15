#include <iostream>
using namespace std;

struct Nodo{
    int dato; 
    Nodo* siguiente;
};


int main(){

    Nodo* head = NULL;
    Nodo* actual = NULL;

    int valor;
    char opcion = 's';

    while(opcion == 's'){

        cout << "Ingrese un número: ";
        cin >> valor;

        Nodo* nuevo = new Nodo; //Creo el nodo en la memoria dinámica

        nuevo->dato = valor; //Nuevo dato guardará el valor que se ingresa
        nuevo->siguiente = NULL; //Ese nuevo dato apunta a null esperando otro valor o dejándolo ahí.

        if(head == NULL){ //Sí la lista está vacía
            head = nuevo; //La cabeza de la lista es el nuevo que ingresamos
            actual = nuevo; //Y el actual igual será el nuevo
        }
        else{  //Sí la lista no está vacía
            actual->siguiente = nuevo; //El nodo actual ahora apuntará al nuevo que ya está creado antes
            actual = nuevo; //Y el actual ahora apuntará el nuevo nodo, dejándolo al final.
        }

        cout << "Desea ingresar otro numero? (s/n): ";
        cin >> opcion;
    }


    Nodo* temp = head; //Puntero temporal que apunta a head (el principio de la lista)

    cout << "\nElementos de la lista:\n";

    while(temp != NULL){  //Mientras el puntero temporal sea diferente de NULL, osea, sí apunta a algún dato
        cout << temp->dato << " -> "; //Imprimirá el dato actual
        temp = temp->siguiente; //Apunta al siguiente dato para repetir el ciclo
    }   

    cout << "NULL" << endl;

}
