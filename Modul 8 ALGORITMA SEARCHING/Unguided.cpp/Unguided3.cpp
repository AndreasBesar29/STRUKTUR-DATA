// Andreas Besar Wibowo
// 2311102198 / S1 IF-11-E

#include <iostream>

using namespace std;

int main() {
    int dataNomor[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int size = sizeof(dataNomor) / sizeof(dataNomor[0]);
    int pencarian = 4;
    int Hitung = 0;

    for (int a = 0; a < size; a++) {
        if (dataNomor[a] == pencarian) {
            Hitung++;
        }
    }

    cout << "Jadi jumlah angka " << pencarian << " dalam data nomor adalah: " << Hitung << endl;

    return 0;
}
