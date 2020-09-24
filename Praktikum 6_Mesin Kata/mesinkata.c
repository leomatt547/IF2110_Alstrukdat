/*
Nama: Leonard Matheus
NIM: 13519215
Topik: Pra-Praktikum 5
Deskripsi: mesin kata
*/

#include <stdio.h>
#include "mesinkata.h"

void IgnoreBlank(){
    while (CC==BLANK){
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA(){
    IgnoreBlank();
    if (CC==MARK){
        EndKata = true;
    }else{
        EndKata = false;
        SalinKata();
    }
}
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA(){
    IgnoreBlank();
    if(CC==MARK){
        EndKata = true;
    }
    else{
        SalinKata();
    }
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata(){
    int i = 0;
    while ((CC!=MARK)||(CC!=BLANK)){
        CC = CKata.TabKata[i];
        ADV();
        i++;
    }
}
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */