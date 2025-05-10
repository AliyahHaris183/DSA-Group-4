**Saya memberikan link soal dan kode yang baru setengah jadi kepada AI, serta meminta perbedaan calloc dan malloc.**

https://www.hackerrank.com/challenges/poisonous-plants/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int poisonousPlants(int jumlah_p, int* p) {
    int* days = calloc(jumlah_p, sizeof(int));
    int max_days = 0;

    for (int i = 1; i < jumlah_p; i++) {
        int day = 0;
        if (p[i] > p[i-1]) {
            days[i] = 1;
        }
}

saya baru di sini. beda calloc dan malloc itu, calloc men-set agar semua isi array bernilai 0 dan bukan nilai acak kan?


**AI menjawab, bahwa saya betul. Calloc digunakan saat saya ingin memastikan semua elemen array terinisialisasi ke 0. Maka saya lanjut meminta bantuan untuk meneruskan program.**


**Kode solusi dari AI:**

int poisonousPlants(int n, int* p) {
    int* days = calloc(n, sizeof(int));
    int max_days = 0;

    for (int i = 1; i < n; i++) {
        int day = 0;

        if (p[i] > p[i - 1]) {
            day = 1;
        } else {
            int j = i - 1;
            while (j >= 0 && p[j] >= p[i]) {
                if (days[j] > day) {
                    day = days[j];
                }
                j--;
            }

            if (day > 0) {
                day++;
            }
        }

        days[i] = day;
        if (day > max_days) {
            max_days = day;
        }
    }

    free(days);
    return max_days;
}


**Kode saya improvisasi, sesuai dengan yang saya pahami—gaya yang biasa saya pakai.**

int poisonousPlants(int p_count, int* p) {
    int* days = calloc(p_count, sizeof(int));
    int max_days = 0;

    for (int i = 1; i < p_count; i++) {
        if (p[i] > p[i - 1]) {
            days[i] = 1;
        } else if (p[i] <= p[i - 1]) {
            int max_day = 0;
            for (int j = i - 1; j >= 0 && p[j] >= p[i]; j--) {
                if (days[j] > max_day) {
                    max_day = days[j];
                }
            }
            days[i] = max_day + 1;
        }
        if (days[i] > max_days) {
            max_days = days[i];
        }
    }

    free(days);
    return max_days;
}

int main() {
    int p[] = {6, 5, 8, 4, 7, 10, 9};
    int p_count = sizeof(p) / sizeof(p[0]);

    int poisonousPlants(p_count, p);
    printf("Jumlah hari sampai semua tanaman stabil: %d\n", result);

    return 0;
}

**Perbaikan dari AI:**

    int poisonousPlants(p_count, p);
    Harusnya:
    int result = poisonousPlants(p_count, p);
