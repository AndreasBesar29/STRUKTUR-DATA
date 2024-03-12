# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>

<p align="center">Andreas Besar Wibowo</p>
<p align="center">2311102198 / IF-11-E</p>

## Dasar Teori
Tipe data adalah sebuah cara untuk membedakan data berdasarkan dari jenis datanya. Tipe data juga diperlukan untuk komplier bisa mengerti data yang akan digunakan. 

#### 1. TIPE DATA PRMITIF
Tipe data primitive adalah tipe data yang ditentukan melalui sistemnya. Perbedaan dari setiap bahasa pemrograman yang digunakan adalah dari jumlah bitnya. Contoh dari tipe data primitive adalah :
- Int : Tipe data yang digunakan untuk bilangan bulat
- Float : Tipe data yang digunakan untuk bilangan desimal
- Char : Tipe data yang digunakan untuk huruf
- Boolean : Tipe data yang digunakan untuk nilai yang memiliki arti antara true dan false

#### 2. TIPE DATA ABSTRAK
Tipe data abstrak adalah tipe data yang dibuat oleh programmernya sendiri. Tipe data abstrak ini berisi dari berbagai banyak tipe data. Nilai nya juga bisa lebih dari satu dan berbagai tipe data

#### 3. TIPE DATA KOLEKSI
Tipe data koleksi adalah tipe data untuk menyimpan beberapa nilai secara bersamaan. Tipe data koleksi juga bisa mengelola banyak data dengan terstruktur. Contoh dari tipe data koleksi yaitu :
- Array : Array merupakan suatu struktur data statis yang menyimpan elemen-elemen dengan jenis data yang seragam. Elemen-elemen tersebut diakses melalui indeks tertentu. Ukuran array bersifat tetap dan harus ditentukan pada saat pendeklarasian.

- Vector : Vector adalah Standard Template Library (STL), mirip dengan array dalam hal menyimpan data dalam bentuk elemen-elemen yang alokasi memorinya dilakukan otomatis dan bersebelahan. Vector memiliki kemampuan untuk menangani jumlah elemen yang dinamis. Vector menyediakan fleksibilitas dalam mengelola koleksi data dengan kemampuan dinamisnya, yang memungkinkan penambahan atau pengurangan elemen tanpa harus khawatir tentang alokasi memorinya secara manual.

- Map : Map, mirip dengan array, memungkinkan penggunaan indeks, disebut "key", yang tidak terbatas pada tipe data integer. Pada map, indeks diberi nama "key". Bukan hanya integer, sehingga map memberikan fleksibilitas yang lebih besar dibandingkan dengan array konvensional. Implementasi std::map menggunakan struktur data pohon merah-hitam yang secara otomatis seimbang, memberikan efisiensi dalam operasi pencarian dan penyisipan data.

## Guided 

### 1. [TIPE DATA PRIMITIF]
```C++
#include <iostream>

using namespace std;

// Main program
int main()
{
    char op;
    float num1, num2;
    // It allows user to enter operator i.e. +, -, *, /
    cin >> op;
    // It allow user to enter the operands
    cin >> num1 >> num2;
    // Switch statement begins
    switch (op)
    {
    // If user enter +
    case '+':
        cout << num1 + num2;
        break;
    // If user enter -
    case '-':
        cout << num1 - num2;
        break;
    // If user enter *
    case '*':
        cout << num1 * num2;
        break;
    // If user enter /
    case '/':
        cout << num1 / num2;
        break;
    // If the operator is other than +, -, * or /,
    // error message will display
    default:
        cout << "Error! operator is not correct";
    } // switch statement ends
    return 0;
}
```
#### Output:

Kode di atas digunakan untuk mencetak hasil dari penjumlahan, pengurangan, perkalian, dan pembagian atau bisa disebut juga kalkulator sederhana ke layar output dengan menggunakan function cout dan switch untuk menjalani atau mengeksekusi program tersebut.

### 2. [TIPE DATA ABSTRAK ]
```C++
#include <stdio.h>
// Struct
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};
int main()
{
    // menggunakan struct
    struct Mahasiswa mhs1, mhs2;
    // mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;
    // mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;
}
```
#### Output:

Kode diatas digunakan untuk menyimpan data mahasiswa yang terdiri dari nama, alamat, dan umur ke layar output dengan menggunakan function printf agar bisa mengeksekusi program tersebut.

### 3. [TIPE DATA KOLEKSI]
```C++
#include <iostream>
using namespace std;
int main()
{
    // deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;
    // mencetak array
    cout << "Isi array pertama :" << nilai[0] << endl;
    cout << "Isi array kedua :" << nilai[1] << endl;
    cout << "Isi array ketiga :" << nilai[2] << endl;
    cout << "Isi array keempat :" << nilai[3] << endl;
    cout << "Isi array kelima :" << nilai[4] << endl;
    return 0;
}

```
#### Output:

Kode diatas digunakan untuk medeklarasi array nilai dengan nilai elemen bertipe integer dan mencetak masing masing dari integer tersebut ke layar output dan menggunakan function cout untuk mengeksekusinya.

## Unguided 

### 1. [Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!]

