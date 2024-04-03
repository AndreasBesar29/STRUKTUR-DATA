# <h1 align="center">Laporan Praktikum Modul 4 Linked List Circular and Non Circular</h1>

<p align="center">Andreas Besar Wibowo</p>
<p align="center">2311102198 / IF-11-E</p>

## Dasar Teori

### Linked List
Linked List Adalah koleksi data item yang tersusun dalam sebuah barisan secara linear, dengan penyisipan dan pemindahan dapat dilakukan dalam semua tempat di  tersebut[2].

### Linked List Non Cicular
Linked List Non Circular adalah struktur data yang terdiri dari serangkaian node, di mana setiap node memiliki dua pointer: satu untuk menunjuk ke node berikutnya dalam urutan, dan yang lainnya untuk menunjuk ke node sebelumnya. Ini berbeda dengan linked list sirkular di mana node terakhir menunjuk kembali ke node pertama[1]. Didalam Linked List Non Circular, terdapat Single dan Double Linked List Non Circular yaitu :

#### 1. Single Linked List Non Circular
Setiap node pada linked list mempunyai field yang berisi data dan pointer ke node berikutnya & ke node sebelumnya. Untuk pembentukan node baru, mulanya pointer next dan prev akan menunjuk ke nilai NULL. Selanjutnya pointer prev akan menunjuk ke node sebelumnya, dan pointer next akan menunjuk ke node selanjutnya pada list[1].

#### 2. Double Linked List Non Circular 
Double Linked List Non Circular adalah linked list dengan menggunakan pointer, dimana setiap node memiliki 3 field, yaitu 1 field pointer yang menunjuk pointer berikutnya (next), 1 field menunjuk pointer sebelumnya (prev), serta sebuah field yang berisi data untuk node tersebut[1]

### Linked List Circular
Linked List Circular Adalah Double / single Linked List yang simpul terakhirnya menunjuk ke simpul awal, dan simpul awalnya menunjuk ke simpul akhir, atau dapat disebut LL yang dibuat seakanakan merupakan sebuah lingkaran dengan titik awal dan titik akhir saling bersebelahan jika Linked List tersebut masih kosong[2]. Didalam Linked List Circular, terdapat Single dan Double Linked List Circular yaitu :

#### 1. Single Linked List Circular
Single Linked List yang pointer nextnya menunjuk pada dirinya sendiri. Jika Single Linked List tersebut terdiri dari beberapa node, maka pointer next pada node terakhir akan menunjuk ke node terdepannya[2].

#### 2. Double Linked List Circular
Setiap node pada linked list mempunyai field yang berisi data dan pointer ke node berikutnya & ke node sebelumnya. Untuk pembentukan node baru, mulanya pointer next dan prev akan menunjuk ke dirinya sendiri. Jika sudah lebih dari satu node, maka pointer prev akan menunjuk ke node sebelumnya, dan pointer next akan menunjuk ke node sesudahnya[1].

## Guided
### 1. [Linked List Non Circular]
```C++
#include <iostream>
using namespace std;
/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
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
    Node *bantu, *hapus, *sebelum;
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
                sebelum = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}

// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == 0)
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
    if (isEmpty() == 0)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
        }
        else
        {
            cout << "Posisi bukan posisi tengah" << endl;

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
    if (isEmpty() == 0)
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
![Output Guided 1](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/41042fd3-adfe-4461-abc0-c130f665f45a)

Kode diatas digunakan untuk mengimplementasikan fungsi untuk menambah, menghapus, mengubah, dan menampilkan elemen-elemen yang terdapat di dalam linked list. Output yang ditampilkan adalah angka angka yang dimasukkan pada fungsi "init".

### 2. [Linked List Circular]
```C++
#include <iostream>

using namespace std;

/// PROGRAM SINGLE LINKED LIST CIRCULAR

