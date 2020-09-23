
#include <stdio.h>
#include "arraypos.h"
#include "boolean.h"

 
/* ********** SELEKTOR ********** */
#define Elmt(T,i) (T).TI[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T){
  /* I.S. T sembarang */
  /* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
  /* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
  IdxType i;
  for(i = IdxMin; i <= IdxMax; i++){
    Elmt(*T,i) = ValUndef;
  }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T){
  /* Mengirimkan banyaknya elemen efektif tabel */
  /* Mengirimkan nol jika tabel kosong */
  /* *** Daya tampung container *** */
  IdxType i = IdxMin;
  boolean found = false;
  while (i <= IdxMax && !found){
    if(Elmt(T,i) == ValUndef){
      found = true;
    } else {
      i++;
    }
  }
  return i - IdxMin;
}
int MaxNbEl (TabInt T){
  /* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
  return (IdxMax-IdxMin+1);
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T){
  /* Prekondisi : Tabel T tidak kosong */
  /* Mengirimkan indeks elemen T pertama */
  return IdxMin;
}
IdxType GetLastIdx (TabInt T){
  /* Prekondisi : Tabel T tidak kosong */
  /* Mengirimkan indeks elemen T terakhir */
  return NbElmt(T)+IdxMin-1;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i){
  /* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
  /* yaitu antara indeks yang terdefinisi utk container*/
  return (IdxMin <= i && i <= IdxMax);
}
boolean IsIdxEff (TabInt T, IdxType i){
  /* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
  /* yaitu antara FirstIdx(T)..LastIdx(T) */
  return (GetFirstIdx(T) <= i && i <= GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
  /* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
  return NbElmt(T) == 0;
}
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T){
  /* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
  return NbElmt(T) == MaxNbEl(T);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T){
  /* I.S. T sembarang */
  /* F.S. Tabel T terdefinisi */
  /* Proses : membaca banyaknya elemen T dan mengisi nilainya */
  /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
  /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
  /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
  /* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
        IdxMin satu per satu diakhiri enter */
  /*    Jika N = 0; hanya terbentuk T kosong */
  int N,i;
  ElType el;
  scanf("%d\n", &N);
  while (!(0 <= N && N <= MaxNbEl(*T))){
    scanf("%d\n", &N);
  }
  MakeEmpty(T);
  for(i = 0; i < N; i++){
    scanf("%d\n", &el);
    Elmt(*T,IdxMin+i) = el;
  }
}
void TulisIsiTab (TabInt T){
  /* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
     antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
     di tengah, atau di belakang, termasuk spasi dan enter */
  /* I.S. T boleh kosong */
  /* F.S. Jika T tidak kosong: [e1,e2,...,en] */
  /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
  /* Jika tabel kosong : menulis [] */
  IdxType i;
  printf("[");
  for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
    printf("%d", Elmt(T,i));
    if(i != GetLastIdx(T)){ printf(","); }
  }
  printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus){
  /* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
  /* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
  /* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
  int sign;
  ElType el2;
  IdxType i;
  TabInt T;

  if(plus){ sign = 1; }
  else{ sign = -1; }
  MakeEmpty(&T);
  for(i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++){
    if(Elmt(T2,i) == ValUndef){
      el2 = 0;
    } else {
      el2 = sign * Elmt(T2,i);
    }
    Elmt(T,i) = Elmt(T1, i) + el2;
  }
  return T;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2){
  /* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
  boolean isEq;
  isEq = NbElmt(T1) == NbElmt(T2);
  IdxType i;

  i = GetFirstIdx(T1);
  while(isEq && i <= GetLastIdx(T1)){
    isEq = isEq && (Elmt(T1, i) == Elmt(T2, i));
    i++;
  }
  return isEq;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X){
  /* Search apakah ada elemen tabel T yang bernilai X */
  /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
  /* Jika tidak ada, mengirimkan IdxUndef */
  /* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
  /* Skema Searching yang digunakan bebas */
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
boolean SearchB (TabInt T, ElType X){
  /* Search apakah ada elemen tabel T yang bernilai X */
  /* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
  /* Skema searching yang digunakan bebas */
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
  return found;
}

/* ********** NILAI EKSTREM ********** */
void MaxMin (TabInt T, ElType * Max, ElType * Min){
  /* I.S. Tabel T tidak kosong */
  /* F.S. Max berisi nilai maksimum T;
          Min berisi nilai minimum T */
  IdxType i;

  *Max = Elmt(T, GetFirstIdx(T));
  *Min = Elmt(T, GetFirstIdx(T));
  for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
    if(Elmt(T,i) > *Max){ *Max = Elmt(T,i); }
    if(Elmt(T,i) < *Min){ *Min = Elmt(T,i); }
  }
}

/* ********** OPERASI LAIN ********** */
ElType SumTab (TabInt T){
  /* Menghasilkan hasil penjumlahan semua elemen T */
  /* Jika T kosong menghasilkan 0 */
  ElType sum;
  IdxType i;

  sum = 0;
  if(!IsEmpty(T)){
    for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
      sum += Elmt(T,i);
    }
  }
  return sum;
}
int CountX (TabInt T, ElType X){
  /* Menghasilkan berapa banyak kemunculan X di T */
  /* Jika T kosong menghasilkan 0 */
  IdxType i, count;
  count = 0;
  if(!IsEmpty(T)){
    for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
      if(Elmt(T,i) == X){ count++; }
    }
  }
  return count;
}
boolean IsAllGenap (TabInt T){
  /* Menghailkan true jika semua elemen T genap */
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

/* ********** SORTING ********** */
void Sort (TabInt * T, boolean asc){
  /* I.S. T boleh kosong */
  /* F.S. Jika asc = true, T terurut membesar */
  /*      Jika asc = false, T terurut mengecil */
  /* Proses : Mengurutkan T dengan salah satu algoritma sorting,
     algoritma bebas */

  /* Algoritma Insertion Sort */
  int i, j;
  IdxType key;

  for(i = GetFirstIdx(*T) + 1; i <= GetLastIdx(*T); i++){
    key = Elmt(*T, i);
    j = i-1;
    while(j >= GetFirstIdx(*T) && ((!asc && Elmt(*T,j) < key) || (asc && Elmt(*T,j) > key))){
      Elmt(*T,j+1) = Elmt(*T, j);
      j--;
    }
    Elmt(*T,j+1) = key;
  }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X){
  /* Proses: Menambahkan X sebagai elemen terakhir tabel */
  /* I.S. Tabel T boleh kosong, tetapi tidak penuh */
  /* F.S. X adalah elemen terakhir T yang baru */
  if(!IsFull(*T)){
    Elmt(*T, GetLastIdx(*T)+1) = X;
  }
}
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X){
  /* Proses : Menghapus elemen terakhir tabel */
  /* I.S. Tabel tidak kosong */
  /* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
  /*      Banyaknya elemen tabel berkurang satu */
  /*      Tabel T mungkin menjadi kosong */
  if(!IsEmpty(*T)){
    *X = Elmt(*T, GetLastIdx(*T));
    Elmt(*T, GetLastIdx(*T)) = ValUndef;
  }
}
