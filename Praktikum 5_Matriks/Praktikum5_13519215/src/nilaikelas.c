/*
NIM : 16519382
Nama : Leonard Matheus
Tanggal: 24 September 2020
Topik praktikum: Praktikum 5
Deskripsi: Matriks 
*/

#include <stdio.h>
#include "matriks.h"
void TulisNilaiX(MATRIKS M, indeks j, ElType X){
    indeks i;
    int count = 0;
    printf("[");
    for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        if (Elmt(M, i, j) == X){
            if(count != 0){ 
                printf(",");
            }
            printf("%d", i);
            count += 1;
        }
    }
    printf("]");
}
/*
{ Menuliskan nomor urut mahasiswa yang mendapatkan nilai X pada mata kuliah dengan nomor urut j. }
{ Pada dasarnya: Menuliskan semua indeks baris pada kolom j dengan nilai elemen = X. }
{ Nomor urut mahasiswa dituliskan dalam 1 baris, masing-masing dipisahkan koma, diawali [, diakhiri ], tanpa tambahan karakter apa pun (termasuk spasi dan enter) di awal maupun akhir }
{ I.S. M terdefinisi, j adalah indeks kolom efektif M, X terdefinisi }
{ F.S. Menuliskan semua indeks baris pada kolom j dengan nilai = X.
Jika tidak ada elemen dengan nilai = X, menuliskan []
{ Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
1 3 3
2 5 6
7 3 9
maka jika j = 1 dan X = 3, akan tercetak: [0,2]
}
*/
void TulisStatistikMhs(MATRIKS M, indeks i){
    indeks j;
    int min = -1;
    int max = -1;
    printf("[%d] ", i);
    printf("%.2f ", RataBrs(M, i));
    MaxMinBrs(M, i, &max, &min);
    printf("%d ",max);
    printf("%d ",min);
}
/*
{ Menuliskan statistik untuk mahasiswa dengan nomor urut i. }
{ Statistik yang dituliskan adalah: nilai rata-rata, nilai mata kuliah tertinggi, nilai mata kuliah terendah. }
{ Pada dasarnya: menuliskan statistik untuk data pada baris ke-i }
{ I.S. M terdefinisi, i adalah indeks baris efektif M }
{ F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
[i] <rata-rata> <nilai max> <nilai min> }
Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
100 83 83
72 55 60
77 93 90
maka jika i = 1 akan tercetak:
[1] 62.33 72 55
*/
void TulisStatistikMK (MATRIKS M, indeks j){
    indeks i;
    int min = -1;
    int max = -1;
    printf("[%d] ", j);
    printf("%.2f ", RataKol(M, j));
    MaxMinKol(M, j, &max, &min);
    printf("[");
    printf("%d ",max);
    printf("%d ",CountXKol(M, j, max));
    TulisNilaiX(M, j, max);
    printf("] [");
    printf("%d ",min);
    printf("%d ",CountXKol(M, j, min));
    TulisNilaiX(M, j, min);
    printf("]");
}
/*
{ Menuliskan statistik untuk mata kuliah dengan nomor urut j. }
{ Statistik yang dituliskan adalah: nilai rata-rata, nilai tertinggi (berikut berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya), nilai mata kuliah terendah (berikut berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya). }
{ Pada dasarnya: menuliskan statistik untuk data pada kolom ke-j }
{ I.S. M terdefinisi, j adalah indeks kolom efektif M }
{ F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
[j] <rata-rata> [max <nilai max> <#max> [<daftar max>]] [min <nilai min> <#min> [<daftar min>]] }
{ Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
100 83 83
72 55 60
77 93 90
maka jika j = 1 akan tercetak:
[1] 77.00 [93 1 [2]] [55 1 [1]]
}
*/
int main(){
    MATRIKS M1;
    int NB, NK;
    indeks i,j;

    scanf("%d", &NB);
    scanf("%d", &NK);
    BacaMATRIKS(&M1, NB, NK);
    printf("STATISTIK PER MAHASISWA\n");
    for (i=GetFirstIdxBrs(M1);i<=GetLastIdxBrs(M1);i++){
        TulisStatistikMhs(M1, i);
        printf("\n");
    }
    printf("STATISTIK PER MATA KULIAH\n");
    for (j=GetFirstIdxKol(M1);j<=GetLastIdxKol(M1);j++){
        TulisStatistikMK(M1, j);
        printf("\n");
        printf("\n");
    }
    return 0;
}