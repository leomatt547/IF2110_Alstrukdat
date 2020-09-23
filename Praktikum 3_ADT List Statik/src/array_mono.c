/*
NIM:13519215
Nama:Leonard Matheus
Tanggal:10 September 2020
Topik praktikum: Praktikum 3
Deskripsi: ADT List 2
*/

#include <stdio.h>
#include "boolean.h"
#include "arraypos.h"
#include "arraypos2.c"

int main(){
    TabInt T1;
    IdxType i1, i2;
    int c1;
    boolean monotdkkecil, monotdkbesar, monostatik;
    i1, i2= IdxMin;
    monotdkkecil, monotdkbesar, monostatik= true;
    BacaIsi(&T1);
    while(i1 < GetLastIdx(T1) && (monotdkkecil)){
        if(Elmt(T1,i1) >= Elmt(T1,i1+1)){
           i1++;
            } else if (Elmt(T1,i1) < Elmt(T1,i1+1)){
                monotdkkecil=false;
        }
    }
    while(i2 < GetLastIdx(T1) && (monotdkbesar)){
        if(Elmt(T1,i2) <= Elmt(T1,i2+1)){
            i2++;
            } else if (Elmt(T1,i2) > Elmt(T1,i2+1)){
                monotdkbesar=false;
        }
    }
    if((monotdkbesar==true)&&(monotdkkecil==true)){
        c1=3;
    }else{
        if(monotdkbesar){
            c1=2;
        }
        else if(monotdkkecil){
            c1=1;
        }
    }

    switch(c1){
        case 1:
            printf("Array monotonik tidak mengecil\n");
            break;
        case 2:
            printf("Array monotonik tidak membesar\n");
            break;
        case 3:
            printf("Array monotonik statik\n");
            break;
        default:
            printf("Array tidak monotonik\n");
            break;
    }
    TulisIsiTab(T1);
    printf("\n");
    printf("Mono tidak Kecil %d", monotdkkecil);
    printf("Mono tidak Besar %d", monotdkbesar);
    return 0;
}