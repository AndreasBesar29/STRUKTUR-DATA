<h2 align="center"><strong>ALGORITMA DAN PEMROGRAMAN 2</strong></h2>

<br>

<h2 align="center"><strong>MODUL II</strong></h2>
<h2 align="center"><strong> REVIEW STRUKTUR KONTROL </strong></h2>

<br>

<p align="center">
  
  <img src="https://github.com/user-attachments/assets/741cb565-774a-4298-b1fb-22ebf35822f1" alt="Logo" width="200"/>

</p>

<br>

<p align="center">
  <strong>Disusun Oleh:</strong><br>
  Andreas Besar Wibowo / 2311102198<br>
  S1 IF11-05
</p>

<br>

<p align="center">
  <strong>Dosen Pengampu:</strong><br>
  Arif Amrulloh,S.Kom.,M.Kom.
</p>

<br>

<p align="center">
  <strong>PROGRAM STUDI S1 TEKNIK INFORMATIKA</strong><br>
  <strong>FAKULTAS INFORMATIKA</strong><br>
  <strong>TELKOM UNIVERSITY PURWOKERTO</strong><br>
  <strong>2024</strong>
</p>

------

## I. Dasar Teori
### Pengertian Go
GO adalah bahasa pemrograman yang digunakan untuk pembuatan aplikasi berat, seperti sistem operasi dan aplikasi web, sehingga programmer yang memahami GO dapat memanfaatkan peluang karir sebagai pembuat aplikasi berat[1].
### Variabel Tipe Data .
#### 1. Varibel Keyword var
Keyword var digunakan untuk membuat variabel baru.
Skema Penggunaan var :
```go
var <nama-variabel> <tipe-data>
var <nama-variabel> <tipe-data> = <nilai>
```
#### 2. Penggunaan fungsi 
Fungsi ini digunakan untuk menampilkan output dalam bentuk tertentu. Kegunaannya sama seperti fungsi fmt.Println(), hanya saja struktur outputnya didefinisikan di awal.

Perhatikan bagian "halo %s %s!\n", karakter %s di situ akan diganti dengan data string yang berada di parameter ke-2, ke-3, dan seterusnya.

Contoh lain, ketiga baris kode berikut ini akan menghasilkan output yang sama, meskipun cara penulisannya berbeda.
Skema Penggunaan fungsi :
```go
fmt.Printf("halo john wick!\n")
fmt.Printf("halo %s %s!\n", firstName, lastName)
fmt.Println("halo", firstName, lastName + "!")
```
Tanda plus (+) jika digunakan untuk penghubung 2 data string fungsinya adalah untuk operasi penggabungan string atau string concatenation.

Fungsi fmt.Printf() tidak menghasilkan baris baru di akhir text, oleh karena itu digunakanlah literal newline yaitu \n, untuk memunculkan baris baru di akhir. Hal ini sangat berbeda jika dibandingkan dengan fungsi fmt.Println() yang secara otomatis menghasilkan new line (baris baru) di akhir[2].

### Perulangan 
#### 1. For Loop
For loop adalah statement yang digunakan untuk mengeksekusi suatu blok kode secara berulang. Biasanya digunakan untuk melakukan iterasi terhadap nilai yang ada pada data slice, array, atau pada data yang bersifat iterable (dapat dilakukan perulangan).
Skema Penggunaan For Loop :
```go
package main

import "fmt"

func main() {
	count := 1

	for count <= 5 {
		fmt.Println("Perulangan:", count)
		count++
	}
}
```
Ada 2 statement tambahan yaitu : 
1.  Init statement, merupakan sebuah statement sebelum for loop dieksekusi. Init statement hanya dieksekusi sekali sehingga bisa kita digunakan untuk menginisialisasi variabel awal yang menentukan counter perulangan.
2. Post statement, merupakan statement yang akan selalu dieksekusi di akhir pada tiap-tiap perulangan. Post statement yang selalu dieksekusi pada akhir tiap perulangan bisa kita gunakan untuk menaikkan nilai counter perulangan[3].
Skema Penggunaan For Loop dengan Init Statement dan Poat Statement :
```go
for count := 1; count <= 5; count++ {
    fmt.Println("Perulangan:", count)
```
#### 2. Range
Untuk melakukan iterasi menggunakan for loop kita bisa menggunakan keyword range.
Skema Penggunaan Range :
```go
package main

import "fmt"

func main() {
	fruits := []string{"Nanas", "Melon", "Semangka"}

	for index, fruit := range fruits {
		fmt.Println("Index:", index, "=", fruit)
	}

    fmt.Println("---")

    website := map[string]string{
		"name": "Ruang Developer",
		"domain": "www.ruangdeveloper.com",
	}

	for key, value := range website {
		fmt.Println(key, ":", value)
	}
}
```
### Percabangan
Percabangan dalam bahasa pemrograman Go adalah struktur kontrol yang memungkinkan program untuk membuat keputusan berdasarkan kondisi tertentu. Instruksi seperti if, else if, else, dan switch digunakan untuk menentukan jalur eksekusi program berdasarkan hasil evaluasi ekspresi logika.

