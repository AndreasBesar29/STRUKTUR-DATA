// Andreas Besar Wibowo
// 2311102198 / IF-11-E

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string balikKalimat(string Kalimat) {
    stack<char> stackChar;

    for (char a : Kalimat) {
        stackChar.push(a);
    }

    string pembalikanKalimat = "";

    while (!stackChar.empty()) {
        pembalikanKalimat += stackChar.top();
        stackChar.pop();
    }

    return pembalikanKalimat;
}

int main() {
    string kalimat;

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    string pembalikanKalimat = balikKalimat(kalimat);

    cout << "Hasil kalimat setelah dibalik: " << pembalikanKalimat << endl;

    return 0;
}
