#include <stdio.h>
#include <stdlib.h>

// Struktur untuk menyimpan info tiap tanaman:
// - pesticide: kadar racun tanaman
// - daysAlive: berapa hari dibutuhkan sampai tanaman ini tidak membunuh tanaman setelahnya
typedef struct {
    int pesticide;
    int daysAlive;
} PlantInfo;

// Fungsi utama untuk menentukan berapa hari sampai semua tanaman stabil
int poisonousPlants(int p_count, int* p) {
    // Alokasi memori untuk stack (pakai array biasa)
    PlantInfo* stack = malloc(sizeof(PlantInfo) * p_count);
    int top = -1; // indeks teratas dari stack

    int max_days = 0; // nilai maksimum hari yang dibutuhkan hingga stabil

    // Iterasi setiap tanaman
    for (int i = 0; i < p_count; i++) {
        int days = 0; // hari yang dibutuhkan sampai tanaman ini tidak lagi membunuh

        // Cek semua tanaman sebelumnya di stack
        // Pop semua tanaman yang racunnya >= tanaman sekarang
        // karena mereka tidak akan membunuh tanaman ini
        while (top >= 0 && p[i] <= stack[top].pesticide) {
            // Ambil jumlah hari maksimum dari tanaman yang di-pop
            if (stack[top].daysAlive > days) {
                days = stack[top].daysAlive;
            }
            top--; // keluarkan dari stack
        }

        // Kalau tidak ada tanaman sebelumnya yang lebih kecil (stack kosong)
        // berarti tanaman ini aman sejak awal
        if (top == -1) {
            days = 0;
        } else {
            // Kalau ada tanaman sebelumnya yang lebih kecil,
            // maka butuh 1 hari ekstra untuk bisa selamat
            days += 1;
        }

        // Masukkan tanaman ini ke stack
        stack[++top] = (PlantInfo){p[i], days};

        // Update hari maksimum jika perlu
        if (days > max_days) {
            max_days = days;
        }
    }

    // Bebaskan memori setelah selesai
    free(stack);

    // Kembalikan jumlah hari maksimum sebagai hasil akhir
    return max_days;
}

// Fungsi utama (entry point)
int main() {
    // Contoh array tanaman dan kadar racunnya
    int p[] = {6, 5, 8, 4, 7, 10, 9};
    int p_count = sizeof(p) / sizeof(p[0]);

    // Panggil fungsi utama
    int result = poisonousPlants(p_count, p);

    // Tampilkan hasil
    printf("Jumlah hari sampai semua tanaman stabil: %d\n", result);

    return 0;
}
