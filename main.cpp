#include <iostream>
#include "MLL.h"
using namespace std;

int main() {
    ListPoli LP;
    createListPoli(LP);

    int pilih;

    do {
        cout << "\n===== SISTEM ADMINISTRASI POLIKLINIK =====\n";
        cout << "1. Tambah Poliklinik\n";
        cout << "2. Tambah Dokter\n";
        cout << "3. Cari Poliklinik\n";
        cout << "4. Tambah Dokter ke Poliklinik tertentu\n";
        cout << "5. Tampilkan Dokter berdasarkan Poliklinik\n";
        cout << "6. Hapus Poliklinik beserta Dokter\n";
        cout << "7. Hapus Dokter dari Poliklinik\n";
        cout << "8. Tampilkan Semua Poliklinik dan Dokter\n";
        cout << "9. Hitung jumlah Dokter pada Poliklinik\n";
        cout << "10. Tampilkan Poliklinik dengan Dokter terbanyak\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            string nama;
            cout << "Nama Poliklinik (tanpa spasi): ";
            cin >> nama;
            insertPoli(LP, createPoli(nama));
        }

        else if (pilih == 2) {
            string nama, spes;
            int jam;

            cout << "Nama Dokter: ";
            cin >> nama;
            cout << "Spesialis: ";
            cin >> spes;
            cout << "Jam Praktik: ";
            cin >> jam;

            cout << "Masukkan Poliklinik: ";
            string poli;
            cin >> poli;

            adrPoli P = findPoli(LP, poli);
            if (P) insertDokter(P, createDokter(nama, spes, jam, exp));
            else cout << "Poliklinik tidak ditemukan.\n";
        }

        else if (pilih == 3) {
            string nama;
            cout << "Cari poliklinik: ";
            cin >> nama;

            adrPoli P = findPoli(LP, nama);
            if (P) cout << "Poliklinik ditemukan.\n";
            else cout << "Tidak ditemukan.\n";
        }

        else if (pilih == 4) {
            string poli, nama, spes;
            int jam;

            cout << "Nama Poliklinik: ";
            cin >> poli;
            adrPoli P = findPoli(LP, poli);

            if (!P) {
                cout << "Poliklinik tidak ditemukan.\n";
                continue;
            }

            cout << "Nama Dokter: ";
            cin >> nama;
            cout << "Spesialis: ";
            cin >> spes;
            cout << "Jam Praktik: ";
            cin >> jam;

            insertDokter(P, createDokter(nama, spes, jam));
        }

        else if (pilih == 5) {
            string poli;
            cout << "Nama Poliklinik: ";
            cin >> poli;

            adrPoli P = findPoli(LP, poli);
            if (P) showDokter(P);
            else cout << "Poliklinik tidak ditemukan.\n";
        }

        else if (pilih == 6) {
            string poli;
            cout << "Hapus Poliklinik: ";
            cin >> poli;
            deletePoli(LP, poli);
        }

        else if (pilih == 7) {
            string poli, nama;
            cout << "Nama Poliklinik: ";
            cin >> poli;
            adrPoli P = findPoli(LP, poli);

            if (!P) {
                cout << "Poliklinik tidak ditemukan.\n";
                continue;
            }

            cout << "Nama Dokter: ";
            cin >> nama;
            deleteDokter(P, nama);
        }

        else if (pilih == 8) {
            showAll(LP);
        }

        else if (pilih == 9) {
            string poli;
            cout << "Nama Poliklinik: ";
            cin >> poli;

            adrPoli P = findPoli(LP, poli);
            if (P) cout << "Jumlah Dokter: " << countDokter(P) << endl;
            else cout << "Poliklinik tidak ditemukan.\n";
        }

        else if (pilih == 10) {
            adrPoli P = poliDokterTerbanyak(LP);
            if (P) {
                cout << "Poliklinik dengan dokter terbanyak: "
                     << P->nama << " (" << countDokter(P) << " Dokter)\n";
            }
        }

    } while (pilih != 0);

    return 0;
}
