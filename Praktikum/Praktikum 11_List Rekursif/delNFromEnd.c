/*Nama : Leonard Matheus
NIM : 13519215
Tanggal: 19 November 2020
Topik: Praktikum 11
*/

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listrek.h"

List LAkhir = Nil;
int length = 0;

int target(List L, int celmt, int n){
	if(IsEmpty(L)){
        return 1;
    }
    length++;
	target(Tail(L), celmt+1, n);
	if(n+celmt-1==length){
        LAkhir = L;
    }
	if(n+celmt==length){
        Dealokasi(L);
        if(celmt==0){
            return 0;
        }
    }
	if((n+celmt)+1==length){
        SetNext(L, LAkhir);
    }
}

List delNFromEnd(List L, int n) {
	if(IsEmpty(L)){
        return L;
    }
	if(!target(L,0,n)){
        return LAkhir;
    }
	return L;
}