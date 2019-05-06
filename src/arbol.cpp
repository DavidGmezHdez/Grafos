#include "arbol.h"

int minimo(int x, int y){
    if (x<y)
        return x;
    else
        return y;
}





int recubrimientoArbol(struct nodo *raiz, vector<int> &nodoscubiertos){
    if(raiz==NULL)
        return 0;
    if(raiz->hijoIzquierda == NULL && raiz->hijoDerecha)
        return 0;
    
    if(raiz->nodocubierto != 0)
        return raiz->nodocubierto;

    int tamanioincl = 1 + recubrimientoArbol(raiz->hijoIzquierda,nodoscubiertos) + recubrimientoArbol(raiz->hijoDerecha,nodoscubiertos);

    int tamanionoincl = 0;

    if(raiz->hijoIzquierda)
        tamanionoincl = 1 + recubrimientoArbol(raiz->hijoIzquierda->hijoIzquierda,nodoscubiertos) +  recubrimientoArbol(raiz->hijoIzquierda->hijoDerecha,nodoscubiertos);
    if(raiz->hijoDerecha)
        tamanionoincl = 1 + recubrimientoArbol(raiz->hijoDerecha->hijoIzquierda,nodoscubiertos) + recubrimientoArbol(raiz->hijoDerecha->hijoDerecha,nodoscubiertos);
    
    raiz->nodocubierto = minimo(tamanioincl,tamanionoincl);
    nodoscubiertos.push_back(raiz->id);

    return raiz->nodocubierto;
}

struct nodo* nuevoNodo(int idnodo){
    struct nodo* tmp = (struct nodo *) malloc(sizeof(struct nodo));
    tmp->id = idnodo;
    tmp->hijoIzquierda = tmp->hijoDerecha = NULL;
    tmp->nodocubierto = 0;
    return tmp;
}

