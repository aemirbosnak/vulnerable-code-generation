//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt((double)num); i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

// Function to generate prime numbers
int* generate_prime_numbers(int num_primes) {
    int* prime_numbers = (int*)malloc(sizeof(int) * num_primes);

    int count = 0;
    int candidate = 2;

    while (count < num_primes) {
        if (is_prime(candidate)) {
            prime_numbers[count] = candidate;
            count++;
        }

        candidate++;
    }

    return prime_numbers;
}

// Function to print an array of prime numbers
void print_prime_numbers(int* prime_numbers, int num_primes) {
    for (int i = 0; i < num_primes; i++) {
        printf("%d ", prime_numbers[i]);
    }

    printf("\n");
}

int main() {
    int num_primes;

    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &num_primes);

    int* prime_numbers = generate_prime_numbers(num_primes);

    printf("The first %d prime numbers are:\n", num_primes);
    print_prime_numbers(prime_numbers, num_primes);

    free(prime_numbers);

    return 0;
}