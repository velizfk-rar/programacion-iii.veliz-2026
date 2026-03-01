#include <iostream>
using namespace std;

struct Producto{
    int codigo;
    string nombre;
    double precio;
};

struct Nodo{

    Producto data;
    Nodo * siguiente;
};


int main(){

    //Creacion de primer nodo

    Nodo*primero = new Nodo;

    primero -> data.codigo = 101;
    primero -> data.nombre = "Laptop";
    primero -> data.precio = 5500.50;

    primero ->siguiente = nullptr;

    //Creacion de segundo nodo

    Nodo*segundo = new Nodo;

    segundo -> data.codigo = 102;
    segundo -> data.nombre = "Mouse";
    segundo -> data.precio = 150.75;

    //Conexión de primer nodo con segundo nodo

    segundo ->siguiente = nullptr;
    
    primero ->siguiente = segundo;

    //Creacion de tercer nodo

    Nodo*tercero = new Nodo;

    tercero -> data.codigo = 103;
    tercero -> data.nombre = "Teclado";
    tercero -> data.precio = 330;

    //Conexión de segundo nodo con tercer nodo

    tercero ->siguiente = nullptr;
    
    segundo ->siguiente = tercero;
    

    //Creacion de cuarto nodo

    Nodo*cuarto = new Nodo;

    cuarto -> data.codigo = 104;
    cuarto -> data.nombre = "Monitor";
    cuarto -> data.precio = 799;

    //Conexión de segundo nodo con tercer nodo

    cuarto ->siguiente = nullptr;
    
    tercero ->siguiente = cuarto;    

    Nodo*actual = primero;
    while(actual != nullptr){

        cout << "Codigo: " << actual->data.codigo<< endl;
        cout << "Codigo: " << actual->data.nombre<< endl;
        cout << "Codigo: " << actual->data.precio<< endl;
        cout << "Codigo: " << "-----------------"<< endl;

        actual = actual->siguiente; 

    }
    
    //Limpieza de memoria

    while(actual != nullptr){

        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }

    primero = nullptr;


    //José Daniel Véliz Velásquez
    //9941 - 24 - 12576
    //Tarea #3 - Estructuras, Nodos y Listas simples


}
