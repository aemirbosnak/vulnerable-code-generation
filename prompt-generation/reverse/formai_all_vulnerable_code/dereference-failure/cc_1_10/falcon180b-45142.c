//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to calculate mean
double calculate_mean(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double) sum / n;
}

// Function to calculate median
double calculate_median(int arr[], int n) {
    int median_index = n / 2;
    if (n % 2 == 0) {
        return (arr[median_index - 1] + arr[median_index]) / 2.0;
    } else {
        return arr[median_index];
    }
}

// Function to calculate mode
int calculate_mode(int arr[], int n) {
    int mode = arr[0];
    int max_count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_count) {
            max_count = arr[i];
            mode = arr[i];
        }
    }
    return mode;
}

int main() {
    int n, i;
    srand(time(NULL));
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        arr[i] = rand_num(1, 100); // Generate random numbers between 1 and 100
    }
    printf("\nOriginal array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nMean: %.2f\n", calculate_mean(arr, n));
    printf("Median: %.2f\n", calculate_median(arr, n));
    printf("Mode: %d\n", calculate_mode(arr, n));
    return 0;
}