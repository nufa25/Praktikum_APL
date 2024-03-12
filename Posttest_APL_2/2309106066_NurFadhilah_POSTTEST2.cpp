#include <iostream>
#include <limits>

using namespace std;

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

        if (menu == 1) {
            cout << "\n";
            cout << "______Menambah Daftar Naskah______\n";
            cout << "\n";
            cout << "Masukkan Judul Naskah: ";
            cin.ignore();
            getline(cin, naskah[jml]);
            jml++;
            cout << "__________________________________\n"<< endl;
        }

        else if (menu == 2) {
            cout << "\n";
            cout << "______Mengubah Daftar Naskah______\n";
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

        else if (menu == 3) {
            cout << "\n";
            cout << "__________Daftar Naskah___________\n";
            cout << " \n";
            for (int i = 0; i < jml; i++) {
                cout << i + 1 << ". " << naskah[i] << endl;
            }
            cout << "__________________________________\n"<< endl;
        }
        else if (menu == 4) {
            cout << "\n";
            cout << "______Menghapus Daftar Naskah______\n";
            cout << "\n";
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
        else if (menu == 5) {
            cout << "\n";
            cout << "Ingin keluar sistem? (y/n): ";
            cin >> keluar;
            if (keluar == "y") {
                break;
            }
           
            
        }
        else {
            cout << "\n" << endl;
            cout << "MENU INVALID." << endl;
        }
    }
    return 0;
}

