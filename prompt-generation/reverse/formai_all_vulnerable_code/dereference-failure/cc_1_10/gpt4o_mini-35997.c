//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_PRIME 10000

// Function to check if a number is prime
int is_prime(int number) {
    if (number <= 1) return 0;
    if (number <= 3) return 1;
    if (number % 2 == 0 || number % 3 == 0) return 0;
    
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return 0;
    }
    return 1;
}

// Function to generate and display prime numbers
void generate_primes(int limit) {
    printf("Cyberpunk Prime Number Generator\n");
    printf("================================\n");
    printf("Finding prime numbers up to %d...\n", limit);

    // Create a list to store prime numbers
    int *primes = malloc(sizeof(int) * limit);
    if (!primes) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    int prime_count = 0;
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            primes[prime_count++] = i;
            printf("#%03d: %d\n", prime_count, i);
            usleep(50000); // Simulate some delay for the cyberpunk vibe
        }
    }

    printf("Total prime numbers found: %d\n", prime_count);
    printf("Prime numbers stored in the dark web repository.\n");

    // Write primes to a file, simulating storage into the cyberpunk database
    FILE *db_file = fopen("cyberpunk_db.txt", "w");
    if (!db_file) {
        perror("Failed to open file");
        free(primes);
        exit(EXIT_FAILURE);
    }

    fprintf(db_file, "Cyberpunk Prime Numbers:\n");
    for (int i = 0; i < prime_count; i++) {
        fprintf(db_file, "%d\n", primes[i]);
    }

    fclose(db_file);
    printf("Prime numbers have been saved to the cyberpunk database.\n");

    // Clean up
    free(primes);
}

// Main function to execute the prime number generator
int main(int argc, char *argv[]) {
    // Handle command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <limit>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int limit = atoi(argv[1]);
    if (limit <= 0 || limit > MAX_PRIME) {
        fprintf(stderr, "Please enter a valid limit (1 - %d)\n", MAX_PRIME);
        return EXIT_FAILURE;
    }

    // Initialize the generator
    srand(time(NULL));
    printf("Initiating Cyberpunk Prime Generator...\n");
    usleep(1000000); // Wait 1 second for effect

    generate_primes(limit);

    printf("Process completed. Unravel more secrets in the shadows.\n");
    return EXIT_SUCCESS;
}