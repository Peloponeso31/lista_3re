#ifndef _HEADER_NODO_
#define _HEADER_NODO_

#include <stdlib.h>
#include <stdio.h> // Incluye stdio.h para usar printf

typedef struct nodo {
    int dato;
    struct nodo * siguiente;
} nodo;

struct nodo * crear_nodo(int dato, struct nodo * siguiente)
{
    struct nodo * nodo = malloc(sizeof(struct nodo));
    nodo->dato = dato;
    nodo->siguiente = siguiente;

    return nodo;
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

void imprimir_nodos(nodo* inicio)
{
    nodo * temp = inicio;
    
    printf("[");

    while(temp != NULL)
    {
        printf("%d", temp->dato);
        if(temp->siguiente != NULL) printf(", ");
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
    if (nodo == NULL) return 0;
    if (nodo->siguiente == NULL)
    {
        nodo->siguiente = malloc(sizeof(struct nodo));

        if (nodo->siguiente == NULL) return 0;
        
        nodo = nodo->siguiente;
        nodo->dato = nuevo;
        nodo->siguiente = NULL;

        return 1;
    }

    return 1 && agregar_final(nodo->siguiente, nuevo);
}

/**
 * Funcion que inserta un nodo entre dos nodos.
 * 
 * @param nodo Direccion de memoria del nodo al que se
 * quiere insertar el siguiente elemento (se inserta
 * "a la derecha").
 * 
 * @param nuevo Valor que guardara el nuevo nodo.
 * 
 * @return 0 si no se pudo agregar el elemento
 * exitosamente, 1 si fue agregado con exito.
 */
int insertar_entre_nodos(struct nodo * nodo, int valor)
{
    if (nodo == NULL) return 0;

    struct nodo * nuevo = malloc(sizeof(struct nodo));
    if (nuevo == NULL) return 0;

    nuevo->dato = valor;
    nuevo->siguiente = nodo->siguiente;
    nodo->siguiente = nuevo;
    
    return 1;
}

/**
 * Funcion que agrega un nodo existente al inicio de una lista.
 * 
 * @param inicio Doble puntero al nodo inicial de la lista.
 * @param nuevo_nodo Nodo que se desea agregar al inicio.
 * 
 * @return 1 si el nodo fue agregado con exito, 0 en caso contrario.
 */
int agregar_inicio(struct nodo **inicio, struct nodo *nuevo_nodo)
{
    if (nuevo_nodo == NULL) return 0;

    nuevo_nodo->siguiente = *inicio; // El nodo actual apunta al antiguo inicio
    *inicio = nuevo_nodo;           // Actualizamos el inicio de la lista

    return 1;
}

#endif
