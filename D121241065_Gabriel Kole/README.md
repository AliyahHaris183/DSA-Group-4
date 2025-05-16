# Struktur Data - Queue

<pre>
<strong>NAMA         :</strong> GABRIEL IMANUEL KOLE
<strong>NIM          :</strong> D121241065
<strong>Problem Link :</strong> <a href="https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/problem?isFullScreen=true">Insert a node at the head of a linked list - HackerRank</a>
<strong>Difficulty   :</strong> Easy
</pre>

## Short Approach Summary
- Buat node baru dengan data yang diberikan.

- Arahkan next dari node baru ke node head saat ini.

- Perbarui head agar menunjuk ke node baru.

- Kembalikan node baru sebagai head yang baru dari linked list.


---
Langkah ini diulangi untuk setiap data yang dimasukkan, sehingga list terbentuk secara terbalik dari urutan input.
Operasi ini memiliki kompleksitas waktu O(1) karena tidak memerlukan traversal pada linked list.