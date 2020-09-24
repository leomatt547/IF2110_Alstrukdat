#include <stdio.h>
#include "boolean.h"
#include "matriks.c"

int main(){
    MATRIKS M1, M2;
    int NB, NK;
    int min = -1;
    int max = -1;

    printf("---KELOMPOK BACA/TULIS---\n");
    printf("---Masukkan Baris dan Kolom---\n");
    scanf("%d", &NB);
    scanf("%d", &NK);
    printf("\n"); printf("---Baca Matriks---\n");
    BacaMATRIKS(&M1, NB, NK);
    printf("\n"); printf("---Tulis Matriks---\n");
    TulisMATRIKS(M1);

    printf("\n");printf("---SELEKTOR DUNIA MATRIKS---\n");
    printf("\n");printf("---Indeks Elemen Valid (1,1)? (false 0/True 1)---\n");
    printf("%d",IsIdxValid(1 , 1));

    printf("\n");printf("---Selektor: Untuk sebuah matriks M yang terdefinisi:---\n");
    printf("\n");printf("---Indeks Elemen Baris Pertama M1---\n");
    printf("%d\n",GetFirstIdxBrs(M1));
    printf("\n");printf("---Indeks Elemen Kolom Pertama M1---\n");
    printf("%d\n",GetFirstIdxKol(M1));
    printf("\n");printf("---Indeks Elemen Baris Terakhir M1---\n");
    printf("%d\n",GetLastIdxBrs(M1));
    printf("\n");printf("---Indeks Elemen Kolom Terakhir M1---\n");
    printf("%d\n",GetLastIdxKol(M1));
    printf("\n");printf("---Indeks Elemen Valid (2,2) di M1? (false 0/true 1)---\n");
    printf("%d\n", IsIdxEff(M1, 2 , 2));
    printf("\n");printf("---Get Element Diagonal indeks (2,2) = M1---\n");
    printf("%d\n",GetElmtDiagonal(M1, 2));

    printf("\n");printf("---Assignment MATRIKS---\n");
    printf("---Copy MATRIKS---\n");
    CopyMATRIKS(M1, &M2);
    printf("--- MATRIKS 1---\n");
    TulisMATRIKS(M1);printf("\n");
    printf("\n");printf("---MATRIKS 2---\n");
    TulisMATRIKS(M2);printf("\n");

    printf("\n");printf("---KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE---\n");
    printf("\n");printf("---Tambah Matriks---\n");
    TulisMATRIKS(TambahMATRIKS(M1, M2));printf("\n");
    printf("\n");printf("---Kurang Matriks---\n");
    TulisMATRIKS(KurangMATRIKS(M1, M2));printf("\n");
    printf("\n");printf("---Kali Matriks---\n");
    TulisMATRIKS(KaliMATRIKS(M1, M2));printf("\n");
    printf("\n");printf("---Kali dengan Konstanta (3) Matriks ---\n");
    TulisMATRIKS(KaliKons(M1, 3));printf("\n");
    printf("\n");printf("---Kali dengan Konstanta (3) Matriks Void ---\n");
    /*PKaliKons(&M1, 3);*/
    TulisMATRIKS(M1);printf("\n");

    printf("\n");printf("---KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS---\n");
    printf("\n");printf("---Elemen M1 sama dengan M2? (false 0/true 1)---\n");
    printf("%d\n",EQ(M1,M2));
    printf("\n");printf("---Elemen M1 tidak sama dengan M2? (false 0/true 1)---\n");
    printf("%d\n",NEQ(M1,M2));
    printf("\n");printf("---Ukuran M1 sama dengan M2? (false 0/true 1)---\n");
    printf("%d\n",EQSize(M1,M2));

    printf("\n");printf("---OPERASI LAIN---\n");
    printf("\n");printf("---Jumlah elemen M1?---\n");
    printf("%d\n",NBElmt(M1));
    printf("\n");printf("---Apakah M1 Bujur Sangkar? (false 0/true 1)---\n");
    printf("%d\n",IsBujurSangkar(M1));
    printf("\n");printf("---Apakah M1 Simetri? (false 0/true 1)---\n");
    printf("%d\n",IsSimetri(M1));
    printf("\n");printf("---Apakah M1 Matriks Identitas? (false 0/true 1)---\n");
    printf("%d\n",IsSatuan(M1));
    printf("\n");printf("---Apakah M1 Matriks SParse (0.05 elemen terisi)? (false 0/true 1)---\n");
    printf("%d\n",IsSparse(M1));
    printf("\n");printf("---Matriks M1 dinegasikan---\n");
    TulisMATRIKS(Inverse1(M1));printf("\n");
    
    printf("\n");printf("---Matriks M1 Sekarang---\n");
    TulisMATRIKS(M1);printf("\n");
    printf("\n");printf("---Determinan Matriks M1---\n");
    printf("%f\n",Determinan(M1));
    printf("\n");printf("---Matriks M1 void dinegasikan---\n");
    PInverse1(&M1);
    TulisMATRIKS(M1);printf("\n");
    printf("\n");printf("---Transpose Matriks M1---\n");
    Transpose(&M1);
    TulisMATRIKS(M1);printf("\n");

    MaxMinKol(M1, 0, &max, &min);
    printf("\n");printf("---Max Min Kolom M1 di indeks kolom 0---\n");
    printf("Max: %d\n",max);
    printf("Min: %d\n",min);

    MaxMinBrs(M1, 0, &max, &min);
    printf("\n");printf("---Max Min Kolom M1 di indeks baris 0---\n");
    printf("Max: %d\n",max);
    printf("Min: %d\n",min);

    printf("\n");printf("---CountXKol angka 0 di kolom M1---\n");
    printf("%d\n",CountXKol(M1, 0, 0));
    printf("\n");printf("---CountXBrs angka 0 di kolom M1---\n");
    printf("%d\n",CountXBrs(M1, 0, 0));

    printf("\n");printf("---Rata2 Kol M1---\n");
    printf("%.2f\n", RataKol(M1, 0));
    printf("\n");printf("---Rata2 Brs M1---\n");
    printf("%.2f\n", RataBrs(M1, 0));
    return 0;
}