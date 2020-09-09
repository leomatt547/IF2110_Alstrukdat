/* File : mjam.c */
/* Program MainJam */
/* Driver ADT Jam */
/*Create by Leonard Matheus 13519215*/
#include <stdio.h>
#include "jam.h"
#include "jam.c"

int main()
{ /* KAMUS */
JAM J1, J2, J3, J4, J5, J6, J7;
int N1, N2;

scanf("%d", &N1);
scanf("%d", &N2);
/* ALGORITMA */
BacaJAM(&J1);
printf("Jam 1: ");
TulisJAM(J1); printf("\n");

BacaJAM(&J2);
printf("Jam 2: ");
TulisJAM(J2); printf("\n");

printf("Konversi menjadi detik J1: %ld\n",JAMToDetik(J1));
printf("Konversi menjadi detik J2: %ld\n",JAMToDetik(J2));
printf("\n");
printf("Waktunya Sama ga 0/1: %d\n",JEQ(J1, J2));
printf("Waktunya Beda ga 0/1: %d\n",JNEQ(J1, J2));
printf("J1 < J2 0/1? : %d\n",JLT(J1, J2));
printf("J1 > J2 0/1? : %d\n",JGT(J1, J2));
printf("\n");
printf("Operator Aritmatika Jam\n");

J3 = NextDetik(J1);
printf("Next 1 Detik? :\n");
TulisJAM(J3); printf("\n");

printf("Next N Detik? :\n");
J4 = NextNDetik(J1, N1);
TulisJAM(J4); printf("\n");

J5 = PrevDetik(J2);
printf("Prev 1 Detik? :\n");
TulisJAM(J5); printf("\n");

printf("Prev N Detik? :\n");
J6 = PrevNDetik(J2, N2);
TulisJAM(J6); printf("\n");

J7 = DetikToJAM(5000);
printf("5000 detik sama dengan jam : ");
TulisJAM(J7);

printf("Durasi dalam detik: %ld\n",Durasi(J1, J2));
return 0;
}