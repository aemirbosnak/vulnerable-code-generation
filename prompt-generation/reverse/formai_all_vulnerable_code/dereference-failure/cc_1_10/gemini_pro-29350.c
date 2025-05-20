//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define BASE_COUNT 4
#define MAX_SEQUENCE_LENGTH 10000

// Base types
typedef enum {
    A,
    C,
    G,
    T
} Base;

// Sequence type
typedef struct {
    Base* bases;
    int length;
} Sequence;

// Prototypes
Sequence* generate_sequence(int length);
void print_sequence(Sequence* sequence);
void free_sequence(Sequence* sequence);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random sequence of length 10000
    Sequence* sequence = generate_sequence(MAX_SEQUENCE_LENGTH);

    // Print the sequence
    printf("Generated sequence:\n");
    print_sequence(sequence);

    // Free the sequence
    free_sequence(sequence);

    return 0;
}

// Generates a random sequence of length 'length'
Sequence* generate_sequence(int length) {
    // Allocate memory for the sequence
    Sequence* sequence = malloc(sizeof(Sequence));
    sequence->bases = malloc(sizeof(Base) * length);
    sequence->length = length;

    // Generate a random sequence of bases
    for (int i = 0; i < length; i++) {
        sequence->bases[i] = rand() % BASE_COUNT;
    }

    return sequence;
}

// Prints the sequence to the console
void print_sequence(Sequence* sequence) {
    for (int i = 0; i < sequence->length; i++) {
        switch (sequence->bases[i]) {
            case A:
                printf("A");
                break;
            case C:
                printf("C");
                break;
            case G:
                printf("G");
                break;
            case T:
                printf("T");
                break;
        }
    }
    printf("\n");
}

// Frees the memory allocated for the sequence
void free_sequence(Sequence* sequence) {
    free(sequence->bases);
    free(sequence);
}