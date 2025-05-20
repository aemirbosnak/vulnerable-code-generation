//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime or not
bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate prime numbers
int* generate_primes(int num_primes, int min_prime, int max_prime) {
    int *primes = malloc(num_primes * sizeof(int));
    int count = 0;
    int current_prime = min_prime;

    // Generate prime numbers and add them to the array
    while (count < num_primes && current_prime <= max_prime) {
        if (is_prime(current_prime)) {
            primes[count] = current_prime;
            count++;
        }
        current_prime++;
    }

    return primes;
}

int main() {
    int num_primes, min_prime, max_prime;

    // Get user input for number of primes, minimum prime, and maximum prime
    printf("Enter the number of primes to generate: ");
    scanf("%d", &num_primes);
    printf("Enter the minimum prime number: ");
    scanf("%d", &min_prime);
    printf("Enter the maximum prime number: ");
    scanf("%d", &max_prime);

    // Generate and print prime numbers
    int *primes = generate_primes(num_primes, min_prime, max_prime);
    printf("The generated prime numbers are:\n");
    for (int i = 0; i < num_primes; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    // Free memory allocated for the array of prime numbers
    free(primes);

    return 0;
}