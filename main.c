#include <stdio.h>
#include "nodo.h"
#include "lista.h"

int main(int argc, char * argv)
{
    struct lista * lista = crear_lista();

    if (lista == NULL) 
    {
        printf("No hay lista que operar\n");

        return 0;
    }

    append(lista, 1);
    append(lista, 2);
    append(lista, 3);
    append(lista, 4);

    agregar_inicio(lista, &(nodo) {
        .dato = 99,
        .siguiente = NULL
    });

    imprimir_nodos(lista->inicio);

    consultar(lista, 3);

    printf("Largo de la lista: %d.\n", lista->largo);

    return 0;
}