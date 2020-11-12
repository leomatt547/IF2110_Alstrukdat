#include "boolean.h"
#include "queuelist.c"
#include <stdlib.h>
#include <stdio.h>
void PrintInfo (Queue Q)
{
    printf("[");
    if (!IsEmpty(Q)){
        address CP = Head(Q);
        do{
            printf("%d",Info(CP));
            CP = Next(CP);
            if (CP != Nil){
                printf(",");
            }
        } while (CP != Nil);
    }
    printf("]");
}

int main(){
    int i, N, X, P;
    Queue Q;
    CreateEmpty(&Q);
    scanf("%d", &N);
    for (i = 0; i<N; i++){
        scanf("%d %d",&P,&N);
        if (P == 1){
            Enqueue(&Q, N);
            PrintInfo(Q);
            printf("\n");
        }else{
            Dequeue(&Q, &X);
            PrintInfo(Q);
            printf("\n");
            printf("%d",X);
            printf("\n");
        }
    }
    return 0;
}