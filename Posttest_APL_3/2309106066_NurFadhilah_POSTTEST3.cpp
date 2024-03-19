#include <iostream>
#include <limits>

using namespace std;

void tambah_naskah(string naskah[], int& jml) {
    cout << "\n______Menambah Daftar Naskah______\n";
    cout << "Masukkan Judul Naskah: ";
    cin.ignore();
    getline(cin, naskah[jml]);
    jml++;
    cout << "__________________________________\n" << endl;
}

void ubah_naskah(string naskah[], int jml) {
    int idx;
    cout << "\n______Mengubah Daftar Naskah______\n";
    cout << "\n";
    for (int i = 0; i < jml; i++) {
        cout << i + 1 << ". " << naskah[i] << endl;
    }
    cout << "\n";
    cout << "Pilih opsi naskah yang ingin diubah: ";
    cin >> idx;
    cout << "\n";
    cout << "Masukkan Judul Naskah Baru: ";
    cin.ignore();
    getline(cin, naskah[idx - 1]);
    cout << "\n";
}

void lihat_naskah(string naskah[], int jml) {
    cout << "\n__________Daftar Naskah___________\n\n";
    for (int i = 0; i < jml; i++) {
        cout << i + 1 << ". " << naskah[i] << endl;
    }
    cout << "__________________________________\n" << endl;
}

void hapus_naskah(string naskah[], int& jml) {
    int idx;
    cout << "\n______Menghapus Daftar Naskah______\n\n";
    
    for (int i = 0; i < jml; i++) {
        cout << i + 1 << ". " << naskah[i] << endl;
    }
    cout << "\n";
    cout << "Pilih opsi naskah yang ingin dihapus: ";
    cin >> idx;

    for (int i = idx - 1; i < jml; i++) {
        naskah[i] = naskah[i + 1];
        jml--;
    }
    cout << "\n";
}


void keluar_sistem(string& keluar) {
    cout << "\nIngin keluar sistem? (y/n): ";
    cin >> keluar;
    if (keluar != "y" && keluar != "n") {
        cout << "Pilihan tidak valid. Silakan masukkan 'y' atau 'n'." << endl;
        keluar_sistem(keluar);
    }
}

int main() {
    int jml = 0, menu, idx;
    string naskah[100];
    string keluar = "n";

    cout << "-----------Selamat Datang Di Sistem Manajemen Naskah-----------" << endl;
    while (keluar == "n") {
        cout << "\n1. Tambahkan Daftar Naskah yang Terseleksi\n"
            "2. Ubah Daftar Naskah\n"
            "3. Lihat Daftar Naskah \n"
            "4. Hapus Daftar Naskah\n"
            "5. Keluar Sistem\n\n";
        cout << "Pilih Menu: ";

        if (!(cin >> menu)) {
            cout << " " << endl;
            cout << "INPUT INVALID"<< endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (menu) {
            case 1:
                tambah_naskah(naskah, jml);
                break;
            case 2:
                ubah_naskah(naskah, jml);
                break;
            case 3:
                lihat_naskah(naskah, jml);
                break;
            case 4:
                hapus_naskah(naskah, jml);
                break;
            case 5:
                keluar_sistem(keluar);
                break;
            default:
                cout << "\n" << endl;
                cout << "MENU INVALID." << endl;
        }
    }
    return 0;
}
