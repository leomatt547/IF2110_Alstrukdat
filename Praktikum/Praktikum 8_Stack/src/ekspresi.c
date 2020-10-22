// NIM      : 13519163 
// Nama     : Alvin Wilta
// Tanggal  : 22/10/2020
// Topik    : Stack
// Deskripsi: Praktikum Stack
/* Dengan memanfaatkan ADT Stack yang telah Anda kerjakan sebagai tugas pra-praktikum (file header: stackt.h) dan Mesin Token yang dihasilkan pada praktikum sebelumnya, buatlah sebuah program dalam file bernama ekspresi.c yang membaca sebuah pita karakter yang hanya berisi bilangan positif dan 0 serta operator ’+’, ’-’, ’*’, ’/’, dan ’^’ yang membentuk sebuah ekspresi aritmatika dalam notasi postfix dan mengevaluasi ekspresi yang terdapat pada pita karakter tersebut.


Secara lebih rinci, program memroses hasil dari mesin token sebagai berikut:

Apabila menerima token bilangan, maka bilangan yang dibaca ditampilkan di layar dan dimasukkan ke dalam stack.

Apabila menerima token operator, maka operan yang sesuai diambil dari stack, sub ekspresi yang harus dieksekusi dituliskan ke layar (format <operan1> <operator> <operan2>), hitung hasil sub ekspresi tersebut, tampilkan ke layar, dan masukkan ke dalam stack. Operan ”/” diartikan sebagai pembagian bilangan bulat (div).

Apabila pembacaan pita karakter telah selesai, hasil akhir ekspresi dituliskan ke layar.


Program akan menuliskan pesan ”Ekspresi kosong” apabila pita karakter kosong.


Petunjuk:

Untuk operasi ’^’ gunakan fungsi pow pada library math.h.*/

#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "mesintoken.h"
#include "stackt.h"

int main() {
	Stack S;
	CreateEmpty(&S);
	STARTTOKEN();
	while (!EndToken) {
		if (CToken.tkn == 'b') {
			Push(&S, CToken.val);
			printf("%d\n", CToken.val);
		} else {
			int a,b,hasil;
			Pop(&S, &a);
			Pop(&S, &b);
			printf("%d %c %d\n", b, CToken.tkn, a);
			
			switch(CToken.tkn) {
				case '+':
					hasil = b + a;
					break;
				case '-':
					hasil = b - a;
					break;
				case '*':
					hasil = b * a;
					break;
				case '/':
					hasil = b / a;
					break;
				case '^':
					hasil = pow(b , a);
					break;
			}
			
			Push(&S, hasil);
			printf("%d\n", hasil);
		}
		ADVTOKEN();
	}
	if (IsEmpty(S))
		printf("Ekspresi kosong\n");
	else {
		int hasil;
		Pop(&S, &hasil);
		printf("Hasil=%d\n", hasil);
	}
	return 0;
} 

