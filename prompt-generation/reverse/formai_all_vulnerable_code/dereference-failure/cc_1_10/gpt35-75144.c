//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* sequence;
    int length;
} DNASequence;

// Function to generate a random DNA sequence of given length
DNASequence generateRandomSequence(int length) {
    DNASequence seq;
    seq.sequence = malloc(length + 1); // Allocate memory for sequence
    seq.length = length;
    int i;
    for (i = 0; i < length; i++) {
        // Assign a random nucleotide (A, C, T, or G)
        seq.sequence[i] = "ACTG"[rand() % 4];
    }
    seq.sequence[length] = '\0'; // End sequence with null character
    return seq;
}

// Function to print a DNA sequence
void printSequence(DNASequence seq) {
    printf("%s\n", seq.sequence);
}

// Function to compare two DNA sequences
int compareSequences(DNASequence seq1, DNASequence seq2) {
    if (seq1.length != seq2.length) {
        return 0; // Sequences are different lengths
    }
    int i;
    for (i = 0; i < seq1.length; i++) {
        if (seq1.sequence[i] != seq2.sequence[i]) {
            return 0; // Sequences have different nucleotides at this position
        }
    }
    return 1; // Sequences are identical
}

int main() {
    // Generate three random DNA sequences
    DNASequence seq1 = generateRandomSequence(10);
    DNASequence seq2 = generateRandomSequence(7);
    DNASequence seq3 = generateRandomSequence(15);
    
    // Print the sequences
    printf("Sequence 1:\n");
    printSequence(seq1);
    printf("Sequence 2:\n");
    printSequence(seq2);
    printf("Sequence 3:\n");
    printSequence(seq3);
    
    // Compare sequences
    printf("Sequence 1 is %s to sequence 2\n", compareSequences(seq1, seq2) ? "identical" : "different");
    printf("Sequence 1 is %s to sequence 3\n", compareSequences(seq1, seq3) ? "identical" : "different");
    
    // Free memory
    free(seq1.sequence);
    free(seq2.sequence);
    free(seq3.sequence);
    
    return 0;
}