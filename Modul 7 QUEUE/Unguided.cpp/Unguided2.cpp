// Andreas Besar Wibowo
// IF-11-E / 2311102198

#include <iostream>

using namespace std;

const int maksAntrian = 5;

struct dataMahasiswa {
    string nama_Mhs;
    string nim_Mhs;
};

struct Node {
    dataMahasiswa data;
    Node* next;
};

class Queue {
private:
    Node* head;
    Node* tail;
    int size;
public:
    Queue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void enqueueAntrian(string nama_Mhs, string nim_Mhs) {
        Node* newNode = new Node;
        newNode->data.nama_Mhs = nama_Mhs;
        newNode->data.nim_Mhs = nim_Mhs;
        newNode->next = nullptr;

        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void tampilkanAntrian() {
        if (isEmpty()) {
            cout << "Data antrian daftar mahasiswa:" << endl;
            for (int a = 1; a <= maksAntrian; a++) {
                cout << a << ". (kosong)" << endl;
            }
            cout << "Jumlah antrian = 0" << endl;
            return;
        }

        Node* current = head;
        int position = 1;
        cout << "Data antrian daftar mahasiswa:" << endl;
        while (current != nullptr && position <= maksAntrian) {
            cout << position << ". Nama : " << current->data.nama_Mhs << " ( " << current->data.nim_Mhs << " ) "<<endl;
            current = current->next;
            position++;
        }
        while (position <= maksAntrian) {
            cout << position << ". (kosong)" << endl;
            position++;
        }
        cout << "Jumlah antrian = " << hitungAntrian() << endl;
    }

    int hitungAntrian() {
        return size;
    }

    void bersihkanAntrian() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }
};

int main() {
    Queue antrian;

    antrian.enqueueAntrian("Andreas", "2311102198");
    antrian.enqueueAntrian("Alexandra", "2204150209");
    antrian.enqueueAntrian("Octa Wijaya", "1810010207");
    antrian.tampilkanAntrian();
    cout << endl;
    antrian.dequeueAntrian();
    antrian.tampilkanAntrian();
    cout << endl;
    antrian.bersihkanAntrian();
    antrian.tampilkanAntrian();

    return 0;
}
