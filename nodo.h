#ifndef _HEADER_NODO_
#define _HEADER_NODO_

typedef struct nodo {
    int dato;
    struct nodo * siguiente;
} nodo;

/**
 * Funcion que recorre nodos e imprime el dato que contienen y la direccion de 
 * memoria de su siguiente elemento desde uno en particular hasta llegar al 
 * final deestos de manera incondicional.
 * 
 * @param nodo Direccion de memoria del nodo desde el cual se quiere recorrer.
 */
void recorrer(struct nodo * nodo)
{
    while (nodo != NULL)
    {
        printf(
            "Dato: %d\t\tSiguiente: %p\n",
            nodo->dato,
            nodo->siguiente
        );

        nodo = nodo->siguiente;
    }
}

void recorrer_recursivo(struct nodo * nodo)
{
    if (nodo == NULL) return;
    
    printf(
        "Dato: %d\t\tSiguiente: %p\n",
        nodo->dato,
        nodo->siguiente
    );

    recorrer_recursivo(nodo->siguiente);
}


/**
 * Funcion que recorre nodos y los cuenta hasta llegar al final.
 * 
 * @param nodo Direccion de memoria del nodo desde el cual se quiere recorrer.
 * @return Numero entero que representa cuantos elementos despues del nodo dado.
 */
int contar(struct nodo * nodo)
{
    if (nodo == NULL) return 0;
    return 1 + contar(nodo->siguiente);
}

void imprimir_nodos(nodo*inicio)
{
    // Alan Flores participo
    nodo * temp = inicio;
    
    printf("[");

    while(temp != NULL)
    {
        printf("%d",temp->dato);
        if(temp ->siguiente != NULL) printf(", ");
        temp = temp->siguiente;
    }

    printf("]\n");
}

/**
 * Funcion que agrega un nuevo nodo al final de una
 * serie de nodos.
 * 
 * @param nodo Direccion de memoria del nodo desde
 * donde se quiere recorrer
 * 
 * @param nuevo Numero entero que se quiere agregar
 * al final de una serie de nodos.
 * 
 * @return 0 si no se pudo agregar el elemento
 * exitosamente, 1 si fue agregado con exito.
 */
int agregar_final(struct nodo * nodo, int nuevo)
{
    
}

#endif
