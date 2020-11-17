/* check Made by Leonard M. 13519215 */
#include "check.h"
#include "stdio.h"
#include "stdlib.h"
#include "../src/listrek.h"

void IsiList(List *L){
  infotype i;
  for (i = 1; i<=3; i++){
    Alokasi(i);
    Konso(i,*L);
  }
}

void IsiList1(List *L){
  Alokasi(1);
  Konso(1,*L);
}

/****************** TEST LIST KOSONG ******************/
/* Mengirim true jika list kosong */
START_TEST(IsEmpty_TC1) {
  List L;
  IsiList(&L);
  ck_assert_int_eq(0, IsEmpty(L));
}

START_TEST(IsOneElmt_TC1) {
  List L;
  IsiList1(&L);
  ck_assert_int_eq(1, IsOneElmt(L));
}

/****************** Manajemen Memori ******************/
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka P)=X, Next(P)=Nil */
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
/* Mencari apakah ada elemen list dengan P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
START_TEST(Search_T1) {
  List L;
  int P;
  infotype search = 2;
  IsiList(&L);
  P = Search(L, search);
  ck_assert_int_eq(P, 1);
}

START_TEST(Search_T2) {
  List L;
  int P;
  infotype search = 6;
  IsiList(&L);
  P = Search(L, search);
  ck_assert_int_eq(P, 0);
}

START_TEST(FirstElmt_T1) {
  List L;
  IsiList(&L);
  ck_assert_int_eq(NbElmtList(L), 3);
  ck_assert_int_eq(Info(L), 1);
}

START_TEST(Tail_T1) {
  List L;
  IsiList(&L);
  L = Tail(L);
  ck_assert_int_eq(NbElmtList(L), 1);
  ck_assert_int_eq(Info(L), 2);
}

START_TEST(Konso_T1) {
  List L;
  infotype X = 2;
  IsiList(&L);
  Konso(X, L);
  ck_assert_int_eq(NbElmtList(L), 4);
  ck_assert_int_eq(Info(L), 2);
}

START_TEST(KonsB_T1) {
  List L;
  infotype X = 2;
  IsiList(&L);
  Konso(X, L);
  ck_assert_int_eq(NbElmtList(L), 4);
  ck_assert_int_eq(Info(L), 1);
}

START_TEST(Copy_T1) {
  List L;
  List L3;
  IsiList(&L);
  L3 = Copy(L);
  ck_assert_int_eq(NbElmtList(L3), 3);
  ck_assert_int_eq(Info(L3), 1);
}

START_TEST(MCopy_T1) {
  List L;
  List L3;
  IsiList(&L);
  MCopy(L, &L3);
  ck_assert_int_eq(NbElmtList(L3), 3);
  ck_assert_int_eq(Info(L3), 1);
}

START_TEST(Concat_T1) {
  List L1,L2;
  List L3;
  IsiList(&L1);
  IsiList(&L2);
  L3 = Concat(L1,L2);
  ck_assert_int_eq(NbElmtList(L3), 6);
  ck_assert_int_eq(Info(L3), 1);
}

START_TEST(MConcat_T1) {
  List L1,L2;
  List L3;
  IsiList(&L1);
  IsiList(&L2);
  MConcat(L1,L2,&L3);
  ck_assert_int_eq(NbElmtList(L3), 6);
  ck_assert_int_eq(Info(L3), 1);
}

START_TEST(NbElmtList_T1) {
  List L;
  IsiList(&L);
  ck_assert_int_eq(NbElmtList(L), 3);
}

START_TEST(PrintList_T1) {
  List L;
  IsiList(&L);
  PrintList(L);
  ck_assert_int_eq(NbElmtList(L), 3);
}

/* ********** SUITE DAN EKSEKUSI ********** */
Suite *listlinier_suite(void) { 
  Suite *s;
  TCase *tc_prototype, *tc_memory, *tc_search, *tc_primitif, *tc_proses;
  s = suite_create("listrekursif");

  tc_prototype = tcase_create("Prototype");
  tcase_add_test(tc_prototype, IsOneElmt_TC1);
  tcase_add_test(tc_prototype, IsEmpty_TC1);
  suite_add_tcase(s, tc_prototype);

  tc_memory = tcase_create("Memory");
  tcase_add_test(tc_memory, Alokasi_TC1);
  tcase_add_test(tc_memory, Dealokasi_TC1);
  suite_add_tcase(s, tc_memory);

  tc_search = tcase_create("Search");
  tcase_add_test(tc_search, Search_T1);
  tcase_add_test(tc_search, Search_T2);
  suite_add_tcase(s, tc_search);

  tc_primitif = tcase_create("Primitif");
  tcase_add_test(tc_primitif, FirstElmt_T1);
  tcase_add_test(tc_primitif, Tail_T1);
  tcase_add_test(tc_primitif, Konso_T1);
  tcase_add_test(tc_primitif, KonsB_T1);
  tcase_add_test(tc_primitif, Copy_T1);
  tcase_add_test(tc_primitif, MCopy_T1);
  tcase_add_test(tc_primitif, Concat_T1);
  tcase_add_test(tc_primitif, MConcat_T1);
  tcase_add_test(tc_primitif, NbElmtList_T1);
  suite_add_tcase(s, tc_primitif);

  tc_proses = tcase_create("Proses");
  tcase_add_test(tc_proses, PrintList_T1);
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