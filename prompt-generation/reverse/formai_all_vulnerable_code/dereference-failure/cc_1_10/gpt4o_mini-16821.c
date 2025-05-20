//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LIMIT 1000

// Function prototypes
void greetUser();
void displayUsage();
void generatePrimes(int upperLimit);
bool isPrime(int number);
void printPrimes(int *primes, int count);

// Main function
int main() {
    int upperLimit;
    greetUser();
    displayUsage();

    printf("Enter the upper limit for prime number generation (greater than 1): ");
    scanf("%d", &upperLimit);

    if (upperLimit < 2) {
        printf("Please enter a number greater than 1.\n");
        return 1;
    }

    generatePrimes(upperLimit);
    return 0;
}

// Function to greet the user
void greetUser() {
    printf("*******************************************\n");
    printf("*            Prime Number Generator       *\n");
    printf("*                by Retro C               *\n");
    printf("*******************************************\n");
    printf("\nWelcome, friend! Let's generate some primes!\n\n");
}

// Function to display program usage
void displayUsage() {
    printf("Usage: Enter a number greater than 1 as the upper limit.\n");
    printf("This program will list all prime numbers up to that limit.\n");
}

// Function to generate primes up to a specified limit
void generatePrimes(int upperLimit) {
    int *primes = (int *)malloc(sizeof(int) * upperLimit);
    int count = 0;

    for (int num = 2; num <= upperLimit; num++) {
        if (isPrime(num)) {
            primes[count] = num;
            count++;
        }
    }

    printPrimes(primes, count);
    free(primes); // Freeing allocated memory
}

// Function to check if a number is prime
bool isPrime(int number) {
    if (number < 2) return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0)
            return false;
    }
    return true;
}

// Function to print the generated primes
void printPrimes(int *primes, int count) {
    printf("\nThe prime numbers up to your limit are:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
        if ((i + 1) % 10 == 0) // Newline every 10 numbers
            printf("\n");
    }
    printf("\nTotal prime numbers found: %d\n", count);
}