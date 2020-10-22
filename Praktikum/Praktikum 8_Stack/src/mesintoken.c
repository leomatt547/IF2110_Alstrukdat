// Nama     : Alvin Wilta
// NIM      : 13519163
// Tanggal  : 01/10/2020
// Topik    : Praktikum 6
/* Deskripsi: Mesin Token
Dengan mengadaptasi Mesin Kata yang telah Anda kerjakan sebagai tugas pra-praktikum, buatlah modifikasi terhadap mesin kata tersebut sehingga menjadi Mesin Token yang memiliki spesifikasi sebagai berikut:

Mesin token membaca pita karakter yang hanya berisi rangkaian bilangan bulat dan operator. Ada lima operator yang dikenali, yaitu: +, -, *, /, dan ^.

Mesin token akan membaca pita karakter dan mengembalikan nilai CToken yang bertipe Token, dengan struktur sebagai berikut:

type Token : < tkn : character, {token yang dibaca} 
               val : integer {nilai bilangan apabila tkn = ‘b’}
             >
dengan

tkn berisi token yang diakuisisi. Ada 6 nilai yang mungkin bagi tkn yaitu ‘+’, ‘-’, ‘*’, ‘/’, dan ‘^’ masing-masing untuk setiap operator yang terdefinisi, serta ‘b’ untuk token yang merupakan bilangan.
val berisi nilai dari bilangan yang diakuisisi, apabila tkn berisi ‘b’. Apabila tkn adalah salah satu dari lima operator, maka nilai val diabaikan (diisi -1).

Diasumsikan setiap token dalam pita karakter selalu dipisahkan spasi.

Karena tidak mengenal tanda, maka semua bilangan yang diakuisisi pasti merupakan bilangan positif.

Petunjuk untuk proses konversi menjadi bilangan:

321 = (((3 *10) + 2) * 10) + 1


Header file ADT Token dapat dilihat pada file: mesintoken.h. Buatlah mesintoken.c.
*/

#include "boolean.h"
#include "mesinkar.c"
#include "mesintoken.h"

#define NMax 50
#define BLANK ' '


/* State Mesin Kata */
boolean EndToken;
Token CToken;


void IgnoreBlank(){
    while ((CC == BLANK) && (CC != MARK)) {
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTTOKEN() {
    EndToken = false;
    START();
    ADVTOKEN();
}
/* I.S. : CC sembarang
   F.S. : EndToken = true, dan CC = MARK;
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */

void ADVTOKEN() {
    IgnoreBlank();
    if (CC == MARK) {
        EndToken= true;
    } else {
        SalinToken();
    }
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinToken() {
	CToken.tkn = CC;
	if (CC == '+' || CC == '-' || CC == '*' || CC == '/' || CC == '^') {
		CToken.val = -1;
		ADV();
	} else {
		CToken.tkn = 'b';
		CToken.val = 0;
		while (CC != MARK && CC != BLANK) {
			CToken.val *= 10;
			CToken.val += (int) (CC - '0');
			ADV();
		}
	}
}

/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */