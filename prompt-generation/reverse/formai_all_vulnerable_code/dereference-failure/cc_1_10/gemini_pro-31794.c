//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scientific
// Simulating DNA Sequencing for C Programming - C Genome Sequencing Simulator

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Enumerating Nucleotides
typedef enum { A, C, G, T } Nucleotide;

// Binary Sequence Structure
typedef struct {
    unsigned int length;
    Nucleotide* sequence;
} BinarySequence;

// Random Number Generation Function
int random_int(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Function to Generate Random Nucleotides
Nucleotide random_nucleotide() {
    return random_int(A, T);
}

// Function to Generate a Random Binary Sequence
BinarySequence generate_random_sequence(int length) {
    BinarySequence sequence;
    sequence.length = length;
    sequence.sequence = malloc(sizeof(Nucleotide) * length);
    for (int i = 0; i < length; i++) {
        sequence.sequence[i] = random_nucleotide();
    }
    return sequence;
}

// Function to Print a Binary Sequence
void print_sequence(BinarySequence sequence) {
    for (int i = 0; i < sequence.length; i++) {
        switch (sequence.sequence[i]) {
            case A: printf("A"); break;
            case C: printf("C"); break;
            case G: printf("G"); break;
            case T: printf("T"); break;
        }
    }
    printf("\n");
}

// Simulator Parameters
#define SEQUENCE_LENGTH 1000
#define READ_LENGTH 100
#define COVERAGE 10

int main() {
    // Initialize the Random Number Generator
    srand(time(NULL));

    // Generate the Reference Genome
    BinarySequence reference = generate_random_sequence(SEQUENCE_LENGTH);
    printf("Reference Genome:\n");
    print_sequence(reference);

    // Simulate Sequencing Reads
    int num_reads = COVERAGE * SEQUENCE_LENGTH / READ_LENGTH;
    BinarySequence** reads = malloc(sizeof(BinarySequence*) * num_reads);
    for (int i = 0; i < num_reads; i++) {
        int start = random_int(0, SEQUENCE_LENGTH - READ_LENGTH);
        reads[i] = malloc(sizeof(BinarySequence));
        reads[i]->length = READ_LENGTH;
        reads[i]->sequence = malloc(sizeof(Nucleotide) * READ_LENGTH);
        for (int j = 0; j < READ_LENGTH; j++) {
            reads[i]->sequence[j] = reference.sequence[start + j];
        }
    }

    // Output Sequencing Reads
    printf("Sequencing Reads:\n");
    for (int i = 0; i < num_reads; i++) {
        print_sequence(*reads[i]);
    }

    return 0;
}