// Andreas Besar Wibowo
// 2311102198 / S1 IF-11-E

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Untuk Memasukkan jumlah kota
// (andreasBesarWibowo_2311102198) ini menunjukan jumlah dari kota
void masukanKota(string kota[], int andreasBesarWibowo_2311102198) {
    for (int a = 0; a < andreasBesarWibowo_2311102198; a++) {
        cout << "Simpul " << a + 1 << " : ";
        cin >> kota[a];
    }
}

// Untuk Menginput Jarak Antar Kota
void masukanJarak(int jarak[][100], string kota[], int andreasBesarWibowo_2311102198) {
    for (int a = 0; a < andreasBesarWibowo_2311102198; a++) {
        for (int b = 0; b < andreasBesarWibowo_2311102198; b++) {
            cout << kota[a] << " --> " << kota[b] << " = ";
            cin >> jarak[a][b];
        }
    }
}
// Untuk Menampilkan Tabel
void tampilTabel(int jarak[][100], string kota[], int andreasBesarWibowo_2311102198) {
    // Untuk Menampilkan Bagian Atas Tabel
    cout << endl << setw(15) << "";
    for (int a = 0; a < andreasBesarWibowo_2311102198; a++) {
        cout << setw(15) << kota[a];
    }
    cout << endl;

    // Untuk Menampilkan Isi di dalam Tabel
    for (int a = 0; a < andreasBesarWibowo_2311102198; a++) {
        cout << setw(15) << kota[a];
        for (int b = 0; b < andreasBesarWibowo_2311102198; ++b) {
            cout << setw(15) << jarak[a][b];
        }
        cout << endl;
    }
}

int main() {
    int andreasBesarWibowo_2311102198;
    cout << "Silahkan masukan jumlah simpul: ";
    cin >> andreasBesarWibowo_2311102198;

    string kota[andreasBesarWibowo_2311102198];
    int jarak[andreasBesarWibowo_2311102198][100];

    masukanKota(kota, andreasBesarWibowo_2311102198);
    masukanJarak(jarak, kota, andreasBesarWibowo_2311102198);
    tampilTabel(jarak, kota, andreasBesarWibowo_2311102198);

    return 0;
}
