//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    int rand_val;
    srand(time(NULL));
    rand_val = rand() % (max - min + 1) + min;
    return rand_val;
}

// Function to calculate the mean of an array
double calculate_mean(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double) sum / n;
}

// Function to calculate the standard deviation of an array
double calculate_std_dev(int arr[], int n) {
    double mean = calculate_mean(arr, n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow((arr[i] - mean), 2);
    }
    return sqrt(sum / n);
}

int main() {
    int n, min, max;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the minimum value: ");
    scanf("%d", &min);
    printf("Enter the maximum value: ");
    scanf("%d", &max);

    int arr[n];

    // Populate the array with random numbers
    for (int i = 0; i < n; i++) {
        arr[i] = rand_num(min, max);
    }

    // Calculate the mean and standard deviation
    double mean = calculate_mean(arr, n);
    double std_dev = calculate_std_dev(arr, n);

    // Print the results
    printf("Mean: %.2f\n", mean);
    printf("Standard deviation: %.2f\n", std_dev);

    return 0;
}