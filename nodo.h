#ifndef _HEADER_NODO_
#define _HEADER_NODO_

typedef struct nodo {
    int dato;
    struct nodo * siguiente;
} nodo;

void recorrer(struct nodo * inicio)
{
    while (inicio != NULL)
    {
        printf(
            "Dato: %d\t\tSiguiente: %p\n",
            inicio->dato,
            inicio->siguiente
        );

        inicio = inicio->siguiente;
    }
}

void recorrer_rec(struct nodo * inicio)
{
    if (inicio == NULL) return;
    
    recorrer_rec(inicio->siguiente);
    
    printf(
        "Dato: %d\t\tSiguiente: %p\n",
        inicio->dato,
        inicio->siguiente
    );
}

#endif
