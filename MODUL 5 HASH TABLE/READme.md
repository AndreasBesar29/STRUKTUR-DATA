# <h1 align="center">Laporan Praktikum Modul 5 Hash Table</h1>

<p align="center">Andreas Besar Wibowo</p>
<p align="center">2311102198 / IF-11-E</p>

## Dasar Teori
Hashing merupakan sebuah metode yang digunakan untuk mentransformasi suatu string menjadi karakter yang nilainya merepresentasikan string aslinya dengan operasi aritmatika. Dari segi Bahasa, hashing berasal dari kata hash yang berarti memenggal lalu menggabungkan. Dalam penggunaannya, metode hashing dapat digunakan sebagai metode penyimapanan data dalam sebuah larik (array) agar penyimpanan, pencarian, penambahan, dan penghapusan data dapat dilakukan dengan cepat. 


Dasar proses dalam metode hashing adalah dengan menghitung posisi record yang dicari di dalam array dan bukan membandingkan record denga nisi pada array. Hal ini yang membuat proses hashing dapat mempercepat dalam proses pencarian data. Fungsi yang mengembalikan nilai atau kunci disebuah fungsi hash (hash function) dan array yang digunakan disebut tabel hash (hash table). Fungsi hash menyimpan nilai asli atau kunci pada alamat yang sama dengan nilai hashnya. Pada pencarian suatu nilai pada tabel hash, yang pertama dilakukan adalah menghitung nilai hash dari kunci atau nilai aslinya, kemudian membandingkan kunci atuau nilai asli dengan isi pada memori yang beralamat nomor hashnya[1].


Hash Table adalah sebuah struktur data yang sangat cepat dalam insertion dan searching. Hash table diimplementasikan menggunakan array. Penambahan dan pencarian sebuah key pada hash table berdasarkan fungsi hash yang digunakan. Fungsi hash memetakkan elemen pada indek hash table. Fungsi hash yang baik memiliki sifat berikut: mudah dihitung, cukup mampu mendistribusikan key, meminimalkan jumlah collision (tabrakan) yang terjadi. Fungsi hash dapat menggunakan beberapa teknik, diantaranya: 

a. Truncation. Mengambil beberapa digit dari key sebagai indeks                                                                                                                          
b. Folding. Menjumlahkan beberapa digit dari key, hasil penjumlahan sebagai indeks                                                                                                       
            c. Modular. Menggunakan sisa hasil bagi dari key (bilangan bulat) dengan ukuran hash table[2].

## Guided
### 1. [Guided I]
```C++

```
#### Output:

Kode diatas digunakan untuk

### 2. [Guided II]
```C++

```
#### Output:

Kode diatas digunakan untuk

## Unguided 
### 1. [Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswamemiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru,menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkannilai. Dengan ketentuan :    a. Setiap mahasiswa memiliki NIM dan nilai.    b. Program memiliki tampilan pilihan menu berisi poin C.    c. Implementasikan fungsi untuk menambahkan data baru, menghapus data,mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai(80 – 90).]
```C++

```
#### Output:

Kode diatas digunakan untuk

## Kesimpulan

## Referensi
[1] Rahim, I., Anwar, N., Widodo, A. M., Juman, K. K., & Setiawan, I. (2023). Komparasi Fungsi Hash Md5 Dan Sha256 Dalam Keamanan Gambar Dan Teks. IKRA-ITH Informatika: Jurnal Komputer dan Informatika, 7(2).                                                                                    

[2] Holle, Khadijah Fahmi Hayati (2022). Modul praktikum struktur data.
