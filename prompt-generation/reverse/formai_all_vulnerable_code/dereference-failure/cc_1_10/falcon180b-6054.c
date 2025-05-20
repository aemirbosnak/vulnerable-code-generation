//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_SAMPLES 1000000
#define NUM_DIMENSIONS 10

double **generate_data(int num_samples, int num_dimensions) {
    double **data = (double **)malloc(num_samples * sizeof(double *));
    for (int i = 0; i < num_samples; i++) {
        data[i] = (double *)malloc(num_dimensions * sizeof(double));
        for (int j = 0; j < num_dimensions; j++) {
            data[i][j] = rand() % 100;
        }
    }
    return data;
}

void free_data(double **data, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        free(data[i]);
    }
    free(data);
}

void print_data(double **data, int num_samples, int num_dimensions) {
    for (int i = 0; i < num_samples; i++) {
        for (int j = 0; j < num_dimensions; j++) {
            printf("%lf ", data[i][j]);
        }
        printf("\n");
    }
}

double calculate_mean(double **data, int num_samples, int num_dimensions) {
    double sum = 0;
    for (int i = 0; i < num_samples; i++) {
        for (int j = 0; j < num_dimensions; j++) {
            sum += data[i][j];
        }
    }
    return sum / (num_samples * num_dimensions);
}

double calculate_variance(double **data, int num_samples, int num_dimensions) {
    double mean = calculate_mean(data, num_samples, num_dimensions);
    double sum_squares = 0;
    for (int i = 0; i < num_samples; i++) {
        for (int j = 0; j < num_dimensions; j++) {
            sum_squares += pow(data[i][j] - mean, 2);
        }
    }
    return sum_squares / (num_samples * num_dimensions);
}

int main() {
    srand(time(NULL));

    double **data = generate_data(NUM_SAMPLES, NUM_DIMENSIONS);
    print_data(data, NUM_SAMPLES, NUM_DIMENSIONS);

    double mean = calculate_mean(data, NUM_SAMPLES, NUM_DIMENSIONS);
    printf("Mean: %lf\n", mean);

    double variance = calculate_variance(data, NUM_SAMPLES, NUM_DIMENSIONS);
    printf("Variance: %lf\n", variance);

    free_data(data, NUM_SAMPLES);

    return 0;
}