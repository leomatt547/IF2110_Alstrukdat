#include "check.h"
#include "stdio.h"
#include "stdlib.h"
#include "../src/bintree.h"
#include "../src/listrek.h"

BinTree BuildBalanceCheck(int n,infotype i);
int NbElmtCheck(BinTree P);
addrNode AlokNodeCheck(infotype x);

/****************** TEST LIST KOSONG ******************/
/* Mengirim true jika list kosong */
START_TEST(IsTreeEmpty_TC1) {
  BinTree P=Nil;
  ck_assert_int_eq(1, IsTreeEmpty(P));
  P = AlokNode(1);
  ck_assert_int_eq(0, IsTreeEmpty(P));
} END_TEST

/* Mengirim true jika list hanya 1 elemen */
START_TEST(IsTreeOneElmt_TC1) {
  BinTree P = Nil;
  ck_assert_int_eq(0, IsTreeOneElmt(P));
  P = AlokNodeCheck(1);
  ck_assert_int_eq(1, IsTreeOneElmt(P));
} END_TEST

START_TEST(IsUnerLeft_TC1) {
  BinTree P = Nil,L;
  L = AlokNodeCheck(1);
  MakeTree(2,L,Nil,&P);
  ck_assert_int_eq(1, IsUnerLeft(P));
} END_TEST

START_TEST(IsUnerRight_TC1) {
  BinTree P = Nil,R;
  R = AlokNodeCheck(1);
  MakeTree(2,Nil,R,&P);
  ck_assert_int_eq(1, IsUnerRight(P));
} END_TEST

START_TEST(IsBiner_TC1) {
  BinTree P = Nil,L,R;
  L = AlokNodeCheck(1); R = AlokNodeCheck(2);
  MakeTree(3,L,R,&P);
  ck_assert_int_eq(1, IsBiner(P));
} END_TEST

/****************** Manajemen Memori ******************/
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
START_TEST(AlokNode_TC1) {
  infotype X = 2;
  addrNode P = AlokNode(X);
  ck_assert_int_eq(Info(P), X);
  ck_assert_ptr_eq(Left(P), Nil);
  ck_assert_ptr_eq(Right(P), Nil);
} END_TEST

/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
START_TEST(DealokNode_TC1) {
  infotype X = 2;
  addrNode P = AlokNode(X);
  // Delokasi, seems impossible to be tested, so just check if no runtime error
  DealokNode(P);
} END_TEST

/****************** KONSTRUKTOR ******************/
START_TEST(Tree_T1) {
  BinTree P = Nil;
  P = Tree(1,Nil,Nil);
  ck_assert_int_eq(NbElmtCheck(P), 1);
  ck_assert_int_eq(Akar(P), 1);
} END_TEST

START_TEST(MakeTree_T1) {
  BinTree P = Nil;
  MakeTree(1,Nil,Nil,&P);

  ck_assert_int_eq(NbElmtCheck(P), 1);
  ck_assert_int_eq(Akar(P), 1);
} END_TEST

START_TEST(AddDaunTerkiri_T1) {
  BinTree P = Nil;
  MakeTree(1,Nil,Nil,&P);
  AddDaunTerkiri(&P,2);

  ck_assert_int_eq(NbElmtCheck(P), 2);
  ck_assert_int_eq(Akar(Left(P)), 2);
} END_TEST

START_TEST(AddDaun_T1) {
  BinTree P = Nil;
  MakeTree(1,Nil,Nil,&P);
  AddDaun(&P,1,2,true);

  ck_assert_int_eq(NbElmtCheck(P), 2);
  ck_assert_int_eq(Akar(Left(P)), 2);
} END_TEST

START_TEST(DelDaunTerkiri_T1) {
  BinTree P = Nil;
  infotype X;
  P = BuildBalanceCheck(5,4);
  DelDaunTerkiri(&P,&X);

  ck_assert_int_eq(NbElmtCheck(P), 4);
  ck_assert_int_eq(X, 2);
} END_TEST

START_TEST(DelDaun_T1) {
  BinTree P = Nil;
  P = BuildBalanceCheck(5,4);
  DelDaun(&P,2);
  ck_assert_int_eq(NbElmtCheck(P), 4);
} END_TEST

/*** OPERASI LAIN ***/
START_TEST(SearchTree_T1) {
  BinTree P = Nil;
  P = BuildBalanceCheck(5,4);

  ck_assert_int_eq(1, SearchTree(P,4));
  ck_assert_int_eq(0, SearchTree(P,1));
} END_TEST

START_TEST(NbElmt_T1) {
  BinTree P = Nil;
  P = BuildBalanceCheck(5,4);

  ck_assert_int_eq(5, NbElmt(P));
} END_TEST

START_TEST(NbDaun_T1) {
  BinTree P = Nil;
  P = BuildBalanceCheck(5,4);

  ck_assert_int_eq(2, NbDaun(P));
} END_TEST

START_TEST(IsSkewLeft_T1) {
  BinTree P = Nil,L1,L2;
  L2 = AlokNodeCheck(1);
  MakeTree(2,L2,Nil,&L1);
  MakeTree(3,L1,Nil,&P);

  ck_assert_int_eq(1, IsSkewLeft(P));
} END_TEST

START_TEST(IsSkewRight_T1) {
  BinTree P = Nil,R1,R2;
  R2 = AlokNodeCheck(1);
  MakeTree(2,Nil,R2,&R1);
  MakeTree(3,Nil,R1,&P);

  ck_assert_int_eq(1, IsSkewRight(P));
} END_TEST

