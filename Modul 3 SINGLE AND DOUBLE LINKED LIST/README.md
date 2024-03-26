# <h1 align="center">Laporan Praktikum Modul 3 Single And Double Linked List</h1>

<p align="center">Andreas Besar Wibowo</p>
<p align="center">2311102198 / IF-11-E</p>

## Dasar Teori

#### Linked List
Linked list adalah suatu bentuk struktur data yang berupa sekumpulan elemen data yang bertipe sama dimana tiap elemen saling berkaita atau dihubungkan dengan elemen lain melalui suatu pointer. Pointer itu sendiri adalah alamat elemen data yang tersimpan di memori. Penggunaan pointer untuk mengacu elemen berakibat elemen-elemen bersebelahan secara logik walau tidak bersebelahan secara fisik di memori. Linked list terdiri dari node-node (simpul-simpul) yang saling terhubung (linked). Simpul berupa struct, sedangkan link berupa komponen yang bertipe pointer ke simpul. Ada dua jenis pointer yang digunakan, yaitu head (menunjukkan alamat pointer paling depan) dan tail (menunjukkan simpul terakhir). Operasi penambahan atau penghapusan sebuah simpul akan mengubah nilai pointer link nya. Sedangkan pointer link di simpul terkahir diberi nilai null[1].

#### Single Linked List
Single Linked List adalah sebuah LINKED LIST yang menggunakan sebuah variabel pointer saja untuk menyimpan banyak data dengan metode LINKED LIST, suatu daftar isi yang saling berhubungan[2]Single Linked List Pada list jenis ini, tiap node nya memiliki field yang berisi pointer ke node berikutnya dan juga memiliki field yang berisi data. Akhir linked list ditandai dengan node terakhir yang menunjuk ke null yang akan digunakan sebagai kondisi berhenti saat pembacaan linked list[1].

#### Double Linked List
Double Linked List Merupakan linked list dengan menggunakan pointer, dimana setiap node memiliki tiga buah field, yaitu : field pointer yang menunjuk ke pointer berikutnya, field pointer yang menunjuk ke pointer sebelumnya dan field yang berisi data dari node tersebut. Semenatara pointer next dan prev-nya menunjuk ke null[1].

#### Perbedaan Antara Single dan Double Linked List
Perbedaan single linked list dan double linked list Seperti yang kita ketahui bahwa senarai itu memiliki dua jenis yaitu senarai berantai satu arah (senarai tunggal) atau singel linked list dan senarai berantai dua arah atau double linked list. Senarai satu arah yaitu bila struktur data sebuah node hanya memiliki satu tautan atas node berikutnya dalam sebuah senarai, maka senarai tersebut dinamakan sebagai senarai tunggal. Senarai tunggal dengan tiap-tiap node yang terdiri atas dua elemen, data integer, dan elemen rujukan ke node berikutnya. Pada dasarnya, penggunaan Double Linked List hampir sama dengan penggunaan Single Linked List yang telah kita pelajari pada materi sebelumnya. Hanya saja Double Linked List menerapkan sebuah pointer baru, yaitu prev, yang digunakan untuk menggeser mundur selain tetap mempertahankan pointer next. Keberadaan 2 pointer penunjuk (next dan prev) menjadikan Double Linked List menjadi lebih fleksibel dibandingkan Single Linked List, namun dengan mengorbankan adanya memori tambahan dengan adanya pointer tambahan tersebut. Berbeda halnya dengan senarai tunggal, pada senarai dua arah (singel linked list), struktur data atas tiap-tiap node memiliki rujukan pada node sebelum dan berikutnya. Sebagian algoritma membutuhkan taut ganda, contohnya sorting dan reverse traversing. Senarai ganda dengan tiap-tiap node yang terdiri atas tiga elemen, data integer, dan dua elemen rujukan ke node sebelum serta berikutnya[3].

## Guided 
### 1. [Latihan Single Linked List]
```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    // komponen/member
    int data;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == false)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == false)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```
#### Output:
![Guided 1 Output](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/f2c25ee7-338a-4c79-8194-e4e1d8fdf26b)

Kode diatas digunakan untuk menambahkan operasi yaitu penambahan elemen depan, belakang, dan temgah. Penghapusan elemen depan, belakang, dan tengah. Pengubahan nilai depan, belakang, dan tengah. Dilayar output akan muncul angka angka secara urut sesuai dengan yang user kode kan.

