//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// A prime number is a natural number greater than 1 that is not a product of two smaller natural numbers.

// A prime number is a natural number greater than 1 that is not a product of two smaller natural numbers.

// Write a C program to generate prime numbers using the Sieve of Eratosthenes algorithm.

// The Sieve of Eratosthenes is an ancient algorithm for finding all prime numbers up to a given limit. 
// It does so by iteratively marking as composite (i.e., not prime) the multiples of each prime, 
// starting with the first prime number, 2.

// The algorithm maintains a boolean array, where the index of each element represents a natural number, 
// and the value of each element represents whether the number is prime or not. 
// Initially, all elements are set to true, indicating that all numbers are prime. 

// The algorithm then iterates over the elements of the array, 
// starting with the first prime number, 2. 
// For each prime number, it marks all multiples of that number as composite.

// The algorithm continues until all elements of the array have been processed. 
// The elements that remain set to true are the prime numbers up to the given limit.

// Input:
// An integer n, representing the upper limit for finding prime numbers

// Output:
// A list of all prime numbers up to the given limit

int main() {
    int n;
    // Get the upper limit from the user
    printf("Enter the upper limit for finding prime numbers: ");
    scanf("%d", &n);

    // Create a boolean array to mark numbers as prime or composite
    bool *isPrime = (bool *)calloc(n + 1, sizeof(bool));
    assert(isPrime != NULL);

    // Initialize all elements to true, indicating that all numbers are prime
    for (int i = 0; i <= n; i++) {
        isPrime[i] = true;
    }

    // Iterate over the elements of the array, starting with the first prime number, 2
    for (int i = 2; i <= n; i++) {
        // If the current number is prime, mark all multiples of it as composite
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Print the list of prime numbers
    printf("The list of prime numbers up to %d is: ", n);
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    // Free the allocated memory
    free(isPrime);

    return 0;
}