# <h1 align="center">Laporan Praktikum Modul 5 Hash Table</h1>

<p align="center">Andreas Besar Wibowo</p>
<p align="center">2311102198 / IF-11-E</p>

## Dasar Teori
Hashing merupakan sebuah metode yang digunakan untuk mentransformasi suatu string menjadi karakter yang nilainya merepresentasikan string aslinya dengan operasi aritmatika. Dari segi Bahasa, hashing berasal dari kata hash yang berarti memenggal lalu menggabungkan. Dalam penggunaannya, metode hashing dapat digunakan sebagai metode penyimapanan data dalam sebuah larik (array) agar penyimpanan, pencarian, penambahan, dan penghapusan data dapat dilakukan dengan cepat. 


Dasar proses dalam metode hashing adalah dengan menghitung posisi record yang dicari di dalam array dan bukan membandingkan record denga nisi pada array. Hal ini yang membuat proses hashing dapat mempercepat dalam proses pencarian data. Fungsi yang mengembalikan nilai atau kunci disebuah fungsi hash (hash function) dan array yang digunakan disebut tabel hash (hash table). Fungsi hash menyimpan nilai asli atau kunci pada alamat yang sama dengan nilai hashnya. Pada pencarian suatu nilai pada tabel hash, yang pertama dilakukan adalah menghitung nilai hash dari kunci atau nilai aslinya, kemudian membandingkan kunci atuau nilai asli dengan isi pada memori yang beralamat nomor hashnya[1].


Hash Table adalah sebuah struktur data yang sangat cepat dalam insertion dan searching. Hash table diimplementasikan menggunakan array. Penambahan dan pencarian sebuah key pada hash table berdasarkan fungsi hash yang digunakan. Fungsi hash memetakkan elemen pada indek hash table. Fungsi hash yang baik memiliki sifat berikut: mudah dihitung, cukup mampu mendistribusikan key, meminimalkan jumlah collision (tabrakan) yang terjadi. Fungsi hash dapat menggunakan beberapa teknik, diantaranya: 

a. Truncation. Mengambil beberapa digit dari key sebagai indeks                                                                                                                          
b. Folding. Menjumlahkan beberapa digit dari key, hasil penjumlahan sebagai indeks                                                                                                       
            c. Modular. Menggunakan sisa hasil bagi dari key (bilangan bulat) dengan ukuran hash table[2].

## Guided
### 1. [Guided I]
```C++
#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key)
{
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node
{
    int key;
    int value;
    Node *next;
    Node(int key, int value) : key(key), value(value),
                               next(nullptr) {}
};

// Class hash table
class HashTable
{
private:
    Node **table;

public:
    HashTable()
    {
        table = new Node *[MAX_SIZE]();
    }
    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node *node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        Node *prev = nullptr;
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << current->key << ": " << current->value

                     << endl;

                current = current->next;
            }
        }
    }
};

int main()
{
    HashTable ht;

    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;

    // Deletion
    ht.remove(4);

    // Traversal
    ht.traverse();

    return 0;
}
```
#### Output:
![Output Guided 1](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/634f0957-d040-43b3-92f4-ab8f225a9ef4)

Kode diatas digunakan untuk mengimplementasikan pemasukan, pencarian, dan penghapusan nilai-nilai. Output yang ditampilkan adalah hasil dari pencarian nilai tertentu dan menampilkan semua pasangan nilai yang tersimpan di dalam hash table.

### 2. [Guided II]
```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int TABLE_SIZE = 11;

string name;
string phone_number;
class HashNode
{
public:
    string name;
    string phone_number;
    HashNode(string name, string phone_number)
    {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];

public:
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name,
                                               phone_number));
    }

    void remove(string name)
    {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it !=
                                                table[hash_val].end();
             it++)
        {
            if ((*it)->name == name)
            {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                return node->phone_number;
            }
        }
        return "";
    }

    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->name << ", " <<

                        pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah : "
         << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : "
         << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus : "
         << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table : " << endl;

    employee_map.print();

    return 0;
}
```
#### Output:
![Output Guided 2](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/21564e19-3be9-4dab-b81c-403693263258)

Kode diatas digunakan untuk mengimplementasikan pemasukan, pencarian, dan penghapusan pasangan dari nilai tertentu yang terdiri dari nama dan nomor telepon. Output yang dihasilkan adalah menunjukan nama dan nomor telepon yang dicari dan menampilkan pasangan nama dan nomor yang tersimpan di dalam hash table.

