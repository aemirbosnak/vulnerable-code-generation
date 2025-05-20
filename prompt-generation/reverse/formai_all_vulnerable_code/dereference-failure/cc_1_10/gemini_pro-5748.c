//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the nucleotide characters
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the sequence length
#define SEQ_LEN 100

// Define the number of sequences to generate
#define NUM_SEQ 10

// Function to generate a random nucleotide
char random_nucleotide() {
    int r = rand() % 4;
    switch (r) {
        case 0:
            return A;
        case 1:
            return C;
        case 2:
            return G;
        case 3:
            return T;
    }
}

// Function to generate a random sequence
char* random_sequence() {
    char* seq = malloc(SEQ_LEN + 1);
    for (int i = 0; i < SEQ_LEN; i++) {
        seq[i] = random_nucleotide();
    }
    seq[SEQ_LEN] = '\0';
    return seq;
}

// Function to write sequences to a file
void write_sequences(char** seqs, int num_seqs, char* filename) {
    FILE* fp = fopen(filename, "w");
    for (int i = 0; i < num_seqs; i++) {
        fprintf(fp, "%s\n", seqs[i]);
    }
    fclose(fp);
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate sequences
    char** seqs = malloc(NUM_SEQ * sizeof(char*));
    for (int i = 0; i < NUM_SEQ; i++) {
        seqs[i] = random_sequence();
    }

    // Write sequences to a file
    write_sequences(seqs, NUM_SEQ, "sequences.txt");

    // Free memory
    for (int i = 0; i < NUM_SEQ; i++) {
        free(seqs[i]);
    }
    free(seqs);

    return 0;
}