//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
int isPrime(int num);
void generatePrimes(int limit);
void savePrimesToFile(int *primes, int count, const char *filename);
void displayMenu();
void clearBuffer();

int main() {
    int choice, limit;

    displayMenu();
    
    while (1) {
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                printf("Enter the limit up to which primes should be generated: ");
                scanf("%d", &limit);
                clearBuffer();
                generatePrimes(limit);
                break;

            case 2:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
}

// Function to display a whimsical menu
void displayMenu() {
    printf("****************************************\n");
    printf("*       Welcome to the Prime Wizard!   *\n");
    printf("****************************************\n");
    printf("* 1 - Generate Prime Numbers            *\n");
    printf("* 2 - Exit                               *\n");
    printf("****************************************\n");
}

// Function to clear the input buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) return 0; // 0 and 1 are not prime numbers
    if (num <= 3) return 1; // 2 and 3 are prime numbers
    if (num % 2 == 0 || num % 3 == 0) return 0; // eliminate multiples of 2 and 3
    
    // Check for factors from 5 to sqrt(num)
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}

// Function to generate prime numbers and save them to a file
void generatePrimes(int limit) {
    printf("Generating prime numbers up to %d...\n", limit);
    int *primes = (int *)malloc(limit * sizeof(int));
    int count = 0;

    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            primes[count++] = i;
            printf("Found prime: %d\n", i);
        }
    }

    if (count > 0) {
        savePrimesToFile(primes, count, "primes.txt");
        printf("Prime numbers saved to primes.txt file.\n");
    } else {
        printf("No prime numbers found up to %d.\n", limit);
    }

    free(primes);
}

// Function to save prime numbers to a file
void savePrimesToFile(int *primes, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for saving primes.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d\n", primes[i]);
    }
    
    fclose(file);
    printf("Successfully saved %d prime numbers to %s.\n", count, filename);
}