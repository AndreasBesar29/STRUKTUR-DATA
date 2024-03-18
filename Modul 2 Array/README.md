# <h1 align="center">Laporan Praktikum Modul 2 Array</h1>

<p align="center">Andreas Besar Wibowo</p>
<p align="center">2311102198 / IF-11-E</p>

## Dasar Teori
Array adalah suatu struktur untuk data yang terdiri dari sejumlah elemen yang memiliki tipe data yang sama. Elemen dalam array tersusun secara sekuensial. Array sangat cocok untuk kumpulan data yang ukuran dana elemennya sudah ditentukan dari awal. Semua elemen array bertipe sama atau homogen.

#### 1. Array Satu Dimensi
Array satu dimensi adalah kumpulan elemen identic yang tersusun dalam satu baris, tetapi isi dari elemen itu boleh berbeda-beda.
#### 2. Array Dua Dimensi
Array dua dimensi adalah perluasan dari array satu dimensi. Berbeda dengan array satu dimensi yang dimana hanya terdiri dari sebuah baris dan beberapa kolom dan elemen, sedangkan array dua dimensi terdiri dari beberapa baris dan beberapa kolom yang bertipe sama.
#### 3. Array Tiga Dimensi
Array tiga dimensi adalah array yang digunakan untuk mengelola data dalam bentuk 3 dimensi atau 3 sisi.
#### 4. Array Banyak DImensi / Multi Dimensi
Array banyak dimensi merupakan array yang sama dengan array satu, dua, tiga dimensi namun yang berbeda adalah banyaknya jumlah dimensinya. [1]
## Guided 

### 1. [Program Input Array Tiga Dimensi]
```C++
#include <iostream>

using namespace std;

// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
    // Deklarasi array
    int arr[2][3][3];
    // Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z
                     << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```
#### Output:
![Output Guided 1](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/6e6e1a88-256d-4f78-9a12-650192321f26)

Kode diatas digunakan untuk menampilkan array yang berbentuk tiga dimensi dan user mengisi array tersebut. Program dilayar output menampilkan nilai nilai yang sudah diinputkan oleh user dalam bentuk tiga dimensi.
### 2. [Program Mencari Nilai Maksimal pada Array]
```C++
#include <iostream>

using namespace std;

int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukkan panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}
```
#### Output:
![Output Guided 2](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/168d21b9-27ed-4f21-9124-b5943895d749)

Kode diatas digunakan untuk mencari nilai maksimum dari sebuah array yang telah diinputkan oleh user dan dilayar output menampilkan angka-angka yang telah diinputkan user dan mencari nilai maksimumnya.
## Unguided 
### 1. [Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!]
```C++
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

```
#### Output:
![Output Unguided 1](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/57d22c5a-801e-4d9c-88e5-526771693f07)

Kode diatas digunakan untuk meminta user mengisikan jumlah elemen array lalu mengisikan elemen elemen dalam arraynya dan ouputnya akan muncul data array beserta nomor ganjil dan nomor genapnya.
### 2. [Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!]
```C++
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

```
#### Output:
![Output Unguided 2](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/2669613a-acde-42e7-95d0-fef1305e4296)

Kode diatas digunakan untuk meminta user menginputkan ukuran elemen a, b, dan c lalu memgisi array tersebut dengan nilai nilai yang diinputkan user dan layar output menampilkan data pengguna dan menampilkan array tersebut dengan terstruktur.
### 3. [Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!]
```C++
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

```
#### Output:
![Output Unguided 3](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/e3e9de3a-e277-4b2a-8284-dc193b3870f1)

Kode diatas digunakan untuk meminta user mengisikan berapa jumlah elemen array yang diinginkan lalu mengisi array tersebut dengan nilai nilai dan dilayar output menampilkan nilai maksimum, nilai minimum, dan nilai rata-rata dari elemen yang dimasukkan oleh user.
## Kesimpulan
Kesimpulannya, array merupakan data untuk menyimpan beberapa elemen dengan tipe data yang sama dan tersusun secara sekuensial. Array memiliki beberapa jenis, seperti array satu dimensi, array dua dimensi, array tiga dimensi, dan array multi dimensi. Kita dapat mengelola data didalam program dengan mudah dan cepat. Array juga memungkinkan pengerjaan data yang kompleks dengan lebih efisien.

Dari materi array ini, pembelajaran yang didapat adalah bagaimana array dapat digunakan untuk mengelola dan menyimpan data didalam program. Array mempermudah kita untuk menyimpan beberapa jumlah data dengan tipe data yang sama. Dengan memahami konsep array ini, kita dapat mengelola data secara efisien.

## Referensi
[1] Pratama, Muhammad Aldi (2020). STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++.
