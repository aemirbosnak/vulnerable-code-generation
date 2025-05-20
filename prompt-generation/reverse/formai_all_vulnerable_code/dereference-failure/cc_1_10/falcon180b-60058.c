//Falcon-180B DATASET v1.0 Category: Educational ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VALUES 1000
#define MAX_ITERATIONS 10000

int generate_random_number() {
    return rand() % 100;
}

void generate_random_data(int* data, int num_values) {
    for (int i = 0; i < num_values; i++) {
        data[i] = generate_random_number();
    }
}

void print_data(int* data, int num_values) {
    for (int i = 0; i < num_values; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

double calculate_mean(int* data, int num_values) {
    double sum = 0;
    for (int i = 0; i < num_values; i++) {
        sum += data[i];
    }
    return sum / num_values;
}

double calculate_standard_deviation(int* data, int num_values) {
    double mean = calculate_mean(data, num_values);
    double sum_squared_diffs = 0;
    for (int i = 0; i < num_values; i++) {
        sum_squared_diffs += pow(data[i] - mean, 2);
    }
    return sqrt(sum_squared_diffs / num_values);
}

int main() {
    srand(time(NULL));

    int num_values = MAX_VALUES;
    int* data = malloc(num_values * sizeof(int));

    printf("Generating %d random numbers...\n", num_values);
    generate_random_data(data, num_values);

    print_data(data, num_values);

    double mean = calculate_mean(data, num_values);
    printf("Mean: %.2f\n", mean);

    double standard_deviation = calculate_standard_deviation(data, num_values);
    printf("Standard deviation: %.2f\n", standard_deviation);

    free(data);
    return 0;
}