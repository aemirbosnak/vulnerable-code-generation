//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the nucleotide bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of a read
#define MAX_READ_LENGTH 100

// Define the number of reads to generate
#define NUM_READS 100000

// Define the error rate
#define ERROR_RATE 0.01

// Define the function to generate a random nucleotide base
char generate_random_base() {
    int random_number = rand() % 4;
    switch (random_number) {
        case 0:
            return A;
        case 1:
            return C;
        case 2:
            return G;
        case 3:
            return T;
        default:
            return 'N';
    }
}

// Define the function to generate a random read
char *generate_random_read() {
    // Allocate memory for the read
    char *read = malloc(MAX_READ_LENGTH + 1);

    // Generate the read
    for (int i = 0; i < MAX_READ_LENGTH; i++) {
        read[i] = generate_random_base();
    }

    // Add the null terminator
    read[MAX_READ_LENGTH] = '\0';

    // Return the read
    return read;
}

// Define the function to introduce errors into a read
char *introduce_errors(char *read) {
    // Allocate memory for the new read
    char *new_read = malloc(MAX_READ_LENGTH + 1);

    // Copy the read into the new read
    strcpy(new_read, read);

    // Introduce errors into the read
    for (int i = 0; i < MAX_READ_LENGTH; i++) {
        if (rand() < ERROR_RATE) {
            new_read[i] = generate_random_base();
        }
    }

    // Return the new read
    return new_read;
}

// Define the main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Open the output file
    FILE *output_file = fopen("reads.fasta", "w");

    // Generate the reads
    for (int i = 0; i < NUM_READS; i++) {
        // Generate a random read
        char *read = generate_random_read();

        // Introduce errors into the read
        char *new_read = introduce_errors(read);

        // Write the read to the output file
        fprintf(output_file, ">read%d\n%s\n", i, new_read);

        // Free the memory allocated for the read
        free(read);
        free(new_read);
    }

    // Close the output file
    fclose(output_file);

    return 0;
}