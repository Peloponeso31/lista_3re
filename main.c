#include <stdio.h>
#include "nodo.h"
#include "lista.h"

int main(int argc, char * argv)
{
    struct nodo otro_nodo = {8, NULL};
    struct nodo inicio = {5, &otro_nodo};

    
    printf("Dato: %d\tSiguiente: %p\tDireccion del nodo: %p\n", inicio.dato, inicio.siguiente, &inicio);
    printf("Dato: %d\tSiguiente: %p\tDireccion del nodo: %p\n", otro_nodo.dato, otro_nodo.siguiente, &otro_nodo);
    return 0;
}