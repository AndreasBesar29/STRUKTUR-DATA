// Andreas Besar Wibowo
// 2311102198 / S1 IF-11-E

#include <iostream>

using namespace std;

void bubbleSort(char arr[], int i) {
    for (int a = 0; a < i - 1; a++) {
        for (int b = 0; b < i - a - 1; b++) {
            if (arr[b] > arr[b + 1]) {
                char temp = arr[b];
                arr[b] = arr[b + 1];
                arr[b + 1] = temp;
            }
        }
    }
}

bool binarySearch(char arr[], int i, char pencarian) {
    int posisiKiri = 0;
    int posisiKanan = i - 1;

    while (posisiKiri <= posisiKanan) {
        int posisiTengah = posisiKiri + (posisiKanan - posisiKiri) / 2;
        if (arr[posisiTengah] == pencarian) {
            return true;
        }
        if (arr[posisiTengah] < pencarian) {
            posisiKiri = posisiTengah + 1;
        } else {
            posisiKanan = posisiTengah - 1;
        }
    }
    return false;
}

int main() {
    const int maxKarakter = 100;
    char kalimat[maxKarakter];
    char pencarian;

    cout << "Tuliskan sebuah kalimat: ";
    cin.getline(kalimat, maxKarakter);

    int i = 0;
    while (kalimat[i] != '\0') {
        i++;
    }

    cout << "Masukkan huruf yang dicari: ";
    cin >> pencarian;

    bubbleSort(kalimat, i);

    bool ketemu = binarySearch(kalimat, i, pencarian);

    if (ketemu) {
        cout << "Huruf " << pencarian << " terdapat pada kalimat." << endl;
    } else {
        cout << "Huruf " << pencarian << " tidak terdapat pada kalimat." << endl;
    }

    return 0;
}
