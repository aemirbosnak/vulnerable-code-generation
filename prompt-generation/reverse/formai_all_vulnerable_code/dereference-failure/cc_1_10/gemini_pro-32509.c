//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    // Get the input from the user
    printf("Enter the number of prime numbers to generate: ");
    int num;
    scanf("%d", &num);

    // Initialize the array to store the prime numbers
    int *primeNumbers = (int *)malloc(num * sizeof(int));

    // Initialize the index of the array
    int index = 0;

    // Iterate through the numbers from 2 to num
    for (int i = 2; index < num; ++i) {
        // Check if the number is prime
        if (isPrime(i)) {
            // Add the prime number to the array
            primeNumbers[index++] = i;
        }
    }

    // Print the prime numbers
    printf("The prime numbers are: ");
    for (int i = 0; i < num; ++i) {
        printf("%d ", primeNumbers[i]);
    }

    // Free the memory allocated for the array
    free(primeNumbers);

    return 0;
}