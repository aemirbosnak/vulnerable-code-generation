//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum size of the array
#define MAX_SIZE 10000

// Function to initialize the array with random numbers
void init_array(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to calculate the sum of all odd numbers in the array
int sum_odd(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2!= 0) {
            sum += arr[i];
        }
    }
    return sum;
}

// Function to calculate the average of all even numbers in the array
double avg_even(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            sum += arr[i];
        }
    }
    return (double) sum / size;
}

// Function to calculate the product of all prime numbers in the array
int product_prime(int arr[], int size) {
    int product = 1;
    for (int i = 0; i < size; i++) {
        int is_prime = 1;
        for (int j = 2; j <= arr[i] / 2; j++) {
            if (arr[i] % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            product *= arr[i];
        }
    }
    return product;
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("Array size is too large!\n");
        return 1;
    }

    int arr[size];

    init_array(arr, size);

    int sum_odd_result = sum_odd(arr, size);
    double avg_even_result = avg_even(arr, size);
    int product_prime_result = product_prime(arr, size);

    printf("Sum of all odd numbers: %d\n", sum_odd_result);
    printf("Average of all even numbers: %.2f\n", avg_even_result);
    printf("Product of all prime numbers: %d\n", product_prime_result);

    return 0;
}