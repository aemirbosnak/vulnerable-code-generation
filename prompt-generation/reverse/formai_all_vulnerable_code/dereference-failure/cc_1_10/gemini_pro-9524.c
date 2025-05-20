//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate a prime number between 1 and n
int generate_prime(int n) {
    int prime = 2;
    while (!is_prime(prime)) {
        prime++;
    }
    while (prime <= n) {
        if (is_prime(prime)) {
            return prime;
        }
        prime += 2;
    }
    return -1;
}

// Function to generate a list of prime numbers between 1 and n
int* generate_prime_list(int n, int* length) {
    int* primes = (int*)malloc(n * sizeof(int));
    int count = 0;
    int prime = 2;
    while (prime <= n) {
        if (is_prime(prime)) {
            primes[count++] = prime;
        }
        prime += 2;
    }
    *length = count;
    return primes;
}

// Function to print a list of prime numbers
void print_prime_list(int* primes, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("The smallest prime number greater than or equal to %d is %d\n", n, generate_prime(n));
    int length;
    int* primes = generate_prime_list(n, &length);
    printf("The list of prime numbers between 1 and %d is:\n", n);
    print_prime_list(primes, length);
    free(primes);
    return 0;
}