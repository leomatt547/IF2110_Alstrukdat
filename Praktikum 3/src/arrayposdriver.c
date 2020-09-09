#include <stdio.h>
#include "boolean.h"
#include "arraypos.c"

int main(){
    TabInt T1, T2;
    ElType *Max, *Min;
    printf("---Make Empty---\n");
    MakeEmpty(&T1);
    printf("\n");printf("---Baca Isi---\n");
    BacaIsi(&T1);
    printf("\n");printf("---Tulis Isi Tab---\n");
    TulisIsiTab(T1);

    printf("\n");printf("---SELEKTOR (TAMBAHAN)---\n");
    printf("\n");printf("---Banyaknya elemen efektif tabel---\n");
    printf("%d\n",NbElmt(T1));
    printf("\n");printf("---Maksimum elemen yang dapat ditampung oleh tabel---\n");
    printf("%d\n",MaxNbEl(T1));

    printf("\n");printf("---Selektor INDEKS---\n");
    printf("\n");printf("---Indeks elemen T pertama---\n");
    printf("%d\n",GetFirstIdx(T1));
    printf("\n");printf("---Indeks elemen T terakhir---\n");
    printf("%d\n",GetLastIdx(T1));

    printf("\n");printf("---Test Indeks yang valid---\n");

    printf("\n");printf("---Indeks elemen T pertama (True 0/False 1)---\n");
    printf("%d",IsIdxValid(T1,20));

    printf("\n");printf("---Indeks elemen T terakhir (True 0/False 1)---\n");
    printf("%d",IsIdxValid(T1,3));

    printf("\n");printf("---TEST KOSONG/PENUH---\n");
    printf("\n");printf("---Test tabel kosong (True 0/False 1)---\n");
    printf("%d",IsEmpty(T1));
    printf("\n");printf("---Test tabel penuh (True 0/False 1)---\n");
    printf("%d",IsFull(T1));

    printf("\n");printf("---OPERATOR ARITMATIKA---\n");
    printf("\n");printf("---Penjumlahan, pengurangan)---\n");
    printf("\n");printf("---Baca Isi---\n");
    printf("Masukan %d elemen:\n",NbElmt(T1));
    BacaIsi(&T2);
    printf("\n");printf("---Penjumlahan---\n");
    TulisIsiTab(PlusMinusTab(T1, T2, true));
    printf("\n");printf("---Pengurangan---\n");
    TulisIsiTab(PlusMinusTab(T1, T2, false));

    printf("\n");printf("---OPERATOR RELASIONAL---\n");
    printf("\n");printf("---Operasi pembandingan tabel (True 1/ False 0)---\n");
    printf("%d",IsEQ(T1,T2));

    printf("\n");printf("---SEARCHING---\n");
    printf("\n");printf("---Search apakah ada elemen tabel T yang bernilai X (3) (Menghasilkan angka index)---\n");
    printf("%d",Search1(T1,3));
    printf("\n");printf("---Search apakah ada elemen tabel T yang bernilai X (1000) (Menghasilkan -999)---\n");
    printf("%d",Search1(T1,1000));

    printf("\n");printf("---Search apakah ada elemen tabel T yang bernilai X (3) (True 1/ False 0)---\n");
    printf("%d",SearchB(T1,3));
    printf("\n");printf("---Search apakah ada elemen tabel T yang bernilai X (1000) (True 1/ False 0)---\n");
    printf("%d",SearchB(T1,1000));
/*
    printf("\n");printf("---Nilai Ekstrem---\n");
    MaxMin(T1, Max, Min);
    printf("---Nilai Maksimum---\n");
    printf("%d\n",Max);
    printf("---Nilai Minimum---\n");
    printf("%d\n",Min);
*/
    printf("\n");printf("---OPERASI LAIN---\n");
    printf("---Sum Tab T1---\n");
    printf("%d\n",SumTab(T1));
    printf("---Banyak kemunculan angka 2---\n");
    printf("%d\n",CountX(T2, 2));
    printf("---Apakah T2 semua genap (True 1/ False 0)---\n");
    printf("%d\n",IsAllGenap(T2));

    printf("\n");printf("---OPERASI LAIN---\n");
    printf("---SORTING---\n");
    printf("---terurut membesar---\n");
    Sort(&T1, true);
    TulisIsiTab(T1);
    printf("---terurut mengecil---\n");
    Sort(&T1, false);
    TulisIsiTab(T1);

    return 0;
}