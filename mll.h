#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

typedef struct Dokter* adrDokter;
typedef struct Poliklinik* adrPoli;

struct Dokter {
    string nama;
    string spesialis;
    int jam;
    Dokter next;
    Dokter prev;
};

struct Poliklinik {
    string nama;
    adrDokter firstDokter;
    Poliklinik *next, *prev;
};

struct ListPoli {
    adrPoli first;
    adrPoli last;
};

void createListPoli(ListPoli &LP);
adrPoli createPoli(string namaPoli);
void insertPoli(ListPoli &LP, adrPoli P);
adrDokter createDokter(string namaDokter, string spesialis, int jam);
void insertDokter(adrPoli P, adrDokter D);
adrPoli findPoli(ListPoli LP, string namaPoli);
void showAll(ListPoli LP);

#endif
