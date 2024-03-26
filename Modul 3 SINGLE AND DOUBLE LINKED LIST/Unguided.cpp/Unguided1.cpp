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