```C++
#include <iostream>

using namespace std;

// Fungsi untuk memfaktorialkan suatu bilangan
int factorial(int Bilangan) {
    if (Bilangan == 0 || Bilangan == 1)
        return 1;
    else
        return Bilangan * factorial(Bilangan - 1);
}

int main() {
    int Bilangan;

    cout << "Masukkan suatu bilangan: ";
    cin >> Bilangan;

    // Untuk menghitung faktorial dari sebuah bilangan
    cout << "Bilangan Faktorial dari " << Bilangan << " adalah: " << factorial(Bilangan) << endl;

    return 0;
}

```
#### Output:

Kode diatas digunakan untuk mencetak hasil faktorial dari bilangan yang diinputkan oleh peng-input ke layar output dengan menggunakan function cout dan factorial untuk mengeksekusi program tersebut.


#### Full code Screenshot:

### 2. [Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya!]

Contoh Untuk Fungsi Dari Struct
```C++
#include <iostream>
#include <string>

using namespace std;

// struct Mahasiswa
struct Mahasiswa {
    string nama;
    int nim;
    float ipk;
};

// memasukkan data mahasiswa
void inputMahasiswa(Mahasiswa& mhs) {
    cout << "Masukkan Nama Mahasiswa: ";
    getline(cin, mhs.nama);

    cout << "Masukkan NIM Mahasiswa: ";
    cin >> mhs.nim;

    cout << "Masukkan IPK Mahasiswa: ";
    cin >> mhs.ipk;
}

// menampilkan data mahasiswa
void tampilkanMahasiswa(const Mahasiswa& mhs) {
    cout << "\nData Mahasiswa\n";
    cout << "Nama: " << mhs.nama << endl;
    cout << "NIM: " << mhs.nim << endl;
    cout << "IPK: " << mhs.ipk << endl;
}

int main() {
    // Mendefinisikan variabel bertipe struct Mahasiswa
    Mahasiswa mahasiswa1;

    // Memanggil fungsi inputMahasiswa untuk mengisi data mahasiswa1
    inputMahasiswa(mahasiswa1);

    // Memanggil fungsi tampilkanMahasiswa untuk menampilkan data mahasiswa1
    tampilkanMahasiswa(mahasiswa1);

    return 0;
}
```
#### Output:

Kode diatas digunakan untuk membuat struktur data mahasiswa dari nama, nim, dan ipk dengan  menggunakan struct  dan kemudian ditampilkan ke layar output dengan menggunakan function cout untuk mengelola programnya.

#### Full code Screenshot:

Contoh Untuk Fungsi Dari Class
```C++
#include <iostream>
#include <string>

using namespace std;

class Mahasiswa {
private:
    string nama;
    int nim;
    float ipk;

public:
    void inputData() {
        cout << "Masukkan Nama Mahasiswa: ";
        getline(cin, nama);

        cout << "Masukkan NIM Mahasiswa: ";
        cin >> nim;

        cout << "Masukkan IPK Mahasiswa: ";
        cin >> ipk;

        cin.ignore();
    }

    void MenampilkanData() {
        cout << "\nD Mahasiswa\n";
        cout << "Nama: " << nama << endl;
        cout << "NIM: " << nim << endl;
        cout << "IPK: " << ipk << endl;
    }
};

int main() {
    Mahasiswa mahasiswa1;

    // Memasukkan data mahasiswa
    mahasiswa1.inputData();

    // Menampilkan data mahasiswa
    mahasiswa1.MenampilkanData();

    return 0;
}
```
#### Output:

Kode diatas digunakan untuk mendefinisikan sebuah class mahasiswa yang bersifat privat seperti nama, nim, dan ipk dan bersifat publik pada input data dan user diminta untuk menginputkan datanya dan di layar output sistem langsung menunjukan data yang diinput oleh user.

#### Full code Screenshot:

### 3. [Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map!]

```C++
#include <iostream>
#include <map>
#include <string>

using namespace std;

// Fungsi untuk menampilkan jenis motor berdasarkan plat nomor
void tampilkanJenisMotor(const map<string, string>& dataMotor, const string& platNomor) {
    auto it = dataMotor.find(platNomor);
    
    if (it != dataMotor.end()) {
        cout << "Jenis motor untuk plat nomor " << platNomor << ": " << it->second << endl;
    } else {
        cout << "Plat nomor " << platNomor << " tidak ditemukan." << endl;
    }
}

int main() {
    // Membuat map untuk menyimpan data plat nomor dan jenis motor
    map<string, string> dataMotor;

    // Mengisi data plat nomor dan jenis motor
    dataMotor["Honda"] = "R 7782 GA";
    dataMotor["Suzuki"] = "K 7574 TY";
    dataMotor["Yamaha"] = "H 6548 UW";

    // Meminta input plat nomor dari pengguna
    string MerkMotor;
    cout << "Masukkan jenis motor: ";
    cin >> MerkMotor;

    // Menampilkan jenis motor berdasarkan plat nomor
    tampilkanJenisMotor(dataMotor, MerkMotor);

    return 0;
}
```
#### Output:

Kode diatas digunakan untuk mencari plat nomor dengan cara menginputkan merk motor yang dicari oleh user dan di layar output memunculkan hasil dari yang diinputkan oleh user berupa plat nomor.

#### Full code Screenshot:

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.


