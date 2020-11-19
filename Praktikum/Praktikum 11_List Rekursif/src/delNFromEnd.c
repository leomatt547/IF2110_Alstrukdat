
// Nama     : Alvin Wilta
// NIM      : 13519163
// Topik    : Praktikum 11
// Deskripsi: List Rekursif
/*Anda diminta membuat sebuah fungsi delNFromEnd dengan definisi:


Ada beberapa catatan dalam mengerjakan soal ini:

Dijamin n valid (minimal 1, maksimal banyaknya elemen pada list)
Anda akan mendapat verdict Wrong Answer apabila:
Tidak melakukan dealokasi pada elemen yang dihapus
Melakukan dealokasi pada elemen yang salah
Melakukan dealokasi pada beberapa elemen (hanya perlu 1)
Melakukan alokasi. Pada soal ini, Anda diminta mengubah list, bukan membuat list baru.
Anda boleh membuat fungsi tambahan
Khusus di soal ini, untuk mengubah Next(P) = next;, gunakan SetNext(P, next) (sudah disediakan). Penggunaan Next(P) akan menghasilkan Compile Error
3 testcase terakhir (8, 9, 10) hanya akan mendapat verdict Correct apabila iterasi list hanya terjadi sekali (dengan menghitung pemanggilan Next() di masing-masing elemen list). Dengan demikian, pengunaan Next berkali-kali akan menyebabkan verdict Wrong Answer.*/

#include <stdio.h>
#include <stdlib.h>
#include "listrek.h"

List delNFromEnd(List L, int n) {
    int num = 0;
    address A[1000];
    address P = (L);
    while ((P) != Nil) {
        A[num] = P;
        num++;
        P = Next(P);
    }
    A[num] = Nil;
    int pos = num - n;
    if (A[pos] == L) {
        Dealokasi(L);
        return A[pos + 1];
    } else {
        SetNext(A[pos - 1], A[pos + 1]);
    }
    Dealokasi(A[pos]);
    return L;
}
/* L terdefinisi, tidak mungkin kosong. */
/* Elemen ke-n L dari belakang akan dihapus dan didealokasi,
   lalu mengembalikan head dari list
   misal L = [1, 2, 3, 4, 5] dan n = 2
         L akan menjadi [1, 2, 3, 5] */