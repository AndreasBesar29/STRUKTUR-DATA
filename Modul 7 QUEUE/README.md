# <h1 align="center">Laporan Praktikum Modul 7 Queue</h1>

<p align="center">Andreas Besar Wibowo</p>
<p align="center">2311102198 / IF-11-E</p>

## Dasar Teori
Kata antrian dalam bahasa Inggris untuk baris untuk "mengantri" berarti mengantre. Dalam ilmu komputer, antrian adalah struktur data yang agak berbeda seperti tumpukan, kecuali bahwa dalam antrian, item pertama yang dimasukkan adalah yang pertama jadi dihapus (First-In-First-Out, FIFO), sementara dalam tumpukan, seperti yang telah terlihat, item terakhir dimasukkan adalah yang pertama akan dihapus (LIFO). Antrian berfungsi seperti baris di film: Orang pertama yang bergabung di belakang garis adalah orang pertama yang mencapai garis depan antrian dan beli tiket. Orang terakhir yang mengantre adalah orang terakhir yang membeli tiket (atau — jika pertunjukan terjual habis — gagal membeli tiket).

Ini mendemonstrasikan antrian berdasarkan array. Ini adalah pendekatan umum, meskipun daftar tertaut juga biasa digunakan untuk mengimplementasikan antrian. Dua operasi antrian dasar adalah memasukkan item, yang ditempatkan di belakang antrian, dan menghapus item, yang diambil dari depan antrian. Ini adalah mirip dengan seseorang yang bergabung dengan barisan belakang penonton film dan, setelah tiba dibarisan depan dan membeli tiket, melepaskan dirinya dari depan garis. 

Istilah penyisipan dan penghapusan dalam tumpukan cukup standar; semua orang bilang dorong dan muncul. Standardisasi belum berkembang sejauh ini dengan antrian. Sisipkan juga disebut put atau add atau enque, sedangkan remove bisa disebut delete atau get atau deque. Bagian belakang queue, tempat item dimasukkan, juga disebut back atau tail atau end. Bagian depan, dimana barang dilepas, bisa juga disebut kepala[1].

Karakteristik penting antrian sebagai berikut : 
1) Elemen antrian yaitu item-item data yang terdapat di elemen antrian. 
2) Head/front (elemen terdepan dari antrian ). 
3) Tail/rear (elemen terakhir dari antrian ). 
4) Jumlah elemen pada antrian (count). 
5) Status/kondisi antrian.

Kondisi antrian yang menjadi perhatian adalah : 
- Penuh, Bila elemen di antrian mencapai kapasitas maksimum antrian. Pada kondisi ini, tidak mungkin dilakukan penambahan ke antrian. Penambahan elemen menyebabkan kondisi kesalahan Overflow.
- Kosong, Bila tidak ada elemen di antrian. Pada kondisi ini, tidak mungkin dilakukan pengambilan elemen dari antrian. Pengambilan elemen menyebabkan kondisi kesalahan Underflow[2]. 

Operasi yang terkait dengan antrian adalah: 
1) Enqueue: Menambahkan item ke antrian. Jika antrian penuh, maka dikatakan sebagai kondisi Overflow – Kompleksitas Waktu: O (1). 
2) Dequeue: Menghapus item dari antrian. Item yang muncul dalam urutan yang sama di mana mereka didorong. Jika antrian kosong, maka dikatakan sebagai kondisi Underflow – Kompleksitas Waktu: O (1).
3) Depan: Dapatkan item depan dari antrian – Kompleksitas Waktu: O(1). 
4) Belakang: Dapatkan item terakhir dari antrian – Kompleksitas Waktu: O(1)[1].

Operasi-0perasi Queue tambahan yang dapat dilakukan adalah : 
- isEmptyQueue (Q), mengirim apakah antrian Q adalah kosong.
- isFullQueue (Q), mengirim apakah antrian Q adalah penuh bila kapasitas antrian Q didefinisikan.
- isOverflowQueue (Q), mengirim apakah antrian Q telah mengalamioverflow.
- isUnderflowQueue (Q), mengirim apakah antrian Q mengalami underflow[2]. 

## Guided
### 1. [Guided I]
```C++
#include <iostream>

using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0;               // Penanda antrian
int back = 0;                // Penanda
string queueTeller[5];       // Fungsi pengecekan

bool isFull()
{ // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue)
    {
        return true; // =1
    }
    else
    {
        return false;
    }
}

bool isEmpty()
{ // Antriannya kosong atau tidak
    if (back == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueueAntrian(string data)
{ // Fungsi menambahkan antrian
    if (isFull())
    {
        cout << "Antrian penuh" << endl;
    }
    else
    {
        if (isEmpty())
        { // Kondisi ketika queue kosong
            queueTeller[0] = data;
            front++;
            back++;
        }
        else
        { // Antrianya ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian()
{ // Fungsi mengurangi antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue()
{ // Fungsi menghitung banyak antrian
    return back;
}

void clearQueue()
{ // Fungsi menghapus semua antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue()
{ // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++)
    {
        if (queueTeller[i] != "")
        {
            cout << i + 1 << ". " << queueTeller[i] <<

                endl;
        }
        else
        {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main()
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    
    return 0;
}
```
#### Output:

Kode diatas digunakan untuk

## Unguided
### 1. [Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list]
```C++

```
#### Output:

Kode diatas digunakan untuk

### 1. [Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa]
```C++

```
#### Output:

Kode diatas digunakan untuk

## Kesimpulan

## Referensi
[1]Zein, A., & Eriana, E. S. (2022). ALGORITMA DAN STRUKTUR DATA.

[2]Adlaimi, Nazri. (2019). STRUKTUR DATA MAJEMUK (QUEUE).
