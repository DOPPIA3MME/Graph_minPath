#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>


#include "Funzioni.h"



int Menu()
{
    int scelta;

     printf("\t\t\t\t\tProgetto3 - Gruppo 13\n\t\t\t  Maurizio Minieri - Alessio Spina - Domenico Maione");

    printf("\n\nx------------------------------------------------x");
             printf("\n| 0) EXIT\t\t\t\t\t |\n| 1) Per creare random il grafo connesso G\t |\n| 2) Per aggiungere un intersezione \t\t |\n| 3) Per aggiungere un segmento stradale\t |\n| 4) Per cancellare un intersezione");
             printf("\t\t |\n| 5) Per cancellare un segmento stradale\t |\n| 6) Per calcolare il percorso\t\t\t |\n");
           printf("x------------------------------------------------x");
            printf("\n  SCELTA = ");
            while (scanf("%d",&scelta) != 1)
            {
                 printf("Devi inserire un numero : ");
                 while (getchar() != '\n');
            }

    return scelta;
}


void Pulisci()
{
   printf("\n\nPremi Enter per continuare... ");
     char prev=0;

        while(1)
        {
            char c = getchar();

            if(c == '\n' && prev == c)
            {

                system("@cls||clear");
                break;
            }

            prev = c;
        }
}


void Stampa_Array(int* A,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
         printf("A[%d]\t\t%d\n",i,A[i]);
    }
}


//Considera il grafo G2, grafo riempito con le informazioni stradali per il percorso minimo.
//Per la salita, min sarà il nodo più elevato dell'università, e partenza ovviamente la casa
//Per la discesa, min sarà l'università mentre partenza il nodo trovato da Calcola_percorso_min_salita
void Stampa_Percorso_Salita(Graph G,int min,int partenza)
{
    if(G->adj[min]->lunghezza==partenza)
    {
        printf("\nPercorri la strada %d per arrivare all'intersezione %d",G->adj[min]->target,min);
        return;
    }
    else
    {
      Stampa_Percorso_Salita(G,G->adj[min]->lunghezza,partenza);
      printf("\nPercorri la strada %d per arrivare all'intersezione %d",G->adj[min]->target,min);
    }

}



//
void Stampa_Percorso_Discesa(Graph G,int partenza)
{
    if(G->adj[partenza]==NULL)
    {
           return;
    }
    else
    {
       Stampa_Percorso_Discesa(G,G->adj[partenza]->lunghezza);
        printf("\nPercorri la strada %d per arrivare all'intersezione %d" ,G->adj[partenza]->target,partenza);
    }
}


int Trova_intersezione(Graph G,int partenza)
{
    if(G->adj[partenza]==NULL)
    {
           return partenza;
    }
    else
    {
        return Trova_intersezione(G,G->adj[partenza]->lunghezza);
    }
}





int Calcola_percorso_min_discesa(Graph G,int UNI,Graph G2,int* dist)
{

    int V=G->n_intersezioni,t,i;
    List top=G->adj[V-1];



      for(i=(V-1);i>UNI;i--)
      {

        if(dist[i]!=INT_MAX )
        {
              top=G->adj[i];

              while(top!=NULL)
              {

                  t=top->target;

                  if(t<i&&t>=UNI&&dist[i]!=INT_MAX && dist[t]>=(top->lunghezza+dist[i]))
                  {

                    dist[t]=(top->lunghezza+dist[i]);


                     G2->adj[t]=freeList(G2->adj[t]);
                     addEdgeforG2(G2,t,top->lunghezza,i);       //G2 salva l'informazione: arrivo, lunghezza della strada, partenza
                  //   printf("!!!!Mi salvo la strada %d %d con lunghezza %d!!!!\n",i,t,top->lunghezza);

                  }

                            top=top->next;
              }
        }

     }

     printf("\nSTAMPA DIST DISCESA\n");
     Stampa_Array(dist,G->n_intersezioni);
      printf("\n\nG2 in discesa()\n\n");
       printGraph(G2);


}





int Calcola_percorso_min(Graph G,int CASA,int UNI)
{

    int V=G->n_intersezioni,curr2,conta=0;
    int t,i=0,salto=0;
    int minnodo;
    Graph G2=initGraph(V);
    Graph G3=initGraph(V);
    List top=G->adj[CASA],curr;
    int dist[V],A[V];
    int DISTANZA_MINIMA,ULTIMO;



     for (i=0;i<V;i++)
     {
        dist[i]=INT_MAX;
        A[i]=-1;
     }

     dist[CASA]=0;
     i=CASA;



    while(i!=(V+1))
    {
         if(i!=UNI&&A[i]==-1)
         {
                 while(top!=NULL)
                 {
                     t=top->target;

                     if(t!=UNI &&dist[i]!=INT_MAX && dist[t]>(top->lunghezza+dist[i]))
                     {

                         if(t>i)   //t>i cioè voglio solo strade in salita!!!
                         {

                              dist[t]=top->lunghezza+dist[i];


                              G2->adj[t]=freeList(G2->adj[t]);
                              addEdgeforG2(G2,t,top->lunghezza,i);       //G2 salva l'informazione: arrivo, lunghezza della strada, partenza
                             // printf("Mi salvo la strada %d %d con lunghezza %d\n",i,t,top->lunghezza);

                          }

                     }

                     if(t!=UNI&&A[t]==-1&&salto==0)
                     {
                                 curr2=i;
                                 i=t;
                                 curr=top;
                                 salto=1;
                                 top=G->adj[i];
                                 break;
                     }

                     top=top->next;
                 }

                 if(top==NULL)
                 {
                    A[i]=1;

                       if(salto==1)
                       {
                           top=curr->next;

                           i=curr2;
                           salto=0;
                       }
                       else
                       {
                              i++;
                              top=G->adj[i];
                       }
                 }
         }
         else
         {

              i++;
              top=G->adj[i];

         }
     }


      printf("\nSTAMPA DIST SALITA\n");
           Stampa_Array(dist,G->n_intersezioni);
            printf("\nSTAMPA G2 SALITA\n");
              printGraph(G2);



              Calcola_percorso_min_discesa(G,UNI,G3,&dist);          //salva in G3 le strade in discesa che formano il percorso minimo




      if(dist[UNI]==INT_MAX)
           printf("\nNON e' possibile fare un percorso con le caratteristiche volute");
      else
      {
            printf("\n\nLa distanza minima e' %d\n",dist[UNI]);

            minnodo=Trova_intersezione(G3,UNI);           //Trova l'intersezione sopraelevata all'università dove dovrò arrivare in salita

            Stampa_Percorso_Salita(G2,minnodo,0);          //Stampo le strade che mi portano a tale intersezione
            Stampa_Percorso_Discesa(G3,UNI);               //infine le strade in discesa che mi portano all'università
            printf("\nSEI ARRIVATO\n");
      }

      G2=freeGraph(G2);
      G3=freeGraph(G3);

}





void Algoritmo(Graph G,int CASA,int UNI)
{
     printf("\n\n\t\t\t\tx-----------------x\n");
     printf("\t\t\t\t|   PERCORSO_MINIMO   |");
     printf("\n\t\t\t\tx------------------x");
     printf("\n\n");
     int Nodo_in_salita=Calcola_percorso_min(G,CASA,UNI);

}



int Random_UNI(Graph G)
{
    if(G!=NULL)
    {
       if(G->n_intersezioni>=3)
          return (rand()% (G->n_intersezioni-2)+1);
       else
         return 1;
    }

}


