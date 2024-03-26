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
