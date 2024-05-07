// Andreas Besar Wibowo
// 2311102198 / IF-11-E

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool Palindrom(const string& Kalimat) {

    stack<char> stackChar;

    for (char a : Kalimat) {
        if (isalpha(a)) {
            if (a >= 'A' && a <= 'Z') {
                stackChar.push(a + 32); 
            } else {
                stackChar.push(a);
            }
        }
    }

    for (char a : Kalimat) {
        if (isalpha(a)) {
            if (a >= 'A' && a <= 'Z') {
                a += 32;
            }
            if (a != stackChar.top()) {
                return false; 
            }
            stackChar.pop(); 
        }
    }

    return true; 
}

int main() {

    string masukkanKalimat;

    cout << "Masukkan kalimat: ";
    getline(cin, masukkanKalimat);

    if (Palindrom(masukkanKalimat)) {
        cout << "Kalimat diatas merupakan kalimat polindrom." << endl;
    } else {
        cout << "Kalimat diatas bukan kalimat polindrom." << endl;
    }

    return 0;
}
