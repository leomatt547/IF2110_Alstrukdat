/* Nama: Leonard Matheus
Tanggal: 4 Oktober 2020
Deskripsi: Praktikum 7
Topik: Queue
*/

#include <stdio.h>
#include "prioqueuechar.h"
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q){
    return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (PrioQueueChar Q){
    return (NBElmt(Q)==MaxEl(Q));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (PrioQueueChar Q){
    if (IsEmpty(Q))
        return 0;
    else if (Head(Q) <= Tail(Q)){
        return (Tail(Q) - Head(Q) + 1);
    }else{
        return (MaxEl(Q) - (Head(Q) - Tail(Q) - 1));
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max){
    (*Q).T = (infotype *) malloc ((Max + 1) * sizeof(infotype));
    if ((*Q).T != NULL) {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }else{
        MaxEl(*Q) = 0;
    }
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q){
    MaxEl(*Q) = 0;
    Tail(*Q)=Nil;
    Head(*Q)=Nil;
    free((*Q).T); 
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotype X){
    if (IsEmpty(*Q)){
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoTail(*Q) = X;
    }else{
        int i = NBElmt(*Q);
        int tail = Tail(*Q);
        while ((Prio(X) < Prio(Elmt(*Q, tail))) && (i > 0)){
            Elmt(*Q,(tail % MaxEl(*Q)) + 1) = Elmt(*Q,tail);
            tail--;
            i--;
            if (tail == NBElmt(*Q)){
                tail = MaxEl(*Q);
            }
        }
        Elmt(*Q,((tail % MaxEl(*Q)) + 1)) = X;
        Tail(*Q) = (Tail(*Q) % MaxEl(*Q)) + 1;
    }
}
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
        
void Dequeue (PrioQueueChar * Q, infotype * X){
    *X= InfoHead(*Q);
    if (NBElmt(*Q) == 1) {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }else if (Head(*Q) == MaxEl(*Q)) {
        Head(*Q) = 0;
    }else{
        Head(*Q)++;
    }
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q){
    infotype X;
    int i;
    for(i = Head(Q); i < Tail(Q); i++){
		printf("%d %c\n", Prio(Elmt(Q, i)), Info(Elmt(Q, i)));
	}
	if(!IsEmpty(Q)){
		i = Tail(Q);
		printf("%d %c\n", Prio(Elmt(Q, i)), Info(Elmt(Q, i)));
    }
    printf("#\n");
}
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
