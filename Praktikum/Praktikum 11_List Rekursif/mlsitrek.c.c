// Nama/NIM     : Jonathan Yudi Gunawan/13518084
// Hari, Tanggal  : Selasa, 29 Oktober 2019
// Topik/Deskripsi  : Variasi List Linier/ADT List Rekursif nya Tuan Yon

#include <stdio.h>
#include <stdlib.h>
#include "listrek1.c"

#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
#define abs(a) a<0?-a:a 
#define selisih(a, b) abs(a-b)
#define swap(a,b) {infotype tmp; tmp = b; b = a; a = tmp;}

#define intput(a)     scanf("%d", &a)
#define intput2(a,b)  scanf("%d %d", &a, &b)
#define charput(a)    scanf(" %c", &a)
#define print(a)      printf("%d", a)
#define prints(a)     printf("%d ", a)
#define println(a)    printf("%d\n", a)
#define ENDL          printf("\n")

#define fori(i, n) for(int i = 0; i < n; i++)
#define forii(i, s, e) for(int i = s; i < e; i++)

int main(){
	List L = Alokasi(-1);
	fori(i, 4){
		L = Konso(i, L);
	}
	L = Konso(-5, L);
	PrintList(L); ENDL;
	// printf("Avergae is %.2f", AverageList(L)); ENDL;

	// List L1 = Nil;
	// List L2 = Nil;
	// SplitPosNeg(L, &L1, &L2);
	// PrintList(L1); ENDL;
	// PrintList(L2); ENDL;
	PrintList(InverseList(L));
	return 0;
}