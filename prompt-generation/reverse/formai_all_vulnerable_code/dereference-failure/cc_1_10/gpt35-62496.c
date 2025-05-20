//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the DNA alphabet
const char* DNA_ALPHABET = "ATGC";

// Define the length of DNA sequence to generate
#define SEQ_LENGTH 100

// Define the probability of each base appearing
#define A_PROB 0.25
#define T_PROB 0.25
#define G_PROB 0.25
#define C_PROB 0.25

// Function to generate a random base according to given probabilities
char get_random_base() {
    double r = (double)rand() / RAND_MAX;
    if (r < A_PROB) {
        return 'A';
    } else if (r < A_PROB + T_PROB) {
        return 'T';
    } else if (r < A_PROB + T_PROB + G_PROB) {
        return 'G';
    } else {
        return 'C';
    }
}

// Function to generate a random DNA sequence of given length
char* generate_dna_sequence(int seq_length) {
    char* dna_seq = (char*)malloc(seq_length + 1);
    for (int i = 0; i < seq_length; i++) {
        dna_seq[i] = get_random_base();
    }
    dna_seq[seq_length] = '\0';
    return dna_seq;
}

// Function to print a DNA sequence
void print_dna_sequence(char* dna_seq) {
    printf("%s\n", dna_seq);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate a random DNA sequence
    char* dna_seq = generate_dna_sequence(SEQ_LENGTH);
    
    // Print the DNA sequence
    printf("DNA Sequence:\n");
    print_dna_sequence(dna_seq);
    
    // Free memory
    free(dna_seq);
    
    return 0;
}