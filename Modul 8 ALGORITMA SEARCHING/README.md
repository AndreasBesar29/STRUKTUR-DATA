# <h1 align="center">Laporan Praktikum Modul 8 Algoritma Searching</h1>

<p align="center">Andreas Besar Wibowo</p>
<p align="center">2311102198 / IF-11-E</p>

## Dasar Teori
Pencarian (searching) merupakan proses menemukan suatu data tertentu di dalam sekumpulan banyak data yang bertipe sama[1]. Pencarian merupakan pekerjaan yang sering kita lakukan dalam kehidupan sehari– hari. Dalam text editor, kita sering melakukan pekerjaan mencari kata, atau mencari kata1 dan menggantikannya dengan kata 2. Metode pencrian (searching) terbagi lima, yaitu metode pencarian linier (Linear / Sequential Search), metode pencarian biner (Binary Search), metode pencarian interpolasi (Interpolation Search), metode pencarian langsung (Direct Search), metode pencarian relatif (Hash Search). Masing-masing metode memiliki kelebihan dan kekurangan[2]. Berikut ini adalah penjelasan dari Binary Search dan Sequential Search : 

### A. Binary Search
Binary Search adalah algoritma pencarian yang lebih efisien daripada algoritma Sequential Search. Hal ini dikarenakan algoritma ini tidak perlu menjelajahi setiap elemen dari table. Kerugiannya algoritma ini hanya biasa digunakan pada tabel yang elemenya sudah terurut baik menaik maupun menurun. Binary Search merupakan salah satu algoritma untuk meoplakukan pencarian pada array yang sudah terurut. Namun jika kita telah mengetahui integer dalam array terorganisasi baik secara menaik maupun menurun maka bisa dengan cepat menggunakan algoritma Binary Search[2].

Berikut langkah-langkah pencarian binary search : 
1. Mengurutkan data terlebih dahulu bisa secara ascending (dari depan ke belakang) atau descending (dari belakang ke depan). 
2. Membagi dua array atau keseluruhan data. Apabila data yang dicari lebih kecil dari data yang terletak di tengah, maka pencarian data akan berlanjut kesebelah kiri. Apabila data yang dicari lebih besar dari data terletak ditengah, maka pencarian data akan berlanjut kesebelah kanan kemudian proses pencarian tersebut akan terus berulang sampai data yang dimaksud atau dicari dapat ditemukan[4].

Binary Search ini dilakukan untuk : 
1. Memperkecil jumlah operasi perbandingan yang harus dilakukan antara data yang dicari dengan data yang ada didalam tabel, khususnya untuk jumlah data yang sangat besar ukurannya. 
2. Beban komputasi lebih kecil karena pencarian dilakukan dari depan, belakang dan tengah. 
3. Prinsip dasarnya adalah melakukan proses pembagian ruang pencarian secara berulang-ulang sampai data ditemukan atau sampai pencarian tidak dapat dibagi lagi (berarti terdapat kemungkinan data tidak dtiemukan)[3].

### B. Sequential Search
Algoritma Sequential search atau bisa juga disebut pencarian linear atau linear search adalah algoritma pencarian sederhana yang pencariannya dilakukan secara beruntun. Algoritma beruntun merupakan proses yang membandingkan tiap elemen larik satu persatu berurutan, mulai dari elemen awal, sampai dengan elemen yang dicari bisa ditemukan. Algoritma ini bekerja dengan mencocokkan data pada database dengan data yang dicari pencarian dilakukan secara beruntun dari data awal hingga data terakhir. 
Langkah-langkah pencarian dengan sequential search: 
1. Melakukan perbandingan beruntun pada kumpulan data dengan menggunakan keyword atau kata kunci yang akan dicari 
2. Pencarian ini melakukan looping atau pengulangan dari data pertama hingga jumlah data ke-n 
3. Setiap perulangan dilakukan pencocokan data dengan kata kunci yang dicari 
4. Apabila terdapat kecocokan data dengan kata kunci yang di cari maka data berhasil ditemukan dan pencarian di hentikan, sebaliknya apabila tidak ada kecocokan data hingga data terakhir maka pencarian dihentikan dan data tidak ditemukan[4].

Terdapat 2 kemungkinan yang akan terjadi dalam waktu pencarian data Sequential Search, diantaranya yaitu : 
1. Best Case Best case / kemungkinan terbaik akan terjadi apabila data yang dicari terletak pada index array yang paling depan, sehingga waktu yang dibutuhkan untuk mencari data sedikit. 
2. Worse Case Worse case / kemungkinan terburuk akan terjadi apabila data yang dicari terletak pada index array yang paling akhir, sehingga waktu yang dibutuhkan untuk mencari data akan sangat lama. 
Untuk meningkatkan efisiensi pencarian data pada Sequential Search dapat dilakukan dengan cara menghentikan looping dengan menggunakan BREAK apabila data yang dicari sudah ketemu[3].

