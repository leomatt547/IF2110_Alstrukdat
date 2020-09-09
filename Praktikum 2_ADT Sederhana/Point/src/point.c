/* File: point.c */
/* Tanggal: 2 September 2020 */
/* Definisi ADT Point */

#include <stdio.h>
#include <math.h>
#include "point.h"
#include "boolean.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y){
 /* KAMUS */
    POINT P1;
    /* ALGORITMA */
    Absis(P1) = X;
    Ordinat(P1) = Y;
    return P1;
}
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT *P){
    /* Kamus Lokal */
    float X, Y;
    /* Algoritma */
    scanf("%f %f",&X, &Y);
    *P = MakePOINT(X,Y);
}
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPOINT (POINT P){
    printf("(%.2f, %.2f)\n",Absis(P), Ordinat(P));
}
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
    return((Absis(P1) == Absis(P2))&&(Ordinat(P1) == Ordinat(P2)));
}
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean NEQ (POINT P1, POINT P2){
    return(!EQ(P1, P2));
}
/* Mengirimkan true jika P1 tidak sama dengan P2 */

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
    /* Menghasilkan true jika P adalah titik origin */
    return ((Absis(P) == 0) && (Ordinat(P) == 0));
}
boolean IsOnSbX (POINT P){
    return(Ordinat(P)==0);
}
/* Menghasilkan true jika P terletak Pada sumbu X */
boolean IsOnSbY (POINT P){
    return(Absis(P)==0);
}
/* Menghasilkan true jika P terletak pada sumbu Y */
int Kuadran (POINT P){
    if (Absis(P)>0 && Ordinat(P)>0){
        return 1;
    }
    else if (Absis(P)<0 && Ordinat(P)>0){
        return 2;
    }
    else if (Absis(P)<0 && Ordinat(P)<0){
        return 3;
    }
    else if (Absis(P)>0 && Ordinat(P)<0){
        return 4;
    }
    else if ((Absis(P)==0) || (Ordinat(P)==0)){
        return (-1);
    }
    else{
        return 0;
    }
}
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P){
    return(MakePOINT(Absis(P)+1, Ordinat(P)));
}
/* Mengirim salinan P dengan absis ditambah satu */
POINT NextY (POINT P){
    return(MakePOINT(Absis(P), Ordinat(P)+1));
}
/* Mengirim salinan P dengan ordinat ditambah satu */
POINT PlusDelta (POINT P, float deltaX, float deltaY){
    float a, b;
    a = Absis(P)+deltaX;
    b = Ordinat(P)+deltaY;
    return(MakePOINT(a, b));
}
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
POINT MirrorOf (POINT P, boolean SbX){
    if (SbX){
        return(MakePOINT(Absis(P), (-1)*Ordinat(P)));
    }
    else{
        return(MakePOINT((-1)*Absis(P), Ordinat(P)));
    }
}
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
float Jarak0 (POINT P){
    return(sqrt(Absis(P)*Absis(P) + Ordinat(P)*Ordinat(P)));
}
/* Menghitung jarak P ke (0,0) */
float Panjang (POINT P1, POINT P2){
    return Jarak0(PlusDelta(P2, -Absis(P1), -Ordinat(P1)));
}
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
void Geser (POINT *P, float deltaX, float deltaY){
    float a, b;
    a = Absis(*P)+deltaX;
    b = Ordinat(*P)+deltaY;
    *P = MakePOINT(a, b);
}
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
void GeserKeSbX (POINT *P){
    float a, b;
    a = Absis(*P);
    b = 0;
    *P = MakePOINT(a, b);
}
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
void GeserKeSbY (POINT *P){
    float a, b;
    a = 0;
    b = Ordinat(*P);
    *P = MakePOINT(a, b);
}
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
void Mirror (POINT *P, boolean SbX){
    float a, b;
    a = Absis(*P);
    b = Ordinat (*P);
    if (SbX){
        *P= MakePOINT(a, (-1)*b);
    }
    else{
        *P=MakePOINT((-1)*a, b);
    }
}
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
void Putar (POINT *P, float Sudut){
    float a, b;
    Sudut = -(Sudut/180)*acos(-1);
    a = ((Absis(*P)*cos(Sudut))-(Ordinat(*P)*sin(Sudut)));
    b = ((Absis(*P)*sin(Sudut))+(Ordinat(*P)*cos(Sudut)));
    *P= MakePOINT(a, b);
}
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) searah jarum jam*/
