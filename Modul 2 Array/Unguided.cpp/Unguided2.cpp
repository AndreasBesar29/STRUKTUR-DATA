#include <iostream>

using namespace std;

int main() {
    int Array_a, Array_b, Array_c;
    
    cout << "Masukkan ukuran elemen dalam a: ";
    cin >> Array_a;
    cout << "Masukkan ukuran elemen dalam b: ";
    cin >> Array_b;
    cout << "Masukkan ukuran elemen dalam c: ";
    cin >> Array_c;

  
int arr[Array_a][Array_b][Array_c];

    for (int a = 0; a < Array_a; a++) {
        for (int b = 0; b < Array_b; b++) {
            for (int c = 0; c < Array_c; c++) {
                cout << "Input Array[" << a << "][" << b << "][" << c << "] = ";
                cin >> arr[a][b][c];
            }
        }
        cout << endl;
    }

    cout << "Data Array:\n";
    for (int a = 0; a < Array_a; a++) {
        for (int b = 0; b < Array_b; b++) {
            for (int c = 0; c < Array_c; c++) {
                cout << "Array[" << a << "][" << b << "][" << c << "] = " << arr[a][b][c] << endl;
            }
        }
    }
    cout << endl;

    for (int a = 0; a < Array_a; a++) {
        for (int b = 0; b < Array_b; b++) {
            for (int c = 0; c < Array_c; c++) {
                cout << arr [a][b][c] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