// Deklarasi Struct Node
struct Node
{
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init()
{
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty()
{
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList()
{
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }

    return jumlah;
}

// Tambah Depan
void insertDepan(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }

        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        // transversing
        int nomor = 1;
        bantu = head;
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
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;

        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            delete hapus;

            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;

            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            delete hapus;
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;

            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        // transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;

        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;

        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
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
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();

    return 0;
}
```
#### Output:
![Output Guided 2](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/284c8b06-b0b5-4467-ae69-e5f62f094223)

Kode diatas digunakan untuk mengimplementasikan fungsi untuk menambahkan node depan, belakang, dan di tengah linked list. Bisa juga menghapus node depan, belakang, dan di tengah linked list. Output yang ditampilkan yaitu elemen - elemen yang dimasukkan pada fungsi "init".

## Unguided 
### 1. [Buatlah program menu Linked List Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user.]
```C++
// Andreas Besar Wibowo
// 2311102198 IF 11 E

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Deklarasi Struct Node
struct Node {
    string Nama_Mahasiswa;
    string Nim_Mahasiswa;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Untuk Tambah Depan
    void InsertDepan(string Nama_Mahasiswa, string Nim_Mahasiswa) {
        Node* newNode = new Node;
        newNode->Nama_Mahasiswa = Nama_Mahasiswa;
        newNode->Nim_Mahasiswa = Nim_Mahasiswa;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            newNode->next = head;
        } else {
            newNode->next = head;
            tail->next = newNode;
            head = newNode;
        }
        cout << "Data telah ditambahkan" << endl;
    }

    // Untuk Tambah Belakang
    void InsertBelakang(string Nama_Mahasiswa, string Nim_Mahasiswa) {
        Node* newNode = new Node;
        newNode->Nama_Mahasiswa = Nama_Mahasiswa;
        newNode->Nim_Mahasiswa = Nim_Mahasiswa;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            newNode->next = head;
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Data telah ditambahkan" << endl;
    }