START_TEST(Level_T1) {
  BinTree P = Nil;
  P = BuildBalanceCheck(5,4);

  ck_assert_int_eq(2, Level(P,5));
} END_TEST

START_TEST(Tinggi_T1) {
  BinTree P = Nil;
  P = BuildBalanceCheck(5,4);

  ck_assert_int_eq(3, Tinggi(P));
} END_TEST

/*** PEMBUATAN LIST LINIER ***/
START_TEST(MakeListDaun_T1) {
  BinTree P = Nil;
  List L;
  P = BuildBalanceCheck(5,4);
  L = MakeListDaun(P);
  //PrintPreorder(P);printf("\n");

  ck_assert_int_eq(2, Info(L));
} END_TEST

START_TEST(MakeListPreorder_T1) {
  BinTree P = Nil;
  List L;
  P = BuildBalanceCheck(5,4);
  L = MakeListPreorder(P);

  ck_assert_int_eq(4, Info(L));
} END_TEST

START_TEST(MakeListLevel_T1) {
  BinTree P = Nil;
  List L;
  P = BuildBalanceCheck(5,4);
  L = MakeListLevel(P,2);

  ck_assert_int_eq(3, Info(L));
} END_TEST

/*** Binary Search Tree ***/
START_TEST(BSearch_T1) {
  BinTree P = Nil;
  P = BuildBalanceCheck(5,4);

  ck_assert_int_eq(1, BSearch(P,5));
} END_TEST

START_TEST(InsSearch_T1) {
  BinTree P = Nil;
  P = BuildBalanceCheck(5,4);
  InsSearch(&P,8);

  ck_assert_int_eq(NbElmtCheck(P),6);
} END_TEST

START_TEST(DelBtree_T1) {
  BinTree P = Nil;
  P = BuildBalanceCheck(5,4);
  DelBtree(&P,2);

  ck_assert_int_eq(4,NbElmtCheck(P));
} END_TEST

BinTree BuildBalanceCheck(int n,infotype i){
  BinTree L,R; addrNode P;
  int nR,nL;
  if (n==0) return Nil;
  else{
    P = AlokNode(i);
    if (P!=Nil){   
      nL =(int) n/2; nR = n-nL-1;
      L = BuildBalanceCheck(nL,i-1);
      R = BuildBalanceCheck(nR,i+1);
      Left(P) = L; Right(P) = R;
    }
    return P;
  }
}

addrNode AlokNodeCheck(infotype X){
  addrNode P = (addrNode) malloc(sizeof(Node));
  if (P!=Nil){
    Akar(P) = X;
    Left(P) = Nil;
    Right(P) = Nil;
    return P;
  }else return Nil;
}

int NbElmtCheck (BinTree P){
/* Mengirimkan banyaknya elemen P, Nol jika P kosong */
  if (IsTreeEmpty(P)){// Basis 0
    return 0;
  }else{// Rekurens
    return 1+NbElmt(Left(P))+NbElmt(Right(P));
  }
}

/* ********** SUITE DAN EKSEKUSI ********** */
Suite *bintree_suite(void) {
  Suite *s;
  TCase *tc_prototype, *tc_memory, *tc_konstruktor, *tc_operasi, *tc_list, *tc_bst;
  s = suite_create("Binary Tree");

  tc_prototype = tcase_create("Prototype");
  tcase_add_test(tc_prototype, IsTreeEmpty_TC1);
  tcase_add_test(tc_prototype, IsTreeOneElmt_TC1);
  tcase_add_test(tc_prototype, IsUnerLeft_TC1);
  tcase_add_test(tc_prototype, IsUnerRight_TC1);
  tcase_add_test(tc_prototype, IsBiner_TC1);
  suite_add_tcase(s, tc_prototype);

  tc_memory = tcase_create("Memory");
  tcase_add_test(tc_memory, AlokNode_TC1);
  tcase_add_test(tc_memory, DealokNode_TC1);
  suite_add_tcase(s, tc_memory);

  tc_konstruktor = tcase_create("Konstruktor");
  tcase_add_test(tc_konstruktor, Tree_T1);
  tcase_add_test(tc_konstruktor, MakeTree_T1);
  tcase_add_test(tc_konstruktor, AddDaunTerkiri_T1);
  tcase_add_test(tc_konstruktor, AddDaun_T1);
  tcase_add_test(tc_konstruktor, DelDaunTerkiri_T1);
  tcase_add_test(tc_konstruktor, DelDaun_T1);
  suite_add_tcase(s, tc_konstruktor);

  tc_operasi = tcase_create("Operasi");
  tcase_add_test(tc_operasi, SearchTree_T1);
  tcase_add_test(tc_operasi, NbElmt_T1);
  tcase_add_test(tc_operasi, NbDaun_T1);
  tcase_add_test(tc_operasi, IsSkewLeft_T1);
  tcase_add_test(tc_operasi, IsSkewRight_T1);
  tcase_add_test(tc_operasi, Level_T1);
  tcase_add_test(tc_operasi, Tinggi_T1);
  suite_add_tcase(s, tc_operasi);

  tc_list = tcase_create("List");
  tcase_add_test(tc_list, MakeListDaun_T1);
  tcase_add_test(tc_list, MakeListPreorder_T1);
  tcase_add_test(tc_list, MakeListLevel_T1);
  suite_add_tcase(s, tc_list);

  tc_bst = tcase_create("BST");
  tcase_add_test(tc_bst, BSearch_T1);
  tcase_add_test(tc_bst, InsSearch_T1);
  tcase_add_test(tc_bst, DelBtree_T1);
  suite_add_tcase(s, tc_bst);

  return s;
}

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = bintree_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
