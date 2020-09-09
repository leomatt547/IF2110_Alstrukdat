/*Pra Praktikum 2
Nama: Leonard Matheus
NIM: 13519215
Tanggal: 8 September 2020
*/

#include <stdio.h>
#include "arraypos.h"
#include "boolean.h"

void MakeEmpty (TabInt * T){
    IdxType i;
    for (i=IdxMin;i<=IdxMax;i++){
        Elmt(*T,i) = ValUndef;
    }
}
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T){
    IdxType i = IdxMin;
    boolean last = false;
    while ((!last) && (i<IdxMax)){
        if (Elmt(T, i) == ValUndef){
            last = true;
        }else{
            i++;
        }
    }
    return i;
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbEl (TabInt T){
    return (IdxMax-IdxMin+1);
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T){
    return IdxMin;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx (TabInt T){
    return NbElmt(T)+IdxMin-1;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i){
    return ((i<=IdxMax)&&(i>=IdxMin));
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff (TabInt T, IdxType i){
    return ((i<=GetLastIdx(T))&&(i>=GetFirstIdx(T)));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
    return(NbElmt(T)==0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T){
    return(NbElmt(T) == MaxNbEl(T)-1);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T){
    int N,i;
    ElType elem;
    scanf("%d\n", &N);
    while (!(0 <= N && N <= MaxNbEl(*T))){
        scanf("%d\n", &N);
    }
    MakeEmpty(T);
    for(i = 0; i < N; i++){
        scanf("%d\n", &elem);
        Elmt(*T,IdxMin+i) = elem;
    }
}
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
void TulisIsiTab (TabInt T){
    IdxType i;
    printf("[");
    for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        printf("%d", Elmt(T,i));
        if(i != GetLastIdx(T)){
            printf(","); 
        }
    }
    printf("]");
}
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus){
    int tanda;
    ElType Elem;
    IdxType i;
    TabInt T;

    if(plus){
        tanda = 1; 
    }else{
        tanda = -1;
    }
    MakeEmpty(&T);
    for(i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++){
        if(Elmt(T2,i) == ValUndef){
        Elem = 0;
        } else {
        Elem = tanda * Elmt(T2,i);
        }
        Elmt(T,i) = Elmt(T1, i) + Elem;
    }
    return T;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2){
    IdxType i = GetFirstIdx(T1);
    boolean equal = true;
    while(equal && i <= GetLastIdx(T1)){
        equal = equal && (Elmt(T1,i)==Elmt(T2,i));
        i++;
    }
    return equal;
}
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X){
  IdxType i;
  boolean found;

  i = IdxMin;
  found = false;
  while(i <= GetLastIdx(T) && !found){
    if(Elmt(T,i) == X){
      found = true;
    } else {
      i++;
    }
  }
  if(!found){ i = IdxUndef; }
  return i;
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
boolean SearchB (TabInt T, ElType X){
    IdxType i = IdxMin;
    boolean found = false;
    while ((i<=GetLastIdx(T)) && (found == false)){
        if (X==Elmt(T,i)){
            found = true;
        }else{
            i++;
        }
    }
    return found;
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void MaxMin (TabInt T, ElType * Max, ElType * Min){
    IdxType i;
    *Min = Elmt(T,GetFirstIdx(T));
    *Max = Elmt(T,GetFirstIdx(T));
    for (i = GetFirstIdx(T)+1; i <= GetLastIdx(T)+1; i++){
        if (Elmt(T,i)>=*Max){
            *Max=Elmt(T,i);
        }
        if (Elmt(T,i)<=*Min){
            *Min=Elmt(T,i);
        }
    }
}
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */

/* ********** OPERASI LAIN ********** */
ElType SumTab (TabInt T){
    IdxType i;
    ElType s = 0;
    if (IsEmpty(T)){
        return 0;
    }else{
        for (i = GetFirstIdx(T); i<=GetLastIdx(T); i++){
            s+=Elmt(T,i);
        }
        return s;
    }
}
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
int CountX (TabInt T, ElType X){
    int N = 0;
    IdxType i;
    if (!IsEmpty(T)){
        for (i = GetFirstIdx(T); i<=GetLastIdx(T); i++){
            if (Elmt(T,i)==X){
                N++;
            }
        }
    }return N;
}
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
boolean IsAllGenap (TabInt T){
    IdxType i = GetFirstIdx(T);
    boolean genap = true;
    while ((i<=GetLastIdx(T)) && (genap)){
        genap = (genap & (Elmt(T,i)%2 == 0));
        i++;
    }
    return genap;
}
/* Menghasilkan true jika semua elemen T genap */

/* ********** SORTING ********** */
/*Algoritma Insertion Sort*/
void Sort (TabInt * T, boolean asc){
    int m, n;
    IdxType key;

    for(m = GetFirstIdx(*T) + 1; m <= GetLastIdx(*T); m++){
        key = Elmt(*T, m);
        n = m-1;
        while(n >= GetFirstIdx(*T) && ((!asc && Elmt(*T,n) < key) || (asc && Elmt(*T,n) > key))){
            Elmt(*T,n+1) = Elmt(*T, n);
            n--;
        }
        Elmt(*T,n+1) = key;
    }
}
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X){
    if(!IsFull(*T)){
        Elmt(*T, GetLastIdx(*T)+1) = X;
    }
}
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X){
    if(!IsEmpty(*T)){
        *X = Elmt(*T, GetLastIdx(*T));
        Elmt(*T, GetLastIdx(*T)) = ValUndef;
    }
}
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */