/* check Made by Leonard M. 13519215 */
#include "check.h"
#include "stdio.h"
#include "stdlib.h"
#include "../src/listrek.h"

/****************** TEST LIST KOSONG ******************/
/* Mengirim true jika list kosong */
START_TEST(IsEmpty_TC1) {
  List L = Nil;
  ck_assert_int_eq(IsEmpty(L), 1);
}

START_TEST(IsEmpty_TC2) {
  List L = Nil;
  L = KonsB(L,2);
  ck_assert_int_eq(IsEmpty(L), 0);
}

START_TEST(IsOneElmt_TC1) {
  List L = Nil;
  ck_assert_int_eq(IsOneElmt(L), 0);
}

START_TEST(IsOneElmt_TC2) {
  List L = Nil;
  L = KonsB(L,2);
  ck_assert_int_eq(IsOneElmt(L), 1);
}

START_TEST(IsOneElmt_TC3) {
  List L = Nil;
  L = KonsB(L,2);
  L = KonsB(L,3);
  ck_assert_int_eq(IsOneElmt(L), 0);
}

/****************** Manajemen Memori ******************/
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
START_TEST(Alokasi_TC1) {
  address P = Alokasi(2);
  ck_assert_int_eq(Info(P), 2);
  ck_assert_ptr_eq(Next(P), Nil);
}

/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
START_TEST(Dealokasi_TC1) {
  address P = Alokasi(2);
  // Delokasi, seems impossible to be tested, so just check if no runtime error
  Dealokasi(P);
}

START_TEST(FirstElmt_T1) {
  List L = Nil;
  L = KonsB(L,1);
  ck_assert_int_eq(FirstElmt(L), 1);
}

START_TEST(Tail_T1) {
  List L = Nil;
  L=KonsB(L,1);
  L=KonsB(L,2);
  L=KonsB(L,3);
  ck_assert_int_eq(FirstElmt(Tail(L)),2);
}

START_TEST(Konso_T1) {
  List L = Nil;
  infotype X = 2;
  L = Konso(X, L);
  ck_assert_int_eq(FirstElmt(L), 2);
  ck_assert_int_eq(IsOneElmt(L), 1);
}

START_TEST(Konso_T2){
  List L=Nil;
  L=Konso(1,L);
  L=Konso(2,L);
  ck_assert_int_eq(FirstElmt(L),2);
}

START_TEST(KonsB_T1) {
  List L = Nil;
  infotype X = 2;
  L = KonsB(L, X);
  ck_assert_int_eq(FirstElmt(L), 2);
  ck_assert_int_eq(IsOneElmt(L), 1);
}

START_TEST(KonsB_T2){
  List L=Nil;
  L=KonsB(L,1);
  L=KonsB(L,2);
  ck_assert_int_eq(FirstElmt(L),1);
}

START_TEST(Copy_T1) {
  List L1 = Nil;
  L1=KonsB(L1,1);
  L1=KonsB(L1,2);
  L1=KonsB(L1,3);
  List L2=Copy(L1);
  for (int i=1;i<=3;i++){
    ck_assert_int_eq(Info(L2),i);
    L2=Next(L2);
  }
}

START_TEST(MCopy_T1) {
  List L1 = Nil;
  L1=KonsB(L1,1);
  L1=KonsB(L1,2);
  L1=KonsB(L1,3);
  List L2 = Nil;
  MCopy(L1,&L2);
  int i;
  for (i=1;i<=3;i++){
    ck_assert_int_eq(Info(L2),i);
    L2=Next(L2);
  }
}

START_TEST(Concat_T1) {
  List L1=Nil;
  L1=KonsB(L1,1);
  L1=KonsB(L1,2);
  L1=KonsB(L1,3);
  List L2=Nil;
  L2=KonsB(L2,4);
  L2=KonsB(L2,5);
  L2=KonsB(L2,6);
  List L3=Concat(L1,L2);
  int i;
  for (i=1;i<=6;i++){
    ck_assert_int_eq(Info(L3),i);
    L3=Next(L3);
  }
}

START_TEST(MConcat_T1) {
  List L1=Nil;
  L1=KonsB(L1,1);
  L1=KonsB(L1,2);
  L1=KonsB(L1,3);
  List L2=Nil;
  L2=KonsB(L2,4);
  L2=KonsB(L2,5);
  L2=KonsB(L2,6);
  List L3=Nil;
  MConcat(L1,L2,&L3);
  int i;
  for (i=1;i<=6;i++){
    ck_assert_int_eq(Info(L3),i);
    L3=Next(L3);
  }
}

START_TEST(NbElmtList_T1) {
  List L = Nil;
  ck_assert_int_eq(NbElmtList(L), 0);
}
START_TEST(NbElmtList_T2){
  List L=Nil;
  L=KonsB(L,1);
  ck_assert_int_eq(NbElmtList(L),1);
}
START_TEST(NbElmtList_T3){
  List L=Nil;
  L=KonsB(L,1);
  L=KonsB(L,2);
  ck_assert_int_eq(NbElmtList(L),2);
}

START_TEST(PrintList_T1) {
  List L = Nil;
  L=KonsB(L,1);
  L=KonsB(L,2);
  L=KonsB(L,3);
  L=KonsB(L,4);
  PrintList(L);
  ck_assert_int_eq(FirstElmt(L), 1);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
/* Mencari apakah ada elemen list dengan P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
START_TEST(Search_T1) {
  List L=Nil;
  L=KonsB(L,1);
  L=KonsB(L,2);
  L=KonsB(L,3);
  ck_assert_int_eq(Search(L,2),1);
}

START_TEST(Search_T2) {
  List L=Nil;
  L=KonsB(L,1);
  L=KonsB(L,2);
  L=KonsB(L,3);
  ck_assert_int_eq(Search(L,4),0);
}

START_TEST(Search_T3) {
  List L = Nil;
  ck_assert_int_eq(Search(L,2), 0);
}

/* ********** SUITE DAN EKSEKUSI ********** */
Suite *listlinier_suite(void) { 
  Suite *s;
  TCase *tc_prototype, *tc_memory, *tc_search, *tc_primitif, *tc_proses;
  s = suite_create("listrekursif");

  tc_prototype = tcase_create("Prototype");
  tcase_add_test(tc_prototype, IsEmpty_TC1);
  tcase_add_test(tc_prototype, IsEmpty_TC2);
  tcase_add_test(tc_prototype, IsOneElmt_TC1);
  tcase_add_test(tc_prototype, IsOneElmt_TC2);
  tcase_add_test(tc_prototype, IsOneElmt_TC3);
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
  tcase_add_test(tc_primitif, FirstElmt_T1);
  tcase_add_test(tc_primitif, Tail_T1);
  tcase_add_test(tc_primitif, Konso_T1);
  tcase_add_test(tc_primitif, Konso_T2);
  tcase_add_test(tc_primitif, KonsB_T1);
  tcase_add_test(tc_primitif, KonsB_T2);
  tcase_add_test(tc_primitif, Copy_T1);
  tcase_add_test(tc_primitif, MCopy_T1);
  tcase_add_test(tc_primitif, Concat_T1);
  tcase_add_test(tc_primitif, MConcat_T1);
  tcase_add_test(tc_primitif, NbElmtList_T1);
  tcase_add_test(tc_primitif, NbElmtList_T2);
  tcase_add_test(tc_primitif, NbElmtList_T3);
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