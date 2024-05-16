// Andreas Besar Wibowo
// IF-11-E / 2311102198

#include <iostream>

using namespace std;

const int maksAntrian = 5;

struct Node {
    string data;
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

    void enqueueAntrian(string dataAntrian) {
        Node* newNode = new Node;
        newNode->data = dataAntrian;
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
            cout << "Data antrian teller:" << endl;
            for (int a = 1; a <= maksAntrian; a++) {
                cout << a << ". (kosong)" << endl;
            }
            cout << "Jumlah antrian = 0" << endl;
            return;
        }

        Node* current = head;
        int position = 1;
        cout << "Data antrian teller:" << endl;
        while (current != nullptr && position <= maksAntrian) {
            cout << position << ". " << current->data << endl;
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

    antrian.enqueueAntrian("Andi");
    antrian.enqueueAntrian("Maya");
    antrian.tampilkanAntrian();
    cout << endl;
    antrian.dequeueAntrian();
    antrian.tampilkanAntrian();
    cout << endl;
    antrian.bersihkanAntrian();
    antrian.tampilkanAntrian();

    return 0;
}
