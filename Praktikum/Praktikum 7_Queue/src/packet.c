/* Nama: Leonard Matheus
Tanggal: 4 Oktober 2020
Deskripsi: Praktikum 7
Topik: Queue
*/

#include <stdio.h>
#include "prioqueuechar.h"
#include <stdlib.h>

int main(){
	int p, i; 
    int prio; char info;
    infotype X, pc;
    PrioQueueChar Q;
    scanf("%d", &p);
	MakeEmpty(&Q, p);
	int dpt = 0;
	for(i = 0; i < p; i++){
		while(!IsEmpty(Q) && (Prio(InfoHead(Q)) == dpt+1)){
			Dequeue(&Q, &X);
			printf("%d %c\n", i, Info(X));
			dpt++;
		}
		
		scanf("%d %c", &prio, &info);
		Prio(pc) = prio;
		Info(pc) = info;
		Enqueue(&Q, pc);
	}
	while(!IsEmpty(Q) && Prio(InfoHead(Q)) == dpt+1){
		Dequeue(&Q, &X);
		printf("%d %c", p, Info(X));
		dpt++;
		printf("\n");
	}
    return 0;
}