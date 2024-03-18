#include <iostream>

using namespace std;

int main() {
    int x;
    cout << "Masukkan jumlah elemen array: ";
    cin >> x;

    int arr[x];

    cout << "Masukkan elemen-elemen array:\n";
    for (int a = 0; a < x; ++a) {
        cout << "Elemen ke-" << a + 1 << ": ";
        cin >> arr[a];
    }

    int nilai_max = arr[0];
    for (int a = 1; a < x; a++) {
        if (arr[a] > nilai_max) {
            nilai_max = arr[a];
        }
    }

    int nilai_min = arr[0];
    for (int a = 1; a < x; a++) {
        if (arr[a] < nilai_min) {
            nilai_min = arr[a];
        }
    }

    int total = 0;
    for (int a = 0; a < x; a++) {
        total += arr[a];
    }
    float nilai_ratarata = static_cast<float>(total) / x;

    cout << "Nilai maksimum: " << nilai_max << endl;
    cout << "Nilai minimum: " << nilai_min << endl;
    cout << "Nilai rata-rata: " << nilai_ratarata << endl;

    return 0;
}
