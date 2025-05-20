//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

// Function to calculate the sum of all even numbers in an array
int sum_even(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            sum += arr[i];
        }
    }
    return sum;
}

// Function to calculate the average of an array
double avg(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double) sum / size;
}

// Function to calculate the standard deviation of an array
double std_dev(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += pow(arr[i] - avg(arr, size), 2);
    }
    return sqrt(sum / size);
}

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Fill the array with even numbers
    for (int i = 0; i < size; i++) {
        arr[i] = 2 * i;
    }

    // Calculate the sum of all even numbers
    int sum = sum_even(arr, size);
    printf("Sum of all even numbers: %d\n", sum);

    // Calculate the average of the array
    double avg_val = avg(arr, size);
    printf("Average of the array: %.2f\n", avg_val);

    // Calculate the standard deviation of the array
    double std_dev_val = std_dev(arr, size);
    printf("Standard deviation of the array: %.2f\n", std_dev_val);

    return 0;
}