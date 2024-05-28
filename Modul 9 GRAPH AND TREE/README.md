# <h1 align="center">Laporan Praktikum Modul 9 Graph And Tree</h1>

<p align="center">Andreas Besar Wibowo</p>
<p align="center">2311102198 / IF-11-E</p>

## Dasar Teori
### Graph
Graf adalah kumpulan noktah (simpul) di dalam bidang dua dimensi yang dihubungkan dengan sekumpulan garis (sisi). Graph dapat digunakan untuk merepresentasikan objek-objek diskrit dan hubungan antara objekobjek tersebut.
Representasi visual darigraph adalah dengan menyatakan objek sebagai noktah, bulatan atau titik (Vertex), sedangkan hubungan antara objek dinyatakan dengan garis (Edge). 
<p align="center">G = (V, E)</p>
Dimana :

- G = Graph 
- V = Simpul atau Vertex, atau Node, atau
- Titik E = Busur atau Edge, atau arc

Graf merupakan suatu cabang ilmu yang memiliki banyak terapan. Banyak sekali struktur yang bisa direpresentasikan dengan graf, dan banyak masalah yang bisa diselesaikan dengan bantuan graf. Seringkali graf digunakan untuk merepresentasikan suaru jaringan. Misalkan jaringan jalan raya dimodelkan graf dengan kota sebagai simpul (vertex/node) dan jalan yang menghubungkan setiap kotanya sebagai sisi (edge) yang bobotnya (weight) adalah panjang dari jalan tersebut[1]. 

Istilah pada Graph 
1. Vertex, Vertex adalah himpunan node/titik pada sebuah graph
2. Edge, Edge yaitu himpunan garis yang menghubungkan tiap node/vertex.
3. Adjacent, Dua buah titik dikatakan berdekatan (adjacent) jika keduanya terhubung dengan sebuah sisi.
4. Weight, Sebuah graph G = (V, E) disebut sebuah graph berbobot (weight graph) apabila terdapat sebuah fungsi bobot bernilai real W pada himpunan E
5. Path, Path adalah jalur dengan setiap vertex berbeda.
6. Cycle, Cycle (siklus) atau circuit (sirkuit) merupakan lintasan yang berawal dan berakhir pada simpul yang sama[3].

Jenis Jenis Graph
1. Graph tak berarah (undirected graph atau non-directed graph) : 
Urutan simpul dalam sebuah busur tidak dipentingkan. Misal busur e1 dapat disebut busur AB atau BA 
2. Graph berarah (directed graph) : 
Urutan simpul mempunyai arti. Misal busur AB adalah e1 sedangkan busur BA adalah e8. 
3. Graph Berbobot (Weighted Graph) 
Jika setiap busur mempunyai nilai yang menyatakan hubungan antara 2 buah simpul, maka busur tersebut dinyatakan memiliki bobot. Bobot sebuah busur dapat menyatakan panjang sebuah jalan dari 2 buah titik, jumlah rata-rata kendaraan perhari yang melalui sebuah jalan, dll[2].

### Tree
Tree dalam pemrograman merupakan struktur data yang tidak linear / non linear yang digunakan terutama untuk merepresentasikan hubungan data yang bersifat hierarkis antara elemen-elemennya. Kumpulan elemen yang salah satu elemennya disebut dengan root (akar) dan sisa elemen yang lain disebut sebagai simpul (node/vertex) yang terpecah menjadi sejumlah himpunan yang tidak saling berhubungan satu sama lain, yang disebut subtree / cabang[2].
Binary tree adalah struktur pohon yang di dalamnya terdapat data beserta dua buah link untuk kedua anak cabangnya. Binary tree digunakan untuk memperkecil indeks data, sehingga waktu operasional penelusuran data dalam koleksi ADT bisa lebih cepat dibandingkan struktur sekuensial, seperti array, list, ataupun linked list[3].
Ketentuan Tree Root (akar) adalah node yang memiliki derajat keluar >=0 dan derajat masuk = 0. 
- Subtree/child adalah bagian salah satu node dibawah root sampai ke bawah.
- Leaf (daun) adalah semua node yang derajat masuknya 1 dan derajat keluarnya 0.
- Height (ketinggian) adalah level tertinggi dari tree ditambah 1.
- Weight (bobot) adalah jumlah leaf(daun) pada tree[1].

