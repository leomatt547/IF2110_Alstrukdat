/*Nama : Leonard Matheus
NIM : 13519215
Tanggal: 12 November 2020
Topik: Praktikum 10
*/

#include "boolean.h"
#include "stacklist.h"
#include <stdlib.h>
#include <stdio.h>

/* Prototype manajemen memori */
void Alokasi (address *P, infotype X){
    *P = (address)malloc(sizeof(ElmtStack));
    if (*P != Nil){
        Info(*P) = X;
        Next(*P) = Nil;
    }
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void Dealokasi (address P){
    free(P);
}
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */ 

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty (Stack S){
    return Top(S) == Nil;
}
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
void CreateEmpty (Stack * S){
    Top(*S) = Nil;
}
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack S yang kosong */
void Push (Stack * S, infotype X){
    address P;
    Alokasi(&P, X);
    if (P != Nil){
        Next(P) = Top(*S);
        Top(*S) = P;
    }
}
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
void Pop (Stack * S, infotype * X){
    address P;
    P = Top(*S);
    if (Next(Top(*S)) == Nil){
        CreateEmpty(S);
    }else{
        Top(*S) = Next(Top(*S));
    }
    *X = Info(P);
    Dealokasi(P);
}
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */