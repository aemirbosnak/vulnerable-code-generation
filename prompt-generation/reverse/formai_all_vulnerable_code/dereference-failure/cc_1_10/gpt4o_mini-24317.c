//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_NUM 10000

// Function prototype declarations
void generate_primes(int limit);
void print_primes(int primeArray[], int count);
bool is_prime(int num);

int main() {
    int limit;

    printf("Enter the upper limit to generate prime numbers (up to %d): ", MAX_NUM);
    scanf("%d", &limit);

    if (limit < 1 || limit > MAX_NUM) {
        printf("Please enter a number between 1 and %d.\n", MAX_NUM);
        return 1;
    }

    generate_primes(limit);

    return 0;
}

// Function to generate prime numbers up to a specified limit
void generate_primes(int limit) {
    int *primeArray = malloc(limit * sizeof(int));
    int count = 0;

    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            primeArray[count++] = num;
        }
    }

    print_primes(primeArray, count);
    free(primeArray);
}

// Function to check if a number is prime
bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to print prime numbers
void print_primes(int primeArray[], int count) {
    printf("Prime numbers up to the specified limit:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primeArray[i]);
    }
    printf("\n");
}