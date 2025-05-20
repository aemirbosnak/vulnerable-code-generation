//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEQUENCE_LENGTH 1000
#define MAX_MISMATCHES 10

// Structure to hold genome sequence and related metadata
typedef struct {
    char *sequence;
    int length;
    int mismatches;
} Genome;

// Function to generate a random nucleotide sequence
char random_nucleotide() {
    int rand_num = rand() % 4;
    switch (rand_num) {
        case 0: return 'A';
        case 1: return 'C';
        case 2: return 'G';
        case 3: return 'T';
        default: return 'A'; // should never reach here
    }
}

// Function to create a new Genome
Genome* create_genome(int length) {
    Genome *genome = malloc(sizeof(Genome));
    genome->length = length;
    genome->sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        genome->sequence[i] = random_nucleotide();
    }
    genome->sequence[length] = '\0'; // null-terminate the string
    genome->mismatches = 0;
    return genome;
}

// Function to mutate the genome with a specified number of mismatches
void mutate_genome(Genome *genome) {
    for (int i = 0; i < genome->length; i++) {
        if (genome->mismatches < MAX_MISMATCHES && (rand() % 10) < 2) { // chance of mutation
            char old_nucleotide = genome->sequence[i];
            char new_nucleotide;
            do {
                new_nucleotide = random_nucleotide();
            } while (new_nucleotide == old_nucleotide); // ensure a different nucleotide
            genome->sequence[i] = new_nucleotide;
            genome->mismatches++;
        }
    }
}

// Function to display the genome
void display_genome(Genome *genome) {
    printf("Genome Sequence: %s\n", genome->sequence);
    printf("Length: %d\n", genome->length);
    printf("Mismatches Introduced: %d\n", genome->mismatches);
}

// Function to clean up the genome
void cleanup_genome(Genome *genome) {
    free(genome->sequence);
    free(genome);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int length_of_genome = SEQUENCE_LENGTH;
    Genome *genome = create_genome(length_of_genome);
    printf("Original ");
    display_genome(genome);

    // Introduce mutations
    mutate_genome(genome);
    printf("Mutated ");
    display_genome(genome);

    // Clean up resources
    cleanup_genome(genome);
    return 0;
}