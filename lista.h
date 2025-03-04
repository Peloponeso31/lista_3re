#ifndef _HEADER_LISTA_
#define _HEADER_LISTA_

#include <stdlib.h>
#include "nodo.h"

typedef struct lista {
    struct nodo * inicio;
    int largo;
} lista;

struct lista * crear_lista()
{
    struct lista * nueva_lista = malloc(sizeof(struct lista));
    nueva_lista->inicio = NULL;
    nueva_lista->largo = -1;
    return nueva_lista;
}

struct lista * crear_lista_entero(int dato)
{
    struct lista * nueva_lista = malloc(sizeof(struct lista));
    nueva_lista->inicio = malloc(sizeof(struct nodo));

    nueva_lista->inicio->dato = dato;
    nueva_lista->inicio->siguiente = NULL;

    nueva_lista->largo = 0;
    return nueva_lista;
}

struct lista * crear_lista_nodo(struct nodo * nodo)
{
    if (nodo == NULL) return NULL;
    struct lista * nueva_lista = malloc(sizeof(struct lista));

    nueva_lista->inicio = nodo;
    nueva_lista->largo = 0;

    return nueva_lista;
}

// Agrega elementos al final de la lista
int append(struct lista * lista, int dato)
{
    if (lista == NULL) return 0;
    lista->largo++;
    return agregar_final(lista->inicio, dato);
}

void consultar(struct lista * lista, int indice)
{
    if (lista->largo == -1) printf("La lista esta vacia.\n");
    if (indice > lista->largo || indice < 0) printf("El indice esta fuera de rango.\n");

    int contador = indice;
    struct nodo * actual = lista->inicio;

    while (contador != 0)
    {
        contador--;
        actual = actual->siguiente;
    }

    printf("lista[%d] = %d.\n", indice, actual->dato);
}

#endif