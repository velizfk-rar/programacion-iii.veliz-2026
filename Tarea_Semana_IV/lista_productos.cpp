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


    cout << "José Daniel Véliz Velásquez\n";
    cout << "9941-24-12576\n";

    cout << "Ingrese datos de los 4 productos: \n\n";

    //Creacion de primer nodo

    Nodo*primero = new Nodo;

    cout <<"Producto 1: \n";
    cout << "Código: "; cin >> primero -> data.codigo;
    cout << "Nombre: "; cin.ignore();
    getline(cin, primero->data.nombre);
    cout << "Precio: "; cin >> primero -> data.precio;

    primero ->siguiente = nullptr;
    cout << "-----------------\n";

    //Creacion de segundo nodo

    Nodo*segundo = new Nodo;

    cout <<"Producto 2: \n";
    cout << "Código: "; cin >> segundo -> data.codigo;
    cout << "Nombre: "; cin.ignore();
    getline(cin, segundo->data.nombre);
    cout << "Precio: "; cin >> segundo -> data.precio;

    //Conexión de primer nodo con segundo nodo

    segundo ->siguiente = nullptr;
    
    primero ->siguiente = segundo;
    cout << "-----------------\n";

    //Creacion de tercer nodo

    Nodo*tercero = new Nodo;

    cout <<"Producto 3: \n";
    cout << "Código: "; cin >> tercero -> data.codigo;
    cout << "Nombre: "; cin.ignore();
    getline(cin, tercero->data.nombre);
    cout << "Precio: "; cin >> tercero -> data.precio;

    //Conexión de segundo nodo con tercer nodo

    tercero ->siguiente = nullptr;
    
    segundo ->siguiente = tercero;
    cout << "-----------------\n";
    

    //Creacion de cuarto nodo

    Nodo*cuarto = new Nodo;

    cout <<"Producto 4: \n";
    cout << "Código: "; cin >> cuarto -> data.codigo;
    cout << "Nombre: "; cin.ignore();
    getline(cin, cuarto->data.nombre);
    cout << "Precio: "; cin >> cuarto -> data.precio;

    //Conexión de segundo nodo con tercer nodo

    cuarto ->siguiente = nullptr;
    
    tercero ->siguiente = cuarto;  
    cout << "-----------------\n";
    cout << "-----------------\n"; 
    cout << "-----------------\n"; 
    cout << "-----------------\n"; 


    double total = 0;

    Nodo*actual = primero;
    while(actual != nullptr){

        cout << "Codigo: " << actual->data.codigo<< endl;
        cout << "Nombre: " << actual->data.nombre<< endl;
        cout << "Precio: " << actual->data.precio<< endl;
        cout << "-----------------\n"<< endl;


        total += actual -> data.precio;
        actual = actual->siguiente; 

        
    }
    
        cout << "\nTotal acumulado: Q" << total;


    //Limpieza de memoria

    actual = primero;

    while(actual != nullptr){

        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }

    return 0;


    //José Daniel Véliz Velásquez
    //9941 - 24 - 12576
    //Tarea #3 - Estructuras, Nodos y Listas simples


}
