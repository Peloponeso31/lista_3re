#include <stdio.h>
#include "nodo.h"
#include "lista.h"

int main(int argc, char * argv)
{
    struct nodo segundo_nodo = {8, NULL};
    struct nodo inicio = {5, &segundo_nodo};

    recorrer_rec(&inicio);

    //int cantidad_nodos = contar(&inicio);

    return 0;
}