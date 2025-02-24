/*Nama : Leonard Matheus
NIM : 13519215
Tanggal: 10 November 2020
Topik: Praktikum 10
*/
#include "boolean.h"
#include "listsirkuler.h"
#include <stdio.h>
#include <stdlib.h>
/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
    return First(L) == Nil;
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
    First(*L) = Nil;
}
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
    ElmtList *P = (ElmtList *) malloc (sizeof(ElmtList));
	if (P != Nil) {
		Info(P) = X;
		Next(P) = Nil;
		return P;
	} else {
		return Nil;
	}
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
    address P = First(L);
	boolean found = false;
	if (!IsEmpty(L)) {
		if (Info(P) != X) {
			P = Next(P);
			while ((P != First(L)) && (!found)) {
				if (Info(P) == X) {
					found = true;
				} else {
					P = Next(P);
				}
			}
		}
	}
	if (found) {
		return P;
	} else {
		return Nil;
	}
}
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
    address P = Alokasi(X);
	if (P != Nil) {
		InsertFirst(L, P);
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
    address P = Alokasi(X);
	if (P != Nil) {
		InsertLast(L, P);
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X){
    address P;
	DelFirst(L, &P);
	*X = Info(P);
	Dealokasi(P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype * X){
    address P;
	DelLast(L, &P);
	*X = Info(P);
	Dealokasi(P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    InsertLast(L, P);
	First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P){
    if (IsEmpty(*L)) {
		First(*L) = P;
		Next(P) = P;
	} else {
		address PTemp = First(*L);
		while (Next(PTemp) != First(*L)) {
			PTemp = Next(PTemp);
		}
		Next(PTemp) = P;
		Next(P) = First(*L);
	}
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec){
    Next(P) = Next(Prec);
	Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    *P = First(*L);
	if (Next(*P) == *P) {
		First(*L) = Nil;
	} else {
		address PTemp = First(*L);
		while (Next(PTemp) != First(*L)) {
			PTemp = Next(PTemp);
		}
		First(*L) = Next(First(*L));
		Next(PTemp) = First(*L);
	}
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P){
    if (Next(First(*L)) == First(*L)) {
		*P = First(*L);
		First(*L) = Nil;
	} else {
		address Prec = First(*L);
		while (Next(Next(Prec)) != First(*L)) {
			Prec = Next(Prec);
		}
		*P = Next(Prec);
		Next(Prec) = First(*L);
	}
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
	if (*Pdel == Prec) {
		First(*L) = Nil;
	} else {
		if (*Pdel == First(*L)) {
			DelFirst(L, Pdel);
		} else {
			Next(Prec) = Next(*Pdel);
		}
	}
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelP (List *L, infotype X){
    address P = Search(*L, X);
    address Prec = First(*L);
	if (!IsEmpty(*L)) {
		if (Info(First(*L)) == X) {
			DelFirst(L, &P);
			Dealokasi(P);
		}else{
            if (P != Nil) {
                while (Next(Prec) != P) {
                    Prec = Next(Prec);
                }
                DelAfter(L, &P, Prec);
                Dealokasi(P);
            }
		}
	}
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
    address P = First(L);
	printf("[%d", Info(P));
	P = Next(P);
	while (P != First(L)) {
		printf(",%d", Info(P));
		P = Next(P);
	}
	printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
