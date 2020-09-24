/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef MATRIKS_H
#define MATRIKS_H

#include "boolean.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 0
#define BrsMax 99
#define KolMin 0
#define KolMax 99

typedef int indeks; /* indeks baris, kolom */
typedef int ElType; 
typedef struct { 
	ElType Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;
/* NBrsEff >= 1 dan NKolEff >= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M); 
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j);
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M);
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (MATRIKS M);
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (MATRIKS M);
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (MATRIKS M);
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff (MATRIKS M, indeks i, indeks j);
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
ElType GetElmtDiagonal (MATRIKS M, indeks i);
/* Mengirimkan elemen M(i,i) */

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl);
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK);
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void TulisMATRIKS (MATRIKS M);
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2);
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2);
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2);
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
MATRIKS KaliKons (MATRIKS M, ElType X);
/* Mengirim hasil perkalian setiap elemen M dengan X */
void PKaliKons (MATRIKS * M, ElType K);
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2);
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
boolean NEQ (MATRIKS M1, MATRIKS M2);
/* Mengirimkan true jika M1 tidak sama dengan M2 */
boolean EQSize (MATRIKS M1, MATRIKS M2);
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M);
/* Mengirimkan banyaknya elemen M */

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M);
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
boolean IsSimetri (MATRIKS M);
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
boolean IsSatuan (MATRIKS M);
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
boolean IsSparse (MATRIKS M);
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
MATRIKS Inverse1 (MATRIKS M);
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
float Determinan (MATRIKS M);
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
void PInverse1 (MATRIKS * M);
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
void Transpose (MATRIKS * M);
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
float RataBrs (MATRIKS M, indeks i);
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
float RataKol (MATRIKS M, indeks j);
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min);
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min);
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
int CountXBrs (MATRIKS M, indeks i, ElType X);
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
int CountXKol (MATRIKS M, indeks j, ElType X);
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
void TulisNilaiX(MATRIKS M, indeks j, ElType X);
/*
{ Menuliskan nomor urut mahasiswa yang mendapatkan nilai X pada mata kuliah dengan nomor urut j. }
{ Pada dasarnya: Menuliskan semua indeks baris pada kolom j dengan nilai elemen = X. }
{ Nomor urut mahasiswa dituliskan dalam 1 baris, masing-masing dipisahkan koma, diawali [, diakhiri ], tanpa tambahan karakter apa pun (termasuk spasi dan enter) di awal maupun akhir }
{ I.S. M terdefinisi, j adalah indeks kolom efektif M, X terdefinisi }
{ F.S. Menuliskan semua indeks baris pada kolom j dengan nilai = X.
Jika tidak ada elemen dengan nilai = X, menuliskan []
{ Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
1 3 3
2 5 6
7 3 9
maka jika j = 1 dan X = 3, akan tercetak: [0,2]
}
*/
void TulisStatistikMhs(MATRIKS M, indeks i);
/*
{ Menuliskan statistik untuk mahasiswa dengan nomor urut i. }
{ Statistik yang dituliskan adalah: nilai rata-rata, nilai mata kuliah tertinggi, nilai mata kuliah terendah. }
{ Pada dasarnya: menuliskan statistik untuk data pada baris ke-i }
{ I.S. M terdefinisi, i adalah indeks baris efektif M }
{ F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
[i] <rata-rata> <nilai max> <nilai min> }
Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
100 83 83
72 55 60
77 93 90
maka jika i = 1 akan tercetak:
[1] 62.33 72 55
*/
void TulisStatistikMK (MATRIKS M, indeks j);
/*
{ Menuliskan statistik untuk mata kuliah dengan nomor urut j. }
{ Statistik yang dituliskan adalah: nilai rata-rata, nilai tertinggi (berikut berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya), nilai mata kuliah terendah (berikut berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya). }
{ Pada dasarnya: menuliskan statistik untuk data pada kolom ke-j }
{ I.S. M terdefinisi, j adalah indeks kolom efektif M }
{ F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
[j] <rata-rata> [max <nilai max> <#max> [<daftar max>]] [min <nilai min> <#min> [<daftar min>]] }
{ Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
100 83 83
72 55 60
77 93 90
maka jika j = 1 akan tercetak:
[1] 77.00 [93 1 [2]] [55 1 [1]]
}
*/
#endif