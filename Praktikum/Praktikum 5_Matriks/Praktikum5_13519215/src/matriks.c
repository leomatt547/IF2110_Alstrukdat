/*
Nama :Leonard Matheus
Tanggal: 17 September 2020
NIM:13519215
Topik: Pra-praktikum 5
Deskripsi: Matriks
*/

#include <stdio.h>
#include "matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
    NBrsEff(*M)=NB;
    NKolEff(*M)=NK;

    indeks i,j;
    for (i = BrsMin; i < NB; i++){
        for (j = KolMin; j < NK; j++){
            Elmt(*M, i, j) = 0;
        }
    }
}
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
    return (((i>=BrsMin)&&(i<=BrsMax))&&((j>=KolMin)&&(j<=KolMax)));
}
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
    return (BrsMin);
}
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (MATRIKS M){
    return (KolMin);
}
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (MATRIKS M){
    return(NBrsEff(M)-1+BrsMin);
}
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (MATRIKS M){
    return(NKolEff(M)-1+KolMin);
}
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
    return (((i>=BrsMin)&&(i<NBrsEff(M)))&&((j>=KolMin)&&(j<NKolEff(M))));
}
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
ElType GetElmtDiagonal (MATRIKS M, indeks i){
    return (Elmt(M,i,i));
}
/* Mengirimkan elemen M(i,i) */

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
    indeks i, j;

    MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);
    for (i = GetFirstIdxBrs(MIn); i <= GetLastIdxBrs(MIn); i++){
        for (j = GetFirstIdxKol(MIn); j <= GetLastIdxKol(MIn); j++){
            Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
        }
    }
    NKolEff(*MHsl)=NKolEff(MIn);
    NBrsEff(*MHsl)=NBrsEff(MIn);
}
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
    indeks i,j;
    ElType input;
    if (IsIdxValid(NB,NK)){
        MakeMATRIKS(NB, NK, M);
        for (i = BrsMin; i <= NB-1+BrsMin; i++){
            for (j = KolMin; j <= NK-1+KolMin; j++){
                scanf("%d",&input);
                Elmt(*M,i,j)=input;
            }
    }
    NBrsEff(*M)=NB;
    NKolEff(*M)=NK;
    }
}
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void TulisMATRIKS (MATRIKS M){
    indeks i,j;
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
            printf("%d", Elmt(M,i,j));
            if (j!=GetLastIdxKol(M)){
                printf(" ");
            }
        }
        if (i!=GetLastIdxBrs(M)){
            printf("\n");
        }
    }
}
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
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
    MATRIKS M;
    indeks i,j;
    MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &M);
    for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++){
        for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++){
            Elmt(M,i,j)=Elmt(M1,i,j)+Elmt(M2,i,j);
            }
        }
    return M;
}
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
    MATRIKS M;
    indeks i,j;
    MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &M);
    for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++){
        for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++){
            Elmt(M,i,j)=Elmt(M1,i,j)-Elmt(M2,i,j);
        }
    }
    return M;
}
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
    indeks i, j, k;
    ElType sum;
    MATRIKS M;

    MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &M);

    for (i = BrsMin; i <= NBrsEff(M); i++){
        for (j = KolMin; j <= NKolEff(M); j++){
            sum = 0;
            for (k = KolMin; k <= NKolEff(M1) ; k++){
                sum += Elmt(M1,i,k) * Elmt(M2,k, j);
            }
            Elmt(M, i, j) = sum;
        }
    }
    return M;
}
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
MATRIKS KaliKons (MATRIKS M, ElType X){
    MATRIKS M1;
    indeks i,j;
    MakeMATRIKS(NBrsEff(M), NKolEff(M), &M1);
    for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++){
        for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++){
            Elmt(M1,i,j)=Elmt(M,i,j)*X;
        }
    }
    return M1;
}
/* Mengirim hasil perkalian setiap elemen M dengan X */
void PKaliKons (MATRIKS * M, ElType K){
    indeks i,j;
    for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++){
        for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++){
            Elmt(*M,i,j)=Elmt(*M,i,j)*K;
        }
    }
}
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2){
    boolean hasil = (NBElmt(M1) == NBElmt(M2));
    if (hasil){
        int i,j;
        for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++){
            for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++){
                hasil = hasil && (Elmt(M1, i, j) == Elmt(M2, i, j));
            }
        }
    }
    return hasil;
}
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
boolean NEQ (MATRIKS M1, MATRIKS M2){
    return (!EQ(M1,M2));
}
/* Mengirimkan true jika M1 tidak sama dengan M2 */
boolean EQSize (MATRIKS M1, MATRIKS M2){
    return ((NBrsEff(M1)==NBrsEff(M2))&&(NKolEff(M1)==NKolEff(M2)));
}
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M){
    return (NBrsEff(M)*NKolEff(M));
}
/* Mengirimkan banyaknya elemen M */

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
    return(NBrsEff(M)==NKolEff(M));
}
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
boolean IsSimetri (MATRIKS M){
    indeks i, j;

    if (!(IsBujurSangkar(M))){
        return false;
    }
    else {
        for (i = BrsMin; i <= NBrsEff(M); i++){
            for (j = KolMin; j <= NKolEff(M); j++){
                if (Elmt(M, i, j) != Elmt(M, j, i)){
                    return false;
                }
            }
        }
    }
    return true;
}
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
boolean IsSatuan (MATRIKS M){
    boolean equal = true;
    indeks i,j;
    if (!IsBujurSangkar(M)){
        equal = false;
    }else{
        i = BrsMin;
        while ((i<=GetLastIdxBrs(M))&&(equal)){
            j = KolMin;
            while (j<=GetLastIdxKol(M)&&(equal)){
                if (i==j){
                    equal = equal && (Elmt(M, i, j)==1);
                }else{
                    equal = equal && (Elmt(M, i, j)==0);
                }
                j++;
            }
            i++;
        }
    }
    return equal;
}
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
boolean IsSparse (MATRIKS M){
   indeks i,j;
    int count = 0;
    float batas = NBElmt(M) * 0.05;

    for (i = BrsMin; i <= NBrsEff(M); i++){
        for (j = KolMin; j <= NKolEff(M); j++){
            if (Elmt(M, i, j) != 0){
                count += 1;
                }
            }
        }
    return (count <= batas);
}
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
MATRIKS Inverse1 (MATRIKS M){
    return KaliKons(M, -1);
}
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */

