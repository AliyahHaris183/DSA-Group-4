#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk menghitung jumlah hari sampai semua tanaman menjadi stabil
int poisonousPlants(int p_count, int* p) {
    // Array 'days' menyimpan jumlah hari tanaman ke-i mati
    int* days = calloc(p_count, sizeof(int));
    int max_days = 0; // Menyimpan hari maksimum yang diperlukan

    // Iterasi dimulai dari indeks 1 karena tanaman pertama tidak bisa mati
    for (int i = 1; i < p_count; i++) {
        // Jika tanaman saat ini lebih besar dari tanaman sebelumnya, maka dia akan mati keesokan harinya
        if (p[i] > p[i - 1]) {
            days[i] = 1;
        }
        // Jika tanaman saat ini tidak lebih besar dari sebelumnya
        else {
            int max_day = 0;

            // Cek ke belakang untuk melihat berapa hari maksimal tanaman sebelumnya mati
            for (int j = i - 1; j >= 0 && p[j] >= p[i]; j--) {
                if (days[j] > max_day) {
                    max_day = days[j];
                }
            }

            // Tanaman ini mati satu hari setelah tanaman sebelumnya yang paling lambat mati
            days[i] = max_day + 1;
        }

        // Update jumlah hari maksimum jika perlu
        if (days[i] > max_days) {
            max_days = days[i];
        }
    }

    // Bebaskan memori yang sudah dialokasikan
    free(days);

    // Kembalikan jumlah hari maksimal
    return max_days;
}

int main() {
    // Contoh input: array berisi tingkat racun tanaman
    int p[] = {6, 5, 8, 4, 7, 10, 9};
    int p_count = sizeof(p) / sizeof(p[0]); // Hitung jumlah elemen dalam array

    // Panggil fungsi dan simpan hasilnya
    int result = poisonousPlants(p_count, p);

    // Cetak hasilnya
    printf("Jumlah hari sampai semua tanaman stabil: %d\n", result);

    return 0;
}
