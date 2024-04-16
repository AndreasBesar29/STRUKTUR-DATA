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
