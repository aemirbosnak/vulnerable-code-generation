//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 100
#define NUM_SIDES 6
#define NUM_ROLLS 100000

int roll_dice() {
    return rand() % NUM_SIDES + 1;
}

double calculate_mean(int *data, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}

double calculate_variance(int *data, int n, double mean) {
    double sum_squares = 0;
    for (int i = 0; i < n; i++) {
        sum_squares += pow(data[i] - mean, 2);
    }
    return sum_squares / n;
}

double calculate_standard_deviation(double variance) {
    return sqrt(variance);
}

int main() {
    srand(time(NULL));

    int *data = malloc(NUM_ROLLS * sizeof(int));

    for (int i = 0; i < NUM_ROLLS; i++) {
        data[i] = roll_dice();
    }

    double mean = calculate_mean(data, NUM_ROLLS);
    double variance = calculate_variance(data, NUM_ROLLS, mean);
    double standard_deviation = calculate_standard_deviation(variance);

    printf("Mean: %lf\n", mean);
    printf("Variance: %lf\n", variance);
    printf("Standard Deviation: %lf\n", standard_deviation);

    free(data);

    return 0;
}