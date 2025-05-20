//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Nucleotide sequences
char nucleotides[] = {'A', 'C', 'G', 'T'};

// Function to generate a random nucleotide sequence
char generate_nucleotide() {
    return nucleotides[rand() % 4];
}

// Function to generate a random DNA sequence of a given length
char *generate_dna_sequence(int length) {
    char *sequence = malloc(length + 1);  // +1 for the null-terminator
    for (int i = 0; i < length; i++) {
        sequence[i] = generate_nucleotide();
    }
    sequence[length] = '\0';
    return sequence;
}

// Function to simulate the sequencing process
void simulate_sequencing(char *sequence, int read_length) {
    int start = 0;
    while (start + read_length <= strlen(sequence)) {
        // Generate a random read
        char *read = malloc(read_length + 1);
        for (int i = 0; i < read_length; i++) {
            read[i] = sequence[start + i];
        }
        read[read_length] = '\0';

        // Print the read
        printf("%s\n", read);

        // Move the starting position
        start += read_length;

        // Free the memory allocated for the read
        free(read);
    }
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random DNA sequence of length 1000
    char *sequence = generate_dna_sequence(1000);

    // Simulate the sequencing process with a read length of 100
    simulate_sequencing(sequence, 100);

    // Free the memory allocated for the sequence
    free(sequence);

    return 0;
}