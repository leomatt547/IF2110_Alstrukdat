/*Nama : Leonard Matheus
NIM : 13519215
Tanggal: 24 November 2020
Topik: PraPraktikum 12
*/

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "bintree.h"

/* *** Konstruktor *** */
BinTree Tree(infotype Akar, BinTree L, BinTree R){
    BinTree Tree=(BinTree) malloc(sizeof(BinTree));
    if(Tree!=Nil){
        Akar(Tree)=Akar;
        Left(Tree)=L;
        Right(Tree)=R;
        return Tree;
    }else{
        return Nil;
    }
}
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P){
    *P=Tree(Akar, L, R);
}
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
BinTree BuildBalanceTree(int n){
    int Akar;
    BinTree Left;
    BinTree Right;
    if(n == 0){
        return Nil;
    }
    scanf("%d",&Akar);
    Left = BuildBalanceTree(n/2);
    Right = BuildBalanceTree(n - n/2 - 1);
    return Tree(Akar, Left, Right);
}
/* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca */

/* Manajemen Memory */
addrNode AlokNode(infotype X){
    addrNode Node = (addrNode) malloc(sizeof(Node));
    if(Node!=Nil){
        Akar(Node)=X;
        Left(Node)=Nil;
        Right(Node)=Nil;
        return Node;
    }else{
        return Nil;
    }
}
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokNode(addrNode P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P){
    return (P==Nil);
}
/* Mengirimkan true jika P adalah pohon biner kosong */
boolean IsTreeOneElmt(BinTree P){
    if(!IsTreeEmpty(P)){
        return ((Left(P)==Nil)&&(Right(P)==Nil));
    }else{
        return false;
    }
}
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
boolean IsUnerLeft(BinTree P){
    if(!IsTreeEmpty(P)){
        return ((Left(P)!=Nil)&&(Right(P)==Nil));
    }else{
        return false;
    }
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
boolean IsUnerRight(BinTree P){
    if(!IsTreeEmpty(P)){
        return ((Left(P)==Nil)&&(Right(P)!=Nil));
    }else{
        return false;
    }
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
boolean IsBiner(BinTree P){
     if(!IsTreeEmpty(P)){
        return ((Left(P)!=Nil)&&(Right(P)!=Nil));
    }else{
        return false;
    }
}
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/

/* *** Traversal *** */
void PrintPreorder(BinTree P){
    printf("(");
    if(!IsTreeEmpty(P)){
        printf("%d",Akar(P));
        PrintPreorder(Left(P));
        PrintPreorder(Right(P));
    }
    printf(")");
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
void PrintInorder(BinTree P){
    printf("(");
    if(!IsTreeEmpty(P)){
        PrintInorder(Left(P));
        printf("%d",Akar(P));
        PrintInorder(Right(P));
    }
    printf(")");
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
void PrintPostorder(BinTree P){
    printf("(");
    if(!IsTreeEmpty(P)){
        PrintPostorder(Left(P));
        PrintPostorder(Right(P));
        printf("%d",Akar(P));
    }
    printf(")");
}

void printtree(BinTree P, int h, int masuk){
    if (!IsTreeEmpty(P)){
        printf("%*s%d\n", masuk, "", Akar(P));
        printtree(Left(P), h, masuk+h);
        printtree(Right(P), h, masuk+h);
    }
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
void PrintTree(BinTree P, int h){
    printtree(P,h,0);
}
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/

/* *** Searching *** */
boolean SearchTree(BinTree P, infotype X){
    if(IsTreeEmpty(P)){
        return false;
    }else{
        if(Akar(P)==X){
            return true;
        }else{
            return(SearchTree(Left(P), X)||SearchTree(Right(P), X));
        }
    }
}
/* Mengirimkan true jika ada node dari P yang bernilai X */

/* *** Fungsi-Fungsi Lain *** */
int NbElmt(BinTree P){
    if(IsTreeEmpty(P)){
        return 0;
    }else{
        return (NbElmt(Left(P))+NbElmt(Right(P))+1) ;
    }
}
/* Mengirimkan banyaknya elemen (node) pohon biner P */
int NbDaun(BinTree P){
    if(IsTreeEmpty(P)){
        return 0;
    }else{
        if(IsTreeOneElmt(P)){
            return 1;
        }else{
            return(NbDaun(Left(P))+NbDaun(Right(P)));
        }
    }
}
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
boolean IsSkewLeft(BinTree P){
    if (IsTreeEmpty(P)){
        return true;
    }else if(IsTreeOneElmt(P)){
        return true;
    }
    else{
        return IsSkewLeft(Left(P))&&(Right(P)==Nil);
    }
}
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
boolean IsSkewRight(BinTree P){
    if(IsTreeEmpty(P)){
        return true;
    }else if(IsTreeOneElmt(P)){
        return true;
    }else{
        return (IsSkewRight(Right(P))&&(Left(P)==Nil));
    }
}
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
int Level(BinTree P, infotype X){
    if(SearchTree(Left(P), X)){
        return (1+Level(Left(P),X));
    }else if(SearchTree(Right(P),X)){
        return (1+Level(Right(P),X));
    }else{
        return 1;
    }
}
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. 
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
int Tinggi(BinTree P){
    if (IsTreeEmpty(P)){
        return 0;
    }else{
        int Tinggi_l=Tinggi(Left(P));
        int Tinggi_r=Tinggi(Right(P));
        if (Tinggi_l > Tinggi_r){
            return (Tinggi_l+1);
        }else{
            return (Tinggi_r+1);
        }
    }
}
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */

/* *** Operasi lain *** */
void AddDaunTerkiri(BinTree *P, infotype X){
    if(IsTreeEmpty(*P)){
        *P=Tree(X,Nil,Nil);
    }else{
        AddDaunTerkiri(&Left(*P), X);
    }
}
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
void AddDaun(BinTree *P, infotype X, infotype Y, boolean Kiri){
    if (IsTreeOneElmt(*P)&&Akar(*P) == X){
        if(Kiri){
            Left(*P)=Tree(Y,Nil,Nil);
        }else{
            Right(*P)=Tree(Y,Nil,Nil);
        }
    }else{
        if (SearchTree(Left(*P),X)){
            AddDaun(&Left(*P),X,Y,Kiri);
        }else if(SearchTree(Right(*P),X)){
            AddDaun(&Right(*P),X,Y,Kiri);
        }
    }
}
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau 
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
void DelDaunTerkiri(BinTree *P, infotype *X){
    addrNode Temp;
    if (IsTreeOneElmt(*P)){
        *X=Akar(*P);
        Temp=*P;
        *P=Nil;
        DealokNode(Temp);
    }else{
        if (IsUnerRight(*P)){
            DelDaunTerkiri(&Right(*P),X);
        }else{
            DelDaunTerkiri(&Left(*P),X);
        }
    }
}
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula 
        disimpan pada daun terkiri yang dihapus */
void DelDaun(BinTree *P, infotype X){
    addrNode Temp;
    if (!IsTreeEmpty(*P)){
        if (IsTreeOneElmt(*P)&&Akar(*P)==X){
            Temp=*P;
            *P = Nil;
            DealokNode(Temp);
        }else{
            DelDaun(&Left(*P),X);
            DelDaun(&Right(*P),X);
        }
    }
}
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
List MakeListDaun(BinTree P){
    if(IsTreeEmpty(P)){
        return Nil;
    }else if(IsTreeOneElmt(P)){
        return Alokasi(Akar(P));
    }else{
        return Concat(MakeListDaun(Left(P)),MakeListDaun(Right(P)));
    }
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
   jika semua alokasi list berhasil.
   Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
List MakeListPreorder(BinTree P){
    List Left_l;
    List Right_l;
    if (IsTreeEmpty(P)){
        return Nil;
    }else{
        Left_l=MakeListPreorder(Left(P));
        Right_l=MakeListPreorder(Right(P));
        return Concat(Konso(Akar(P),Left_l), Right_l);
    }
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P 
   dengan urutan preorder, jika semua alokasi berhasil.   
   Menghasilkan list kosong jika ada alokasi yang gagal. */
List MakeListLevel(BinTree P, int N){
    List Left_l;
    List Right_l;
    if (IsTreeEmpty(P)){
        return Nil;
    }else if (N==1){
        return Alokasi(Akar(P));
    }else{
        Left_l=MakeListLevel(Left(P),N-1);
        Right_l=MakeListLevel(Right(P),N-1);
        if(Left_l==Nil){
            return Right_l;
        }
        if(Right_l==Nil){
            return Left_l;
        }
        return (Concat(Left_l, Right_l));
    }
}
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P 
   yang levelnya=N, jika semua alokasi berhasil. 
   Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */

/* *** Binary  Search  Tree  *** */
boolean BSearch(BinTree P, infotype X){
    if(IsTreeEmpty(P)){
        return false;
    }else{
        if(Akar(P)==X){
            return true;
        }else if(X > Akar(P)){
            BSearch(Right(P),X);
        }else{
            BSearch(Left(P),X);
        }
    }
}
/* Mengirimkan true jika ada node dari P yang bernilai X */

void InsSearch(BinTree *P, infotype X){
    if(IsTreeEmpty(*P)){
        *P = AlokNode(X);
    }else{
        if(X >= Akar(*P)){
            InsSearch(&Right(*P),X);
        }else{
            InsSearch(&Left(*P),X);
        }
    }
}
/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. */

void DelNode(BinTree *P, infotype X){
    if(Right(*P)!=Nil){
        DelNode(&Right(*P),X);
    }
    else{
        X = Akar(*P);
        *P = Left(*P);
    }
}
void DelBtree(BinTree *P, infotype X){
    if(X < Akar(*P)){
        DelBtree(&Left(*P),X);
    }else if(X>Akar(*P)){
        DelBtree(&Right(*P),X);
    }else{
        if(IsTreeOneElmt(*P)){
            *P = Nil;
        }else if(IsUnerLeft(*P)){
            *P = Left(*P);
        }else if(IsUnerRight(*P)){
            *P = Right(*P);
        }else{
            DelNode(&Left(*P),X);
        }
    }
}
/* I.S. Pohon P tidak  kosong */
/* F.S. Nilai X yang dihapus pasti ada */
/* Sebuah node dengan nilai X dihapus */