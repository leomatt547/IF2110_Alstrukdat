#include "boolean.h"
#include "stacklist.c"
#include <stdlib.h>
#include <stdio.h>
void PrintInfo (Stack S)
{
    printf("[");
    if (!IsEmpty(S)){
        address CP = Top(S);
        printf(" <Top> ");
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
    Stack S;
    CreateEmpty(&S);
    scanf("%d", &N);
    for (i = 0; i<N; i++){
        scanf("%d %d",&P,&N);
        if (P == 1){
            Push(&S, N);
            PrintInfo(S);
            printf("\n");
        }else{
            Pop(&S, &X);
            PrintInfo(S);
            printf("\n");
            printf("%d",X);
            printf("\n");
        }
    }
    return 0;
}