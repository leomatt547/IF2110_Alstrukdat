/* check Made by Leonard M. 13519215 */
#include "check.h"
#include "stdio.h"
#include "stdlib.h"
#include "../src/listsirkuler.h"

/****************** TEST LIST KOSONG ******************/
/* Mengirim true jika list kosong */
START_TEST(IsEmpty_TC1) {
  List L;
  CreateEmpty(&L);
  ck_assert_int_eq(1, IsEmpty(L));
  InsVLast(&L, 100);
  ck_assert_int_eq(0, IsEmpty(L));
}

/****************** PEMBUATAN LIST KOSONG ******************/
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
START_TEST(CreateEmpty_TC1) {
  List L;
  CreateEmpty(&L);
  ck_assert_ptr_eq(First(L), Nil);
}

/****************** Manajemen Memori ******************/
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
START_TEST(Alokasi_TC1) {
  infotype X = 2;
  address P = Alokasi(X);
  ck_assert_int_eq(Info(P), X);
  ck_assert_ptr_eq(Next(P), Nil);
}

/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
START_TEST(Dealokasi_TC1) {
  infotype X = 2;
  address P = Alokasi(X);
  // Delokasi, seems impossible to be tested, so just check if no runtime error
  Dealokasi(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
START_TEST(Search_T1) {
  List L;
  infotype search = 2;
  IsiList(&L);
  address P = Search(L, search);
  ck_assert_ptr_ne(P, Nil);
}

START_TEST(Search_T2) {
  List L;
  infotype search = 6;
  IsiList(&L);
  address P = Search(L, search);
  ck_assert_ptr_eq(P, Nil);
}

START_TEST(Search_T3) {
  List L;
  infotype search = 1;
  CreateEmpty(&L);
  address P = Search(L, search);
  ck_assert_ptr_eq(P, Nil);
}

START_TEST(InsVFirst_T1) {
  List L;
  infotype X;
  X = 1;
  CreateEmpty(&L);
  InsVFirst(&L, X);
  ck_assert_int_eq(NbElmt(L), 1);
  ck_assert_int_eq(Info(First(L)), 1);
}

START_TEST(InsVFirst_T2) {
  List L;
  infotype X = 0;

  IsiList(&L);
  InsVFirst(&L, X);
  ck_assert_int_eq(NbElmt(L), 4);
  address P = First(L);
  ck_assert_int_eq(Info(P), 0);
  P = Next(P);
  int i = 1;
  while (P != First(L)) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
}

/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
START_TEST(InsVLast_T1) {
  List L;
  infotype X = 1;
  CreateEmpty(&L);
  InsVLast(&L, X);
  ck_assert_int_eq(NbElmt(L), 1);
  ck_assert_int_eq(Info(First(L)), 1);
}

START_TEST(InsVLast_T2) {
  List L;
  infotype X = 4;

  IsiList(&L);
  InsVLast(&L, X);

  ck_assert_int_eq(NbElmt(L), 4);

  int i = 2;
  address P = First(L);
  ck_assert_int_eq(Info(P), 1);
  P = Next(P);
  while (P != First(L)) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
}

START_TEST(DelVFirst_T1) {
  List L;
  infotype X;

  IsiList(&L);
  DelVFirst(&L, &X);

  ck_assert_int_eq(X, 1);
  ck_assert_int_eq(NbElmt(L), 2);

  int i = 3;
  address P = First(L);
  ck_assert_int_eq(Info(P), 2);
  while (P != First(L)) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
}

/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
START_TEST(DelVLast_T1) {
  List L;
  infotype X;

  IsiList(&L);
  DelVLast(&L, &X);

  ck_assert_int_eq(X, 3);
  ck_assert_int_eq(NbElmt(L), 2);

  int i = 2;
  address P = First(L);
  ck_assert_int_eq(Info(P), 1);
  while (P != First(L)) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
START_TEST(InsertFirst_T1) {
  List L;
  CreateEmpty(&L);

  address P3 = Alokasi(3);
  InsertFirst(&L, P3);
  address P2 = Alokasi(2);
  InsertFirst(&L, P2);
  address P1 = Alokasi(1);
  InsertFirst(&L, P1);
  
  ck_assert_int_eq(NbElmt(L), 3);
  int i = 2;
  address P = First(L);
  ck_assert_int_eq(Info(P), 1);
  P = Next(P);
  while (P != First(L)) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
}

/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
START_TEST(InsertAfter_T1) {
  List L;
  CreateEmpty(&L);

  address P3 = Alokasi(3);
  InsertFirst(&L, P3);
  address P1 = Alokasi(1);
  InsertFirst(&L, P1);

  address P2 = Alokasi(2);
  InsertAfter(&L, P2, P1);
  
  ck_assert_int_eq(NbElmt(L), 3);
  int i = 2;
  address P = First(L);
  ck_assert_int_eq(Info(P), 1);
  P = Next(P);
  while (P != First(L)) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
}

/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
START_TEST(InsertLast_T1) {
  List L;
  CreateEmpty(&L);

  address P1 = Alokasi(1);
  InsertLast(&L, P1);
  address P2 = Alokasi(2);
  InsertLast(&L, P2);
  address P3 = Alokasi(3);
  InsertLast(&L, P3);
  
  ck_assert_int_eq(NbElmt(L), 3);
  int i = 2;
  address P = First(L);
  ck_assert_int_eq(Info(P), 1);
  P = Next(P);
  while (P != First(L)) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
START_TEST(DelFirst_T1) {
  List L;
  CreateEmpty(&L);

  address P1 = Alokasi(1);
  InsertLast(&L, P1);
  address P2 = Alokasi(2);
  InsertLast(&L, P2);
  address P3 = Alokasi(3);
  InsertLast(&L, P3);
  
  ck_assert_int_eq(NbElmt(L), 3);
  DelFirst(&L, P1);
  int i = 3;
  address P = First(L);
  ck_assert_int_eq(Info(P), 2);
  P = Next(P);
  while (P != First(L)) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
}

/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
START_TEST(DelP_T1) {
  List L;
  IsiList(&L);
  DelP(&L, 3);
  
  ck_assert_int_eq(NbElmt(L), 2);
  int i = 2;
  address P = First(L);
  ck_assert_int_eq(Info(P), 1);
  P = Next(P);
  while (P != First(L)) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
}

START_TEST(DelP_T2) {
  List L;
  IsiList(&L);
  DelP(&L, 4);
  
  ck_assert_int_eq(NbElmt(L), 3);
  int i = 2;
  address P = First(L);
  ck_assert_int_eq(Info(P), 1);
  P = Next(P);
  while (P != First(L)) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
}

START_TEST(DelP_T3) {
  List L;
  CreateEmpty(&L);
  DelP(&L, 1);
  
  ck_assert_int_eq(NbElmt(L), 0);
}

START_TEST(DelP_T4) {
  List L;
  CreateEmpty(&L);
  InsVLast(&L, 1);
  DelP(&L, 1);
  
  ck_assert_int_eq(NbElmt(L), 0);
}

/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
START_TEST(DelLast_T1) {
  List L;
  IsiList(&L);

  address P;
  DelLast(&L, &P);
  ck_assert_int_eq(Info(P), 3);
  ck_assert_ptr_eq(Next(P), First(L));
  ck_assert_int_eq(NbElmt(L), 2);

  int i = 2;
  P = First(L);
  ck_assert_int_eq(Info(P), 1);
  P = Next(P);
  while (P != First(L)) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
  }
}

START_TEST(DelLast_T2) {
  List L;
  CreateEmpty(&L);
  InsVLast(&L, 1);

  address P;
  DelLast(&L, &P);
  ck_assert_int_eq(Info(P), 1);
  ck_assert_ptr_eq(Next(P), P);
  ck_assert_int_eq(NbElmt(L), 0);
}

/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
START_TEST(DelAfter_T1) {
  List L;
  address Prec, Pdel;
  IsiList(&L);
  Prec = First(L);
  DelAfter(&L, &Pdel, Prec);

  ck_assert_int_eq(NbElmt(L), 2);
  ck_assert_int_eq(Info(Prec), 1);
  ck_assert_int_eq(Info(Pdel), 2);
}

START_TEST(DelAfter_T2) {
  List L;
  int i;

  address Prec, Pdel;
  IsiList(&L);
  for (i = 4; i <= 8; i++) {
    InsVLast(&L, i);
  }

  Prec = First(L);
  for (i = 1; i < 3; i++) {
    Prec = Next(Prec);
  }
  DelAfter(&L, &Pdel, Prec);

  ck_assert_int_eq(NbElmt(L), 7);
  ck_assert_int_eq(Info(Prec), 3);
  ck_assert_int_eq(Info(Pdel), 4);

  i = 2;
  address P = First(L);
  ck_assert_int_eq(Info(P), 1);
  P = Next(P);
  while (P != First(L)) {
    ck_assert_int_eq(Info(P), i);
    P = Next(P);
    i++;
    if (i == 4) {
      i++;
    }
  }
}

START_TEST(PrintInfo_T1) {
  List L;
  int i;
  IsiList(&L);
  for (i = 4; i <= 8; i++) {
    InsVLast(&L, i);
  }
  PrintInfo(L);
  printf("\n");
}

/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */


void IsiList(List *L) {
  /* I.S. L kosong */
  /* F.S. Terbentuk list L dengan 3 elemen pertama berupa 1, 2, dan 3 */
  CreateEmpty(L);
  InsVLast(L, 1);
  InsVLast(L, 2);
  InsVLast(L, 3);
}

int NbElmt(List L) {
  int cnt = 0;
  address P;
  if (!IsEmpty(L)) {
    P = First(L);
    cnt++;
    P = Next(P);
    while (P != First(L)) {
      cnt++;
      P = Next(P);
    }
  }
  return cnt;
}
/* ********** SUITE DAN EKSEKUSI ********** */
Suite *listlinier_suite(void) { 
  Suite *s;
  TCase *tc_prototype, *tc_memory, *tc_search, *tc_primitif, *tc_proses;
  s = suite_create("listsirkuler");

  tc_prototype = tcase_create("Prototype");
  tcase_add_test(tc_prototype, CreateEmpty_TC1);
  tcase_add_test(tc_prototype, IsEmpty_TC1);
  suite_add_tcase(s, tc_prototype);

  tc_memory = tcase_create("Memory");
  tcase_add_test(tc_memory, Alokasi_TC1);
  tcase_add_test(tc_memory, Dealokasi_TC1);
  suite_add_tcase(s, tc_memory);
  tc_search = tcase_create("Search");
  tcase_add_test(tc_search, Search_T1);
  tcase_add_test(tc_search, Search_T2);
  tcase_add_test(tc_search, Search_T3);
  suite_add_tcase(s, tc_search);

  tc_primitif = tcase_create("Primitif");
  tcase_add_test(tc_primitif, InsVFirst_T1);
  tcase_add_test(tc_primitif, InsVFirst_T2);
  tcase_add_test(tc_primitif, InsVLast_T1);
  tcase_add_test(tc_primitif, InsVLast_T2);
  tcase_add_test(tc_primitif, DelVFirst_T1);
  tcase_add_test(tc_primitif, DelVLast_T1);
  tcase_add_test(tc_primitif, InsertFirst_T1);
  tcase_add_test(tc_primitif, InsertAfter_T1);
  tcase_add_test(tc_primitif, InsertLast_T1);
  tcase_add_test(tc_primitif, DelFirst_T1);
  tcase_add_test(tc_primitif, DelP_T1);
  tcase_add_test(tc_primitif, DelP_T2);
  tcase_add_test(tc_primitif, DelP_T3);
  tcase_add_test(tc_primitif, DelP_T4);
  tcase_add_test(tc_primitif, DelLast_T1);
  tcase_add_test(tc_primitif, DelLast_T2);
  tcase_add_test(tc_primitif, DelAfter_T1);
  tcase_add_test(tc_primitif, DelAfter_T2);
  suite_add_tcase(s, tc_primitif);

  tc_proses = tcase_create("Proses");
  tcase_add_test(tc_proses, PrintInfo_T1);
  suite_add_tcase(s, tc_proses);

  return s;
} 

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = listlinier_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL); 
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}