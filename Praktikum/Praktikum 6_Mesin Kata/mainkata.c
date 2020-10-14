#include <stdio.h>
#include "mesinkata.h"

int main() {
    int i;
    STARTKATA();
    while(!EndKata){
        for (i=0; i<CKata.Length;i++){
            printf("%c",CKata.TabKata[i]);
        }
        printf("\n");
        ADVKATA();
    }
    return 0;
}