/*Praktikum 4
Leonard Matheus
13519215
15 September 2020*/
#include <stdlib.h>
#include <stdio.h>
#include "arraydin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel){
    TI(*T) = (ElType *)malloc(maxel * sizeof(ElType));
    Neff(*T)=0;
    MaxEl(*T)=maxel;
}
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */

void Dealokasi(TabInt *T){
    free(&TI(*T));
    Neff(*T)=0;
    MaxEl(*T)=0;
}
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T){
    return Neff(T);
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxElement(TabInt T){
    return MaxEl(T);
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T){
    return (IdxMin);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx(TabInt T){
    return (Neff(T) == 0 ? IdxUndef : IdxMin + Neff(T) - 1);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i){
    return (i>=IdxMin && i<=MaxEl(T));
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff(TabInt T, IdxType i){
    return (i>=GetFirstIdx(T) && i<=GetLastIdx(T));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T){
    return (Neff(T)==0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull(TabInt T){
    return (Neff(T)==MaxEl(T));
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T){
    int N;
    IdxType i;

    scanf("%d", &N);
    while(!IsIdxValid(*T, N)){
        scanf("%d", &N);
    }
    for(i = GetFirstIdx(*T); i < N; i++){
        scanf("%d", &Elmt(*T,i));
    }
    Neff(*T) = N;
}
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
void TulisIsiTab(TabInt T){
    IdxType i;
    printf("[");
    for(i = GetFirstIdx(T); i <= GetLastIdx(T) && !IsEmpty(T); i++){
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
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus){
    ElType el2;
    IdxType i;
    TabInt T;
    int tanda;
    if(plus){
        tanda = 1;
    }else{
        tanda = -1;
    }
    MakeEmpty(&T,NbElmt(T1));
    for(i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++){
        if(Elmt(T2,i) == 0){
            el2 = 0;
        } else {
            el2 = tanda * Elmt(T2,i);
        }
    Elmt(T,i) = Elmt(T1, i) + el2;
    Neff(T)=NbElmt(T1);
  }
  return T;
}
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2){
    IdxType i;
    boolean equal;
    equal = (NbElmt(T1) == NbElmt(T2));
    for(i = GetFirstIdx(T1); i <= GetLastIdx(T1) && equal; i++){
        equal &= Elmt(T1,i) == Elmt(T2,i);
    }
    return equal;
}
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X){
    boolean found = false;
    IdxType i = IdxMin;
    while ((!found)&& i<GetLastIdx(T)){
        if (X == Elmt(T,i)){
            found = true;
        }else{
            i++;
        }
    }
    if (found){
        return i;
    }else{
        return IdxUndef;
    }
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
boolean SearchB(TabInt T, ElType X){
    boolean found = false;
    IdxType i = IdxMin;
    while ((!found)&& i<GetLastIdx(T)){
        if (X == Elmt(T,i)){
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
void MaxMin(TabInt T, ElType *Max, ElType *Min){
    IdxType i;
    *Max = Elmt(T, GetFirstIdx(T));
    *Min = Elmt(T, GetFirstIdx(T));
    for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if(Elmt(T,i) > *Max){
            *Max = Elmt(T,i);
        }if(Elmt(T,i) < *Min){
            *Min = Elmt(T,i); 
        }
    }
}
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout){
    IdxType i;
    MakeEmpty(Tout, MaxElement(Tin));
    for (i=IdxMin; i<=GetLastIdx(Tin);i++){
        Elmt(*Tout,i)=Elmt(Tin,i);
    }
    Neff(*Tout)=Neff(Tin);
}
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
ElType SumTab(TabInt T){
    ElType sum=0;
    IdxType i;
    if(!IsEmpty(T)){
    for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        sum += Elmt(T,i);
    }
  }
  return sum;
}
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
int CountX(TabInt T, ElType X){
    IdxType i, count;
    count = 0;
    if(!IsEmpty(T)){
        for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if(Elmt(T,i) == X){
            count++;
        }
    }
  }
  return count;
}
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
boolean IsAllGenap(TabInt T){
    boolean genap;
    IdxType i;

    genap = true;
    i = GetFirstIdx(T);
    while(genap && i <= GetLastIdx(T)){
        genap = (genap & (Elmt(T,i)%2 == 0));
        i++;
    }
    return genap;
}
/* Menghailkan true jika semua elemen T genap. T boleh kosong */

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc){
    int i, j;
    IdxType tag;

    for(i = GetFirstIdx(*T) + 1; i <= GetLastIdx(*T); i++){
        tag = Elmt(*T, i);
        j = i-1;
        while(j >= GetFirstIdx(*T) && ((!asc && Elmt(*T,j) < tag) || (asc && Elmt(*T,j) > tag))){
            Elmt(*T,j+1) = Elmt(*T, j);
            j--;
        }
        Elmt(*T,j+1) = tag;
  }
}
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X){
    if(!IsFull(*T)){
        Elmt(*T, GetLastIdx(*T)+1) = X;
        Neff(*T) += 1;
    }
}
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X){
    if(!IsEmpty(*T)){
        *X = Elmt(*T, GetLastIdx(*T));
        Neff(*T) -= 1;
  }
}
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num){
    ElType *Tnew;
    IdxType i;

    Tnew = (ElType *)malloc(sizeof(ElType)*(MaxElement(*T)+num));
    for(i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
        *(Tnew+i) = Elmt(*T,i);
    }
    free(TI(*T));
    TI(*T) = Tnew;
    MaxEl(*T) += num;
}
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */

void ShrinkTab(TabInt *T, int num){
    TabInt Tnew;

    MakeEmpty(&Tnew, MaxEl(*T)-num);
    CopyTab(*T, &Tnew);
    free(TI(*T));
    TI(*T) = TI(Tnew);
    MaxEl(*T) -= num;
}
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */

void CompactTab(TabInt *T){
    TabInt Tnew;

    MakeEmpty(&Tnew, NbElmt(*T));
    CopyTab(*T, &Tnew);
    free(TI(*T));
    TI(*T) = TI(Tnew);
    MaxEl(*T) = NbElmt(*T);
}
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */