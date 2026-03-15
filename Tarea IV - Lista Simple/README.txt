José Daniel Véliz Velásquez
9941 - 24 - 12576
Programación III - Sección B

Este programa en C++ crea una lista enlazada simple donde el usuario puede ingresar varios números.

Primero se define una estructura llamada Nodo, que tiene:

dato: donde se guarda el número ingresado.

siguiente: un puntero que apunta al siguiente nodo de la lista.

En main se crean dos punteros:

head: apunta al primer nodo de la lista.

actual: se usa para moverse al final de la lista cuando se agregan nuevos nodos.

Luego, con un ciclo while, el programa:

Pide al usuario un número.

Crea un nuevo nodo en memoria dinámica usando new.

Guarda el número en dato.

Hace que siguiente apunte a NULL.

Después:

Si la lista está vacía (head == NULL), el nuevo nodo se vuelve la cabeza de la lista.

Si ya hay nodos, el nodo actual apunta al nuevo nodo y este pasa a ser el último.

Cuando el usuario ya no quiere ingresar más números, el programa recorre la lista usando un puntero temporal (temp) desde head hasta NULL, mostrando cada valor en pantalla.

El resultado es una impresión de la lista
