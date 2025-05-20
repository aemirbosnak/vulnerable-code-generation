//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Nucleotide bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Sequence length
#define SEQ_LEN 1000

// Error probability
#define ERROR_PROB 0.01

// Random number generator
#define RAND_MAX 32767

// Generate a random nucleotide base
char gen_base() {
    int rand_num = rand() % 4;
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
            return 'N'; // Invalid base, should never occur
    }
}

// Generate a random DNA sequence
char *gen_sequence() {
    char *seq = malloc(SEQ_LEN + 1); // Include space for null terminator

    for (int i = 0; i < SEQ_LEN; i++) {
        seq[i] = gen_base();
    }

    seq[SEQ_LEN] = '\0';

    return seq;
}

// Introduce errors into a DNA sequence
char *introduce_errors(char *seq) {
    int num_errors = ERROR_PROB * SEQ_LEN;
    for (int i = 0; i < num_errors; i++) {
        int rand_pos = rand() % SEQ_LEN;
        seq[rand_pos] = gen_base(); // Replace with a random base
    }

    return seq;
}

// Print a DNA sequence
void print_sequence(char *seq) {
    printf("Generated DNA sequence: %s\n", seq);
}

int main() {
    // Set random seed
    srand(time(NULL));

    // Generate a random DNA sequence
    char *seq = gen_sequence();

    // Introduce errors into the sequence
    char *erroneous_seq = introduce_errors(seq);

    // Print the sequences
    print_sequence(seq);
    print_sequence(erroneous_seq);

    // Free allocated memory
    free(seq);
    free(erroneous_seq);

    return 0;
}