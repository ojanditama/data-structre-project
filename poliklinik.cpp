void createListPoli(ListPoli &LP) {
    LP.first = nullptr;
    LP.last = nullptr;
}

adrPoli createPoli(string nama) {
    adrPoli P = new Poliklinik;
    P->nama = nama;
    P->firstDokter = nullptr;
    P->next = nullptr;
    P->prev = nullptr;

    return P;
}

void insertPoli(ListPoli &LP, adrPoli P) {
    if (LP.first == nullptr) {
        LP.first = LP.last = P;
    } else {
        LP.last->next = P;
        P->prev = LP.last;
        LP.last = P;
    }
}

adrPoli findPoli(ListPoli LP, string nama) {
    adrPoli P = LP.first;
    while (P != nullptr) {
        if (P->nama == nama) {
        return P;
        P = P->next;
    }
    return nullptr;
}

void deletePoli(ListPoli &LP, string nama) {
    adrPoli P = findPoli(LP, nama);

    if (P != nullptr) {
        adrDokter D = P->firstDokter;
        while (D != nullptr) {
            adrDokter temp = D;
            D = D->next;

            temp->next = nullptr;
            temp->prev = nullptr;
        }
        P->firstDokter = nullptr;

        if (P == LP.first && P == LP.last) {
            LP.first = nullptr;
            LP.last  = nullptr;
        }
        else if (P == LP.first) {
            LP.first = P->next;
            if (LP.first != nullptr)
                LP.first->prev = nullptr;
        }
        else if (P == LP.last) {
            LP.last = P->prev;
            if (LP.last != nullptr)
                LP.last->next = nullptr;
        }
        else {
            P->prev->next = P->next;
            P->next->prev = P->prev;
        }

        P->next = nullptr;
        P->prev = nullptr;
    }
}

void showAll(ListPoli LP) {
    adrPoli P = LP.first;
    while (P != nullptr) {
        cout << "\nPoliklinik: " << P->nama << endl;
        showDokter(P);
        P = P->next;
    }
}

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