### 2. [Latihan Double Linked List]
```C++
#include <iostream>
using namespace std;


class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
#### Output:
![Guided 2 Output](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/54e6f1bc-e4ce-4e0f-8335-7b9879febd39)

Kode di atas digunakan untuk menambah, menghapus, mengupdate, menghapus semua data, dan menampilkan seluruh data. Pada layar output menampilkan beberapa menu untuk melakukan hal - hal tersebut.

## Unguided 
### 1. [Buatlah program menu Single Linked List Non-Circular untukmenyimpan Nama dan usia mahasiswa, dengan menggunakan inputandari user.]
```C++
// Andreas Besar Wibowo
// 2311102198 / IF - 11 - E

#include <iostream>
#include <string>

using namespace std;

// Deklarasi Struct Node
struct Node {
    string Nama_Mahasiswa;
    int Usia_Mahasiswa;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:

    LinkedList() {
        head = NULL;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = NULL;
    }

    // untuk menambah data di depan
    void MasukkanDepan(string Nama_Mahasiswa, int Usia_Mahasiswa) {
        Node* newNode = new Node;
        newNode->Nama_Mahasiswa = Nama_Mahasiswa;
        newNode->Usia_Mahasiswa = Usia_Mahasiswa;
        newNode->next = head;
        head = newNode;
    }