Sifat pohon Biner
1. Simpul dan Ranting, Pada gambar pohon biner (binary tree) A, B, C, D, E, F, dan G disebut simpul/node/vertex dan disimbolkan dengan m.
2. Tingkatan (Level) dan Kedalaman (Depth), Tingkatan atau level pada pohon biner dimulai dari 0, 1, 2, … dst. Sedangkan, untuk kedalaman (depth) adalah level tertinggi + 1.
3. Derajat Simpul, Derajat simpul adalah jumlah anak yang dimiliki oleh sebuah simpul.
4. Node Internal dan Node Eksternal, Node internal adalah node yang mempunyai anak, sedangkan node eksternal adalah node yang tidak memiliki anak atau yang biasa disebut daun (leaf).

Operasi Pohon Biner
1. Create, Membentuk binary tree baru yang masih kosong.
2. Clear, Mengosongkan binary tree yang sudah ada.
3. Empty Function, Memeriksa apakah binary tree masih kosong.
4. Insert, Memasukkan sebuah node ke dalam tree. Ada tiga pilihan insert, yaitu: root, left child, dan right child. Khusus insert sebagai root, tree harus dalam keadaan kosong.
5. Find, Mencari root, parent, left child, atau right child dari suatu node (tree tidak boleh kosong).
6. Update, Mengubah isi node yang ditunjuk oleh pointer current (tree tidak boleh kosong).
7. Retrieve, Mengetahui isi node yang ditunjuk oleh pointer current (tree tidak boleh kosong)
8. DeleteSub, Menghapus sebuah subtree (node beserta seluruh descendant-nya) yang ditunjuk current. Tree tidak boleh kosong. Setelah itu, pointer current akan berpindah ke parent dari node yang dihapus.
9. Characteristic, Mengetahui karakteristik dari suatu tree, yakni size, height, dan average length. Tree tidak boleh kosong.
10. Transverse, Mengunjungi seluruh node pada tree, masingmasing sekali. Hasilnya adalah urutan informasi secara linear yang tersimpan di dalam tree. Ada tiga cara traverse,yaitu preorder, inorder, dan postorder.

Jenis Jenis Tree
Tree terdiri dari beberapa jenis, antara lain binary tree, full binary tree, complete binary tree, skewed binary tree, dan implementasi binary tree.
1. Binary Tree, Binary tree adalah tree dengan syarat bahwa tiap node hanya boleh memiliki maksimal dua subtree dan kedua subtree tersebut harus terpisah. Dengan demikian, tiap node dalam binary tree hanya boleh memiliki paling banyak dua child. 
2. Full Binary Tree, Jenis binary tree ini tiap node-nya (kecuali leaf) memiliki dua child dan tiap subtree harus mempunyai panjang path yang sama. 
3. Complete Binary Tree, Complete binary tree mirip dengan full binary tree, namun tiap subtree boleh memiliki panjang path yang berbeda dan setiap node kecuali leaf hanya boleh memiliki dua child. 
4. Skewed Binary Tree, Skewed binary tree adalah binary tree yang semua nodenya (kecuali leaf) hanya memiliki satu child. 
5. Implementasi Binary Tree, Implementasi binary tree adalah binary tree yang dapat diimplementasikan dalam C++ dengan menggunakan double linked list.

Transverse Binary Tree
Penelusuran pohon biner (traverse) dapat dilakukan melalui tiga metode sebagai berikut: 
1. Preorder: cetak isi node yang dikunjungi, kunjungi left child, lalu kunjungi right child. 
2. Inorder: kunjungi left child, cetak isi node yang dikunjungi, lalu kunjungi right child. 
3. Postorder: kunjungi left child, kunjungi right child, lalu cetak isi node yang dikunjungi[3].

