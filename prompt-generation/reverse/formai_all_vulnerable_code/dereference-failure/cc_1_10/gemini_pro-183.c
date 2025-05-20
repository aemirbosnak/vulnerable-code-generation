//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the DNA alphabet
#define ALPHABET_SIZE 4
char alphabet[] = {'A', 'C', 'G', 'T'};

// Define the maximum length of a DNA sequence
#define MAX_SEQUENCE_LENGTH 1000

// Define the number of reads to generate
#define NUM_READS 100

// Generate a random DNA sequence
char *generate_sequence(int length) {
    char *sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = alphabet[rand() % ALPHABET_SIZE];
    }
    sequence[length] = '\0';
    return sequence;
}

// Simulate the sequencing process
char **simulate_sequencing(char *sequence, int read_length) {
    // Calculate the number of reads needed to cover the sequence
    int num_reads = (int) ceil((double) strlen(sequence) / (double) read_length);

    // Allocate memory for the reads
    char **reads = malloc(num_reads * sizeof(char *));

    // Generate the reads
    for (int i = 0; i < num_reads; i++) {
        // Calculate the start position of the read
        int start_position = rand() % (strlen(sequence) - read_length + 1);

        // Extract the read from the sequence
        reads[i] = malloc(read_length + 1);
        strncpy(reads[i], sequence + start_position, read_length);
        reads[i][read_length] = '\0';
    }

    return reads;
}

// Print the reads
void print_reads(char **reads, int num_reads, int read_length) {
    for (int i = 0; i < num_reads; i++) {
        printf("%s\n", reads[i]);
    }
}

// Free the memory allocated for the reads
void free_reads(char **reads, int num_reads) {
    for (int i = 0; i < num_reads; i++) {
        free(reads[i]);
    }
    free(reads);
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random DNA sequence
    char *sequence = generate_sequence(MAX_SEQUENCE_LENGTH);

    // Simulate the sequencing process
    char **reads = simulate_sequencing(sequence, 100);

    // Print the reads
    print_reads(reads, NUM_READS, 100);

    // Free the memory allocated for the reads
    free_reads(reads, NUM_READS);

    // Free the memory allocated for the sequence
    free(sequence);

    return 0;
}