#### 1. If
Dalama Bahasa, if berarti Jika, contoh pernyataan: Jika hujan maka mandi hujan. Pernyataan Jika digunakan untuk kita memilih kondisi berdasarkan benar atau tidak, jika benar dianggap memenuhi kondisi dan sebaliknya.
Skema Penggunaan If :
```go
if [operasi]{
   [blok kode]
}
```
#### 2. If Else
Bila kondisi tidak memenuhi pernyataan If maka blok kode akan dilewat, bagian ini membahas blok kode bila tidak memenuhi pernyataan maka akan dijalankan : Pernyataan else (selain).
Skema Penggunaan If Else:
```go
if [operasi]{
   [blok kode]
}else{
   [blok kode]
}
```
#### 3. If Else
Pernyataan ini bertujuan untuk menyambungkan antar pernyataan if. Else-if dalam penerapan ini digunakan untuk menguji batasan yang lebih diutamakan dalam suatu kasus.
Skema Penggunaan Else If:
```go
if [operasi]{
  [blok kode]
}else if [operasi] {
  [blok kode]
}
```
#### 4. Switch
switch bila diartikan ke kata benda dalam bahasa : saklar, filosofinya bila ada nilai yang sesuai dengan kasus saklar (case) maka akan menjalankan blok kode didalamnya seperti pernyataan if.

Perbedaanya, pernyataan switch menguji nilai apakah cocok tidak hanya mengecek data lojik dari operasi (data numerik dan karater juga dicek)[4].
Skema Penggunaan Switch:
```go
switch [variable bernilai/operator bernilai] {
  case [nilai bandingan]:
 	[blok kode]
	...
  default:
	[blok kode]
}
```
## II. GUIDED
1. Menampilkan output yang diinputkan user

