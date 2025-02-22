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

    
    // Cuando se ejecuta:
    recorrer(&inicio);

    // Se obtiene como salida:
    // Dato: 1         Siguiente: 0000000BEAFFFC70
    // Dato: 2         Siguiente: 0000000BEAFFFC80
    // Dato: 3         Siguiente: 0000000BEAFFFCA0
    // Dato: 4         Siguiente: 0000000BEAFFFC90
    // Dato: 5         Siguiente: 0000000000000000

    return 0;
}