## Guided
### 1. [Guided I : Program Graph.]
```C++
//PROGRAM GRAPH

#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis",
    "Bandung",
    "Bekasi",
    "tasikmalaya",
    "Cianjur",
    "Purwokerto",
    "Yogyakarta"
};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}};

void tampilGraph()
{
    for (int baris = 0; baris < 7; baris++)
    {
        cout << " " << setiosflags(ios::left) << setw(15)
             << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++)
        {
            if (busur[baris][kolom] != 0)
            {
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom]

                     << ")";
            }
        }

        cout << endl;
    }
}

int main()
{
    tampilGraph();

    return 0;
}
```
#### Output:

Program diatas digunakan untuk menampilkan representasi dari graph yang berbobot dan terdiri dari tujuh simpul yang menandakan kota, dan beberapa angka yang menandakan busur atau rute. Dari setiap busur ini mempunyai suatu bobot yang menunjukan jarak antar kotanya

### 2. [Guided II : Program Tree.]
```C++
// PROGRAM TREE

#include <iostream>

using namespace std;

// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent; // pointer
};

// pointer global
Pohon *root;

// Inisialisasi
void init()
{
    root = NULL;
}

bool isEmpty()
{
    return root == NULL;
}

Pohon *newPohon(char data) {
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void buatNode(char data) {
    if (isEmpty()) {
        root = newPohon(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kiri!"

                 << endl;

            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
                return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kanan!"

                 << endl;

            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
                return baru;
        }
    }
}

void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " <<

                data << endl;
        }
    }
}

void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node &&

                node->parent->right == node)

                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node

                     && node->parent->left == node)

                cout << "Sibling : " << node->parent->right->data <<

                    endl;

            else
                cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" <<

                    endl;

            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus."
             << endl;
    }
}

// Hapus Tree
void clear()
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void characteristic()
{
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree : " << s / h << endl;
    else
        cout << "Average Node of Tree : 0" << endl;
}

int main() {
    init();
    buatNode('A');

    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI,
        *nodeJ;

    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);
    
    update('Z', nodeC);
    update('C', nodeC);
    retrieve(nodeC);
    find(nodeC);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n"
         << endl;
    cout << "InOrder :" << endl;
    inOrder(root);
    cout << "\n"
         << endl;
    cout << "PostOrder :" << endl;
    postOrder(root);
    cout << "\n"
         << endl;
    characteristic();
    deleteSub(nodeE);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n"
         << endl;
    characteristic();
}
```
#### Output:

Program diatas digunakan untuk membuat operasi pembuatan, penambhan, penghapusan, dan penelusuran simpul di dalam tree. Dalam program ini juga bisa menampilkan karakteristik dari pohonnya.

## Unguided
### 1. [Buatlah program graph dengan menggunakan inputan user untuk menghitungjarak dari sebuah kota ke kota lainnya.]
```C++
// Andreas Besar Wibowo
// 2311102198 / S1 IF-11-E

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Untuk Memasukkan jumlah kota
// (andreasBesarWibowo_2311102198) ini menunjukan jumlah dari kota
void masukanKota(string kota[], int andreasBesarWibowo_2311102198) {
    for (int a = 0; a < andreasBesarWibowo_2311102198; a++) {
        cout << "Simpul " << a + 1 << " : ";
        cin >> kota[a];
    }
}

// Untuk Menginput Jarak Antar Kota
void masukanJarak(int jarak[][100], string kota[], int andreasBesarWibowo_2311102198) {
    for (int a = 0; a < andreasBesarWibowo_2311102198; a++) {
        for (int b = 0; b < andreasBesarWibowo_2311102198; b++) {
            cout << kota[a] << " --> " << kota[b] << " = ";
            cin >> jarak[a][b];
        }
    }
}
// Untuk Menampilkan Tabel
void tampilTabel(int jarak[][100], string kota[], int andreasBesarWibowo_2311102198) {
    // Untuk Menampilkan Bagian Atas Tabel
    cout << endl << setw(15) << "";
    for (int a = 0; a < andreasBesarWibowo_2311102198; a++) {
        cout << setw(15) << kota[a];
    }
    cout << endl;

    // Untuk Menampilkan Isi di dalam Tabel
    for (int a = 0; a < andreasBesarWibowo_2311102198; a++) {
        cout << setw(15) << kota[a];
        for (int b = 0; b < andreasBesarWibowo_2311102198; ++b) {
            cout << setw(15) << jarak[a][b];
        }
        cout << endl;
    }
}

int main() {
    int andreasBesarWibowo_2311102198;
    cout << "Silahkan masukan jumlah simpul: ";
    cin >> andreasBesarWibowo_2311102198;

    string kota[andreasBesarWibowo_2311102198];
    int jarak[andreasBesarWibowo_2311102198][100];

    masukanKota(kota, andreasBesarWibowo_2311102198);
    masukanJarak(jarak, kota, andreasBesarWibowo_2311102198);
    tampilTabel(jarak, kota, andreasBesarWibowo_2311102198);

    return 0;
}

```
#### Output:

