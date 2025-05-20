//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the possible nucleotides
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of a read
#define MAX_READ_LENGTH 100

// Define the number of reads to generate
#define NUM_READS 1000

// Define the probability of a sequencing error
#define ERROR_PROBABILITY 0.01

// Function to generate a random nucleotide
char generate_nucleotide() {
    // Generate a random number between 0 and 3
    int rand_num = rand() % 4;

    // Return the corresponding nucleotide
    switch (rand_num) {
        case 0:
            return A;
        case 1:
            return C;
        case 2:
            return G;
        case 3:
            return T;
        default:
            return 'N'; // This should never happen
    }
}

// Function to generate a random read
char* generate_read() {
    // Allocate memory for the read
    char* read = malloc(MAX_READ_LENGTH + 1);

    // Generate the read
    for (int i = 0; i < MAX_READ_LENGTH; i++) {
        // Generate a random nucleotide
        char nucleotide = generate_nucleotide();

        // Introduce a sequencing error with probability ERROR_PROBABILITY
        if (rand() < ERROR_PROBABILITY * RAND_MAX) {
            // Generate a random nucleotide to replace the original nucleotide
            nucleotide = generate_nucleotide();
        }

        // Add the nucleotide to the read
        read[i] = nucleotide;
    }

    // Null-terminate the read
    read[MAX_READ_LENGTH] = '\0';

    // Return the read
    return read;
}

// Function to generate a set of reads
char** generate_reads(int num_reads) {
    // Allocate memory for the set of reads
    char** reads = malloc(num_reads * sizeof(char*));

    // Generate each read
    for (int i = 0; i < num_reads; i++) {
        // Generate a random read
        reads[i] = generate_read();
    }

    // Return the set of reads
    return reads;
}

// Function to print a set of reads
void print_reads(char** reads, int num_reads) {
    // Print each read
    for (int i = 0; i < num_reads; i++) {
        printf("%s\n", reads[i]);
    }
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a set of reads
    char** reads = generate_reads(NUM_READS);

    // Print the set of reads
    print_reads(reads, NUM_READS);

    // Free the memory allocated for the reads
    for (int i = 0; i < NUM_READS; i++) {
        free(reads[i]);
    }
    free(reads);

    return 0;
}