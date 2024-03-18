#include <iostream>
#include <vector>

using namespace std;

int main() {
    int x;
    cout << "Masukkan jumlah elemen array: ";
    cin >> x;

    vector<int> arr(x);

    cout << "Masukkan elemen-elemen array:\n";
    for (int a = 0; a < x; a++) {
        cout << "Elemen ke-" << a + 1 << ": ";
        cin >> arr[a];
    }

    cout << "\nData array: ";
    for (int a = 0; a < x; a++) {
        cout << arr[a] << " ";
    }

    cout << "\nNomor ganjil: ";
    for (int a = 0; a < x; a++) {
        if (arr[a] % 2 != 0) {
            cout << arr[a] << ", ";
        }
    }

    cout << "\nNomor genap: ";
    for (int a = 0; a < x; a++) {
        if (arr[a] % 2 == 0) {
            cout << arr[a] << ", ";
        }
    }

    cout << endl;

    return 0;
}