    // untuk menambah data di belakang
    void MasukkanBelakang(string Nama_Mahasiswa, int Usia_Mahasiswa) {
        Node* newNode = new Node;
        newNode->Nama_Mahasiswa = Nama_Mahasiswa;
        newNode->Usia_Mahasiswa = Usia_Mahasiswa;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    // untuk menambah data di tengah
    void MasukkanTengah(string Nama_Mahasiswa, int Usia_Mahasiswa, string posisi, string Nama_MahasiswaSebelum) {
        Node* newNode = new Node;
        newNode->Nama_Mahasiswa = Nama_Mahasiswa;
        newNode->Usia_Mahasiswa = Usia_Mahasiswa;

        Node* current = head;
        while (current != NULL && current->Nama_Mahasiswa != Nama_MahasiswaSebelum) {
            current = current->next;
        }

        if (current == NULL) {
            cout << "Data Tidak Ada" << endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // untuk menghapus data berdasarkan Nama_Mahasiswa
    void HapusData(string Nama_Mahasiswa) {
        if (head == NULL) {
            cout << "List" << endl;
            return;
        }

        if (head->Nama_Mahasiswa == Nama_Mahasiswa) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != NULL && current->next->Nama_Mahasiswa != Nama_Mahasiswa) {
            current = current->next;
        }

        if (current->next == NULL) {
            cout << "Data Tidak Ada" << endl;
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // untuk mengubah data berdasarkan Nama_Mahasiswa
    void UbahData(string Nama_Mahasiswa, string newNama_Mahasiswa, int newUsia_Mahasiswa) {
        Node* current = head;
        while (current != NULL) {
            if (current->Nama_Mahasiswa == Nama_Mahasiswa) {
                current->Nama_Mahasiswa = newNama_Mahasiswa;
                current->Usia_Mahasiswa = newUsia_Mahasiswa;
                return;
            }
            current = current->next;
        }
        cout << "Data Tidak Ada" << endl;
    }

    // untuk menampilkan seluruh data
    void TampilanData() {
        if (head == NULL) {
            cout << "List" << endl;
            return;
        }

        Node* current = head;
        cout << endl;
        while (current != NULL) {
            cout << "" << current->Nama_Mahasiswa << "\t\t" << current->Usia_Mahasiswa << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;

    string Nama_MahasiswaUser;
    int Usia_MahasiswaUser;

    cout << "Masukkan Nama Anda: ";
    getline(cin, Nama_MahasiswaUser);
    cout << "Masukkan Usia Anda: ";
    cin >> Usia_MahasiswaUser;

    list.MasukkanDepan(Nama_MahasiswaUser, Usia_MahasiswaUser);
    cin.ignore();
    // Untuk Memasukkan Data
    list.MasukkanBelakang("John", 19);
    list.MasukkanBelakang("Jane", 20);
    list.MasukkanBelakang("Michael", 18);
    list.MasukkanBelakang("Yusuke", 19);
    list.MasukkanBelakang("Akechi", 20);
    list.MasukkanBelakang("Hoshino", 18);
    list.MasukkanBelakang("Karin", 18);

    // Untuk Hapus Data Akechi
    list.HapusData("Akechi");

    // Untuk Menambahkan data Futaba diantara John dan Jane
    list.MasukkanTengah("Futaba", 18, "tengah", "John");

    // Untuk menambhkan data Igot pada awal data
    list.MasukkanDepan("Igor", 20);

    // Untuk mengubah data michael menjadi Reyn 18
    list.UbahData("Michael", "Reyn", 18);

    // Tampilkan seluruh data
    cout << "Seluruh Data Mahasiswa:" << endl;
    list.TampilanData();

    return 0;
}

```
#### Output:
![Unguided 1 Output](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/7d66a68a-4a4a-40f9-8502-d1047584fef6)

Kode di atas digunakan untuk menghapus, mengubah, dan menampilkan data mahasiswa yang ingin dilakukan sesuai pada case nya. Data disimpan yang berupa nama dan usia. Pada layar output menampilkan nama dan usia yang ingin  ditambahkan dan menampilkan seluruh data dengan urut.

### 2. [Modifikasi Guided Double Linked List dilakukan dengan penambahanoperasi untuk menambah data, menghapus, dan update di tengah / diurutan tertentu yang diminta. Selain itu, buatlah agar tampilannyamenampilkan Nama produk dan harga.]
```C++
// Andreas Besar Wibowo
// 2311102198 / IF - 11 - E

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Deklarasi struct node
struct Node {
    string Nama_Produk;
    int Harga_Produk;
    Node* prev;
    Node* next;
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:

    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~DoubleLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }

    // Untuk Menambah Data Di Belakang
    void MasukkanBelakang(string Nama_Produk, int Harga_Produk) {
        Node* newNode = new Node;
        newNode->Nama_Produk = Nama_Produk;
        newNode->Harga_Produk = Harga_Produk;
        newNode->prev = tail;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }

    // Untuk Menampilkan Data
    void TampilanData() {
        Node* current = head;
        cout << "==============================" << endl;
        cout << "   Nama Produk\t|  Harga Produk" << endl;
        cout << "==============================" << endl;
        while (current != nullptr) {
            cout << setw(8) << current->Nama_Produk << "\t| " << setw(6) << current->Harga_Produk << endl;
            current = current->next;
        }
        cout << "==============================" << endl;
    }

    // Untuk Menambah Data Di Posisi Tertentu
    void MasukkanPosisiTertentu(string Nama_Produk, int Harga_Produk, int posisi) {
        Node* newNode = new Node;
        newNode->Nama_Produk = Nama_Produk;
        newNode->Harga_Produk = Harga_Produk;

        Node* current = head;
        int count = 1;

        while (current != nullptr && count < posisi) {
            current = current->next;
            count++;
        }

        if (current == nullptr && count < posisi) {
            cout << "Posisi diluar jangkauan." << endl;
            return;
        }

        newNode->next = current;
        newNode->prev = current->prev;

        if (current->prev == nullptr) {
            head = newNode;
        } else {
            current->prev->next = newNode;
        }
        current->prev = newNode;
    }

    // Untuk Menghapus Pada Urutan Tertentu
    void deleteAtposisi(int posisi) {
        if (head == nullptr || posisi <= 0) {
            cout << "Linked list kosong !" << endl;
            return;
        }

        Node* current = head;
        int count = 1;

        while (current != nullptr && count < posisi) {
            current = current->next;
            count++;
        }

        if (current == nullptr) {
            cout << "Posisi diluar jangkauan." << endl;
            return;
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }

        delete current;
    }

    // Untuk Menghapus Semua Data
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }

    // Untuk Menghapus Data sesuai Namanya
    void deleteByName(string Nama_Produk) {
        Node* current = head;
        while (current != nullptr) {
            if (current->Nama_Produk == Nama_Produk) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                delete current;
                cout << "Data berhasil dihapus." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Data tidak ditemukan." << endl;
    }

    // Untuk Update data berdasarkan Nama Produknya
    void UpdateData(string Nama_Produk, string Nama_Produk_Baru, int Harga_Produk_Baru) {
        Node* current = head;
        bool found = false;
        while (current != nullptr) {
            if (current->Nama_Produk == Nama_Produk) {
                found = true;
                current->Nama_Produk = Nama_Produk_Baru;
                current->Harga_Produk = Harga_Produk_Baru;
                cout << "Data berhasil diupdate." << endl;
                return;
            }
            current = current->next;
        }
        if (!found) {
            cout << "Data dengan nama produk '" << Nama_Produk << "' tidak ditemukan." << endl;
        }
    }
};

int main() {
    DoubleLinkedList list;

    // Untuk Data Awal
    list.MasukkanBelakang("Originote", 60000);
    list.MasukkanBelakang("Somethinc", 150000);
    list.MasukkanBelakang("Skintific", 100000);
    list.MasukkanBelakang("Wardah", 50000);
    list.MasukkanBelakang("Hanasui", 30000);

    int choice;
    string Nama_Produk, Nama_Produk_Baru;
    int Harga_Produk;
    int posisi;

    do {
        cout << "===Toko Skincare Purwokerto===" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Pilihan Anda (1-8): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nama produk: ";
                cin.ignore();
                getline(cin, Nama_Produk);
                cout << "Masukkan HargaProduk: ";
                cin >> Harga_Produk;
                list.MasukkanBelakang(Nama_Produk, Harga_Produk);
                break;
            case 2:
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin.ignore();
                getline(cin, Nama_Produk);
                list.deleteByName(Nama_Produk);
                break;
            case 3:
                cout << "Masukkan nama produk yang ingin diperbarui: ";
                cin.ignore();
                getline(cin, Nama_Produk);
                cout << "Masukkan nama produk yang baru: ";
                getline(cin, Nama_Produk_Baru);
                cout << "Masukkan Harga Produk yang baru: ";
                cin >> Harga_Produk;
                list.UpdateData(Nama_Produk, Nama_Produk_Baru, Harga_Produk);
                break;
            case 4:
                cout << "Masukkan nama produk: ";
                cin.ignore();
                getline(cin, Nama_Produk);
                cout << "Masukkan Harga Produk: ";
                cin >> Harga_Produk;
                cout << "Masukkan posisi produknya: ";
                cin >> posisi;
                list.MasukkanPosisiTertentu(Nama_Produk, Harga_Produk, posisi);
                break;
            case 5:
                cout << "Masukkan posisi data yang akan dihapus: ";
                cin >> posisi;
                list.deleteAtposisi(posisi);
                break;
            case 6:
                list.deleteAll();
                cout << "Semua Data Dihapus." << endl;
                break;
            case 7:
                cout << "Data pada toko skincare Purwokerto :" << endl;
                list.TampilanData();
                break;
            case 8:
                cout << "Terimakasih." << endl;
                break;
            default:
                cout << "Pilihan tidak ada." << endl;
        }
    } while (choice != 8);

    return 0;
}

```
#### Output:
![Unguided 2 ( 1 ) Output](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/e51feaf0-e46c-4fc4-9de2-c36feaff6664)
![Unguided 2 ( 2 ) Output](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/ceb6793b-360e-416a-bc52-67be93e6e1d2)

Kode diatas digunakan untuk menambah, menghapus, mengupdate, dan menampilkan data atau daftar produk. Pengelolan data produk dilakukan secara efisien dalam kedua arah. Pada layar output menampilkan beberapa menu yang dapat digunakan oleh user.

## Kesimpulan
Dalam linked list , terdapat dua jenis utama yaitu Single Linked List dan Double Linked List. Single Link List adalah list yang menggunakan satu pointer untuk menghubungkan setiap node ke node yang berikutnya sehingga hanya bisa bergerak maju dari depan ke belakang. Sedangkan Double Linked List adalah list yang menggunakan dua pointer yaitu satu pointer untuk node berikutnya dan satu lagi untuk node sebelumnya, sehingga bisa bergerak maju dan mundur. Kelebihan dari double linked list adalah ke fleksibilitasnya dalam operasi sorting dan reverse, yang memerlukan akses ke node sebelumnya. Namun, kelemahannya adalah penggunaan memori yang berlebih karena ada pointer tambahan. Single linked list lebih sederhana dan sedikit penggunaan memorinya, tetapi memiliki keterbatasan dam operasi tertentu yang membutuhkan akses ke node sebelumnya.

Dari materi linked list, pembelajaran yang dapat diambil adalah pemilihan linked list harus disesuaikan dengan kebutuhan damam aplikasi atau algoritma yang digunakan. Single linked list cocok untuk yang memerlukan traversing maju tanpa membutuhkan akses dari node sebelumnya, sedangkan double linked list cocok untuk operasi yang kompleks dan manipulasi data yang rumit.

## Referensi
[1] Sihombing, J. (2019). Penerapan Stack Dan Queue Pada Array Dan Linked List Dalam Java. INFOKOM (Informatika & Komputer), 7(2), 15-24.
[2] Kurniman Putra, A. Single linked list.                       
[3] Siregar, A. A. N. (2019). Pengertian Linked Object.
