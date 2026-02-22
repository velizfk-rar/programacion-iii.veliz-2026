#include <iostream>
using namespace std;

struct Estudiante{
    int codigo;
    string nombre;
    double precio;

};

struct Nodo{
    Estudiante data;
    Nodo * siguiente;

};

int main(){

    Nodo* primero = new Nodo;

    primero -> data.codigo = 101;
    primero -> data.nombre = "Laptop";
    primero -> data.precio = 5500.50;

    primero->siguiente = nullptr;

    Nodo* segundo = new Nodo;

    segundo -> data.codigo = 102;
    segundo -> data.nombre = "Mouse";
    segundo -> data.precio = 150.75;

    segundo->siguiente = nullptr;

    primero->siguiente = segundo;

    Nodo* tercero = new Nodo;
    
    tercero -> data.codigo = 103;
    tercero -> data.nombre = "Teclado";
    tercero -> data.precio = 330;

    tercero->siguiente = nullptr;

    segundo->siguiente = tercero;

    Nodo* actual = primero;

    while(actual != nullptr){

        cout << "Codigo: " << actual->data.codigo<< endl;
        cout << "Codigo: " << actual->data.nombre<< endl;
        cout << "Codigo: " << actual->data.precio<< endl;
        cout << "Codigo: " << "-----------------"<< endl;

        actual = actual->siguiente;
    }

    while(actual != nullptr){

        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }

    primero = nullptr;


    //José Daniel Véliz Velásquez
    //9941 - 24 - 12576
    //Hoja de trabajo #2


}