## Unguided 
### 1. [Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswamemiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru,menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkannilai. Dengan ketentuan :    a. Setiap mahasiswa memiliki NIM dan nilai.    b. Program memiliki tampilan pilihan menu berisi poin C.    c. Implementasikan fungsi untuk menambahkan data baru, menghapus data,mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai(80 – 90).]
```C++
//Andreas Besar Wibowo
//2311102198 / IF 11 E

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

const int TABLE_SIZE = 100;

class HashNode {
public:
    string NIM_Mahasiswa;
    int Nilai_Mahasiswa;
    HashNode(string NIM, int Nilai) : NIM_Mahasiswa(NIM), Nilai_Mahasiswa(Nilai) {}
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];

    int hashFunction(const string& NIM) {
        int sum = 0;
        for (char c : NIM) {
            sum += c;
        }
        return sum % TABLE_SIZE;
    }

public:
    void insert(const string& NIM, int Nilai) {
        int hash_val = hashFunction(NIM);
        for (auto node : table[hash_val]) {
            if (node->NIM_Mahasiswa == NIM) {
                node->Nilai_Mahasiswa = Nilai;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(NIM, Nilai));
    }

    void remove(const string& NIM) {
    int hash_val = hashFunction(NIM);
    for (auto it = table[hash_val].begin(); it != table[hash_val].end(); ++it) {
        if ((*it)->NIM_Mahasiswa == NIM) {
                cout << "NIM: " << (*it)->NIM_Mahasiswa << endl;
                delete *it;
                table[hash_val].erase(it);
                return;
            }
        }
    }


    void cariByNIM(const string& NIM) {
        int hash_val = hashFunction(NIM);
        for (auto node : table[hash_val]) {
            if (node->NIM_Mahasiswa == NIM) {
                cout << "NIM: " << node->NIM_Mahasiswa << ", Nilai: " << node->Nilai_Mahasiswa << endl;
                return;
            }
        }
        cout << "Data tidak ditemukan." << endl;
    }

    void cariByNilai(int Minimal_Nilai, int Maximal_Nilai) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            for (auto node : table[i]) {
                if (node->Nilai_Mahasiswa >= Minimal_Nilai && node->Nilai_Mahasiswa <= Maximal_Nilai) {
                    cout << "NIM: " << node->NIM_Mahasiswa << ", Nilai: " << node->Nilai_Mahasiswa << endl;
                }
            }
        }
    }

    void print() {
        cout << "===============================\n";
        cout << "|     NIM      |    Nilai     |\n";
        cout << "===============================\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            for (auto node : table[i]) {
                cout << "| " << setw(12) << left << node->NIM_Mahasiswa << " | " << setw(12) << right << node->Nilai_Mahasiswa << " |\n";
            }
        }
        cout << "===============================\n";
    }
};

int main() {
    HashMap tableMahasiswa;

    tableMahasiswa.insert("2311102904", 76);
    tableMahasiswa.insert("2311100109", 81);
    tableMahasiswa.insert("2311102198", 88);
    tableMahasiswa.insert("2311100901", 80);
    tableMahasiswa.insert("2311100608", 70);
    tableMahasiswa.insert("2311102807", 56);

    cout << "Data Mahasiswa yang dihapus : " << endl;
    tableMahasiswa.remove("2311100608");

    cout << "\nCari data mahasiswa dari NIM: ";
    cout << endl;
    tableMahasiswa.cariByNIM("2311102198");

    cout << "\nCari data mahasiswa dari Rentang Nilai: ";
    cout << endl;
    tableMahasiswa.cariByNilai(80, 90);
    cout << endl;

    cout << "Data Mahasiswa:" << endl;
    tableMahasiswa.print();

    return 0;
}
```
#### Output:
![Output Unguided 1](https://github.com/AndreasBesar29/STRUKTUR-DATA-ASSIGNMENT/assets/161665251/c812f643-b7d7-49d5-9896-3cbeb68af3aa)

Kode diatas digunakan untuk mengimplementasikan penambahan, menghapus, mencari rentang nilai, dan menampilkan data mahasiswa berdasarkan NIM dan Nilai yang tersimpan di dalam Hash Table. Output yang ditampilkan adalah data mahasiswa dan untuk menambah, menghapus, mencari, dan menampilkan data yang tersimpan.

## Kesimpulan
Kesimpulan dari materi ini adalah hashing merupakan cara untuk mentransformasi string menjadi nilai numerik yang ada di dakam struktur data hash table. Hashing bisa untuk menyimpan, mencari, menambah, dan menghapus data yang dilakukan dengan cepat karena hanya berfokus pada array berdasarkan fungsi hash. Hash table, sebagai struktur data yang unggul dalam insertion dan searching, menjadi solusi efektif bagi kita untuk menyelesaikan permasalahan tersebut dengan waktu yang cepat. Teknik hashing atau hash table ini memudahkan kita untuk lebih efisien dalam program yang kita kerjakan.

Dalam pembelajaran materi ini, saya memperoleh pemahaman bahwa hash table ini mempercepat program dan lebih terstruktur. Penggunaan hashing ini dapat mempercepat seperti yang tadi sudah dijelaskan di kesimpulan seperti menambah, menyimpan, mencari, dan menghapus data. Maka dari itu, teknik hash table ini sangat direkomendasikan untuk lebih optimal dalam memecahkan masalh dan solusi dari program.

## Referensi
[1] Rahim, I., Anwar, N., Widodo, A. M., Juman, K. K., & Setiawan, I. (2023). Komparasi Fungsi Hash Md5 Dan Sha256 Dalam Keamanan Gambar Dan Teks. IKRA-ITH Informatika: Jurnal Komputer dan Informatika, 7(2).                                                                                    

[2] Holle, Khadijah Fahmi Hayati (2022). Modul praktikum struktur data.
