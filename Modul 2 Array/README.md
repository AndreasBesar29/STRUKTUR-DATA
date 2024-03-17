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


Kode diatas digunakan untuk mencari nilai maksimum dari sebuah array yang telah diinputkan oleh user dan dilayar output menampilkan angka-angka yang telah diinputkan user dan mencari nilai maksimumnya.
## Unguided 
### 1. [Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!]
```C++

```
#### Output:

#### Full code Screenshot:

Kode diatas digunakan untuk 
### 2. [Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!]
```C++

```
#### Output:

#### Full code Screenshot:

Kode diatas digunakan untuk 
### 3. [Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!]
```C++

```
#### Output:

#### Full code Screenshot:

Kode diatas digunakan untuk 
## Kesimpulan
Kesimpulannya, array merupakan data untuk menyimpan beberapa elemen dengan tipe data yang sama dan tersusun secara sekuensial. Array memiliki beberapa jenis, seperti array satu dimensi, array dua dimensi, array tiga dimensi, dan array multi dimensi. Kita dapat mengelola data didalam program dengan mudah dan cepat. Array juga memungkinkan pengerjaan data yang kompleks dengan lebih efisien.

Dari materi array ini, pembelajaran yang didapat adalah bagaimana array dapat digunakan untuk mengelola dan menyimpan data didalam program. Array mempermudah kita untuk menyimpan beberapa jumlah data dengan tipe data yang sama. Dengan memahami konsep array ini, kita dapat mengelola data secara efisien.

## Referensi
[1] Pratama, Muhammad Aldi (2020). STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++.
