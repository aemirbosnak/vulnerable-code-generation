//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: scientific
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

// Function to check if a number is prime
bool is_prime(unsigned int n) {
    if (n <= 1) {
        return false;
    }
    for (unsigned int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate a prime number
unsigned int generate_prime(unsigned int limit) {
    unsigned int num = 0;
    // Generate a random number within the given limit
    num = rand() % limit + 1;
    // Check if the generated number is prime
    while (!is_prime(num)) {
        num = rand() % limit + 1;
    }
    return num;
}

// Function to print prime numbers up to a given limit
void print_primes(unsigned int limit) {
    unsigned int num = 0;
    printf("Prime numbers up to %d:\n", limit);
    for (unsigned int i = 2; i <= limit; i++) {
        num = i;
        // Check if the generated number is prime
        if (is_prime(num)) {
            printf("%d ", num);
        }
    }
    printf("\n");
}

int main() {
    unsigned int limit = 0;
    // Initialize random number generator
    srand(time(NULL));
    printf("Enter the limit to find prime numbers up to: ");
    scanf("%d", &limit);
    print_primes(limit);
    // Generate a prime number
    unsigned int prime_num = generate_prime(limit);
    printf("A random prime number generated is %d\n", prime_num);
    return 0;
}