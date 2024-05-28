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
