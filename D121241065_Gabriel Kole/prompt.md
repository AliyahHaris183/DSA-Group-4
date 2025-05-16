# AI Prompt dan Analisis
---
## Deskripsi Masalah

Diberikan pointer ke head dari sebuah linked list, sisipkan node baru sebelum head. Nilai next pada node baru harus menunjuk ke head dan nilai data diisi dengan nilai yang diberikan.
Kembalikan referensi ke node head yang baru. Pointer head yang diberikan bisa saja bernilai null, yang berarti linked list awalnya kosong.

---
## Deskripsi Fungsi

Lengkapi fungsi insertNodeAtHead dengan parameter berikut:

- SinglyLinkedListNode llist: referensi ke head dari linked list.

- data: nilai yang akan dimasukkan ke dalam field data pada node baru

---
### Format Input:

- Baris pertama berisi sebuah bilangan bulat n, yaitu jumlah elemen yang akan disisipkan di awal linked list.

- n baris berikutnya masing-masing berisi satu bilangan bulat, yaitu elemen yang akan disisipkan satu per satu melalui pemanggilan fungsi.


### Batasan (Constraints):

- 1 ≤ n ≤ 1000

- 1 ≤ list[i] ≤ 1000
---
### Sample Input

| **Contoh Input** |              
| -----------------| 
| 5                | 
| 383              | 
| 484              | 
| 392              | 
| 975              | 
| 321              | 

| **Contoh Output** |              
| -----------------| 
| 321              | 
| 975              | 
| 392              | 
| 484              | 
| 383              | 


### Penjelasan 

1. Pahami Permintaan Soal
Kita diminta menambahkan node di awal linked list. Artinya, setiap data yang masuk akan menjadi head baru, dan next-nya akan menunjuk ke head sebelumnya.

2. Struktur Node
Biasanya, node pada linked list punya dua bagian:
    - data: menyimpan nilai
    - next: pointer ke node berikutnya

3. Buat Fungsi insertNodeAtHead
    Fungsi ini akan menerima:
    - llist → head saat ini (bisa None)
    - data → nilai yang ingin dimasukkan

    Langkah dalam fungsi:
      - Buat node baru: new_node = Node(data)
      - Hubungkan node baru ke llist: new_node.next = llist
      - Kembalikan node baru sebagai head baru
4. Jalankan fungsi
Misal 5 data sebelumnya 
Lakukan pemanggilan fungsi seperti ini (asumsikan head awalnya None):
- head = None
- head = insertNodeAtHead(head, 383)
- head = insertNodeAtHead(head, 484)
- head = insertNodeAtHead(head, 392)
- head = insertNodeAtHead(head, 975)
- head = insertNodeAtHead(head, 321)
Setelah semua langkah, urutan linked list:
- 321 -> 975 -> 392 -> 484 -> 383 -> NULL
<pre>
Awalnya, linked list bernilai NULL.

- Setelah menyisipkan 383 → 383 -> NULL

- Menyisipkan 484 → 484 -> 383 -> NULL

- Menyisipkan 392 → 392 -> 484 -> 383 -> NULL

- Menyisipkan 975 → 975 -> 392 -> 484 -> 383 -> NULL

- Menyisipkan 321 → 321 -> 975 -> 392 -> 484 -> 383 -> NULL
</pre>

### Efisiensi Waktu

- Waktu per penyisipan: O(1), karena hanya mengubah dua pointer (buat node baru dan sambungkan).

- Total waktu untuk n penyisipan: O(n)

- Memori: O(n) untuk menyimpan n node baru dalam linked list.

### Kesimpulan
Soal ini meminta kita menyisipkan node baru di awal linked list. Solusinya cukup dengan membuat node baru, mengarahkannya ke head lama, lalu mengembalikan node baru sebagai head yang baru. Proses ini diulang sesuai jumlah data yang diberikan, menghasilkan linked list yang urutannya kebalikan dari input.