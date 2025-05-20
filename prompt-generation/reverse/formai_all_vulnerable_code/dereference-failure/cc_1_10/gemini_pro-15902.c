//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is prime
int isPrime(int n) {
    if (n <= 1) {
        return 0; // 1 and negative numbers are not prime
    } else if (n <= 3) {
        return 1; // 2 and 3 are prime
    } else if (n % 2 == 0 || n % 3 == 0) {
        return 0; // Even numbers and numbers divisible by 3 are not prime
    } else {
        int i = 5;
        while (i * i <= n) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return 0; // Number is divisible by a number other than 1 or itself
            }
            i += 6; // Increment i by 6 to check the next odd number
        }
        return 1; // Number is prime
    }
}

// Function to generate a list of prime numbers
int* generatePrimes(int n) {
    int* primes = malloc(sizeof(int) * n);
    int count = 0;
    int i = 2;
    while (count < n) {
        if (isPrime(i)) {
            primes[count] = i;
            count++;
        }
        i++;
    }
    return primes;
}

// Function to print a list of prime numbers
void printPrimes(int* primes, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);
    int* primes = generatePrimes(n);
    printf("The first %d prime numbers are: ", n);
    printPrimes(primes, n);
    free(primes);
    return 0;
}