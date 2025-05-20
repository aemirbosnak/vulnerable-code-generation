//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generateRandSeq(char*, int);
void printDNAStrand(char*, int, int);

int main() {
    int length = 100; // Length of sequence to be generated
    char *seq = (char*) malloc(sizeof(char) * (length+1)); // Allocate memory for sequence
    int i, j, k; // Loop iterators
    int numSeqs = 5; // Number of sequences to be generated
    char **seqs = (char**) malloc(sizeof(char*) * numSeqs); // Allocate memory for array of sequences

    // Initialize random number generator
    srand(time(0));
    
    // Generate random sequences
    for (i = 0; i < numSeqs; i++) {
        // Generate sequence
        generateRandSeq(seq, length);
        // Allocate memory for sequence
        seqs[i] = (char*) malloc(sizeof(char) * (length+1));
        // Copy sequence to array
        for (j = 0; j < length; j++) {
            seqs[i][j] = seq[j];
        }
        // Add null terminator
        seqs[i][length] = '\0';
        // Print sequence
        printDNAStrand(seqs[i], length, i);
    }

    // Free memory
    free(seq);
    for (i = 0; i < numSeqs; i++) {
        free(seqs[i]);
    }
    free(seqs);

    return 0;
}

// Generates a random DNA sequence of given length
void generateRandSeq(char *seq, int length) {
    int i; // Loop iterator

    for (i = 0; i < length; i++) {
        // Generate random nucleotide and add to sequence
        switch (rand() % 4) {
            case 0: // Adenine
                seq[i] = 'A';
                break;
            case 1: // Thymine
                seq[i] = 'T';
                break;
            case 2: // Cytosine
                seq[i] = 'C';
                break;
            case 3: // Guanine
                seq[i] = 'G';
                break;
        }
    }
}

// Prints a DNA strand with optional label
void printDNAStrand(char *seq, int length, int index) {
    int i; // Loop iterator

    if (index >= 0) {
        printf("Sequence %d: ", index+1);
    }
    for (i = 0; i < length; i++) {
        printf("%c", seq[i]);
    }
    printf("\n");
}