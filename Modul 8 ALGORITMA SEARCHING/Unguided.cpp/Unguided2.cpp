// Andreas Besar Wibowo
// 2311102198 / S1 IF-11-E

#include <iostream>
#include <string>

using namespace std;

bool isVowel(char j) {
    j = tolower(j);
    return (j == 'a' || j == 'e' || j == 'i' || j == 'o' || j == 'u');
}

int main() {
    string kalimat;
    int jumlahHuruf_Vokal = 0;

      cout << "Tuliskan Sebuah Kalimat: ";
    getline(cin, kalimat);

    for (char j : kalimat) {
        if (isVowel(j)) {
            jumlahHuruf_Vokal++;
        }
    }

   
    cout << "Jumlah huruf vokal yang terdapat di dalam kalimat yaitu : " << jumlahHuruf_Vokal << endl;

    return 0;
}
