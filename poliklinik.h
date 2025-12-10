#ifndef POLIKLINIK_H_INCLUDED
#define POLIKLINIK_H_INCLUDED

typedef Poliklinik* adrPoli;

struct Poliklinik {
    string nama;
    adrDokter firstDokter;
    Poliklinik next;
    Poliklinik prev;
};

struct ListPoli {
    adrPoli first;
    adrPoli last;
};

void createListPoli(ListPoli &LP);
adrPoli createPoli(string nama);
void insertPoli(ListPoli &LP, adrPoli P);
adrPoli findPoli(ListPoli LP, string nama);
void deletePoli(ListPoli &LP, string nama);
adrPoli poliDokterTerbanyak(ListPoli LP);
void showAll(ListPoli LP);

#endif // POLIKLINIK_H_INCLUDED

