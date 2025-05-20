//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void generatePrimes(int limit);
bool isPrime(int number);

int main() {
    int limit;
    
    printf("Enter the upper limit to generate prime numbers: ");
    scanf("%d", &limit);

    if (limit < 2) {
        printf("There are no prime numbers less than 2.\n");
        return 0;
    }

    printf("Prime numbers up to %d are:\n", limit);
    generatePrimes(limit);
    return 0;
}

void generatePrimes(int limit) {
    // Allocate memory for storing prime numbers
    bool *isPrimeArray = malloc((limit + 1) * sizeof(bool));
    
    // Initialize all entries as prime
    for (int i = 0; i <= limit; i++) {
        isPrimeArray[i] = true;
    }

    isPrimeArray[0] = isPrimeArray[1] = false; // 0 and 1 are not prime numbers

    // Sieve of Eratosthenes algorithm
    int sqrtLimit = (int)sqrt((double)limit);
    for (int num = 2; num <= sqrtLimit; num++) {
        if (isPrimeArray[num]) {
            for (int multiple = num * num; multiple <= limit; multiple += num) {
                isPrimeArray[multiple] = false;
            }
        }
    }

    // Print prime numbers
    for (int i = 2; i <= limit; i++) {
        if (isPrimeArray[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    // Free allocated memory
    free(isPrimeArray);
}

bool isPrime(int number) {
    if (number <= 1) return false;
    if (number <= 3) return true;

    if (number % 2 == 0 || number % 3 == 0) return false;

    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return false;
    }
    return true;
}