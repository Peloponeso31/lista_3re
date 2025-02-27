#include <stdio.h>
#include "nodo.h"
#include "lista.h"

int main(int argc, char * argv)
{
    // El quinto nodo es creado "in place", es decir, dentro de
    // la misma creacion del otro nodo, esto se puede encadenar
    // indefinidamente, lo cual no es recomendable pero nos sirve
    // para propositos didacticos.

    // Notar tambien el ampersand (&) al inicio de nodo. Esto nos
    // da la direccion de memoria en donde vive el nuevo nodo creado
    struct nodo cuarto_nodo = {4, &(nodo) {
        .dato = 5,
        .siguiente = NULL
    }};

    // Se crea el resto de nodos como variables, esto es para
    // obtener su direccion de memoria despues de su creacion
    // y poder enlazarlos mediante el ampersand (&).
    struct nodo tercer_nodo = {3, &cuarto_nodo};
    struct nodo segundo_nodo = {2, &tercer_nodo};
    struct nodo inicio = {1, &segundo_nodo};

    agregar_final(&inicio, 99);
    agregar_final(&inicio, 98);
    agregar_final(&inicio, 97);
    agregar_final(&inicio, 96);
    agregar_final(&inicio, 95);
    agregar_final(&inicio, 94);

    // Cuando se ejecuta:
    imprimir_nodos(&inicio);

    // Se obtiene como salida:
    // [1, 2, 3, 4, 5, 99, 98, 97, 96, 95, 94]

    return 0;
}