#ifndef Graph_List_h
#define Graph_List_h

struct TList
{
    int target;
    int lunghezza;                                 //lunghezza del segmento stradale
    struct TList* next;                            //next della lista
};

typedef struct TList* List;




// Inizializza un nuovo nodo
List initNodeList(int info, int peso);


// Aggiunge un nodo alla fine della lista
// La funzione ritorna sempre la testa della lista
List appendNodeList(List L, int target, int peso);


// Dealloca la lista interamente
List freeList(List L);


// Stampa la lista
void printList(List L);


//Cancella dalla lista i valori uguali a target e lunghezza
List removeNodeList(List L, int target,int lunghezza);

#endif
