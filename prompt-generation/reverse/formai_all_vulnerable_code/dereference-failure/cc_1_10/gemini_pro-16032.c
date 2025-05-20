//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Define the nucleotide bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of a read
#define MAX_READ_LENGTH 100

// Define the probability of a sequencing error
#define ERROR_PROBABILITY 0.01

// Generate a random nucleotide base
char generate_base() {
    // Generate a random number between 0 and 3
    int base_index = rand() % 4;

    // Return the corresponding nucleotide base
    switch (base_index) {
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

// Generate a random read of a given length
char *generate_read(int length) {
    // Allocate memory for the read
    char *read = malloc(length + 1);

    // Generate each base in the read
    for (int i = 0; i < length; i++) {
        // Generate a random nucleotide base
        char base = generate_base();

        // Simulate a sequencing error with a probability of ERROR_PROBABILITY
        if (rand() / (double)RAND_MAX < ERROR_PROBABILITY) {
            // Generate a random error base
            do {
                base = generate_base();
            } while (base == read[i]);
        }

        // Add the base to the read
        read[i] = base;
    }

    // Add the null terminator to the end of the read
    read[length] = '\0';

    // Return the read
    return read;
}

// Generate a set of reads from a given genome
char **generate_reads(char *genome, int num_reads, int read_length) {
    // Allocate memory for the reads
    char **reads = malloc(num_reads * sizeof(char *));

    // Generate each read
    for (int i = 0; i < num_reads; i++) {
        // Generate a random start position for the read
        int start_position = rand() % (strlen(genome) - read_length + 1);

        // Generate the read
        char *read = generate_read(read_length);

        // Copy the read into the reads array
        reads[i] = read;
    }

    // Return the reads
    return reads;
}

// Print the reads to a file
void print_reads(char **reads, int num_reads, int read_length, char *filename) {
    // Open the file
    FILE *file = fopen(filename, "w");

    // Print each read to the file
    for (int i = 0; i < num_reads; i++) {
        fprintf(file, "%s\n", reads[i]);
    }

    // Close the file
    fclose(file);
}

// Free the memory allocated for the reads
void free_reads(char **reads, int num_reads) {
    // Free each read
    for (int i = 0; i < num_reads; i++) {
        free(reads[i]);
    }

    // Free the reads array
    free(reads);
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Define the genome
    char genome[] = "ACGTACGTACGT";

    // Generate a set of reads from the genome
    int num_reads = 1000;
    int read_length = 100;
    char **reads = generate_reads(genome, num_reads, read_length);

    // Print the reads to a file
    char *filename = "reads.txt";
    print_reads(reads, num_reads, read_length, filename);

    // Free the memory allocated for the reads
    free_reads(reads, num_reads);

    return 0;
}