README
Datos del estudiante

Nombre: José Daniel Véliz Velásquez
Carné: 9941-24-12576

Descripción del programa

El programa permite ingresar números enteros y clasificarlos automáticamente según su valor. Dependiendo de la condición, los datos se almacenan en diferentes estructuras (pila, cola o lista). Además, se mantiene un historial de los valores ingresados y se puede construir un árbol binario de búsqueda (BST) utilizando los números positivos.

Estructuras utilizadas
Punteros y memoria dinámica (new)
Estructuras (struct)
Lista simplemente enlazada
Lista doblemente enlazada
Pila (implementada con lista simple)
Cola (implementada con lista simple)
Árbol binario de búsqueda (BST)
Explicación de la lógica

Los números se clasifican de la siguiente manera: los positivos pares se insertan en una cola, los positivos impares en una pila, y los negativos en una lista simplemente enlazada. Los ceros no se almacenan.
Todos los valores válidos se registran en una lista doble que funciona como historial.
El árbol BST se construye únicamente cuando el usuario lo solicita, utilizando los valores positivos previamente almacenados.
El sistema también permite visualizar las estructuras, eliminar ciertos valores negativos según una condición, buscar elementos en el BST y reorganizar los datos.

Instrucciones de ejecución
Compilar el programa en C++ (por ejemplo: g++ programa.cpp -o programa)
Ejecutar el archivo generado (./programa)
Utilizar el menú para ingresar datos y seleccionar las opciones disponibles
