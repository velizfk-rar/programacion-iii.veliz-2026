José Daniel Véliz Velásquez

9941-24-12576

Sección B

El programa crea una lista simplemente enlazada con exactamente tres productos. Define las estructuras necesarias para el producto (código, nombre y precio) y para el nodo (que almacena un producto y un puntero al siguiente nodo). Luego construye manualmente los tres nodos: solicita los datos de cada producto, los almacena en su nodo correspondiente y los enlaza uno tras otro (el primero apunta al segundo, el segundo al tercero y el tercero queda apuntando a nullptr). Posteriormente, recorre la lista desde el nodo inicial e imprime los datos de los tres productos en orden, y finalmente libera la memoria eliminando cada nodo uno por uno para evitar fugas.
