//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000 // Maximum length of the genome sequence
#define RANDOM_BASE_LENGTH 50 // Number of random bases to insert in the genome sequence
#define MUTATION_PROBABILITY 0.02 // Probability of a base mutating during sequence replication

// Function to generate a random DNA base
char random_base() {
    int r = rand() % 4;
    switch (r) {
        case 0:
            return 'A';
            break;
        case 1:
            return 'C';
            break;
        case 2:
            return 'G';
            break;
        case 3:
            return 'T';
            break;
        default:
            return 'N';
            break;
    }
}

// Function to create a random genome sequence
char* generate_sequence(int length) {
    char* sequence = (char*) malloc((length + 1) * sizeof(char)); // Allocate space for the sequence
    for (int i = 0; i < length; i++) {
        sequence[i] = random_base();
    }
    sequence[length] = '\0';
    return sequence;
}

// Function to randomly insert bases into the genome sequence
void insert_random_bases(char* sequence) {
    for (int i = 0; i < RANDOM_BASE_LENGTH; i++) {
        int position = rand() % (strlen(sequence) + 1);
        char base = random_base();
        memmove(&sequence[position + 1], &sequence[position], strlen(sequence) - position + 1);
        sequence[position] = base;
    }
}

// Function to simulate replication of the genome sequence
void replicate_sequence(char* sequence) {
    int length = strlen(sequence);
    for (int i = 0; i < length; i++) {
        double r = (double) rand() / RAND_MAX;
        if (r < MUTATION_PROBABILITY) {
            sequence[i] = random_base();
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    char* genome_sequence = generate_sequence(MAX_SEQUENCE_LENGTH); // Generate the initial genome sequence
    printf("Initial sequence: %s\n", genome_sequence);
    insert_random_bases(genome_sequence); // Insert random bases into the genome sequence
    printf("Sequence with random bases: %s\n", genome_sequence);
    replicate_sequence(genome_sequence); // Replicate the genome sequence with possible mutations
    printf("Replicated sequence: %s\n", genome_sequence);
    free(genome_sequence); // Free the memory used by the genome sequence
    return 0;
}