    // Untuk Tambah Tengah
    void InsertTengah(string Nama_Mahasiswa, string Nim_Mahasiswa, int posisi) {
        if (posisi <= 0) {
            cout << "Posisi harus lebih dari 0." << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->Nama_Mahasiswa = Nama_Mahasiswa;
        newNode->Nim_Mahasiswa = Nim_Mahasiswa;

        Node* current = head;
        for (int i = 1; i < posisi - 1; i++) {
            if (current == tail) {
                cout << "Posisi Tidak Terjangkau" << endl;
                return;
            }
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

        if (current == tail) {
            tail = newNode;
        }

        cout << "Data telah ditambahkan" << endl;
    }

    // Untuk Ubah Depan
    void GantiDepan(string Nama_Mahasiswa, string Nim_Mahasiswa) {
        if (head == NULL) {
            cout << "List Kosong !" << endl;
            return;
        }
        cout << "Data " << head->Nama_Mahasiswa << " telah diganti dengan data " << Nama_Mahasiswa << endl;
        head->Nama_Mahasiswa = Nama_Mahasiswa;
        head->Nim_Mahasiswa = Nim_Mahasiswa;
    }

    // Untuk Ubah Belakang
    void GantiBelakang(string Nama_Mahasiswa, string Nama_MahasiswaBaru, string Nim_MahasiswaBaru) {
        if (head == NULL) {
            cout << "List Kosong !" << endl;
            return;
        }

        Node* current = head;
        do {
            if (current->Nama_Mahasiswa == Nama_Mahasiswa) {
                current->Nama_Mahasiswa = Nama_MahasiswaBaru;
                current->Nim_Mahasiswa = Nim_MahasiswaBaru;
                cout << "Data " << Nama_Mahasiswa << " berhasil diganti dengan data " << Nama_MahasiswaBaru << endl;
                return;
            }
            current = current->next;
        } while (current != head);
        cout << "Data " << Nama_Mahasiswa << " tidak ditemukan" << endl;
    }

    // Untuk Ubah Tengah
    void GantiTengah(string Nama_MahasiswaBaru, string Nim_MahasiswaBaru, int posisi) {
        if (head == NULL) {
            cout << "List Kosong !" << endl;
            return;
        }

        Node* current = head->next;
        for (int i = 1; i < posisi; i++) {
            if (current == head) {
                cout << "Posisi Tidak Terjangkau" << endl;
                return;
            }
            current = current->next;
        }
        cout << "Data " << current->Nama_Mahasiswa << " telah diganti dengan data " << Nama_MahasiswaBaru << endl;
        current->Nama_Mahasiswa = Nama_MahasiswaBaru;
        current->Nim_Mahasiswa = Nim_MahasiswaBaru;
    }

    // Untuk Hapus Depan
   void HapusDepan() {
    if (head == NULL) {
        cout << "List Kosong !" << endl;
        return;
    }
    Node* temp = head;
    if (temp->next == head) { 
        cout << "Data " << temp->Nama_Mahasiswa << " berhasil dihapus" << endl;
        delete temp;
        head = NULL;
        tail = NULL;
    } else {
        cout << "Data " << head->Nama_Mahasiswa << " berhasil dihapus" << endl;
        tail->next = head->next; 
        head = head->next;
        delete temp;
    }
}

    // Untuk Hapus Belakang
    void Hapusbelakang() {
        if (head == NULL) {
            cout << "List Kosong !" << endl;
            return;
        }

        if (head->next == head) {
            cout << "Data terakhir (" << head->Nama_Mahasiswa << ") berhasil dihapus" << endl;
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }

        Node* current = head;
        Node* prev = NULL;
        while (current->next != head) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        cout << "Data terakhir (" << current->Nama_Mahasiswa << ") berhasil dihapus" << endl;
        delete current;
    }

    // Untuk Hapus Tengah
    void HapusTengah(int posisi) {
        if (head == NULL) {
            cout << "List Kosong !" << endl;
            return;
        }

        if (posisi <= 0) {
            cout << "Posisi harus lebih dari 0." << endl;
            return;
        }

        Node* current = head->next;
        Node* prev = head;

        for (int i = 1; i < posisi; i++) {
            if (current == head) {
                cout << "Posisi Tidak Terjangkau" << endl;
                return;
            }
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        cout << "Data " << current->Nama_Mahasiswa << " berhasil dihapus" << endl;
        delete current;
    }

    // Untuk Hapus Seluruh List
    void HapusList() {
        if (head == NULL) {
            cout << "List Kosong !" << endl;
            return;
        }
        Node* current = head->next;
        while (current != head) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
        head = NULL;
        tail = NULL;
    }

    // Untuk Tampilan List
    void Tampilan() {
        if (head == NULL) {
            cout << "List Kosong !" << endl;
            return;
        }

        cout << "------------------------------" << endl;
        cout << setw(15) << left << "|   Nama  " << "|   NIM    " << "   |" << endl;
        cout << "------------------------------" << endl;

        Node* current = head;
        do {
            cout << "|" << setw(14) << current->Nama_Mahasiswa << "|" << setw(10) << current->Nim_Mahasiswa << "   |" << endl;
            current = current->next;
        } while (current != head);

        cout << "------------------------------" << endl;
    }
};

int main() {
    LinkedList linkedList;
    int pilihan;
    string Nama_Mahasiswa, Nim_Mahasiswa, Nama_MahasiswaBaru, Nim_MahasiswaBaru;
    int posisi;

    do {
        cout << "===PROGRAM SINGLE LINKED LIST CIRCULAR===" << endl;
        cout << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. Tampilan" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih operasi (0-11) : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "-Menambahkan List Depan-" << endl;
                cout << "Masukkan Nama Mahasiswa : ";
                cin >> Nama_Mahasiswa;
                cout << "Masukkan NIM Mahasiswa : ";
                cin >> Nim_Mahasiswa;
                linkedList.InsertDepan(Nama_Mahasiswa, Nim_Mahasiswa);
                break;
            case 2:
                cout << "\n-Menambahkan List Belakang-\n";
                cout << "Masukkan Nama Mahasiswa: ";
                cin >> Nama_Mahasiswa;
                cout << "Masukkan NIM Mahasiswa: ";
                cin >> Nim_Mahasiswa;
                linkedList.InsertBelakang(Nama_Mahasiswa, Nim_Mahasiswa);
                break;
            case 3:
                cout << "-Menambahkan List Tengah-" << endl;
                cout << "Masukkan Nama Mahasiswa : ";
                cin >> Nama_Mahasiswa;
                cout << "Masukkan NIM Mahasiswa : ";
                cin >> Nim_Mahasiswa;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                linkedList.InsertTengah(Nama_Mahasiswa, Nim_Mahasiswa, posisi);
                break;
            case 4:
                cout << "-Mengubah List Depan-" << endl;
                cout << "Masukkan Nama Mahasiswa : ";
                cin >> Nama_Mahasiswa;
                cout << "Masukkan NIM Mahasiswa : ";
                cin >> Nim_Mahasiswa;
                linkedList.GantiDepan(Nama_Mahasiswa, Nim_Mahasiswa);
                break;
            case 5:
                cout << "-Mengubah List Belakang-" << endl;
                cout << "Masukkan Nama Mahasiswa yang ingin diganti: ";
                cin >> Nama_Mahasiswa;
                cout << "Masukkan Nama Mahasiswa baru: ";
                cin >> Nama_MahasiswaBaru;
                cout << "Masukkan NIM Mahasiswa baru: ";
                cin >> Nim_MahasiswaBaru;
                linkedList.GantiBelakang(Nama_Mahasiswa, Nama_MahasiswaBaru, Nim_MahasiswaBaru);
                break;
            case 6:
                cout << "-Mengubah List Tengah-" << endl;
                cout << "Masukkan Nama Mahasiswa baru untuk tengah: ";
                cin >> Nama_MahasiswaBaru;
                cout << "Masukkan NIM Mahasiswa baru untuk tengah: ";
                cin >> Nim_MahasiswaBaru;
                cout << "Masukkan posisi: ";
                cin >> posisi;
                linkedList.GantiTengah(Nama_MahasiswaBaru, Nim_MahasiswaBaru, posisi);
                break;
            case 7:
                cout << "-Menghapus List Depan-" << endl;
                linkedList.HapusDepan();
                break;
            case 8:
                cout << "-Menghapus List Belakang-" << endl;
                linkedList.Hapusbelakang();
                break;
            case 9:
                cout << "-Menghapus List Tengah-" << endl;
                cout << "Masukkan posisi : ";
                cin >> posisi;
                linkedList.HapusTengah(posisi);
                break;
            case 10:
                linkedList.HapusList();
                cout << "Linked list berhasil dihapus." << endl;
                break;
            case 11:
                linkedList.Tampilan();
                break;
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan Tidak Ada" << endl;
                break;
        }
    } while (pilihan != 0);

    return 0;
}


```
#### Output:
![Output Unguided 1 (1)](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/731f46e8-4b65-4b2a-9dfb-e43436d82f19)
![Output Unguided 1 (2)](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/ebf12323-308c-45ec-897d-6c0fb4120f6b)
![Output Unguided 1 (3)](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/0da6986b-3a28-4d26-8902-5b6bc6a319e0)
![Output Unguided 1 (4)](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/fe9195b2-08da-4383-817e-d3dd62f34f41)
![Output Unguided 1 (5)](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/7faf6def-c595-48d8-b181-f44245114d91)
![Output Unguided 1 (6)](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/afe29098-4ad9-4ead-8968-906529311795)
![Output Unguided 1 (7)](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/ffd09d5b-8ce7-45c8-a244-8f035fd6cbc4)
![Output Unguided 1 (8)](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/0e19f860-2b00-40d6-bb22-eb5bb72b8867)
![Output Unguided 1 (9)](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/13d194dd-8214-4c89-aa5c-53ed47a320a3)
![Output Unguided 1 (10)](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/560cd4ee-fd40-45a4-937a-17b971b04a3d)


Kode diatas digunakan untuk mengelola data mahasiswa yaitu Nama dan NIM. Di dalam program ini terdapat operasi seperti menambahkan, mengurangkan, mengganti data di depan, belakang, dan tengah. Output pada programnya adalah menu operasi yang ditawarkan dalam programnya. Program pun bisa menampilkan seluruh data yang ada di dalam linked list.

## Kesimpulan
Linked List adalah struktur data linear yang terdiri dari serangkaian node. Terdapat beberapa jenis Linked List, termasuk Single Linked List Non Circular, Double Linked List Non Circular, Single Linked List Circular, dan Double Linked List Circular. Setiap jenis Linked List memiliki karakteristik dan penggunaan yang berbeda. Misalnya, Single Linked List Non Circular memiliki setiap node dengan pointer next yang menunjuk ke node berikutnya, sementara Double Linked List Non Circular memiliki tambahan pointer prev yang menunjuk ke node sebelumnya. Linked List Circular memiliki simpul terakhir yang menunjuk kembali ke simpul pertama, membentuk lingkaran. Ini memungkinkan fleksibilitas dalam penyisipan dan penghapusan data dalam struktur data tersebut.

Dari materi Linked List Circular dan Non Circular, pembelajaran yang dapat diambil adalah pemahaman yang lebih baik tentang berbagai jenis Linked List dan aplikasi praktisnya dalam pemrograman. Dengan memahami perbedaan antara Single Linked List Non Circular, Double Linked List Non Circular, Single Linked List Circular, dan Double Linked List Circular, kita dapat memilih solusi yang paling sesuai dengan kebutuhan pengembangan perangkat lunak. Hal ini penting untuk pengembangan perangkat lunak yang efisien dan efektif.

## Referensi
[1] Kurniman Putra, A. List linier (linked list) dan variasinya_struktur data.                                                                 
[2] Arraffi, A. (2019). PENGERTIAN LINIER DALAM STRUKTUR DATA MAJEMUK.




