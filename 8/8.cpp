#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Alamat
{
    char provinsi[20];
    char kota[20];
    char jalan[20];
};

typedef struct Mahasiswa
{
    char nim[12];

    char nama[30];

    struct Alamat alamat;
    // padding 26
    int umur;
} Mhs;

// union Mahasiswa2
// {
//     char nim[12];

//     char nama[34];

//     // struct Alamat alamat;
//     // padding 26
//     int umur;
// } mhs;

int main()
{

    // Alamat alamat = {"Sumatera Utara", "Medan", "Anggrek No.259"};
    // Mahasiswa mhs[] = {
    //     {"Adrian",
    //      "2301928433",
    //      20},
    //     {"Kai",
    //      "2601928433",
    //      21},
    // };

    // Mhs *mhsPtr = (Mhs *)malloc(sizeof(Mhs));

    // strcpy(mhsPtr->nama, "Adrian");
    // strcpy((*mhsPtr).nim, "2301928433");
    // (*mhsPtr).umur = 21;

    // printf("%s - %s (%d)\n", mhsPtr->nama, mhsPtr->nim, mhsPtr->umur);

    // strcpy(mhs[0].nama, "Adrian");
    // strcpy(mhs[0].nim, "2301928433");
    // mhs[0].umur = 20;
    // int size = sizeof(mhs) / sizeof(mhs[0]);
    // for (int i = 0; i < size; ++i)
    // {
    //     printf("%s - %s (%d)\n", mhs[i].nama, mhs[i].nim, mhs[i].umur);
    // }

    //       buffer           buffer
    // input   ->    program    ->     output
    // fopen(filename, mode)
    // fclose(fileptr)
    // fscanf(fileptr, format, arg)
    // fprintf(fileptr, format, arg)
    // feof

    // printf("%d\n", sizeof(union Mahasiswa2));
    // mhs2 = {
    //     "Adrian",
    //     "2301928433",
    //     // alamat,
    //     // {"Sumatera Utara", "Medan", "Anggrek No.259"},
    //     20,
    // };

    // mhs.umur = 20;
    // strcpy(mhs.nama, "Adrian");
    // strcpy(mhs.nim, "2301928433");

    // // printf("%s - %s (%d)\n", mhs.nama, mhs.nim, mhs.umur);
    // printf("%s - %s (%d)\n", mhs.nama, mhs.nim, mhs.umur);

    // printf("%s, %s, %s\n", mhs.alamat.jalan, mhs.alamat.kota, mhs.alamat.provinsi);

    return 0;
}