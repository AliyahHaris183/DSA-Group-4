#include <stdio.h>
#include <stdlib.h>

// Struktur data untuk menyimpan kadar racun dan hari hidup
// Contoh: jika tanaman memiliki kadar racun 8 dan mati di hari ke-1, maka
// PlantInfo = {8, 1}
typedef struct {
    int pesticide;
    int daysAlive;
} PlantInfo;

// Fungsi utama logika Poisonous Plants
// Contoh input: p = {6, 5, 8, 4, 7, 10, 9}, p_count = 7
int poisonousPlants(int p_count, int* p) {
    PlantInfo* stack = malloc(sizeof(PlantInfo) * p_count);
    // Alokasi memori stack sebanyak p_count

    int top = -1;
    // Inisialisasi stack kosong

    int max_days = 0;
    // Menyimpan jumlah hari maksimal sampai semua tanaman stabil

    // Iterasi tiap tanaman dari kiri ke kanan
    for (int i = 0; i < p_count; i++) {
        int days = 0;
        // Hari bertahan untuk tanaman saat ini

        int max_popped_days = 0;
        // Menyimpan hari hidup maksimum dari tanaman yang dikeluarkan dari stack

        // Contoh p[i] = 4, dan stack[top].pesticide = 8:
        // 4 <= 8 -> pop stack, ambil max hari hidup dari tanaman yang dipop
        while (top >= 0 && p[i] <= stack[top].pesticide) {
            if (stack[top].daysAlive > max_popped_days) {
                max_popped_days = stack[top].daysAlive;
            }
            top--;
            // Tanaman di-pop karena lebih besar atau sama racunnya dari yang sekarang
        }

        if (top == -1) {
            // Stack kosong, artinya tidak ada tanaman sebelumnya yang lebih kecil racunnya
            days = 0;
        } else {
            // Kalau ada tanaman sebelumnya dengan racun lebih kecil, tambahkan 1 hari
            days = max_popped_days + 1;
        }

        stack[++top] = (PlantInfo){p[i], days};
        // Tambahkan tanaman ini ke stack: nilai racun dan hari hidup

        if (days > max_days) {
            max_days = days;
        }
        // Perbarui max_days jika hari hidup tanaman saat ini lebih besar
    }

    free(stack);
    // Bebaskan memori setelah selesai

    return max_days;
    // Return jumlah hari maksimal sampai tidak ada tanaman mati
}

// Fungsi utama
// Input: jumlah tanaman dan kadar racunnya satu per satu
// Output: jumlah hari sampai semua tanaman tidak mati lagi
int main() {
    int p_count;
    scanf("%d", &p_count);
    // Contoh input: 7

    int* p = malloc(p_count * sizeof(int));
    // Alokasi array p sebanyak p_count

    for (int i = 0; i < p_count; i++) {
        scanf("%d", &p[i]);
        // Contoh input: 6 5 8 4 7 10 9
    }

    int result = poisonousPlants(p_count, p);
    // Panggil fungsi utama dengan array dan ukurannya

    printf("%d\n", result);
    // Output hasil: misalnya 2 (butuh 2 hari sampai semua tanaman stabil)

    free(p);
    // Bebaskan memori

    return 0;
}