Program diatas digunakan untuk membantu user dalam menginputkan informasi mulai dari nama kota dan jarak antar kotanya. Dalam program ini, informasi itu dibentuk dalam tabel agar mudah dipahami.

### 2. [Modifikasi guided tree diatas dengan program menu menggunakan input data treedari user dan berikan fungsi tambahan untuk menampilkan node child dandescendant dari node yang diinput kan!]
```C++
// Andreas Besar Wibowo
// 2311102198 / S1 IF-11-E

#include <iostream>

using namespace std;

// Pendeklarasian Pohon
struct Pohon
{
    char data;
    // Pointer
    Pohon *kiri, *kanan, *parent; 
};

// Sebagai Pointer Utama
Pohon *root;

void init()
{
    root = NULL;
}

bool isEmpty()
{
    return root == NULL;
}

// (andreasBesarWibowo_2311102198) ini menunjukan pohon baru
Pohon *andreasBesarWibowo_2311102198(char data)
{
    Pohon *node = new Pohon();
    node->data = data;
    node->kiri = NULL;
    node->kanan = NULL;
    node->parent = NULL;
    return node;
}

// Untuk Membuat Node Baru
void buatNode(char data)
{
    if (isEmpty())
    {
        root = andreasBesarWibowo_2311102198(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

// Untuk Masukan Kiri
Pohon *tambahKiri(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->kiri != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kiri!"
                 << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = andreasBesarWibowo_2311102198(data);
            baru->parent = node;
            node->kiri = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
            return baru;
        }
    }
}

// Untuk Masukan Kanan
Pohon *tambahKanan(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->kanan != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kanan!"
                 << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = andreasBesarWibowo_2311102198(data);
            baru->parent = node;
            node->kanan = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
            return baru;
        }
    }
}

// Untuk Memperbarui Data
void perbarui(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

// Untuk Menampilkan Data Node
void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

// Untuk Pencarian Node
void cari(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent)
                cout << "parent : (tidak punya parent)" << endl;
            else
                cout << "parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->kiri != node &&
                node->parent->kanan == node)
                cout << "Sibling : " << node->parent->kiri->data << endl;
            else if (node->parent != NULL && node->parent->kanan != node &&
                     node->parent->kiri == node)
                cout << "Sibling : " << node->parent->kanan->data << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->kiri)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->kiri->data << endl;
            if (!node->kanan)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->kanan->data << endl;
        }
    }
}

// Bagian Untuk Traversal / Penelusuran
// Untuk Bagian PreOrder
void preOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->kiri);
            preOrder(node->kanan);
        }
    }
}

// Untuk Bagian InOrder
void inOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->kiri);
            cout << " " << node->data << ", ";
            inOrder(node->kanan);
        }
    }
}

// Untuk Bagian PostOrder
void postOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->kiri);
            postOrder(node->kanan);
            cout << " " << node->data << ", ";
        }
    }
}

// Untuk Menghapus Node Pohon
void deleteTree(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                if (node->parent->kiri == node)
                    node->parent->kiri = NULL;
                else if (node->parent->kanan == node)
                    node->parent->kanan = NULL;
            }
            deleteTree(node->kiri);
            deleteTree(node->kanan);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}

// Untuk Menghapus SubPohon
void hapusSubpohon(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        deleteTree(node->kiri);
        deleteTree(node->kanan);
        cout << "\nNode subtree "
             << node->data << " berhasil dihapus."
             << endl;
    }
}

// Untuk Menghapus Semua Pohon
void hapusPohon()
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Untuk Mengecek ukuran Isi Pohon
int ukuranIsi(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + ukuranIsi(node->kiri) + ukuranIsi(node->kanan);
        }
    }
}

// Untuk Mengecek Tinggi Pohon
int tinggiPohon(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int tinggiPohonKiri = tinggiPohon(node->kiri);
            int tinggiPohonKanan = tinggiPohon(node->kanan);
            if (tinggiPohonKiri >= tinggiPohonKanan)
            {
                return tinggiPohonKiri + 1;
            }
            else
            {
                return tinggiPohonKanan + 1;
            }
        }
    }
}

// Untuk Menampilkan Karakteristik Pohon
void characteristic()
{
    int u = ukuranIsi(root);
    int t = tinggiPohon(root);
    cout << "\n Ukuran Tree : " << u << endl;
    cout << "tinggiPohon Tree : " << t << endl;
    if (t != 0)
        cout << "Rata-Rata Node pada Pohon : " << u / t << endl;
    else
        cout << "Rata-Rata Node pada Pohon : 0" << endl;
}

// Untuk Menampilkan Child Dari Sebuah Node
void tampilChild(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            if (!node->kiri && !node->kanan)
            {
                cout << "\nNode " << node->data << " tidak memiliki child." << endl;
            }
            else
            {
                cout << "\nNode " << node->data << " memiliki child:" << endl;
                if (node->kiri)
                {
                    cout << "Child kiri: " << node->kiri->data << endl;
                }
                if (node->kanan)
                {
                    cout << "Child kanan: " << node->kanan->data << endl;
                }
            }
        }
    }
}

// Untuk Menampilkan Descendant dari Pohon
void tampilDescendant(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\nDescendant dari node " << node->data << " adalah:" << endl;
            if (node->kiri)
            {
                cout << node->kiri->data << " ";
                tampilDescendant(node->kiri);
            }
            if (node->kanan)
            {
                cout << node->kanan->data << " ";
                tampilDescendant(node->kanan);
            }
        }
    }
}

// Untuk Mencari Node dari Data
Pohon *cariNode(Pohon *node, char data)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->data == data)
    {
        return node;
    }
    Pohon *kiriNode = cariNode(node->kiri, data);
    if (kiriNode)
    {
        return kiriNode;
    }
    return cariNode(node->kanan, data);
}

int main()
{
    init();
    int input;
    do
    {
        cout << "=======PROGRAM BINARY TREE=======" << endl;
        cout << "\nMenu Pilihan Program : " << endl;
        cout << "1. Buat Node" << endl;
        cout << "2. Tambah Kiri" << endl;
        cout << "3. Tambah Kanan" << endl;
        cout << "4. Perbarui Node" << endl;
        cout << "5. Tampilkan Data Node" << endl;
        cout << "6. Mencari Data Node" << endl;
        cout << "7. Penelusuran PreOrder" << endl;
        cout << "8. Penelusuran InOrder" << endl;
        cout << "9. Penelusuran PostOrder" << endl;
        cout << "10. Karakteristik Pohon" << endl;
        cout << "11. Tampilkan Child dari Node" << endl;
        cout << "12. Tampilkan Descendant dari Node" << endl;
        cout << "13. Hapus Sub Pohon" << endl;
        cout << "14. Hapus Pohon" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih operasi program yang ingin dijalankan: ";
        cin >> input;
        switch (input)
        {
        case 1:
        {
            char data;
            cout << "\nMasukkan data untuk node baru: ";
            cin >> data;
            buatNode(data);
            break;
        }
        case 2:
        {
            char data;
            char parentData;
            cout << "\nMasukkan data untuk node baru: ";
            cin >> data;
            cout << "Masukkan data parent untuk node baru: ";
            cin >> parentData;
            Pohon *parent = cariNode(root, parentData);
            if (parent)
            {
                tambahKiri(data, parent);
            }
            else
            {
                cout << "\nNode parent tidak ditemukan!" << endl;
            }
            break;
        }
        case 3:
        {
            char data;
            char parentData;
            cout << "\nMasukkan data untuk node baru: ";
            cin >> data;
            cout << "Masukkan data parent untuk node baru: ";
            cin >> parentData;
            Pohon *parent = cariNode(root, parentData);
            if (parent)
            {
                tambahKanan(data, parent);
            }
            else
            {
                cout << "\nNode parent tidak ditemukan!" << endl;
            }
            break;
        }
        case 4:
        {
            char data;
            char nodeData;
            cout << "\nMasukkan data baru untuk node: ";
            cin >> data;
            cout << "Masukkan data node yang ingin diperbarui: ";
            cin >> nodeData;
            Pohon *node = cariNode(root, nodeData);
            if (node)
            {
                perbarui(data, node);
            }
            else
            {
                cout << "\nNode tidak ditemukan!" << endl;
            }
            break;
        }
        case 5:
        {
            char data;
            cout << "\nMasukkan data node yang ingin di-retrieve: ";
            cin >> data;
            Pohon *node = cariNode(root, data);
            if (node)
            {
                retrieve(node);
            }
            else
            {
                cout << "\nNode tidak ditemukan!" << endl;
            }
            break;
        }
        case 6:
        {
            char data;
            cout << "\nMasukkan data node yang ingin ditemukan: ";
            cin >> data;
            Pohon *node = cariNode(root, data);
            if (node)
            {
                cari(node);
            }
            else
            {
                cout << "\nNode tidak ditemukan!" << endl;
            }
            break;
        }
        case 7:
        {
            cout << "\nPreOrder traversal:" << endl;
            preOrder(root);
            cout << endl;
            break;
        }
        case 8:
        {
            cout << "\nInOrder traversal:" << endl;
            inOrder(root);
            cout << endl;
            break;
        }
        case 9:
        {
            cout << "\nPostOrder traversal:" << endl;
            postOrder(root);
            cout << endl;
            break;
        }
        case 10:
        {
            characteristic();
            break;
        }
        case 11:
        {
            char data;
            cout << "\nMasukkan data node yang ingin ditampilkan child-nya: ";
            cin >> data;
            Pohon *node = cariNode(root, data);
            if (node)
            {
                tampilChild(node);
            }
            else
            {
                cout << "\nNode tidak ditemukan!" << endl;
            }
            break;
        }
        case 12:
        {
            char data;
            cout << "\nMasukkan data node yang ingin ditampilkan descendant-nya: ";
            cin >> data;
            Pohon *node = cariNode(root, data);
            if (node)
            {
                tampilDescendant(node);
                cout << endl;
            }
            else
            {
                cout << "\nNode tidak ditemukan!" << endl;
            }
            break;
        }
        case 13:
        {
            char data;
            cout << "\nMasukkan data node yang ingin dihapus subtree-nya: ";
            cin >> data;
            Pohon *node = cariNode(root, data);
            if (node)
            {
                hapusSubpohon(node);
            }
            else
            {
                cout << "\nNode tidak ditemukan!" << endl;
            }
            break;
        }
        case 14:
        {
            hapusPohon();
            break;
        }
        case 0:
        {
            cout << "\nProgram selesai." << endl;
            break;
        }
        default:
        {
            cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
            break;
        }
        }
    } while (input != 0);

    return 0;
}

```
#### Output:

Program diatas digunakan untuk meminta user untuk memilih dari beberapa menu yang tersedia dalam program, seperti : membuat, menambahkan, memperbarui, mencari, dan menu menu lainnya. Program ini menggunakan Struktur data tree yang mempunyai pointer ke simpul kanan, kiri, dan induk atau parent.

## Kesimpulan

## Referensi
[1] Safei, M. R. (2019). PENGERTIAN STRUKTUR DATA NON LINIER.

[2] Triase, T. (2020). Struktur Data: Diktat Edisi Revisi.

[3] Mulyana, A. (2023). E-Books Cara Mudah Mempelajari Algoritma dan Struktur Data.


