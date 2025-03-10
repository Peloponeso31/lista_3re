#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "nodo.h"

struct nodo* crearNodo(int dato) {
    struct nodo* nuevoNodo = (struct nodo*)malloc(sizeof(struct nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

//agg nodo entre 1 y 2


void imprimirLista(struct nodo* inicio) {
    struct nodo* actual = inicio;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}
int main() {
    struct nodo *lista = NULL;

    // Creando la lista: [1, 2, 3]
    lista = crear_nodo(1, NULL);
    agregar_final(lista, 2);
    agregar_final(lista, 3);

    printf("Antes de agregar: ");
    imprimir_nodos(lista);

    // Creando el nodo a agregar
    struct nodo *nuevo_nodo = crear_nodo(99, NULL);

    // Agregar al inicio
    agregar_inicio(&lista, nuevo_nodo);

    printf("Despues de agregar: ");
    imprimir_nodos(lista);

    return 0;
}

