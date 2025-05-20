//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int is_prime(int num) {
    if (num <= 1) return 0; // 0 and 1 are not prime numbers
    if (num <= 3) return 1; // 2 and 3 are prime numbers

    if (num % 2 == 0 || num % 3 == 0)
        return 0; // eliminate multiples of 2 and 3

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return 0; // Found a factor
    }
    return 1; // Number is prime
}

void generate_primes(int count) {
    if (count < 1) {
        printf("The count of prime numbers to generate must be at least 1.\n");
        return;
    }
    
    int found = 0;          // Counter for found prime numbers
    int num = 2;           // Starting number to check for primality
    
    while (found < count) {
        if (is_prime(num)) {
            printf("%d ", num);
            found++;
        }
        num++;
    }
    printf("\n"); // New line after printing primes
}

void display_usage() {
    printf("Usage: prime_generator <number_of_primes>\n");
    printf("Example: prime_generator 10\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_usage();
        exit(EXIT_FAILURE); // Exit if the argument is not valid
    }
    
    int num_primes = atoi(argv[1]); // Convert argument to integer
    
    if (num_primes <= 0) { 
        display_usage();
        exit(EXIT_FAILURE); // Exit if number is not positive
    }
    
    printf("Generating the first %d prime numbers:\n", num_primes);
    generate_primes(num_primes);
    
    return 0; // Successful execution
}