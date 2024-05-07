# <h1 align="center">Laporan Praktikum Modul 6 Stack</h1>

<p align="center">Andreas Besar Wibowo</p>
<p align="center">2311102198 / IF-11-E</p>

## Dasar Teori
Stack (tumpukan) merupakan suatu susunan koleksi data dimana data yang dapat ditambahkan dan dihapus selalu dilakukan pada bagian akhir data, yang disebut dengan top of stack. Dengan kata lain, stack hanya mengijinkan akses pada item yang terakhir dimasukkan[1].

Stack atau tumpukan adalah suatu stuktur data yang penting dalam pemrograman dengan metode pemrosesan yang bersifat LIFO (Last In First Out) dimana objek/benda yang terakhir masuk ke dalam stack akan menjadi benda pertama yang dikeluarkan dari stack. Dengan model demikian, maka hanya bagian paling atas saja dari stack (TOP) yang bisa di akses. Salah satu kelebihan stack adalah bahwa struktur data tersebut dapat di implementasikan baik pada array maupun pada linked list.

Adapun operasi-operasi/fungsi yang dapat dilakukan pada stack adalah sebagai berikut : 
1) Push : digunakan untuk menambah item pada stack pada tumpukan paling atas. 
2) Pop : digunakan untuk mengambil item pada stack pada tumpukan paling atas.
3) Clear : digunakan untuk mengkosongkan stack. 
4) IsEmpty : fungsi yang digunakan untuk mengecek apakah stack sudah kosong.
5) IsFull : fungsi yang digunakan untuk mengecek apakah stack sudah penuh[2].

Ciri-Ciri Stack : 
1. Elemen TOP (puncak) diketahui. Dalam stack, elemen teratas (puncak) selalu teridentifikasi, memudahkan akses langsung ke elemen yang paling baru ditambahkan atau yang paling atas.
2. Pengisipan dan penghapusan elemen selalu dilakukan di TOP. Operasi pengisian (penambahan) dan penghapusan elemen selalu terjadi di puncak stack, memastikan bahwa elemen yang terakhir dimasukkan akan menjadi elemen yang pertama kali dihapus.
3. LIFO ( Last In, First Out ). Konsep LIFO (Last In, First Out) yang mendasari stack menunjukkan bahwa elemen yang paling baru ditambahkan akan menjadi elemen yang pertama kali diakses atau dihapus.

Pemanfaatan Stack : 
1. Perhitungan ekspresi aritmatika (posfix). Untuk mengonversi ekspresi dari bentuk infix ke postfix dan mengevaluasinya dengan urutan yang benar.
2. Algoritma backtraking (runut balik). Untuk menyimpan langkah-langkah sementara dan mencoba solusi alternatif.
3. Algoritma rekursif. Untuk menyimpan konteks panggilan fungsi dan memastikan kedalaman rekursi yang terbatas[3].

## Guided
### 1. [Guided I]
```C++
#include <iostream>

using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull()
{
    return (top == maksimal);
}

bool isEmpty()
{
    return (top == 0);
}

void pushArrayBuku(string data)
{
    if (isFull())
    {
        cout << "Data telah penuh" << endl;
    }
    else
    {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else
    {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi)
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack()
{
    return top;
}

void changeArrayBuku(int posisi, string data)
{
    if (posisi > top)
    {
        cout << "Posisi melebihi data yang ada" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku()
{
    for (int i = top; i >= 0; i--)
    {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dicetak" << endl;
    }
    else
    {
        for (int i = top - 1; i >= 0; i--)
        {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main()
{
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";

    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;

    cetakArrayBuku();
    
    return 0;
}
```

#### Output:
![Output Guided 1](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/f64c6424-fe3d-433f-81e9-bdc62fc5c7d7)

Kode diatas digunakan untuk memasukkan, mengeluarkan, melihat, menghitung, mengubah, menghapus, dan mencetak isi di dalam stack. Dimana dalam program tersebut di tuliskan isi dalam stacknya adalah berupa buku dan di outputnya di tuliskan fungsi-fungsinya. Sehingga, di layar output akan di tampilkan semua fungsi yang di tuliskan di dalam int main ( ).

## Unguided
### 1. [Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkandalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca daridepan dan belakang sama. Jelaskan bagaimana cara kerja programnya.]
```C++
// Andreas Besar Wibowo
// 2311102198 / IF-11-E

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool Palindrom(const string& Kalimat) {

    stack<char> stackChar;

    for (char a : Kalimat) {
        if (isalpha(a)) {
            if (a >= 'A' && a <= 'Z') {
                stackChar.push(a + 32); 
            } else {
                stackChar.push(a);
            }
        }
    }

    for (char a : Kalimat) {
        if (isalpha(a)) {
            if (a >= 'A' && a <= 'Z') {
                a += 32;
            }
            if (a != stackChar.top()) {
                return false; 
            }
            stackChar.pop(); 
        }
    }

    return true; 
}

int main() {

    string masukkanKalimat;

    cout << "Masukkan kalimat: ";
    getline(cin, masukkanKalimat);

    if (Palindrom(masukkanKalimat)) {
        cout << "Kalimat diatas merupakan kalimat polindrom." << endl;
    } else {
        cout << "Kalimat diatas bukan kalimat polindrom." << endl;
    }

    return 0;
}

```

#### Output:
![Output Unguided 1 (1)](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/210050f8-dd74-4e20-a16d-92bbf0eaf9e5)
![Output Unguided 1 (2)](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/22decc96-28f3-4d03-85e0-7f9079ca5529)

Kode diatas digunakan untuk menentukan kalimat atau kata yang diinputkan user itu berupa kalimat palindrom atau bukan. Program ini juga menggunakan fungsi stack untuk membalikkan huruf-huruf di dalam kalimat tersebut dan menentukan palindrom atau tidak. Di layar output akan di tampilkan kalimat yang dimasukkan dan itu merupakan kalimat palindrom atau tidak.

### 2. [Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakanstack dengan minimal 3 kata. Jelaskan output program dan source codenyabeserta operasi/fungsi yang dibuat?]
```C++
// Andreas Besar Wibowo
// 2311102198 / IF-11-E

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string balikKalimat(string Kalimat) {
    stack<char> stackChar;

    for (char a : Kalimat) {
        stackChar.push(a);
    }

    string pembalikanKalimat = "";

    while (!stackChar.empty()) {
        pembalikanKalimat += stackChar.top();
        stackChar.pop();
    }

    return pembalikanKalimat;
}

int main() {
    string kalimat;

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    string pembalikanKalimat = balikKalimat(kalimat);

    cout << "Hasil kalimat setelah dibalik: " << pembalikanKalimat << endl;

    return 0;
}

```

#### Output:
![Output Unguided 2](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/4d86d6c4-8645-413b-b947-b1a5bb98e105)

Kode diatas digunakan untuk membalikkan huruf di dalam kalimat dari huruf kapitalnya atau tidak. Program ini juga menggunakan program fungsi stack untuk menyimpan dan membuat kalimat secara terbalik dan mengurutkan huruf atau karakternya.

## Kesimpulan

## Referensi
[1] Holle, Khadijah Fahmi Hayati. (2022). Modul praktikum struktur data.


[2] Sihombing, Johnson. (2019). Penerapan Stack Dan Queue Pada Array Dan Linked List Dalam Java. INFOKOM (Informatika & Komputer), 7(2), 15-24.


[3] Astuti, Indah Kusuma, (2019). STRUKTUR DATA LINKED LIST.
