//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 100
#define MIN_VALUE -100
#define MAX_VALUE 100

// Function to generate random numbers
int random_number(int min, int max) {
    return (int)(rand() % (max - min) + min);
}

// Function to calculate mean and standard deviation
void calculate_mean_stddev(int arr[], int size) {
    int sum = 0;
    int sum_squared = 0;
    int i;

    for (i = 0; i < size; i++) {
        sum += arr[i];
        sum_squared += arr[i] * arr[i];
    }

    double mean = (double)sum / size;
    double stddev = sqrt(sum_squared / (size - 1));

    printf("Mean: %f\n", mean);
    printf("Standard Deviation: %f\n", stddev);
}

// Function to generate a random sample from a normal distribution
int* generate_normal_sample(int mean, int stddev, int size) {
    int i;
    int* arr = malloc(size * sizeof(int));

    for (i = 0; i < size; i++) {
        arr[i] = random_number(mean - stddev, mean + stddev);
    }

    return arr;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    calculate_mean_stddev(arr, size);

    int* normal_sample = generate_normal_sample(50, 10, 5);
    calculate_mean_stddev(normal_sample, 5);

    free(normal_sample);

    return 0;
}