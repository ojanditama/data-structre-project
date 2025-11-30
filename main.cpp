#include <iostream>
#include "MLL.h"
using namespace std;

int main() {
    ListPoli LP;
    createListPoli(LP);

    int menu;
    do {
        cout << "\n===== SISTEM POLIKLINIK =====\n";
        cout << "1. Tambah Poliklinik\n";
        cout << "2. Tambah Dokter ke Poliklinik\n";
        cout << "3. Tampilkan Semua\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> menu;

        if (menu == 1) {
            string nama;
            cout << "Nama Poliklinik (tanpa spasi): ";
            cin >> nama;
            insertPoli(LP, createPoli(nama));
        }

        else if (menu == 2) {
            string poli;
            cout << "Masukkan nama poliklinik: ";
            cin >> poli;

            adrPoli P = findPoli(LP, poli);
            if (P == NULL) {
                cout << "Poliklinik tidak ditemukan!\n";
                continue;
            }

            string nama, spes;
            int jam, exp;

            cout << "Nama Dokter (tanpa spasi): ";
            cin >> nama;
            cout << "Spesialis (tanpa spasi): ";
            cin >> spes;
            cout << "Jam Praktik: ";
            cin >> jam;
            cout << "Pengalaman: ";
            cin >> exp;

            insertDokter(P, createDokter(nama, spes, jam, exp));
        }

        else if (menu == 3) {
            showAll(LP);
        }

    } while (menu != 0);

    return 0;
}
