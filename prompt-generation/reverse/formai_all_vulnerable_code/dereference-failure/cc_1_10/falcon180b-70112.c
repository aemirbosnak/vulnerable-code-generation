//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 10000

// Function to generate random data
void generate_data(int size, double *data) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 100;
    }
}

// Function to sort data using quicksort
void quicksort(int size, double *data) {
    if (size <= 1) {
        return;
    }

    int pivot_index = rand() % size;
    double pivot_value = data[pivot_index];
    data[pivot_index] = data[size - 1];
    data[size - 1] = pivot_value;

    int left = 0;
    int right = size - 1;

    while (left < right) {
        while (data[left] > pivot_value) {
            left++;
        }
        while (data[right] < pivot_value) {
            right--;
        }
        if (left < right) {
            double temp = data[left];
            data[left] = data[right];
            data[right] = temp;
            left++;
            right--;
        }
    }

    data[left] = pivot_value;
}

// Function to calculate the mean of data
double calculate_mean(int size, double *data) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}

int main() {
    int size = MAX_SIZE;
    double *data = malloc(size * sizeof(double));

    generate_data(size, data);
    quicksort(size, data);

    double mean = calculate_mean(size, data);
    printf("Mean: %.2f\n", mean);

    free(data);
    return 0;
}