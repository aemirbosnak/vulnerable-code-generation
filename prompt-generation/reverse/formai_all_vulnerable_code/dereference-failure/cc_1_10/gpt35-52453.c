//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEQUENCE_LENGTH 1000
#define MUTATION_RATE 0.1

/* Returns a random nucleotide (A,C,G,T) */
char randomNucleotide() {
    int num = rand() % 4;
    if (num == 0) return 'A';
    if (num == 1) return 'C';
    if (num == 2) return 'G';
    if (num == 3) return 'T';
    return 'X'; // Error case
}

/* Generates a random DNA sequence of specified length */
char* generateSequence(int length) {
    char* sequence = malloc((length+1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        sequence[i] = randomNucleotide();
    }
    sequence[length] = '\0';
    return sequence;
}

/* Prints a DNA sequence */
void printSequence(char* sequence) {
    printf("%s\n", sequence);
}

/* Mutates DNA sequence with specified mutation rate */
void mutateSequence(char* sequence, double mutationRate) {
    for (int i = 0; i < strlen(sequence); i++) {
        double mutationChance = ((double) rand() / (RAND_MAX));
        if (mutationChance < mutationRate) {
            sequence[i] = randomNucleotide();
        }
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generator

    char* originalSequence = generateSequence(SEQUENCE_LENGTH);
    printf("Original sequence:\n");
    printSequence(originalSequence);

    char* mutatedSequence = malloc((SEQUENCE_LENGTH+1) * sizeof(char));
    strcpy(mutatedSequence, originalSequence);
    mutateSequence(mutatedSequence, MUTATION_RATE);
    printf("\nMutated sequence:\n");
    printSequence(mutatedSequence);

    // Free memory allocated for sequences
    free(originalSequence);
    free(mutatedSequence);

    return 0;
}