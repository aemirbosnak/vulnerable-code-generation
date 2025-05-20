//FormAI DATASET v1.0 Category: Computer Biology ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define nucleotide bases
#define A 0
#define C 1
#define G 2
#define T 3

// Structure to hold a DNA sequence
typedef struct {
    int *nucleotides; // Array of nucleotides
    int length; // Length of the sequence
} DNA;

// Function to initialize a DNA sequence with random nucleotides
void initialize_sequence(DNA *dna_seq) {
    dna_seq->nucleotides = malloc(sizeof(int) * dna_seq->length);
    srand(time(NULL)); // Seed for random number generator
    for (int i = 0; i < dna_seq->length; i++) {
        int random_base = rand() % 4; // Generate a random nucleotide
        dna_seq->nucleotides[i] = random_base;
    }
}

// Function to calculate the GC content of a DNA sequence
float calculate_gc_content(DNA *dna_seq) {
    int gc_count = 0;
    for (int i = 0; i < dna_seq->length; i++) {
        if (dna_seq->nucleotides[i] == C || dna_seq->nucleotides[i] == G) {
            gc_count++;
        }
    }
    return (float) gc_count / dna_seq->length;
}

int main() {
    DNA dna_sequence; // Declare a DNA sequence
    dna_sequence.length = 100; // Set the length of the sequence
    initialize_sequence(&dna_sequence); // Initialize the sequence with random nucleotides
    float gc_content = calculate_gc_content(&dna_sequence); // Calculate the GC content of the sequence
    printf("DNA Sequence:\n");
    for (int i = 0; i < dna_sequence.length; i++) {
        switch(dna_sequence.nucleotides[i]) {
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
            default:
                printf("N");
                break;
        }
    }
    printf("\nGC Content: %f\n", gc_content);
    free(dna_sequence.nucleotides); // Free allocated memory
    return 0;
}