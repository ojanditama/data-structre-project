#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED
#include <iostream>
using namespace std;

struct Dokter {
    string nama;
    string spesialis;
    int jam;
    int pengalaman;
    Dokter *next, *prev;
};

typedef Dokter* adrDokter;

struct Poliklinik {
    string nama;
    adrDokter firstDokter;
    Poliklinik *next, *prev;
};

typedef Poliklinik* adrPoli;

struct ListPoli {
    adrPoli first, last;
};

void createListPoli(ListPoli &LP);
adrPoli createPoli(string nama);
void insertPoli(ListPoli &LP, adrPoli P);

adrDokter createDokter(string n, string s, int j, int p);
void insertDokter(adrPoli P, adrDokter D);

adrPoli findPoli(ListPoli LP, string nama);

void showAll(ListPoli LP);

#endif
