//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0)
            return false;
    }

    return true;
}

// Function to generate prime numbers up to n
void generatePrimes(int n) {
    printf("Prime numbers up to %d:\n", n);

    for (int i = 2; i <= n; i++) {
        if (isPrime(i))
            printf("%d ", i);
    }
    printf("\n");
}

// Function to print the array in a nice way
void printArray(int arr[], int size) {
    printf("\n[");
    for (int i = 0; i < size; i++) {
        if (i != 0)
            printf(", ");
        printf("%d", arr[i]);
    }
    printf("]\n");
}

// Function to generate a certain number of prime numbers using an array
void generatePrimesArray(int count) {
    int primes[count];
    int index = 0;

    printf("Generating %d prime numbers:\n", count);

    while (index < count) {
        int num = rand() % 100 + 1; // Generate a random number between 1 and 100

        if (isPrime(num)) {
            primes[index] = num;
            index++;
        }
    }

    printArray(primes, count);
}

int main() {
    int choice;
    int num;

    srand(time(NULL)); // Seed the random number generator

    printf("1. Generate prime numbers up to a given number.\n");
    printf("2. Generate a certain number of prime numbers.\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &num);
            generatePrimes(num);
            break;
        case 2:
            printf("Enter the number of prime numbers to generate: ");
            scanf("%d", &num);
            generatePrimesArray(num);
            break;
        default:
            printf("Invalid option.\n");
            break;
    }

    return 0;
}