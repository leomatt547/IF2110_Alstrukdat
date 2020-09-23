/*
NIM:13519215
Nama:Leonard Matheus
Tanggal:10 September 2020
Topik praktikum: Praktikum 3
Deskripsi: ADT List
*/

#include <stdio.h>
#include "boolean.h"
#include "arraypos.h"

IdxType GetMiddleIdx (TabInt T){
  if (NbElmt(T)%2!=0){
      return (((NbElmt(T)/2)));
  }
  else{
      return ((NbElmt(T)/2)-1);
  }
}

int main(){
    TabInt T1;
    int el1;
    IdxType i1;
    BacaIsi(&T1);
    scanf("%d",&el1);
    TulisIsiTab(T1);
    printf("\n");
    if (Search1(T1, el1)==IdxUndef){
        printf("%d tidak ada\n",el1);
    }else{
        printf("%d\n",Search1(T1, el1));
    }
    Sort (&T1,true);
    if (el1==Elmt(T1,GetLastIdx(T1))){
        printf("maksimum\n");
    }
    if (el1==Elmt(T1,GetFirstIdx(T1))){
        printf("minimum\n");
    }
    if (el1==Elmt(T1,GetMiddleIdx(T1))){
        printf("median\n");
        }
    return 0;
}