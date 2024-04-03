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
