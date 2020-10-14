/*
NIM:13519215
Nama:Leonard Matheus
Tanggal:17 September 2020
Topik praktikum: Praktikum 4
Deskripsi: ADT Dinamik
*/

#include <stdio.h>
#include "arraydin.h"

int main (){
    TabInt T1;
    int N,Q, i, op;
    int num;
    scanf("%d",&N);
    MakeEmpty(&T1, N);
    BacaIsi(&T1);
    scanf("%d",&Q);
    for (i=1; i<=Q; i++){
        scanf("%d %d",&op, &num);
        switch(op){
            case(1) : 
            if (IsFull(T1)){
                printf("array sudah penuh\n");
            }
            else{
                AddAsLastEl(&T1, num);
                printf("%d ", MaxEl(T1));TulisIsiTab(T1);printf("\n");
            }
            break;

            case(2) :
                GrowTab(&T1, num);
                printf("%d ", MaxEl(T1));TulisIsiTab(T1);printf("\n");
                break;

            case(3) : if (num>MaxEl(T1)){
                printf("array terlalu kecil\n");
            }else{
                ShrinkTab(&T1, num);
                printf("%d ", MaxEl(T1));TulisIsiTab(T1);printf("\n");
            }
            break;

            case(4):
            CompactTab(&T1);
            printf("%d ", MaxEl(T1));TulisIsiTab(T1);printf("\n");
            break;

            default: printf("Masukkan tidak diterima\n");
            break;
        }
    }
    return 0;
}