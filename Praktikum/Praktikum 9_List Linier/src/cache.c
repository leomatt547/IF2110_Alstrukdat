/*Nama: Leonard Matheus
NIM: 13519215
Tanggal: 5 November 2020
Topik: Praktikum 9
Deskripsi: linked list
*/

#include "listlinier.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,n, q, temp;
    List L;
    address spointer,p;
    scanf("%d", &n);
	CreateEmpty(&L);
	for(i = 0; i < n; i++){
        InsVLast(&L, i+1);
    }
	scanf("%d", &q);
	for(i = 0; i < q; i++){
		scanf("%d", &temp);
		spointer = Search(L,temp);
		if(spointer == Nil){
			DelLast(&L, &p);
			printf("miss ");
		}else {
			DelP(&L,temp);
			printf("hit ");
		}
		InsVFirst(&L,temp);
		PrintInfo(L);
		printf("\n");
	}
	return 0;
}