float Determinan (MATRIKS M){
    int size = NBrsEff(M);
    float m[size][size];
    int i, j;

    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            m[i][j] = Elmt(M, i, j);
        }
    }

    float result = 1;
    int swapped = 0;

    while (size > 0){
        boolean swap = false;
        i = 0;
        if (m[size-1][size-1] == 0){
            while (i < (size-1) && (!swap)){
                if (m[i][size-1] == 0){
                    i++;
                } else {
                    swap = true;
                }
            }
        }
        if (i == (size-1) && (size > 1)){
            return 0;
        } else if (swap){
            for(j = 0; j < size; j++){
                float temp = m[size-1][j];
                m[size-1][j] = m[i][j];
                m[i][j] = temp;
            }
        }
        for (i = 0; i < (size-1); i++){
            for(j=0; j<size; j++){
                m[i][j] -= m[size-1][j]*(m[i][size-1]/m[size-1][size-1]);
            }
        }
        result *= m[size-1][size-1];
        swapped = (swapped+(swap ? 1 : 0))%2;
        size--;
    }
    float finalresult = (result*(swapped==0 ? 1.0f : -1.0f));
    return ((finalresult < 1 && finalresult > -1) ? 0.0f : finalresult);
}
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
void PInverse1 (MATRIKS * M){
    return PKaliKons(M, -1);
}
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
void Transpose (MATRIKS * M){
    ElType temp;
    indeks i,j;

    for (i = BrsMin; i <= NBrsEff(*M); i++){
        for (j = i; j <= NKolEff(*M); j++){
            temp = Elmt(*M, i, j);
            Elmt(*M, i, j) = Elmt(*M, j, i);
            Elmt(*M, j, i) = temp;
        }
    }
}
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
float RataBrs (MATRIKS M, indeks i){
    indeks j;
    float sum = 0;
    for (j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
        sum += Elmt(M, i, j);
    }
    return (sum/NKolEff(M));
}
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
float RataKol (MATRIKS M, indeks j){
    indeks i;
    float sum = 0;
    for (i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
        sum += Elmt(M, i, j);
    }
    return (sum/NBrsEff(M));
}
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min){
    indeks j;
    *min = Elmt(M, i, GetFirstIdxKol(M));
    *max = Elmt(M, i, GetLastIdxKol(M));

    for (j=(GetFirstIdxKol(M)+1);j<=GetLastIdxKol(M);j++){
        if(Elmt(M, i, j)> *max){
            *max = Elmt(M, i, j);
        }
        if(Elmt(M, i, j)< *min){
            *min = Elmt(M, i, j);
        }
    }
}
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min){
    indeks i;
    *min = Elmt(M, GetFirstIdxBrs(M), j);
    *max = Elmt(M, GetFirstIdxBrs(M), j);

    for (i=(GetFirstIdxBrs(M)+1);i<=GetLastIdxBrs(M);i++){
        if(Elmt(M, i, j)> *max){
            *max = Elmt(M, i, j);
        }
        if(Elmt(M, i, j)< *min){
            *min = Elmt(M, i, j);
        }
    }
}
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
int CountXBrs (MATRIKS M, indeks i, ElType X){
    indeks j;
    int count = 0;
    for (j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
        if (Elmt(M, i, j) == X){
            count += 1;
        }
    }
    return count;
}
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
int CountXKol (MATRIKS M, indeks j, ElType X){
    indeks i;
    int count = 0;
    for (i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
        if (Elmt(M, i, j) == X){
            count += 1;
        }
    }
    return count;
}
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
