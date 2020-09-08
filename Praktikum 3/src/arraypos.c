/*Pra Praktikum 2
Nama: Leonard Matheus
NIM: 13519215
Tanggal: 8 September 2020
*/

#include <stdio.h>
#include "arraypos.h"
#include "boolean.h"

void MakeEmpty (TabInt * T){
    int i;
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
    int i = IdxMin;
    int Neff = 0;
    while ((Elmt(T, i) != ValUndef) && (i<=IdxMax)){
        Neff+=1;
        i+=1;
    }
    return Neff;
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbEl (TabInt T){
    return IdxMax;
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T){
    return IdxMin;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx (TabInt T){
    int i = IdxMin;
    while ((Elmt(T, i) != ValUndef) && (i<IdxMax)){
        i+=1;
    }i-=1;
    return i;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i){
    return ((i<=MaxNbEl(T))&&(i>=GetFirstIdx(T)));
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
    return(Elmt(T, IdxMin)==ValUndef);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T){
    return(Elmt(T, IdxMax)!=ValUndef);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T){
    int N;
    int i;
    scanf("%d\n",&N);
    while ((N>=0) && (N<=MaxNbEl(*T))){
        scanf("%d\n",&N);
    }
    if (N>=1){
        for (i = 1; i<=N; i++){
            scanf("%d\n",&Elmt(*T,i));
        }
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
    int i;
    printf("[");
    for (i = IdxMin; i <= IdxMax; i++){
        printf("%ls,",&Elmt(T,i));
    }
    printf("]\n");
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
    int i;
    TabInt T3;
    if (plus){
        for (i = IdxMin; i <= IdxMax; i++){
            Elmt(T3, i) = Elmt(T1,i) + Elmt(T2,i);
        }
    }else{
        for (i = IdxMin; i <= IdxMax; i++){
            Elmt(T3, i) = Elmt(T1,i) - Elmt(T2,i);
        }
    }
    return T3;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2){
    int i = IdxMin;
    boolean equal = true;
    while((equal) && (i<=IdxMax)){
        if (Elmt(T1,i) == Elmt(T2,i)){
            i+=1;
        }else{
            equal = false;
        }
    }
    return equal;
}
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X){
    int i = IdxMin;
    boolean found = false;
    if (IsEmpty(T)){
        return IdxUndef;
    }else{
        while ((Elmt(T, i) != ValUndef) && (i<=IdxMax) && (found == false)){
            if (X==Elmt(T,i)){
                found = true;
            }else{
                i+=1;
            }
        }
        if ((i>0)&&(found == true)){
            return i;
        }else{
            return IdxUndef;
        }
    }
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
boolean SearchB (TabInt T, ElType X){
    int i = IdxMin;
    boolean found = false;
    while ((Elmt(T, i) != ValUndef) && (i<=IdxMax) && (found == false)){
        if (X==Elmt(T,i)){
            found = true;
        }else{
            i+=1;
        }
    }
    return found;
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void MaxMin (TabInt T, ElType * Max, ElType * Min){
    int i;
    *Min = Elmt(T,1);
    *Max = Elmt(T,1);
    for (i = 2; i <= IdxMax; i++){
        if (Elmt(T,i)>=*Max){
            *Max=Elmt(T,i);
        }
        if ((Elmt(T,i)<=*Min) && (Elmt(T,i)!=ValUndef)){
            *Min=Elmt(T,i);
        }
    }
}
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */

/* ********** OPERASI LAIN ********** */
ElType SumTab (TabInt T){
    int i;
    int s;
    if (IsEmpty(T)){
        return 0;
    }else{
        for (i = IdxMin; i<=IdxMax; i++){
            s+=Elmt(T,i);
        }
        return s;
    }
}
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
int CountX (TabInt T, ElType X){
    int N;
    int i;
    if (IsEmpty(T)){
        return 0;
    }else{
        for (i = IdxMin; i<=IdxMax; i++){
            if (Elmt(T,i)==X){
                N+=1;
            }
        }
    }
    return N;
}
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
boolean IsAllGenap (TabInt T){
    int i = IdxMin;
    boolean genap = true;
    while ((Elmt(T, i) != ValUndef) && (i<=IdxMax) && (genap == true)){
        if (Elmt(T,i)%2!=0){
            genap = false;
        }else{
            i+=1;
        }
    }
    return genap;
}
/* Menghasilkan true jika semua elemen T genap */

/* ********** SORTING ********** */
void Sort (TabInt * T, boolean asc){
    int N = NbElmt(*T);
    int Pass;
    int IMax;
    int IMin;
    int i;
    int Temp;
    if (N>1){
        if (!asc){
            for (Pass = IdxMin; Pass<=N; Pass++){
                //Cari Tentukan Maximum [Pass..N]
                IMax = Pass;
                for(i = Pass+1; i <= N; i++){
                    if (Elmt(*T, IMax)<Elmt(*T,i)){
                        IMax = i;
                    }/*T[IMax] adalah maximum T[Pass..N]*/
                }
                Temp = Elmt(*T, IMax);
                Elmt(*T, IMax) = Elmt(*T, Pass);
                Elmt(*T, Pass) = Temp;
                /*T[1..Pass] terurut: T[1]>=T[2]>=...>=T[Pass]*/
            }
        }else{
            for (Pass = IdxMin; Pass<=N; Pass++){
                //Cari Tentukan Minimum [Pass..N]
                IMin = Pass;
                for(i = Pass+1; i <= N; i++){
                    if (Elmt(*T, IMin)>Elmt(*T,i)){
                        IMin = i;
                    }/*T[IMax] adalah maximum T[Pass..N]*/
                }
                Temp = Elmt(*T, IMin);
                Elmt(*T, IMin) = Elmt(*T, Pass);
                Elmt(*T, Pass) = Temp;
                /*T[1..Pass] terurut: T[1]>=T[2]>=...>=T[Pass]*/
            }
        }
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
    int i = IdxMin;
    boolean last = false;
    while((i <= IdxMax)&&(last==false)){
        if (Elmt(*T, i)==ValUndef){
            Elmt(*T,i)=X;
            last = true;
        }else{
            i+=1;
        }
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