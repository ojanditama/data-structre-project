#include "MLL.h"

void createListPoli(ListPoli &LP) {
    LP.first = LP.last = NULL;
}

adrPoli createPoli(string nama) {
    adrPoli P = new Poliklinik;
    P->nama = nama;
    P->firstDokter = NULL;
    P->next = P->prev = NULL;
    return P;
}

void insertPoli(ListPoli &LP, adrPoli P) {
    if (LP.first == NULL) {
        LP.first = LP.last = P;
    } else {
        LP.last->next = P;
        P->prev = LP.last;
        LP.last = P;
    }
}

adrDokter createDokter(string n, string s, int j, i) {
    adrDokter D = new Dokter;
    D->nama = n;
    D->spesialis = s;
    D->jam = j;
    D->pengalaman = p;
    D->next = D->prev = NULL;
    return D;
}

void insertDokter(adrPoli P, adrDokter D) {
    if (P->firstDokter == NULL) {
        P->firstDokter = D;
    } else {
        adrDokter Q = P->firstDokter;
        while (Q->next != NULL) Q = Q->next;
        Q->next = D;
        D->prev = Q;
    }
}

adrPoli findPoli(ListPoli LP, string nama) {
    adrPoli P = LP.first;
    while (P != NULL) {
        if (P->nama == nama) return P;
        P = P->next;
    }
    return NULL;
}

void showAll(ListPoli LP) {
    adrPoli P = LP.first;

    while (P != NULL) {
        cout << "\nPoliklinik: " << P->nama << endl;

        adrDokter D = P->firstDokter;
        if (D == NULL) {
            cout << "  Tidak ada dokter.\n";
        } else {
            while (D != NULL) {
                cout << "  Dokter: " << D->nama
                     << ", Spesialis: " << D->spesialis
                     << ", Jam: " << D->jam
                     << ", Pengalaman: " << D->pengalaman << endl;
                D = D->next;
            }
        }

        P = P->next;
    }
}
