/*Nama : Leonard Matheus
NIM : 13519215
Tanggal: 26 November 2020
Topik: Praktikum 12
*/

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include "listrek.h"

BinTree Merkle(int n){
	if(n==0){
		int N;
		scanf("%d",&N);
		return AlokNode(N);
	}else{
		BinTree MerkleNode;
		MerkleNode = AlokNode(0);
		Left(MerkleNode) = Merkle(n-1);
		Right(MerkleNode) = Merkle(n-1);
		Akar(MerkleNode) = Akar(Left(MerkleNode))+Akar(Right(MerkleNode));
		return MerkleNode;
	}
	
}
int main(){
	int n2;
	int i = 0;
	long faktor = 1;
	scanf("%d",&n2);
	while(faktor < n2){
		faktor *= 2;
		i++;
	}
	if (faktor != n2){
		printf("Jumlah masukan tidak sesuai\n");
	}else{
		BinTree P = Merkle(i);
		PrintTree(P,2);
	}
	return 0;
}



