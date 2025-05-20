//FormAI DATASET v1.0 Category: Weather simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 50
#define MIN_TEMP -30

int random_temperature() {
    return rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
}

void print_stats(int temperatures[], int n) {
    int min_temp = MAX_TEMP + 1;
    int max_temp = MIN_TEMP - 1;
    int sum_temp = 0;

    for (int i = 0; i < n; i++) {
        if (temperatures[i] < min_temp) {
            min_temp = temperatures[i];
        }
        if (temperatures[i] > max_temp) {
            max_temp = temperatures[i];
        }
        sum_temp += temperatures[i];
    }

    printf("----- Stats -----\n");
    printf("Minimum temperature: %d\n", min_temp);
    printf("Maximum temperature: %d\n", max_temp);
    printf("Average temperature: %.2f\n", (float)sum_temp / n);
    printf("-----------------\n");
}

int main(void) {
    srand(time(NULL));

    int num_days;
    printf("Enter the number of days to simulate weather for: ");
    scanf("%d", &num_days);

    int temperatures[num_days];

    for (int i = 0; i < num_days; i++) {
        temperatures[i] = random_temperature();
    }

    printf("\n--- Weather Simulation ---\n");

    for (int i = 0; i < num_days; i++) {
        printf("Day %d: %d\n", i+1, temperatures[i]);
    }

    print_stats(temperatures, num_days);

    return 0;
}