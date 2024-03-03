#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    string nama = "nur fadhilah";
    string nim = "2309106066";
    string Nama;
    string NIM;
    double nilai;
    int ulangi = 0;
    int menu1;
    int menu2;
    const int max_ulangi = 3;
    char lanjut;

    while (ulangi != max_ulangi) {
        cout << "Masukkan Nama : ";
        getline(cin, Nama);
        transform(Nama.begin(), Nama.end(), Nama.begin(), ::tolower);
        cout << "Masukkan NIM : ";
        getline(cin, NIM);

        if (Nama == nama && NIM == nim) {
            cout << "Login berhasil" << endl;
            cout << "-------------------------" << endl;
            while (true) {
                cout << "1. km/jam"<< endl;
                cout << "2. cm/s" << endl;
                cout << "3. m/s" << endl;
                cout << "4. mil/jam" << endl;
                cout << "Pilih Menu: ";
                cin >> menu1;
                cout << "Masukkan nilai: ";
                cin >> nilai;
                cout << "1. km/jam" << endl;
                cout << "2. cm/s" << endl;
                cout << "3. m/s" << endl;
                cout << "4. mil/jam" << endl;
                cout << "Pilih Menu untuk dikonversi: ";
                cin >> menu2;
                
                if (menu1 == 1) {
                    if (menu2 == 1) {
                        cout << "Hasil konversi: " << nilai << " km/jam" << endl; 
                    }
                    else if (menu2 == 2) {
                        cout << "Hasil konversi: " << nilai * 100000/3600 << " cm/s" << endl;
                    }
                    else if (menu2 == 3) {
                        cout << "Hasil konversi: " << nilai * 1000/3600 << " m/s" << endl;
                    }
                    else if (menu2 == 4) {
                        cout << "Hasil konversi: " << nilai * 0.621371 << " mil/jam" << endl;
                    }
                    else if (menu2 > 4){
                        cout << "Input salah" << endl;
                    }
                }
                else if (menu1 == 2){
                    if (menu2 == 1){
                        cout << "Hasil konversi: " << nilai * 3600/100000 << " km/jam" << endl;
                    }
                    else if (menu2 == 2){
                        cout << "Hasil konversi: " << nilai << " cm/s" << endl;
                    }
                    else if (menu2 == 3){
                        cout << "Hasil konversi: " << nilai /100 << " m/s" << endl;
                    }
                    else if (menu2 == 4){
                        cout << "Hasil konversi: " <<  nilai *0.0223694 << " mil/jam"<< endl;
                    }
                    else if (menu2 > 4){
                        cout << "Input salah" << endl;
                    }
                }
                else if (menu1 == 3){
                    if (menu2 == 1){
                        cout << "Hasil konversi: " << nilai /1000 << " km/jam" << endl;
                    }
                    else if (menu2 == 2){
                        cout << "Hasil konversi: " << nilai*100 << " cm/sekon" << endl;
                    }
                    else if (menu2 == 3){
                        cout << "Hasil konversi: " << nilai << " m/sekon" << endl;
                    }
                    else if (menu2 == 4){
                        cout << "Hasil konversi: " << nilai*2.23694 << " mil/jam" << endl;
                    }
                    else if (menu2 > 4){
                        cout << "Input salah" << endl;
                    }
                }
                else if (menu1 == 4){
                    if (menu2 == 1){
                        cout << "Hasil konversi: " << nilai*1.60934 << " km/jam" << endl;
                    }
                    else if (menu2 == 2){
                        cout << "Hasil konversi: " << nilai*44.704 << " cm/sekon" << endl;
                    }
                    else if (menu2 == 3){
                        cout << "Hasil konversi: " << nilai*0.44704 << " m/sekon" << endl;
                    }
                    else if (menu2 == 4){
                        cout << "Hasil konversi: " << nilai << " mil/jam" << endl;
                    }
                    else if (menu2 > 4){
                        cout << "Input salah" << endl;
                    }
                }
                else if (menu1 > 4){
                        cout << "Input salah" << endl;
                    }

                cout << "Apakah Anda ingin melanjutkan konversi? (y/n): ";
                cin >> lanjut;
                if (lanjut == 'n' || lanjut == 'N') {
                    cout << "Selesai" << endl;
                    break;
                }
                else if (lanjut != 'y' && lanjut != 'Y' ){
                    break;
                }
                
            }
            break;
        } else {
            ulangi++;
            cout << "coba lagi" << endl;
            continue;
        }
    }

    if (ulangi == max_ulangi){
        cout << "Login gagal" << endl;
    }
    return 0;
}
