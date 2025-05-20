//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is prime
int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a list of prime numbers
int* generatePrimeNumbers(int n) {
    int* primeNumbers = (int*)malloc(n * sizeof(int));
    int count = 0;
    while (count < n) {
        int randomNumber = generateRandomNumber(1, 1000);
        if (isPrime(randomNumber)) {
            primeNumbers[count] = randomNumber;
            count++;
        }
    }
    return primeNumbers;
}

// Function to print a list of prime numbers
void printPrimeNumbers(int* primeNumbers, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", primeNumbers[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);

    int* primeNumbers = generatePrimeNumbers(n);
    printPrimeNumbers(primeNumbers, n);

    free(primeNumbers);
    return 0;
}