## Guided
### 1. [Guided I : Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.]
```C++
#include <iostream>

using namespace std;

int arr[] = {1,4,2,5,6,7,8,9,10,15,14};
int cari = 15;
int i = 0;
int panjangArray = sizeof(arr)/sizeof(arr[0]);
bool ketemu = false;

int main () {
    for (i = 0; i < panjangArray; i++){
        if (arr[i] == cari) {
            ketemu = true;
            break;
        } else {
            i++;
        }
    }
    cout << "panjang array: " << panjangArray << endl;
    cout << cari << " terdapat pada indeks ke- " << arr[i];
}
```
#### Output:
![Output Guided 1](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/1f9eb4db-8d60-473c-8794-699ee6dc55c0)

Kode diatas digunakan untuk

### 2. [Guided II : Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search.]
```C++
#include <iostream>
#include <iomanip>

using namespace std;

// Deklarasi array dan variabel untuk pencarian
int arrayData[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort(int arr[], int n)
{
    int temp, min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        // Tukar elemen
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void binary_search(int arr[], int n, int target)
{
    int awal = 0, akhir = n - 1, tengah, b_flag = 0;

    while (b_flag == 0 && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (arr[tengah] == target)
        {
            b_flag = 1;
            break;
        }
        else if (arr[tengah] < target)
        {
            awal = tengah + 1;
        }
        else
        {
            akhir = tengah - 1;
        }
    }

    if (b_flag == 1)
        cout << "\nData ditemukan pada index ke-" << tengah << endl;
    else
        cout << "\nData tidak ditemukan\n";
}

int main()
{
    cout << "\tBINARY SEARCH" << endl;
    cout << "\nData awal: ";
    // Tampilkan data awal
    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << arrayData[x];
    }
    cout << endl;

    cout << "\nMasukkan data yang ingin Anda cari: ";
    cin >> cari;

    // Urutkan data dengan selection sort
    selection_sort(arrayData, 7);

    cout << "\nData diurutkan: ";
    // Tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << arrayData[x];
    }
    cout << endl;

    // Lakukan binary search
    binary_search(arrayData, 7, cari);
    
    return 0;
}
```
#### Output:
![Output Guided 2](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/b4846239-3cce-4154-b0a8-9836a55ea517)

Kode diatas digunakan untuk

## Unguided
### 1. [Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!]
```C++
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
```
#### Output:
![Output Unguided 1](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/332d852f-ea3c-4ec5-ab31-e52ecf9aebb3)

Kode diatas digunakan untuk

### 2. [Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!]
```C++
// Andreas Besar Wibowo
// 2311102198 / S1 IF-11-E

#include <iostream>
#include <string>

using namespace std;

bool isVowel(char j) {
    j = tolower(j);
    return (j == 'a' || j == 'e' || j == 'i' || j == 'o' || j == 'u');
}

int main() {
    string kalimat;
    int jumlahHuruf_Vokal = 0;

      cout << "Tuliskan Sebuah Kalimat: ";
    getline(cin, kalimat);

    for (char j : kalimat) {
        if (isVowel(j)) {
            jumlahHuruf_Vokal++;
        }
    }

   
    cout << "Jumlah huruf vokal yang terdapat di dalam kalimat yaitu : " << jumlahHuruf_Vokal << endl;

    return 0;
}
```
#### Output:
![Output Unguided 2](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/b9d923e4-7f22-42f8-9572-b7dd879f39ce)

Kode diatas digunakan untuk

### 3. [Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!]
```C++
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
```
#### Output:
![Output Unguided 3](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/b848fcf3-2fbc-4734-a21e-873d9b6c826c)

Kode diatas digunakan untuk

## Kesimpulan

## Referensi
[1] Wijaya, H. (2021). Algoritma Sequential Searching untuk Pencarian Identitas Mahasiswa dalam Penilaian Monitoring dan Evaluasi Kuliah Kerja Nyata Tematik. Akademika Jurnal, 18(1), 6-10.

[2] Religia, Y., & Nurhakim, A. (2019). Analisa Algoritma Binary Search Untuk Mencari Data Mahasiswa Program Studi Manajemen Universitas Pelita Bangsa Dengan Berbasis Android. Jurnal SIGMA, 10(3), 163-170.

[3] Religia, Y. (2019). Analisis Algoritma Sequential Search Dan Binary Search Pada Big Data: Analysis Of Sequential Search And Binary Search Algorithm In Big Data. Pelita Teknologi, 14(1), 74-79.

[4] Markuci, D., & Prianto, C. (2022). Analisis perbandingan penggunaan algoritma Sequential Search dan Binary Search pada aplikasi surat perjalanan dinas. JATI (Jurnal Mahasiswa Teknik Informatika), 6(1), 110-119.
