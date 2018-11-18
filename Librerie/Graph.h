#ifndef Graph_Graph_h
#define Graph_Graph_h

#include "List.h"

struct TGraph
{
    List* adj;                    //C'è un doppio puntatore (sarà un array)   //adj è l'arco
    int n_intersezioni;          //rappresenta il numero dei nodi(intersezioni) del grafo
};

typedef struct TGraph* Graph;


// Inizializza un nuovo grafo di n_intersezioni nodi
Graph initGraph(int n);


//Funzione che crea un grafo connesso di n intersezioni, e m segmenti stradali
Graph randomGraphConnesso(int n, int m);


//Dealloca l'intero grafo
Graph freeGraph(Graph G);


// Stampa il grafo
void printGraph(Graph G);


//Procedura che aggiunge archi al grafo G2 (grafo che conterra' le strade che formano il percorso minimo)
void addEdgeforG2(Graph G, int intersezione, int target, int lunghezza);


//Aggiunge una strada bidirezionale di una certa lunghezza tra due intersezioni
void addEdge(Graph G, int intersezione, int target, int lunghezza);


//Aggiunge un nodo nel grafo
void addNode(Graph G);


//Rimuove la strada da source(partenza) a target(arrivo)
void removeEdge(Graph G, int source, int target,int lunghezza);


//Cancella il nodo nelle liste e decrementa quindi i maggiori
List checkListRemoval(List L, int node_to_remove);


//Rimuove un nodo nel grafo
Graph removeNode(Graph G, int node_to_remove);


#endif
