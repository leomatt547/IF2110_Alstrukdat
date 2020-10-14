/*
Nama: Leonard Matheus
NIM: 13519215
Tanggal: 1 Oktober 2020
Deskripsi: Mesin Kata
*/

#include <stdio.h>
#include "mesinkata.h"
#include "mesinkar.h"

boolean IsKataSama(Kata K1, Kata K2){
    int pjg, i;
    if (K1.Length != K2.Length){
        return false;
    }else if (K1.Length > K2.Length){
        pjg = K1.Length;
    }else{
        pjg = K2.Length;
    }
    for (i = 0; i < pjg; i++){
        if (K1.TabKata[i] != K2.TabKata[i]){
            return false;
        }
    }
    return true;
}

int main(){
Kata KTitik, KKoma;
	int KReg, KPjg, biaya, i, jumlah;
	boolean spasi, ENDTELE;
	
	KTitik.Length= 5;
	KTitik.TabKata[0]= 'T';
	KTitik.TabKata[1]= 'I';
	KTitik.TabKata[2]= 'T';
	KTitik.TabKata[3]= 'I';
	KTitik.TabKata[4]= 'K';
	
	KKoma.Length= 4;
	KKoma.TabKata[0]= 'K';
	KKoma.TabKata[1]= 'O';
	KKoma.TabKata[2]= 'M';
	KKoma.TabKata[3]= 'A';
	
	KReg= 0;
	KPjg= 0;
	jumlah = 0;
	
	spasi= false;
	ENDTELE= false;
	
	STARTKATA();
	if (CC == BLANK) {
		IgnoreBlank();
	}
	if ((CKata.Length == 0) && (CC == BLANK)) {
		ENDTELE= true;
	}
	while (!ENDTELE) {
		jumlah+= 1;
		if (IsKataSama(CKata, KTitik)) {
			printf(".");
			spasi= false;
		} else if (IsKataSama(CKata, KKoma)) {
			printf(", ");
			spasi= false;
		} else {
			if (spasi== true) {
				printf(" ");
			} else {
				spasi= true;
			}
			for (i= 0; i < CKata.Length; i++) {
				printf("%c", CKata.TabKata[i]);
			}
			if (CKata.Length < 10) {
				KReg+= 1;
			} else if (CKata.Length >= 10) {
				KPjg+= 1;
			}
		}
		CKata.Length = 0;
		ADVKATA();
		IgnoreBlank();
		if (CC == MARK) {
			EndKata= true;
		}
		if (EndKata) {
			ENDTELE= true;
		}	
	}
	if (CKata.Length > 0){
		jumlah+= 1;
		if (IsKataSama(CKata, KTitik)) {
			printf(".");
			spasi= false;
		} else if (IsKataSama(CKata, KKoma)) {
			printf(", ");
			spasi= false;
		} else {
			if (spasi== true) {
				printf(" ");
			}
			for (i= 0; i < CKata.Length; i++) {
				printf("%c", CKata.TabKata[i]);
			}
			spasi= true;
			if (CKata.Length < 10) {
				KReg+= 1;
			} else if (CKata.Length >= 10) {
				KPjg+= 1;
			}
		}
	}		
	if (jumlah <= 10) {
		biaya= (KReg * 1000) + (KPjg * 1500);
	} else if (jumlah > 10){
		biaya= (((KReg * 1000) + (KPjg * 1500)) * 0.9);
	}
	printf("\n%d\n", KReg);
	printf("%d\n", KPjg);
	printf("%d\n", biaya);
	return 0;
}