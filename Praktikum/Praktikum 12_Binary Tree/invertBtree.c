/*Nama : Leonard Matheus
NIM : 13519215
Tanggal: 26 November 2020
Topik: Praktikum 12
*/

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include "listrek.h"

void InvertBtree(BinTree *P){
    if(!IsTreeEmpty(*P)){
        InvertBtree(&Right(*P));
	    InvertBtree(&Left(*P));
	    *P = Tree(Akar(*P),Right(*P),Left(*P));
    }
}
/* I.S. Pohon P terdefinisi */
/* F.S. Pohon P diflip secara vertikal */
/*      Contoh:
           1
         2   5
        3 4 6
        Menjadi:
           1
         5   2
          6 4 3 */
