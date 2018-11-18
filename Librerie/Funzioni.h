#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>


#include "Graph.h"
#include "List.h"


//Interfaccia per l'utente
int Menu();


void Pulisci();


//Stampa tutto il percorso che Matteo deve fare, se possibile.
void STAMPA_PERCORSO(Graph G,int min,int partenza);



//Calcola il percorso minimo da CASA ad un intersezione più elevata dell'università
int Calcola_percorso_min_salita(Graph G,int CASA,int UNI);



//Calcola il percorso minimo (completamente in discesa)
//int Calcola_percorso_min_discesa(Graph G,int UNI,Graph G2,int* DISTANZA_MINIMA,int* ARRAY,int* ARRIVI);



void Algoritmo(Graph G,int CASA,int UNI);



//Randomizza la posizione dell'università in base alle intersezioni presenti nel grafo
int Random_UNI(Graph G);







