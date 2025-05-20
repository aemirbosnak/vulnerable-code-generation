//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i <= number / 2; ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    // Get the input from the user
    int lower_bound, upper_bound;
    printf("Enter the lower bound: ");
    scanf("%d", &lower_bound);
    printf("Enter the upper bound: ");
    scanf("%d", &upper_bound);

    // Initialize the array to store the prime numbers
    int *prime_numbers = (int *)malloc(sizeof(int) * (upper_bound - lower_bound + 1));

    // Initialize the index of the prime numbers array
    int prime_index = 0;

    // Iterate over the numbers from the lower bound to the upper bound
    for (int number = lower_bound; number <= upper_bound; ++number) {
        // Check if the number is prime
        if (is_prime(number)) {
            // Add the prime number to the array
            prime_numbers[prime_index++] = number;
        }
    }

    // Print the prime numbers
    printf("The prime numbers between %d and %d are: ", lower_bound, upper_bound);
    for (int i = 0; i < prime_index; ++i) {
        printf("%d ", prime_numbers[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(prime_numbers);

    return 0;
}