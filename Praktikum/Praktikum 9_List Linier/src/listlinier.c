/*Nama: Leonard Matheus
NIM: 13519215
Tanggal: 5 November 2020
Topik: Praktikum 9
Deskripsi: linked list
*/

#include "listlinier.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
    return(First(L) == Nil);
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
    First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
    ElmtList *P = (ElmtList *) malloc(sizeof(ElmtList));
    if (P != Nil){
        Info(P) = X;
        Next(P) = Nil;
        return P;
    }
    else {
        return Nil;
    }
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P){
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
    boolean found = false;
    address cpointer = First(L);
    address fpointer = Nil;
    if(!IsEmpty(L)){
        while ((cpointer != Nil) && (!found)){
            if (Info(cpointer) == X){
                fpointer = cpointer;
                found = true;
            }else{
                cpointer = Next(cpointer);
            }
        }
    }
    return fpointer;
}
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

boolean FSearch (List L, address P){
    boolean found = false;
	address cpointer = First(L);
	if (!IsEmpty(L)){
        while ((cpointer != Nil) && !found){
            if (cpointer == P){
                found = true;
            }else{
                cpointer = Next(cpointer);
            }
        }
    }
    return found;
}
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */

address SearchPrec (List L, infotype X){
    boolean found = false;
    address Prec = Nil;
    address fpointer = Nil;
    address cpointer = First(L);
    if (!IsEmpty(L)){
        while ((cpointer != Nil) && !found){
            if (Info(cpointer) == X){
                fpointer = Prec;
                found = true;
            }else{
				Prec = cpointer;
                cpointer = Next(cpointer);
            }
        }
    }
    return fpointer;
}
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
    address P = Alokasi(X);
    if (P != Nil){
        InsertFirst(L, P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
    address P = Alokasi(X);
    if (P != Nil){
        InsertLast(L, P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
    address P;
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
    address P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P){
    if (IsEmpty(*L)){
        Next(P) = Nil;
        First(*L) = P;
    }
    else{
        address last = First(*L);
        while(Next(last) != Nil) {
            last = Next(last);
        }
        InsertAfter(L, P, last);
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    *P = First(*L);
    if (Next(First(*L)) == Nil){
        CreateEmpty(L);
    }
    else{
        First(*L) = Next(First(*L));
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, infotype X){
    address P = Search(*L, X);
    if (P != Nil){
        address prec = First(*L);
        if (prec == P){
            DelFirst(L, &P);
        }else{
            while(Next(prec) != P){
                prec = Next(prec);
            }
            DelAfter(L, &P, prec);
        }
    }
    Dealokasi(&P);
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, address *P){
    if (Next(First(*L)) == Nil){
        *P = First(*L);
        CreateEmpty(L);
    }
    else {
        address prec = First(*L);
        while(Next(Next(prec)) != Nil){
            prec = Next(prec);
        }
        DelAfter(L, P, prec);
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    if (*Pdel != Nil){
        Next(Prec) = Next(Next(Prec));
    }
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
    printf("[");
    if (!IsEmpty(L)){
        address cpointer = First(L);
        while (cpointer != Nil){
            printf("%d",Info(cpointer));
            cpointer = Next(cpointer);
            if (cpointer != Nil){
                printf(",");
            }
        }
    }
    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt (List L){
    int Count = 0;
    address cpointer = First(L);
    while(cpointer != Nil){
        cpointer = Next(cpointer);
        Count++;
    }
    return Count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max: List tidak kosong ***/
infotype Max (List L){
    address Max = First(L);
    address cpointer = First(L);
    while(cpointer != Nil){
        if (Info(cpointer) > Info(Max)){
            Max = cpointer;
        }
        cpointer = Next(cpointer);
    }
    return Info(Max);
}
/* Mengirimkan nilai Info(P) yang maksimum */
address AdrMax (List L){
    address Max = First(L);
    address cpointer = First(L);
    while(cpointer != Nil){
        if (Info(cpointer) > Info(Max)){
            Max = cpointer;
        }
        cpointer = Next(cpointer);
    }
    return Max;
}
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */

/*** Prekondisi untuk Min: List tidak kosong ***/
infotype Min (List L){
    address Min = First(L);
    address cpointer = First(L);
    while(cpointer != Nil){
        if (Info(cpointer) < Info(Min)){
            Min = cpointer;
        }
        cpointer = Next(cpointer);
    }
    return Info(Min);
}
/* Mengirimkan nilai Info(P) yang minimum */

address AdrMin (List L){
    address Min = First(L);
    address cpointer = First(L);
    while(cpointer != Nil){
        if (Info(cpointer) < Info(Min)){
            Min = cpointer;
        }
        cpointer = Next(cpointer);
    }
    return Min;
}
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
float Average (List L){
    float sum;
	address P;
	if (!IsEmpty(L)){
		P = First(L);
		sum = Info(P);
		P = Next(P);
		while (P != Nil) {
			sum += Info(P);
			P = Next(P);
		}
		return (sum/NbElmt(L));
	}else{
		return 0;
	}
}
/* Mengirimkan nilai rata-rata info(P) */

/****************** PROSES TERHADAP LIST ******************/
void DelAll (List *L){
    infotype temp;
	while(!IsEmpty(*L)){
		DelVFirst(L, &temp);
	}
	CreateEmpty(L);
}
/* Delete semua elemen list dan alamat elemen di-dealokasi */

void InversList (List *L){
    address P, Prec, Last;
    P = First((*L));
    Prec = Nil;
    while (P != Nil) {
        Last = P;
        P = Next(P);
        Next(Last) = Prec;
        Prec = Last;
    }
    First(*L) = Last;
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

List FInversList (List L){
    List L1;
    CpAlokList(L, &L1);
    InversList(&L1);
    return L1;
}
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */

void CopyList (List *L1, List *L2){
    First(*L2) = First(*L1);
}
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */

List FCopyList (List L){
    List L1;
    address P, P1;
    boolean fail = false;
    P = First(L);
    CreateEmpty(&L1);
    while ((P != Nil) && (!fail)) {
        P1 = Alokasi(Info(P));
        if (P1 != Nil) {
            InsertLast(&L1, P1);
            P = Next(P);
        }else{
            fail = true;
            DelAll(&L1);
        }
    }
    return L1;
}
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */

void CpAlokList (List Lin, List *Lout){
    *Lout = FCopyList(Lin);
}
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */

void Konkat (List L1, List L2, List * L3){
    CreateEmpty(L3);
	address tadr;
	infotype temp;
	address cpointer;
	boolean fail = false;

    if (!(IsEmpty(L1))){
        cpointer = First(L1);
        while ((cpointer != Nil) && (!fail)){
			temp = Info(cpointer);
			tadr = Alokasi(temp);
			if (tadr != Nil){
				InsertLast(L3, tadr);
				cpointer = Next(cpointer);
			}else{
				DelAll(L3);
				fail = true;
			}
		}
		cpointer = First(L2);
        while ((cpointer != Nil) && (!fail)){
			temp = Info(cpointer);
			tadr = Alokasi(temp);
			if (tadr != Nil){
				InsertLast(L3, tadr);
				cpointer = Next(cpointer);
			} else {
				DelAll(L3);
				fail = true;
			}
		}
    }
    else{
		cpointer = First(L2);
        while ((cpointer != Nil) && (!fail)){
			temp = Info(cpointer);
			tadr = Alokasi(temp);
			if (tadr != Nil){
				InsertLast(L3, tadr);
				cpointer = Next(cpointer);
			}else {
				DelAll(L3);
				fail = true;
			}
		}
    }
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */

void Konkat1 (List *L1, List *L2, List *L3){
    CreateEmpty(L3);
    if (!(IsEmpty(*L1))){
        First(*L3) = First(*L1);
        address last1 = First(*L1);
        while(Next(last1) != Nil) {
            last1 = Next(last1);
        }
        Next(last1) = First(*L2);
    }
    else{
        First(*L3) = First(*L2);
    }
    CreateEmpty(L1);
    CreateEmpty(L2);
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

void PecahList (List *L1, List *L2, List L){
    int i;
    address(P);
    CpAlokList(L, L1);
    CpAlokList(L, L2);
    if ((NbElmt(L) % 2) == 1) {
        for (i=1; i<= ((NbElmt(L) + 1) /2); i++) {
            DelLast(L1, &P);
        }
        for (i=1; i<= ((NbElmt(L) - 1) /2); i++) {
            DelFirst(L2, &P);
        }
    }
    else {
        for (i=1; i<= ((NbElmt(L))/2); i++) {
            DelLast(L1, &P);
            DelFirst(L2, &P);
        }
    }
}
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
