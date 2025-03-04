#include <stdio.h>
#include "nodo.h"
#include "lista.h"

int main(int argc, char * argv)
{
    struct lista * lista = crear_lista_nodo(& (nodo) {
        .dato = 987,
        .siguiente = NULL
    });

    if (lista == NULL) 
    {
        printf("No hay lista que operar\n");

        return 0;
    }

    append(lista, 2);
    append(lista, 3);
    append(lista, 4);
    append(lista, 5);
    append(lista, 6);
    append(lista, 7);
    append(lista, 8);

    imprimir_nodos(lista->inicio);

    consultar(lista, 3);

    printf("Largo de la lista: %d.\n", lista->largo);

    return 0;
}