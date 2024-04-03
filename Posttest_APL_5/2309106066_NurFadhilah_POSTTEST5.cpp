#include <iostream>
#include <limits>
using namespace std;

struct Detail {
    string penulis;
    string tanggal_pengiriman;
};

struct Naskah {
    string judul;
    Detail detail;
};

void tambah_naskah(Naskah *draft, int& jml) {
    cout << "\n";
    cout << "\n______Menambah Daftar Naskah______\n";
    cout << "\n";
    cout << "Masukkan Judul Naskah: ";
    cin.ignore();
    getline(cin, draft[jml].judul);
    
    cout << "Masukkan Nama Penulis: ";
    getline(cin, draft[jml].detail.penulis);
    
    cout << "Masukkan Tanggal Pengiriman: ";
    cin >> draft[jml].detail.tanggal_pengiriman;
    
    jml++;
    cout << "__________________________________\n" << endl;
}

void ubah_naskah(Naskah *draft, int jml) {
    int idx;
    cout << "\n______Mengubah Daftar Naskah______\n";
    cout << "\n";
    for (int i = 0; i < jml; i++) {
        cout << i + 1 << ". " << draft[i].judul << endl;
    }
    cout << "\n";
    cout << "Pilih opsi naskah yang ingin diubah: ";
    cin >> idx;
    cout << "\n";
    cout << "Masukkan Judul Naskah Baru: ";
    cin.ignore();
    getline(cin, draft[idx - 1].judul);
    cout << "\n";
    cout << "Masukkan Nama Penulis Baru: ";
    getline(cin, draft[idx - 1].detail.penulis);
    cout << "\n";
    cout << "Masukkan Tanggal Pengiriman Naskah Baru: ";
    getline(cin, draft[idx - 1].detail.tanggal_pengiriman);
}


void lihat_naskah(Naskah *draft, int jml) {
    cout << "\n__________Daftar Naskah___________\n\n";
    for (int i = 0; i < jml; i++) {
        cout << "Judul: " << draft[i].judul << endl;
        cout << "Penulis: " << draft[i].detail.penulis << endl;
        cout << "Tanggal Pengiriman: " << draft[i].detail.tanggal_pengiriman << endl;
        cout << endl;
    }
    cout << "__________________________________\n" << endl;
}

void hapus_naskah(Naskah *draft, int& jml) {
    int idx;
    cout << "\n______Menghapus Daftar Naskah______\n\n";
    
    for (int i = 0; i < jml; i++) {
        cout << i + 1 << ". " << draft[i].judul << endl;
    }
    cout << "\n";
    cout << "Pilih opsi naskah yang ingin dihapus: ";
    cin >> idx;

    for (int i = idx - 1; i < jml; i++) {
        draft[i] = draft[i + 1];
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
    Naskah daftar_naskah[100];
    Naskah *ptr_daftar_naskah = daftar_naskah;
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
                tambah_naskah(ptr_daftar_naskah, jml);
                break;
            case 2:
                ubah_naskah(ptr_daftar_naskah, jml);
                break;
            case 3:
                lihat_naskah(ptr_daftar_naskah, jml);
                break;
            case 4:
                hapus_naskah(ptr_daftar_naskah, jml);
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
