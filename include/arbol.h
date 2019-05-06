#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;


int minimo(int x, int y);

struct nodo{
    int id;
    int nodocubierto;
    struct nodo *hijoIzquierda,*hijoDerecha;
};

int recubrimientoArbol(struct nodo *raiz,vector<int> &nodoscubiertos);


struct nodo* nuevoNodo(int idnodo);
