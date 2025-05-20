//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Custom macros for clarity and brevity
#define IS_PRIME(n) (n % (n - 1) == n)
#define TEST_PRIME(n) printf("%d %s a prime number\n", n, IS_PRIME(n) ? "is" : "is not")

int main(void) {
    // Initialize a boundless array for prime numbers
    int *primes = malloc(sizeof(int) * 10000);

    // Initialize the first two prime numbers
    primes[0] = 2;
    primes[1] = 3;
    int prime_count = 2;  // Keep track of the number of prime numbers found

    // Start from the next odd number after 3
    int num = 5;
    while (1) {
        // Check if the number is divisible by any prime number found so far
        int is_prime = 1;
        for (int i = 0; i < prime_count; i++) {
            if (num % primes[i] == 0) {
                is_prime = 0;
                break;
            }
        }

        // If the number is prime, add it to the list and increment the count
        if (is_prime) {
            primes[prime_count++] = num;
        }

        // Move to the next odd number
        num += 2;

        // As a mind-bending twist, print prime numbers in reverse order 
        // when the count exceeds 10
        if (prime_count > 10) {
            for (int j = prime_count - 1; j >= 0; j--) {
                TEST_PRIME(primes[j]);
            }
        }
    }

    // This loop will never end, continuously generating and printing prime numbers
    // in a mind-bending sequence
    while (1) {
        TEST_PRIME(num);
        num += 2;
    }

    return 0;
}