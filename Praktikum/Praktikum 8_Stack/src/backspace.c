/* Nama: Leonard Matheus
NIM: 13519215
Topik: Praktikum 8
Deskripsi: Stack
*/
#include <stdio.h>
#include <stdlib.h>
#include "stackt.h"

boolean isStackSama(Stack S1, Stack S2){
    boolean sama = true;
    while (!IsEmpty(S1)){
        if (InfoTop(S1) == InfoTop(S2)){
            Pop(&S1, &InfoTop(S1));
            Pop(&S2, &InfoTop(S2));
        }else{
            sama = false;
        }
    }
    return sama;
}
int main(){
    int a,b,n,i;
    Stack S1, S2;
    CreateEmpty(&S1);
    CreateEmpty(&S2);
    scanf("%d %d",&a,&b);
    for (i=1; i<=(a+b); i++){
        if (i<=a){
            scanf("%d",&n);
            if (n==0){
                Pop(&S1, &InfoTop(S1));
            }else{
                Push(&S1,n);
            }
        }else{
            scanf("%d",&n);
            if (n==0){
                Pop(&S2, &InfoTop(S2));
            }else{
                Push(&S2,n);
            }
        }
    }
    if (isStackSama(S1, S2)){
        printf("Sama\n");
    }else{
        printf("Tidak sama\n");
    }
    return 0;
}