//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the nucleotide bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of a read
#define MAX_READ_LENGTH 100

// Define the number of reads to generate
#define NUM_READS 1000

// Define the error rate
#define ERROR_RATE 0.01

// Generate a random nucleotide base
char generate_base() {
    // Generate a random number between 0 and 3
    int random_number = rand() % 4;

    // Return the corresponding nucleotide base
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
            return A;
    }
}

// Generate a random read
char *generate_read() {
    // Allocate memory for the read
    char *read = malloc(MAX_READ_LENGTH + 1);

    // Generate the read
    for (int i = 0; i < MAX_READ_LENGTH; i++) {
        // Generate a random nucleotide base
        char base = generate_base();

        // Add the base to the read
        read[i] = base;
    }

    // Terminate the read with a null character
    read[MAX_READ_LENGTH] = '\0';

    // Return the read
    return read;
}

// Introduce errors into a read
char *introduce_errors(char *read) {
    // Allocate memory for the read with errors
    char *read_with_errors = malloc(MAX_READ_LENGTH + 1);

    // Copy the read into the read with errors
    strcpy(read_with_errors, read);

    // Introduce errors into the read
    for (int i = 0; i < MAX_READ_LENGTH; i++) {
        // Generate a random number between 0 and 1
        double random_number = (double)rand() / (double)RAND_MAX;

        // If the random number is less than the error rate, then introduce an error
        if (random_number < ERROR_RATE) {
            // Generate a random nucleotide base
            char base = generate_base();

            // Replace the base in the read with the error base
            read_with_errors[i] = base;
        }
    }

    // Terminate the read with a null character
    read_with_errors[MAX_READ_LENGTH] = '\0';

    // Return the read with errors
    return read_with_errors;
}

// Write the reads to a file
void write_reads_to_file(char **reads, int num_reads, char *filename) {
    // Open the file
    FILE *file = fopen(filename, "w");

    // Write the reads to the file
    for (int i = 0; i < num_reads; i++) {
        fprintf(file, "%s\n", reads[i]);
    }

    // Close the file
    fclose(file);
}

// Main function
int main(int argc, char **argv) {
    // Generate the reads
    char **reads = malloc(NUM_READS * sizeof(char *));
    for (int i = 0; i < NUM_READS; i++) {
        reads[i] = generate_read();
    }

    // Introduce errors into the reads
    char **reads_with_errors = malloc(NUM_READS * sizeof(char *));
    for (int i = 0; i < NUM_READS; i++) {
        reads_with_errors[i] = introduce_errors(reads[i]);
    }

    // Write the reads to a file
    write_reads_to_file(reads_with_errors, NUM_READS, "reads.txt");

    // Free the memory allocated for the reads
    for (int i = 0; i < NUM_READS; i++) {
        free(reads[i]);
        free(reads_with_errors[i]);
    }
    free(reads);
    free(reads_with_errors);

    return 0;
}