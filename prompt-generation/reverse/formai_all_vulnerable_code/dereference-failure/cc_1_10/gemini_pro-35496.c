//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// DNA bases
char bases[] = {'A', 'C', 'G', 'T'};

// Generate a random DNA sequence of the given length
char *generate_dna(int length) {
    char *dna = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        dna[i] = bases[rand() % 4];
    }
    dna[length] = '\0';
    return dna;
}

// Simulate the Illumina sequencing process
char **illumina_sequencing(char *dna, int read_length) {
    // Generate a list of reads
    int num_reads = (strlen(dna) + read_length - 1) / read_length;
    char **reads = malloc(num_reads * sizeof(char *));
    for (int i = 0; i < num_reads; i++) {
        reads[i] = malloc(read_length + 1);
        strncpy(reads[i], dna + i * read_length, read_length);
        reads[i][read_length] = '\0';
    }

    // Add errors to the reads
    for (int i = 0; i < num_reads; i++) {
        for (int j = 0; j < read_length; j++) {
            if (rand() % 100 < 1) {
                reads[i][j] = bases[rand() % 4];
            }
        }
    }

    return reads;
}

// Assemble the reads into a consensus sequence
char *assemble_reads(char **reads, int num_reads, int read_length) {
    // Create a consensus sequence
    char *consensus = malloc(strlen(reads[0]) + 1);
    strcpy(consensus, reads[0]);

    // Iterate over the reads
    for (int i = 1; i < num_reads; i++) {
        // Find the overlaps between the consensus and the current read
        int overlap = 0;
        while (overlap < read_length && consensus[overlap] == reads[i][overlap]) {
            overlap++;
        }

        // Update the consensus with the current read
        if (overlap > 0) {
            for (int j = overlap; j < read_length; j++) {
                consensus[j] = reads[i][j];
            }
        }
    }

    return consensus;
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a DNA sequence
    char *dna = generate_dna(10000);

    // Simulate the Illumina sequencing process
    char **reads = illumina_sequencing(dna, 100);

    // Assemble the reads into a consensus sequence
    char *consensus = assemble_reads(reads, 100, 100);

    // Print the consensus sequence
    printf("%s\n", consensus);

    // Free the allocated memory
    free(dna);
    for (int i = 0; i < 100; i++) {
        free(reads[i]);
    }
    free(reads);
    free(consensus);

    return 0;
}