#### Source Code
```go
package main

import (
	"fmt" 
)

func main() {
	var nama string 
	
	fmt.Scanln(&nama)

	fmt.Println(nama)
}
```
#### Screenshoot Source Code
![Guided1 carbon](https://github.com/user-attachments/assets/1eeb7260-8e07-4641-b3bd-094ef0ea0839)

#### Screenshoot Output
![Guided1 go](https://github.com/user-attachments/assets/f814d9ba-c656-4558-8e16-efebdfdf9c57)

#### Deskripsi Program
Program ini berisi tentang menampilkan inputan ke layar output

Algoritma dari program ini sebagai berikut:
1. User menginputkan suatu kata
2. Program akan menampilkan inputan dari user

Cara kerja program ini adalah program memunculkan inputan dari user ke terminal output 

2. Siswa kelas IPA di salah satu sekolah menengah atas di Indonesia sedang mengadakan praktikum kimia. Di setiap percobaan akan menggunakan 4 tabung reaksi, yang mana susunan warna cairan di setiap tabung akan menentukan hasil percobaan. Siswa diminta untuk mencatat hasil percobaan tersebut. Percobaan dikatakan berhasil apabila susunan warna zat cair pada gelas 1 hingga gelas 4 secara berturutan adalah 'merah', 'kuning', 'hijau', dan 'ungu' selama 5 kali percobaan berulang.
Buatlah sebuah program yang menerima Input berupa warna dari ke 4 gelas reaks! sebanyak 5 kali percobaan. Kemudian program akan menampilkan true apabila urutan warna sesuat dengan informasi yang diberikan pada paragraf sebelumnya, dan false untuk urutan warna lainnya.

#### Source Code
```go
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Urutan warna yang benar
	correctOrder := []string{"merah", "kuning", "hijau", "ungu"}

	// Membaca input untuk 5 percobaan
	reader := bufio.NewReader(os.Stdin)
	success := true

	for i := 1; i <= 5; i++ {
		fmt.Printf("Percobaan %d: ", i)

		// Membaca input dari pengguna
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)

		// Memisahkan input berdasarkan spasi
		colors := strings.Split(input, " ")

		// Mengecek apakah urutan warna sesuai
		for j := 0; j < 4; j++ {
			if colors[j] != correctOrder[j] {
				success = false
				break
			}
		}

		// Jika ada percobaan yang tidak sesuai, keluar dari loop
		if !success {
			break
		}
	}

	// Menampilkan hasil
	if success {
		fmt.Println("BERHASIL : true")
	} else {
		fmt.Println("BERHASIL : false")
	}
}

```
#### Screenshoot Source Code
![Guided2 carbon](https://github.com/user-attachments/assets/5bc67756-0b53-47bc-be51-75de5b06c115)

#### Screenshoot Output
![Guided2 go](https://github.com/user-attachments/assets/c8ccaf94-6853-4d32-888f-3588a0ba0e1b)
![Guided2(1) go](https://github.com/user-attachments/assets/cadb683c-a6ae-4a9d-a4bb-2c1bcdb175ad)

#### Deskripsi Program
Program ini berisi tentang mengurutkan warna dengan benar dan hanya 5 percobaan. Jika semua inputan diisi dengan benar, maka akan muncul kata "BERHASIL:True". Jika salah maka akan muncul kata "BERHASIL:False"

Algoritma dari program ini sebagai berikut:
1. User menginputkan urutan warna dengan benar yaitu : merah kuning hijau ungu
2. User melakukan inputan sebanyak 5 kali 
3. Program membandingkan inputan user
4. Jika percobaannya benar maka akan menampilkan BERHASIL:True, jika salah maka akan menampilkan BERHASIL:False

Cara kerja dari program ini adalah membaca input dari user dengan 5 kali percobaan. Setiap inputan warna harus di spasi antara satu sama lain. Setelah 5 kali percobaan, program akan menilai ini berhasil atau gagal

3. Menambahkan bilangan yang diinputkan user

#### Source Code
```go
package main

import (
	"fmt" 
)

func main() {
	
	var a, b, c, d, e int
	var hasil int 

	fmt.Scanln(&a, &b, &c, &d, &e)
	
	hasil = a + b + c + d + e

	fmt.Println("Hasil Penjumlahan ", a, b, c, d, e, "adalah = ", hasil)
}
```
#### Screenshoot Source Code
![Guided3 carbon](https://github.com/user-attachments/assets/987fdc2e-1bf6-4ccf-a583-2475226995cf)

#### Screenshoot Output
![Guided3 go](https://github.com/user-attachments/assets/e2f00999-f6eb-4b4c-ac85-886cb2ffd9cd)

#### Deskripsi Program
Program ini berisi tentang perhitungan penjumlahan sederhana dengan memasukkan cukup hanya 5 angka yang ingin dihitung. Program menggunakan 'fmt.Scanln' untuk membaca dan menyimpan input pengguna pada variabel

Algoritma dari program ini sebagai berikut:
1. User menginputkan angka yang ingin dilakukan operasi penjumlahan.
2. Nilai-nilai yang dimasukkan harus sesuai dengan ketentuan
3. Menampilkan hasil dari angka-angka yang diinputkan user.

Cara kerja dari program ini adalah program mengenal 5 variabel untuk menentukan angka-angka yang dijumlahkan. Program membaca input, lalu program menghitung, dan menampilkan hasilnya pada output.

4. Diberikan sebuah nilai akhir mata kullah (NAM) [0..100] dan standar penilaian nilai mata kullah (NMK)
   sebagai berikut:
![Screenshot 2024-10-03 211225](https://github.com/user-attachments/assets/f5ea697d-88cd-43ba-b4dd-2b7779e9ccd1)


#### Source Code
```go
package main

import "fmt"

func main() {
	var nam float32
	var nmk string

	fmt.Print("Masukkan Nilai: ")
	fmt.Scan(&nam)

	if nam > 80 {
		nmk = "A"
	} else if nam > 72.5 {
		nmk = "B"
	} else if nam > 65 {
		nmk = "C"		
	} else if nam > 50 {
		nmk = "D"
	} else if nam > 40 {
		nmk = "E"
	} else {
		nmk = "F"
	}

	fmt.Printf("Nilai indeks untuk nilai %.2f adalah %s\n", nam, nmk)
}
```
#### Screenshoot Source Code
![Guided4 carbon](https://github.com/user-attachments/assets/67f3043e-276a-47e3-823a-8d5fe75d1763)

#### Screenshoot Output

#### Deskripsi Program
Program ini berisi tentang predikat nilai dari rentang nilai yang tersedia seperti A,B,C,dan seterusnya

Algoritma dari program ini sebagai berikut:
1. User menginputkan nilai yang ingin diketahui indeksnya
2. Program menampilkan indeks dari nilai yang diinputkan oleh user

Cara kerja program ini adalah program meminta user untuk memasukkan nilai dan menyimpan nilai dengan tipe data 'float' kemudian menggunakan tipe data 'if' dan 'if else' untuk membandingkan dari berbagai indeks nilai. Kemudian program menampilkan indeks nilai pada output

Jawablah pertanyaan-pertanyaan berikut :


a. jika nam diberikan nilai 80.1, apa keluaran dari program tersebut? Apakah eksekusi program tersebut sesuai spesifikasi soal?
jawab : keluaran dari program tersebut 80.1 berindeks A, sesuai dengan spesifikasi soal


b. Apa saja kesalahan dari program tersebut? Mengapa demikian? Jelaskan alur program seharusnya!
jawab : 
Kesalahannya adalah sebagai berikut :
- kesalahannya ada dipenggunaan float32, seharusnya menggunakan float64 yang lebih pas untuk program ini.
- sebaiknya menggunakan else if dibandingkan if else
Alur yang benar sebagai berikut :
- user menginputkan dengan tipe desimal (float64)
- indeks nilai


c. Perbaiki program tersebut! Ujilah dengan masukan:93.5; 70.6; dan 49.5. Seharusnya keluaran yang diperoleh adalah 'A','B', dan 'D'
jawab : 
```go
package main

import "fmt"

func main() {
	var nam float64 
	var nmk string

	fmt.Print("Masukkan Nilai: ")
	fmt.Scan(&nam)

	if nam >= 80 {
		nmk = "A"
	} else if nam >= 65 {
		nmk = "B"
	} else if nam >= 50 {
		nmk = "C"
	} else if nam >= 40 {
		nmk = "D"
	} else {
		nmk = "F"
	}

	fmt.Printf("Nilai indeks untuk nilai %.2f adalah %s\n", nam, nmk)
}

```
![image](https://github.com/user-attachments/assets/16510a37-0e48-45c3-afc8-0cfb321a71f4)

## III. UNGUIDED

1. Suatu pita (string) berisi kumpulan nama-nama bunga yang dipisahkan oleh spasi dan '-', contoh pita diilustrasikan seperti berikut ini.

Pita: mawar - melati - tulip - teratai - kamboja - anggrek

Buatlah sebuah program yang menerima input sebuah bilangan bulat positif (dan tidak nol) N, kemudian program akan meminta input berupa nama bunga secara berulang sebanyak N kali dan nama tersebut disimpan ke dalam pita.

(Petunjuk: gunakan operasi penggabungan string dengan operator "+").

Tampilkan isi pita setelah proses input selesai.

Modifikasi program sebelumnya, proses input akan berhenti apabila user mengetikkan 'SELESAI'. Kemudian tampilkan isi pita beserta banyaknya bunga yang ada di dalam pita.

#### Source Code
```go
// Andreas Besar Wibowo
// S1 IF11-05 / 2311102198

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var pita string
	var hitung int

	scanner := bufio.NewScanner(os.Stdin)

	for {
		fmt.Printf("Bunga %d: ", hitung+1) 
		scanner.Scan()
		bunga := scanner.Text()

		if strings.ToUpper(bunga) == "SELESAI" {
			break
		}

		if pita == "" {
			pita = bunga
		} else {
			pita = pita + " - " + bunga
		}

		hitung++
	}

	fmt.Println("Pita : ", pita)
	fmt.Printf("Bunga: %d\n", hitung)
}

```
#### Screenshoot Source Code
![Unguided1 carbon](https://github.com/user-attachments/assets/8ac4d2a3-f5d0-448b-9c99-43b21dafae2b)

#### Screenshoot Output
![Unguided1 go](https://github.com/user-attachments/assets/f465eb8b-253c-4538-a775-42ba3f4a3bab)

#### Deskripsi Program
Program ini berisi tentang nama nama bunga secara urut dan pada output disimpulkan semua nama bunga yang diinput dan jumlah bunganya

Algoritma dari program ini sebagai berikut:
1. User menginputkan nama bunga 
2. Jika user mengisi "SELESAI" program akan berhenti
3. Jika user terus mengisi nama bunga progran akan lanjut
4. Pada output terakhir, program menampilkan nama bunga dan totalnya

Cara kerja dari program ini adalah program menggunakan 'bufio.NewScanner' untuk membaca input dari user. Di dalam program menggunakan looping untuk menginput nama bunga. Setiap nama bunga akan di dimasukkan dalam string. Di akhir program akan menampilkan nama bunga dan menghitung jumlah dari bunga itu

2. Setiap hari Pak Andi membawa banyak barang belanjaan dari pasar dengan mengendarai sepeda motor. Barang belanjaan tersebut dibawa dalam kantong terpal di kiri-kanan motor. Sepeda motor tidak akan oleng jika selisih berat barang di kedua kantong sisi tidak lebih dari 9 kg.

Buatlah program Pak Andi yang menerima input dua buah bilangan real positif yang menyatakan berat total masing-masing isi kantong terpal. Program akan terus meminta input bilangan tersebut hingga salah satu kantong terpal berisi 9 kg atau lebih.

Pada modifikasi program tersebut, program akan menampilkan true Jika selisih kedua isi kantong lebih dari atau sama dengan 9 kg. Program berhenti memproses apabila total berat isi kedua kantong melebihi 150 kg atau salah satu kantong beratnya negatif.


#### Source Code
```go
// Andreas Besar Wibowo
// S1 IF11-05 / 2311102198

package main

import (
	"fmt"
)

func main() {
	var beratKiri, beratKanan float64

	for {
		fmt.Print("Masukkan berat belanjaan di kedua kantong : ")
		fmt.Scan(&beratKiri, &beratKanan)

		if beratKiri < 0 || beratKanan < 0 {
			fmt.Println("Salah satu kantong memiliki berat negatif, program selesai.")
			break
		}

		totalBerat := beratKiri + beratKanan
		if totalBerat > 150 {
			fmt.Println("Proses selesai.")
			break
		}

		var selisihBerat float64
		if beratKiri > beratKanan {
			selisihBerat = beratKiri - beratKanan
		} else {
			selisihBerat = beratKanan - beratKiri
		}

		if selisihBerat >= 9 {
			fmt.Println("Sepeda motor Pak Andi akan oleng: True")
		} else {
			fmt.Println("Sepeda motor Pak Andi akan oleng: False")
		}

		fmt.Println() 
	}
}
```
#### Screenshoot Source Code
![Unguided2 carbon](https://github.com/user-attachments/assets/313687d3-8b50-47e0-9ad6-66b706218608)

#### Screenshoot Output
![Unguided2 go](https://github.com/user-attachments/assets/d5495e05-9b1b-479b-bceb-b088e5d3c062)

#### Deskripsi Program
Program ini berisi tentang menghitung berat belanjaan di dua kantong dan selisih berat kedua kantung dan memperkirakan motor akan jatuh atau tidak

Algoritma dari program ini sebagai berikut:
1. User memasukkan berat belanjaan untuk masing-masing kantung
2. Program akan memeriksa beratnya melebihi kapasitas atau tidak
3. Program menghitung selisih berat kedua kantung
4. Program menampilkan apakah motor akan oleng atau tidak

Cara kerja dari program ini adalah program meminta user menginputkan berat kantungnya. Program akan memeriksa apakah beratnya melebihi 150 kg atau tidak. Jika melebihi program akan berhenti. Jika tidak program akan terus berlanjut

3. Diberikan sebuah persamaan sebagai berikut ini.
   Buatlah sebuah program yang menerima input sebuah bilangan sebagai K, kemudian menghitung dan menampilkan nilai f(K) sesuai persamaan di atas.
![Screenshot 2024-10-03 083724](https://github.com/user-attachments/assets/a761515c-219a-43e1-9c5b-bd9fa1a3278a)


#### Source Code
```go
// Andreas Besar Wibowo
// S1 IF11-05 / 2311102198

package main

import (
    "fmt"
)

func main() {
    var K float64
    fmt.Print("Nilai K = ")
    fmt.Scan(&K)

    pembilang := (4*K + 2) * (4*K + 2)
    penyebut := (4*K + 1) * (4*K + 3)
    fK := pembilang / penyebut

    fmt.Printf("Nilai f(K) = %.10f\n", fK)
}


```
#### Screenshoot Source Code
![Unguided3 carbon](https://github.com/user-attachments/assets/9955f643-34e7-4a08-abaf-41550dcf0afc)

#### Screenshoot Output
![Unguided3 go](https://github.com/user-attachments/assets/fed084d7-162f-4c27-866d-950186d2e682)

#### Deskripsi Program
Program ini berisi tentang menghitung nilai akar dari bilangan yang diinoutkan oleh user. 

Algoritma dari program ini sebagai berikut:
1. Meminta user untuk memasukkan nilai dalam integer
2. Program menghitung persamaan
3. Program menghitung fungsi
4. Menampilkan hasil dari hitungan persamaan

Cara kerja dari program ini adalah program meminta pengguna untuk memasukkan nilai integer.  

4. PT POS membutuhkan aplikasi perhitungan biaya kirim berdasarkan berat parsel. Maka, buatlah program BiayaPos untuk menghitung biaya pengiriman tersebut dengan ketentuan sebagai berikut!

Dari berat parsel (dalam gram), harus dihitung total berat dalam kg dan sisanya (dalam gram). Biaya jasa pengiriman adalah Rp. 10.000,- per kg. Jika sisa berat tidak kurang dari 500 gram, maka tambahan biaya kirim hanya Rp. 5,- per gram saja. Tetapi jika kurang dari 500 gram, maka tambahan biaya akan dibebankan sebesar Rp. 15,- per gram. Sisa berat (yang kurang dari 1kg) digratiskan biayanya apabila total berat ternyata lebih dari 10kg.


#### Source Code
```go
// Andreas Besar Wibowo
// S1 IF11-05 / 2311102198

package main

import (
	"fmt"
)

func main() {
	var beratParselGram int

	fmt.Print("Berat parsel (gram): ")
	_, err := fmt.Scan(&beratParselGram)
	if err != nil || beratParselGram < 0 {
		fmt.Println("Input tidak valid. Harap masukkan angka positif.")
		return
	}

	beratParselKilogram := beratParselGram / 1000
	sisaGram := beratParselGram % 1000

	biaya := 10000 * beratParselKilogram 
	detailBiaya := 0         
	
	if beratParselKilogram > 10 {
		sisaGram = 0
	} else if sisaGram >= 500 {
		detailBiaya = 5 * sisaGram 
		biaya += detailBiaya
	} else {
		detailBiaya = 15 * sisaGram 
		biaya += detailBiaya
	}

	fmt.Printf("Detail berat: %d kg + %d gr\n", beratParselKilogram, sisaGram)
	fmt.Printf("Detail biaya: Rp. %d + Rp. %d\n", 10000*beratParselKilogram, detailBiaya)
	fmt.Printf("Total biaya: Rp. %d\n", biaya)
}

```
#### Screenshoot Source Code
![Unguided4 carbon](https://github.com/user-attachments/assets/73f3537c-7ea1-4513-91c6-397defa4af5d)

#### Screenshoot Output
![Unguided4 go](https://github.com/user-attachments/assets/9dc2f071-fa8d-479b-9fbe-5bb4157db459)

#### Deskripsi Program
Program ini berisi tentang menghitung dan mengonversikan berat yang dimasukkan oleh user dengan menggunakan gram dan kilogram. Program ini juga menghitung biaya pengiriman dari ketentuan yang ditentukan.

Algoritma dari program ini sebagai berikut :
1. User menginputkan berat dalam ukuran gram
2. Program menghitung total berat dalam kilogram dan sisanya dalam gram, dan biaya pengirimannya.
3. Program menampilkan berat dan biaya pengiriman barang dengan mendetail

Cara kerja dari program ini adalah program meminta user untuk menginputkan berat barangnya, lalu berat itu dikonversikan menjadi kilogram dan gram. Program juga menentukan biaya pengirimannya, dan diakhir program akan menampilkan dengan detail dari berat dan biaya pengirimannya

5. Sebuah bilangan bulat b memiliki faktor bilangan f > O jika f habis membagi b. Contoh: 2 merupakan faktor dari bilangan 6 karena 6 habis dibagi 2.

Buatlah program yang menerima input sebuah bilangan bulat b dan b> 1. Program harus dapat mencari dan menampilkan semua faktor dari bilangan tersebut!

Bilangan bulat b > 0 merupakan bilangan prima p jika dan hanya jika memiliki persis dua faktor bilangan saja, yaitu 1 dan dirinya sendiri.

Lanjutkan program sebelumnya. Setelah menerima masukan sebuah bilangan bulat b > 0. Program tersebut mencari dan menampilkan semua faktor bilangan tersebut. Kemudian, program menentukan apakah b merupakan bilangan prima.


#### Source Code
```go
// Andreas Besar Wibowo
// S1 IF11-05 / 2311102198

package main

import (
	"fmt"
)

func main() {
	var b int

	fmt.Print("Bilangan: ")
	_, err := fmt.Scan(&b)
	if err != nil || b <= 1 {
		fmt.Println("Input tidak valid. Harap masukkan bilangan bulat lebih dari 1.")
		return
	}

	faktor := []int{}
	bilPrima := true 

	for i := 1; i <= b; i++ {
		if b%i == 0 {
			faktor = append(faktor, i) 
			if i != 1 && i != b {
				bilPrima = false 
			}
		}
	}

	fmt.Printf("Bilangan: %d\n", b)
	fmt.Printf("Faktor: ")
	for i, f := range faktor {
		if i == len(faktor)-1 {
			fmt.Printf("%d", f) 
		} else {
			fmt.Printf("%d, ", f)
		}
	}
	fmt.Println()

	fmt.Printf("Prima: %t\n", bilPrima)
}

```
#### Screenshoot Source Code
![Unguided5 carbon](https://github.com/user-attachments/assets/d17d962a-b956-4e1b-ab12-ebcf28283429)

#### Screenshoot Output
![Unguided5(1) go](https://github.com/user-attachments/assets/dd0c4289-5449-4cfc-bc33-f0654888f4e3)
![Unguided5(2) go](https://github.com/user-attachments/assets/38a31559-8312-4bf6-b5aa-c5e3e482988c)

#### Deskripsi Program
Program ini berisi tentang menentukan bilangan yang dimasukkan termasuk bilangan prima atau bukan. Pada awal program, user diminta untuk memasukkan bilangan bulat terlebih dahulu

Algoritma dari program ini sebagai berikut :
1. User memasukkan bilangan bulat
2. Program akan menentukan apakah bilangan yang dimasukkan oleh user itu merupakan bilangan prima atau bukan
3. Program menampilkan bilangan yang dimasukkan oleh user, faktor dari bilangannya, dan menentukan itu merupakan bilangan prima atau bukan

Cara kerja program ini adalah user memasukkan bilangan bulat lebih dari 1. Setelah itu, program itu akan mencari semua bilangan faktor dan melakukan pemeriksaan apakah bilangan ini termasuk bilangan prima. Pada akhir program, program akan menampilkan bilangan, faktor-faktornya, dan prima atau bukan.

## Referensi 
[1] Wali, M., Nengsih, TA, Hts, DIG, Choirina, P., Awaludin, AAR, Yusuf, M., ... & Baradja, A. (2023). Pengantar 15 Bahasa Pemrograman Terbaik Masa Depan (Referensi & Coding Untuk Pemula) . PT. Sonpedia Penerbitan Indonesia.


[2] Novalagung. Variabel dalam Go. Diakses dari https://dasarpemrogramangolang.novalagung.com/A-variabel.html


[3] Ruang Developer. Mengenal For Loop dalam Golang. Diakses dari https://blog.ruangdeveloper.com/golang-for-loop/


[4] Barungoding. Percabangan pada Golang. Diakses dari https://barungoding.vercel.app/t/go-percabangan/#p
