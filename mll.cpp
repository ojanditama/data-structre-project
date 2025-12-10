#include "MLL.h"

// ================= INISIALISASI LIST =================
void createListPoli(ListPoli &LP) {
    LP.first = NULL;
    LP.last = NULL;
}

// ================= CREATE NODE PARENT =================
adrPoli createPoli(string nama) {
    adrPoli P = new Poliklinik;
    P->nama = nama;
    P->firstDokter = NULL;
    P->next = NULL;
    P->prev = NULL;
    
    return P;
}

// ================= INSERT POLIKLINIK =================
void insertPoli(ListPoli &LP, adrPoli P) {
    if (LP.first == NULL) {
        LP.first = LP.last = P;
    } else {
        LP.last->next = P;
        P->prev = LP.last;
        LP.last = P;
    }
}

// ================= CARI POLIKLINIK =================
adrPoli findPoli(ListPoli LP, string nama) {
    adrPoli P = LP.first;
    while (P != NULL) {
        if (P->nama == nama) return P;
        P = P->next;
    }
    return NULL;
}

// ================= DELETE POLIKLINIK + DOKTER =================
void deletePoli(ListPoli &LP, string nama) {
    adrPoli P = findPoli(LP, nama);
    if (P == NULL) return;

    // hapus semua dokter
    adrDokter D = P->firstDokter;
    while (D != NULL) {
        adrDokter temp = D;
        D = D->next;
        delete temp;
    }

    // hapus poliklinik
    if (P == LP.first && P == LP.last) {
        LP.first = LP.last = NULL;
    } else if (P == LP.first) {
        LP.first = P->next;
        LP.first->prev = NULL;
    } else if (P == LP.last) {
        LP.last = P->prev;
        LP.last->next = NULL;
    } else {
        P->prev->next = P->next;
        P->next->prev = P->prev;
    }

    delete P;
}

// ================ CREATE DOKTER =================
adrDokter createDokter(string nama, string spes, int jam, int exp) {
    adrDokter D = new Dokter;
    D->nama = nama;
    D->spesialis = spes;
    D->jamPraktik = jam;
    D->pengalaman = exp;
    D->next = NULL.
    D->prev = NULL;
    return D;
}

// ================ INSERT DOKTER =================
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

// ================ DELETE DOKTER =================
void deleteDokter(adrPoli P, string namaDokter) {
    adrDokter D = P->firstDokter;
    if (D == NULL) return;

    if (D->nama == namaDokter) {
        P->firstDokter = D->next;
        if (P->firstDokter) P->firstDokter->prev = NULL;
        delete D;
        return;
    }

    while (D != NULL && D->nama != namaDokter) D = D->next;
    if (D == NULL) return;

    if (D->prev) D->prev->next = D->next;
    if (D->next) D->next->prev = D->prev;

    delete D;
}

// ================ TAMPILKAN DOKTER =================
void showDokter(adrPoli P) {
    adrDokter D = P->firstDokter;
    if (D == NULL) {
        cout << "  Tidak ada dokter.\n";
        return;
    }
    while (D != NULL) {
        cout << "  - " << D->nama << " | " << D->spesialis
             << " | Jam: " << D->jamPraktik
             << " | Pengalaman Kerja: " << D->pengalaman << " tahun\n";
        D = D->next;
    }
}

// ================ SHOW ALL =================
void showAll(ListPoli LP) {
    adrPoli P = LP.first;
    while (P != NULL) {
        cout << "\nPoliklinik: " << P->nama << endl;
        showDokter(P);
        P = P->next;
    }
}

// ================ HITUNG DOKTER =================
int countDokter(adrPoli P) {
    int count = 0;
    adrDokter D = P->firstDokter;
    while (D != NULL) {
        count++;
        D = D->next;
    }
    return count;
}

// ================ POLI DOKTER TERBANYAK =================
adrPoli poliDokterTerbanyak(ListPoli LP) {
    int max = -1;
    adrPoli P = LP.first;
    adrPoli maxPoli = NULL;

    while (P != NULL) {
        int jumlah = countDokter(P);
        if (jumlah > max) {
            max = jumlah;
            maxPoli = P;
        }
        P = P->next;
    }
    return maxPoli;
}
