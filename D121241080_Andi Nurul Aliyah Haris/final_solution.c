#include <stdio.h>
// Pustaka input/output.
#include <stdlib.h>
// Pustaka untuk fungsi malloc dan free.

typedef struct { // Definisi sturktur.
    int pesticide; // Menyimpan kadar racun tanaman.
    int daysAlive; // Menyimpan jumlah hari hidup tanaman.
} PlantInfo;

int poisonousPlants(int p_count, int* p) {
// Fungsi yang menerima masukan p_count (panjang array) dan p (isi array).
// Misal p = {6, 5, 8, 4, 7, 10, 9}, p_count = 7.
    PlantInfo* stack = malloc(sizeof(PlantInfo) * p_count);
    // Perintah alokasi memori array stack.
    // Malloc adalah memory location dinamis untuk membuat array stack berukuran fleksibel.
    // sizeof(PlantInfo) * p_count = (4 byte (pesticide) x 4 byte (days Alive)) * 8 = 56 byte.
    int top = -1;
    // Stack kosong.
    int max_days = 0;
    // Untuk menyimpan hasi akhir, yakni maksimal hari hingga semua tanaman stabil.

    for (int i = 0; i < p_count; i++) {
    // Iterasi array dari kiri ke kanan.
        int days = 0; // Hari hidup untuk tanaman, saat ini 0 karena diasumsikan aman.
        int max_popped_days = 0; // Hari hidup maksimum dari tanaman-tanaman yang dikeluarkan (di-pop).

        while (top >= 0 && p[i] <= stack[top].pesticide) {
            // Selama stack tidak kosong,
            // Dan kadar racun i kurang dari atau sama dengan kadar racun top,
                if (stack[top].daysAlive > max_popped_days) {
                // Kalau hari hidup tanaman top lebih dari hari maksimal tanaman yang telah di-pop,
                    max_popped_days = stack[top].daysAlive;
                    // Maka hari maksimal tanaman yang telah di-pop adalah hari hidup tanaman top yang baru.
                }
                top--;
                // Top di-pop keluar dari stack.
            }
    
            if (top == -1) {
            // Kalau stack kosong,
                days = 0;
            } else {
            // Kalau tidak kosong,
                days = max_popped_days + 1;
        }

        stack[++top] = (PlantInfo){p[i], days};
        // Tambahkan tanaman i ke stack, beserta hari hidupnya.

        if (days > max_days) {
            max_days = days;
        }
        // Kalau hari hidup tanaman ini lebih besar dari hari maksimal sebelumnya,
        // maka perbarui max_days jadi nilai yang baru.

    }

    free(stack);
    // Bebaskan memori yang dialokasikan untuk stack setelah selesai.

    return max_days;
    // Kembalikan jumlah hari maksimal sebagai hasil akhir fungsi.

}

int main() {
    int p[] = {6, 5, 8, 4, 7, 10, 9};
    // Array input kadar racun tanaman.

    int p_count = sizeof(p) / sizeof(p[0]);
    // Hitung jumlah tanaman dari ukuran array.

    int result = poisonousPlants(p_count, p);
    // Panggil fungsi utama dan simpan hasilnya ke variabel result.

    printf("Jumlah hari sampai semua tanaman stabil: %d\n", result);
    // Cetak hasil ke layar.

    return 0;
    // Program selesai.
}
