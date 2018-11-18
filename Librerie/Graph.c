#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "Graph.h"


Graph initGraph(int n)
{
    Graph G = malloc(sizeof(struct TGraph));
    G->adj = calloc(n, sizeof(List));
    G->n_intersezioni = n;
    return G;
}




Graph randomGraphConnesso(int n, int m)
{

     Graph G = initGraph(n);

     int i=0;


        for(i=0;i<n-1;i++)
        {
             addEdge(G,i,i+1,rand() % 50+1);       //Un segmento stradale può avere una lunghezza compresa tra 1 e 50
        }

        for(i=0;i<=m-n;i++)
        {
              addEdge(G,rand()%n, rand()%n, rand()%50+1);
        }


    return G;
}



Graph freeGraph(Graph G)
{
     int i = 0;

        if (G != NULL)
        {
                for (i = 0; i < G->n_intersezioni; i++)
                {
                     G->adj[i]=freeList(G->adj[i]);
                }

            free(G);
        }

    return NULL;
}



void printGraph(Graph G)
{
    int i = 0;
    if (G != NULL)
    {
        for (i=0;i<G->n_intersezioni;i++)      //Ciclo che scorre tutti i nodi (le intersezioni) del grafo
        {
            printf("%d -> ", i);
            printList(G->adj[i]);
            printf("\n");
        }
    }
    else
       printf("NULL");
}





void addEdgeforG2(Graph G, int intersezione, int target, int lunghezza)
{
        G->adj[intersezione] = appendNodeList(G->adj[intersezione], target, lunghezza);
}



void addEdge(Graph G, int intersezione, int target, int lunghezza)
{

    if (intersezione != target)
    {
        G->adj[intersezione] = appendNodeList(G->adj[intersezione], target, lunghezza);
        G->adj[target] = appendNodeList(G->adj[target], intersezione, lunghezza);         //Una strada a doppio senso
    }
    else
    {
        addEdge(G,intersezione,rand() % G->n_intersezioni, lunghezza);
    }
}



void addNode(Graph G)
{
    if (G != NULL)
    {
        G->adj = realloc(G->adj, (G->n_intersezioni+1) * sizeof(List));
        G->adj[G->n_intersezioni] = NULL;
        G->n_intersezioni += 1;
    }

}



void removeEdge(Graph G, int source, int target, int lunghezza)
{
        G->adj[source] = removeNodeList(G->adj[source], target,lunghezza);
        G->adj[target] = removeNodeList(G->adj[target], source,lunghezza);
}




List checkListRemoval(List L, int node_to_remove)
{
    if (L != NULL)
    {
        L->next = checkListRemoval(L->next, node_to_remove);
        if (L->target == node_to_remove)
        {
            List tmp = L->next;
            free(L);
            return tmp;
        }
        else if (L->target > node_to_remove)
        {
            L->target -= 1;
        }
    }
    return L;
}




Graph removeNode(Graph G, int node_to_remove)
{
    if (G != NULL)
    {
        int i = 0,x=0;
        List* tmp = G->adj;



        G->adj = calloc(G->n_intersezioni, sizeof(List));

        for (i=0;i<G->n_intersezioni;i++)
        {
            if (i != node_to_remove)      //se i è diverso dal nodo che voglio rimuovere
            {
                G->adj[x] = checkListRemoval(tmp[i], node_to_remove);   //vado a cercare nella lista il nodo che sarà cancellato
                x++;
            }
            else
            {
                freeList(G->adj[x]);      //cancello tutta la lista
            }
        }

        free(tmp);

         G->n_intersezioni--;

         if(G->n_intersezioni==0)
            G=NULL;

    }

      return G;
}

