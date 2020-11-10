#include "check.h"
#include "stdio.h"
#include "stdlib.h"
#include "../src/listsirkuler.h"

/****************** PEMBUATAN LIST KOSONG ******************/
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
START_TEST(CreateEmpty_TC1) {
  List L;
  CreateEmpty(&L);
  ck_assert_ptr_eq(First(L), Nil);
}

/* ********** SUITE DAN EKSEKUSI ********** */
Suite *listlinier_suite(void) { 
  Suite *s;
  TCase *tc_prototype, *tc_memory, *tc_search, *tc_primitif, *tc_proses;
  s = suite_create("listdp");

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
  tcase_add_test(tc_proses, NbElmt_T1);
  tcase_add_test(tc_proses, NbElmt_T2);
  tcase_add_test(tc_proses, Min_T1);
  tcase_add_test(tc_proses, Max_T1);
  tcase_add_test(tc_proses, Konkat1_T1);
  tcase_add_test(tc_proses, Konkat1_T2);
  tcase_add_test(tc_proses, Konkat1_T3);
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