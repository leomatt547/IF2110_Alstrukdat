#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "point.h"
#include "point.c"

int main(){
    POINT P1, P2, P3, P4, P5, P6, P7;
    float F1, F2, F3;
    int SbX;

    scanf("%f\n", &F1);
    scanf("%f\n", &F2);
    scanf("%f\n", &F3);
    scanf("%d\n", &SbX);

    BacaPOINT(&P1);
    printf("Point 1: ");
    TulisPOINT(P1); printf("\n");

    BacaPOINT(&P2);
    printf("Point 2: ");
    TulisPOINT(P2); printf("\n");

    printf("Point Sama ga 0/1: %d\n",EQ(P1, P2));
    printf("Point Beda ga 0/1: %d\n",NEQ(P1, P2));
    printf("Point 1 di (0,0) ga 0/1: %d\n",IsOrigin(P1));
    printf("Point 1 di sumbu x ga 0/1: %d\n",IsOnSbX(P1));
    printf("Point 2 di sumbu y ga 0/1: %d\n",IsOnSbY(P2));
    printf("Point 1 di Kuadran Apa?: %d\n",Kuadran(P1));
    printf("Point 2 di Kuadran Apa?: %d\n",Kuadran(P2));

    P3 = NextX(P1);
    printf("Next 1 Titik P1 di X? :\n");
    TulisPOINT(P3); printf("\n");

    P4 = NextY(P2);
    printf("Next 1 Titik P2 di Y? :\n");
    TulisPOINT(P4); printf("\n");

    printf("Delta Point? :\n");
    P5 = PlusDelta(P1, F1, F2);
    TulisPOINT(P5); printf("\n");

    printf("Mirror? :\n");
    P6 = MirrorOf(P1, SbX);
    TulisPOINT(P6); printf("\n");

    printf("Jarak ke origin?: %f\n",Jarak0(P1));
    printf("Panjang P1 dan P2?: %f\n",Panjang(P1, P2));

    printf("Geser P1? :\n");
    Geser(&P1, F1, F2);
    TulisPOINT(P1); printf("\n");

    printf("Geser ke sb x P2? :\n");
    GeserKeSbX(&P2);
    TulisPOINT(P2); printf("\n");

    printf("Geser ke sb y P1? :\n");
    GeserKeSbY(&P1);
    TulisPOINT(P1); printf("\n");

    printf("Putar P1? :\n");
    Putar(&P1, F3);
    TulisPOINT(P1); printf("\n");

return 0;
}
