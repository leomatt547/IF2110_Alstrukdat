/* File: jam.c */
/* Tanggal: 2 September 2020 */
/* Definisi ADT JAM */

#include <stdio.h>
#include "jam.h"
#include "boolean.h"
/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M, int S)
/* Mengirim true jika H,M,S dapat membentuk Jam yang valid */
{ /* Kamus Lokal */
    /* Algoritma */
    return ((H >= 0 && H <= 23) && (M >= 0 && M <= 59) &&
    (S >= 0 && S <= 59));
}
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS){ 
    /* Kamus Lokal */
    JAM J1;
    /* Algoritma */
    Hour(J1) = HH;
    Minute(J1) = MM;
    Second(J1) = SS;
    return J1;
}
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J){ 
    /* Kamus Lokal */
    int H, M, S;
    /* Algoritma */
    do {
    scanf("%d %d %d",&H, &M, &S);
    } while(!IsJAMValid(H,M,S));
    *J = MakeJAM(H,M,S);
}
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */

void TulisJAM (JAM J){
    /* Kamus lokal */
    /* Algoritma */
    printf("%d:%d:%d\n",Hour(J),Minute(J),Second(J));
}
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.
   Jika jam / menit / detik hanya satu digit, tuliskan satu digit tanpa 0 di depannya. */

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik (JAM J)
/* Konversi Jam menjadi detik */
{ /* Kamus Lokal */
    /* Algoritma */
    return(3600 * Hour(J) + 60 * Minute(J) + Second(J));
}
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */

JAM DetikToJAM (long N)
/* Konversi detik ke Jam */
{ /* Kamus Lokal */
    int sisa;
    JAM JOut;
    /* Algoritma */
    N = N % 86400;
    Hour(JOut) = N / 3600;
    sisa = N % 3600;
    Minute(JOut) = sisa / 60;
    Second(JOut) = sisa % 60;
    return JOut;
}
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2){
    return(Hour(J1) == Hour(J2) && (Minute(J1) == Minute(J2)) && (Second(J1) == Second(J2)));
}
/* Mengirimkan true jika J1=J2, false jika tidak */
boolean JNEQ (JAM J1, JAM J2){
    return(!JEQ(J1, J2));
}
/* Mengirimkan true jika J1 tidak sama dengan J2 */
boolean JLT (JAM J1, JAM J2){
    return(JAMToDetik(J1) < JAMToDetik(J2));
}
/* Mengirimkan true jika J1<J2, false jika tidak */
boolean JGT (JAM J1, JAM J2){
    return(JAMToDetik(J1) > JAMToDetik(J2));
}
/* Mengirimkan true jika J1>J2, false jika tidak */

/* *** Operator aritmatika JAM *** */
JAM NextDetik (JAM J){
    long t = (JAMToDetik(J) + 1)%86400;
    JAM JOut = DetikToJAM(t);
    return JOut;
}
/* Mengirim 1 detik setelah J dalam bentuk JAM */
JAM NextNDetik (JAM J, int N){
    long t = (JAMToDetik(J) + N)%86400;
    JAM JOut = DetikToJAM(t);
    return JOut;
}
/* Mengirim N detik setelah J dalam bentuk JAM */
JAM PrevDetik (JAM J){
    long t = ((JAMToDetik(J) - 1)+86400)%86400;
    JAM JOut = DetikToJAM(t);
    return JOut;
}
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
JAM PrevNDetik (JAM J, int N){
    long t = ((JAMToDetik(J) - N)+86400)%86400;
    JAM JOut = DetikToJAM(t);
    return JOut;
}
/* Mengirim N detik sebelum J dalam bentuk JAM */

/* *** Kelompok Operator Aritmetika *** */
long Durasi (JAM JAw, JAM JAkh){
    if (JLT(JAw, JAkh)){
        return (JAMToDetik(JAkh)-JAMToDetik(JAw));
    }
    else if(JEQ(JAw, JAkh)){
        return 0;
    }
    else{
        return((JAMToDetik(JAkh)-JAMToDetik(JAw)+86400)%86400);
    }
    
}
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */