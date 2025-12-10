adrDokter createDokter(string nama, string spes, int jam, int exp) {
    adrDokter D = new Dokter;
    D->nama = nama;
    D->spesialis = spes;
    D->jamPraktik = jam;
    D->pengalaman = exp;
    D->next = nullptr;
    D->prev = nullptr;
    
    return D;
}

void insertDokter(adrPoli P, adrDokter D) {
    if (P->firstDokter == nullptr) {
        P->firstDokter = D;
    } else {
        adrDokter Q = P->firstDokter;
        while (Q->next != nullptr) {
            Q = Q->next;
            Q->next = D;
            D->prev = Q;
        }
}

void deleteDokter(adrPoli P, string namaDokter) {
    adrDokter D;
    bool found = false;

    if (P != nullptr) {
        D = P->firstDokter;
        if (D != nullptr) {
            if (D->nama == namaDokter) {
                P->firstDokter = D->next;
                if (P->firstDokter != nullptr) {
                    P->firstDokter->prev = nullptr;
                }
                found = true;
            }
            else {
                while (D != nullptr && !found) {
                    if (D->nama == namaDokter) {
                        if (D->prev != nullptr)
                            D->prev->next = D->next;

                        if (D->next != nullptr)
                            D->next->prev = D->prev;
                            found = true;
                    } 
                    else {
                        D = D->next;
                    }
                }
            }
        }
    }
}

void showDokter(adrPoli P) {
    adrDokter D;

    if (P != nullptr) {
        D = P->firstDokter;
        if (D == nullptr) {
            cout << "  Tidak ada dokter.\n";
        }
        else {
            while (D != nullptr) {
                cout << "  - " << D->nama << " | " << D->spesialis
                     << " | Jam: " << D->jamPraktik
                     << " | Pengalaman Kerja: " << D->pengalaman << " tahun\n";
                D = D->next;
            }
        }
    }
}

int countDokter(adrPoli P) {
    int count = 0;
    adrDokter D = P->firstDokter;
    while (D != nullptr) {
        count++;
        D = D->next;
    }
    return count;
}
