#include <stdio.h>
#include <stdlib.h>
#include "Librerie/Funzioni.h"
#include "Librerie/Graph.h"
#include "Librerie/List.h"

int main()
{
    srand((unsigned int)time(NULL));
    int n,m,scelta,nodo_da_rimuovere,partenza,arrivo,lunghezza;
    int CASA=0,UNI,i;

    Graph G=NULL;


   do
   {
       scelta=Menu();
       switch(scelta)
       {
               case 0 :
                    printf("\nArrivederci\n");
               break;

                case 1:

                    if(G!=NULL)
                         G=freeGraph(G);

                         printf("\nScrivi n (il numero delle intersezioni) : ");
                         while (scanf("%d",&n)!=1||n<3)
                         {
                             printf("Devi inserire un numero intero positivo > 2 : ");
                             while (getchar() != '\n');
                         }



                         printf("\nScrivi m (il numero dei segmenti stradali) : ");
                         while (scanf("%d",&m)!=1||m<n-1)
                         {
                               printf("Devi inserire un numero >= di %d : ",n-1);
                               while (getchar() != '\n');
                         }

                         G = randomGraphConnesso(n,m);



                        printf("\n\n\t\t\t\t\tSTAMPA G\n");
                        printGraph(G);


                        UNI=Random_UNI(G);


                        printf("\n\nCASA = Intersezione %d\n",CASA);
                        printf("UNIVERSITA' = Intersezione %d\n",UNI);



                        Pulisci();
                 break;

                 case 2:   //Aggiunge un intersezione

                     if(G==NULL)
                        printf("\nG vuoto, crea prima il grafo");
                     else
                     {
                         addNode(G);

                         printf("\n\n\t\t\t\t\tSTAMPA G\n");
                         printGraph(G);
                     }

                        Pulisci();


                 break;

                 case 3 :   //Aggiunge strada

                       if(G==NULL)
                        printf("\nG vuoto");
                       else
                       {
                           printf("\n\n\t\t\t\t\tSTAMPA G\n");
                           printGraph(G);

                           printf("\nInserisci la partenza : ");
                           while( scanf("%d",&partenza)!=1||partenza>=G->n_intersezioni||partenza<0)
                            {
                                          printf("Nodo non esistente, Reinserisci : ");
                                          while (getchar() != '\n');
                            }

                            printf("\nInserisci l'arrivo : ");
                            while( scanf("%d",&arrivo)!=1||arrivo>=G->n_intersezioni||arrivo<0||arrivo==partenza)
                            {
                                          printf("Arrivo non valido, Reinserisci : ");
                                          while (getchar() != '\n');
                            }

                            printf("\nInserisci la lunghezza : ");
                            while( scanf("%d",&lunghezza)!=1||lunghezza<=0)
                            {
                                          printf("lunghezza non valida, Reinserisci : ");
                                          while (getchar() != '\n');
                            }

                           addEdge(G,partenza,arrivo,lunghezza);

                            printf("\n\n\t\t\tSTAMPA G DOPO LA CREAZIONE DELLA NUOVA STRADA\n");
                            printGraph(G);
                       }

                       Pulisci();

                 break;

                 case 4 :            //cancella un intersezione

                     if(G==NULL)
                        printf("\nG vuoto");
                     else
                     {
                         printf("\n\n\t\t\t\t\tSTAMPA G\n");
                         printGraph(G);

                        printf("\nInserisci l'intersezione che vuoi rimuovere : ");
                        while( scanf("%d",&nodo_da_rimuovere)!=1||nodo_da_rimuovere>=G->n_intersezioni||nodo_da_rimuovere<0)
                        {
                                      printf("Nodo non esistente, Reinserisci : ");
                                      while (getchar() != '\n');
                        }


                       G=removeNode(G,nodo_da_rimuovere);

                       printf("\n\n\t\t\t\t\tSTAMPA G DOPO LA RIMOZIONE DEL NODO\n");
                       printGraph(G);


                             UNI=Random_UNI(G);

                     }

                      Pulisci();

                 break;

                 case 5:              //cancella un segmento stradale

                      if(G==NULL)
                        printf("\nG vuoto");
                     else
                     {
                           printf("\n\n\t\t\t\t\tSTAMPA G\n");
                           printGraph(G);

                           printf("\nInserisci la partenza : ");
                           while( scanf("%d",&partenza)!=1||partenza>=G->n_intersezioni||partenza<0)
                            {
                                          printf("Nodo non esistente, Reinserisci : ");
                                          while (getchar() != '\n');
                            }

                            printf("\nInserisci l'arrivo : ");
                            while( scanf("%d",&arrivo)!=1||arrivo>=G->n_intersezioni||arrivo<0||arrivo==partenza)
                            {
                                          printf("Arrivo non valido, Reinserisci : ");
                                          while (getchar() != '\n');
                            }

                            printf("\nInserisci la lunghezza : ");
                            while( scanf("%d",&lunghezza)!=1||lunghezza<=0)
                            {
                                          printf("lunghezza non valida, Reinserisci : ");
                                          while (getchar() != '\n');
                            }

                         removeEdge(G,partenza,arrivo,lunghezza);

                         printf("\n\n\t\t\tSTAMPA G DOPO LA CANCELLAZIONE DELLA STRADA\n");
                            printGraph(G);
                     }

                     Pulisci();

                    break;

                 case 6:

                     if(G==NULL)
                        printf("\nG vuoto");
                     else if(G->n_intersezioni<3)
                        printf("\nNon e' possibile eseguire l'esercizio, G deve avere almeno 3 nodi");
                     else
                     {
                        printf("\n\n\t\t\t\t\tSTAMPA G\n");
                        printGraph(G);



                        printf("\n\nCASA = Intersezione 0\n");
                        printf("UNIVERSITA' = Intersezione %d\n",UNI);

                         Algoritmo(G,CASA,UNI);
                     }

                     Pulisci();

                break;


                 default:
                      printf("\nErrore, numero non valido");
                      Pulisci();


        }
   }
   while(scelta!=0);

    printf("\n\n");
    system("PAUSE");
    return 0;
}
