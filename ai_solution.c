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
