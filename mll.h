#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
using namespace std;

// ==================== CHILD (DOKTER) ====================
struct Dokter {
    string nama;
    string spesialis;
    int jamPraktik;
    int pengalaman;
    Dokter next;
    Dokter prev;
};
typedef Dokter* adrDokter;

// ==================== PARENT (POLIKLINIK) ====================
struct Poliklinik {
    string nama;
    adrDokter firstDokter;
    Poliklinik next;
    Poliklinik prev;
};
typedef Poliklinik* adrPoli;

// ==================== LIST PARENT ====================
struct ListPoli {
    adrPoli first;
    adrPoli last;
};

// ====== PROTOTYPE FUNGSI ======
void createListPoli(ListPoli &LP);
adrPoli createPoli(string nama);
void insertPoli(ListPoli &LP, adrPoli P);
adrPoli findPoli(ListPoli LP, string nama);
void deletePoli(ListPoli &LP, string nama);

adrDokter createDokter(string nama, string spes, int jam, int exp);
void insertDokter(adrPoli P, adrDokter D);
void deleteDokter(adrPoli P, string namaDokter);

void showDokter(adrPoli P);
void showAll(ListPoli LP);

int countDokter(adrPoli P);
adrPoli poliDokterTerbanyak(ListPoli LP);

#endif

