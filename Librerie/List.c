#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "List.h"


List initNodeList(int info, int lunghezza)
{
    List L = malloc(sizeof(struct TList));
    L->target = info;
    L->lunghezza = lunghezza;
    L->next = NULL;
    return L;
}


List appendNodeList(List L, int target, int lunghezza)
{
    if (L != NULL)
    {
        L->next = appendNodeList(L->next, target, lunghezza);
    }
    else
    {
        L = initNodeList(target, lunghezza);
    }

    return L;
}


List freeList(List L)
{
    if (L != NULL)
    {
        freeList(L->next);
        free(L);
    }

    return NULL;
}



void printList(List L) {
    if (L != NULL) {
        printf(" %d(%d) ", L->target, L->lunghezza);
        printList(L->next);
    }
}


List removeNodeList(List L, int target,int lunghezza)
{
   if(L!=NULL)
    {
        if (L->target == target  && L->lunghezza == lunghezza)
        {
            List tmp = L->next;
            free(L);
            return tmp;
        }
        L->next = removeNodeList(L->next, target,lunghezza);
    }



    return L;
}
