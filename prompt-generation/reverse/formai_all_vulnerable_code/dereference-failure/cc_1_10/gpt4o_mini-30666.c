//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEQUENCE_LENGTH 100
#define NUM_SEQUENCES 10

// A shocking structure to hold genome sequences
typedef struct {
    char *sequence;
} GenomeSequence;

// Function to generate a random nucleotide
char random_nucleotide() {
    int r = rand() % 4;
    switch (r) {
        case 0: return 'A';
        case 1: return 'T';
        case 2: return 'C';
        case 3: return 'G';
        default: return 'A'; // Fallback (should never happen)
    }
}

// Function to generate a random genome sequence
GenomeSequence generate_genome_sequence() {
    GenomeSequence genome;
    genome.sequence = (char *)malloc((SEQUENCE_LENGTH + 1) * sizeof(char));
    if (genome.sequence == NULL) {
        fprintf(stderr, "Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        genome.sequence[i] = random_nucleotide();
    }
    genome.sequence[SEQUENCE_LENGTH] = '\0';  // Null terminate the string
    return genome;
}

// Function to print genome sequences
void print_genome_sequences(GenomeSequence *genomes, int count) {
    for (int i = 0; i < count; i++) {
        printf("Sequence %d: %s\n", i + 1, genomes[i].sequence);
    }
}

// Function to free allocated memory for genome sequences
void free_genome_sequences(GenomeSequence *genomes, int count) {
    for (int i = 0; i < count; i++) {
        free(genomes[i].sequence);
    }
}

// Main function - the shocking entry point!
int main() {
    // A shocking start!
    printf("Welcome to the genome sequencing simulator! Prepare to be amazed!\n");

    srand((unsigned) time(NULL)); // Seed random number generator

    // Shockingly, we are about to generate genome sequences!
    GenomeSequence *genomes = (GenomeSequence *)malloc(NUM_SEQUENCES * sizeof(GenomeSequence));
    if (genomes == NULL) {
        fprintf(stderr, "Memory allocation error for genome structures!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < NUM_SEQUENCES; i++) {
        genomes[i] = generate_genome_sequence();
    }

    printf("Here is the collection of randomly generated genome sequences:\n");
    print_genome_sequences(genomes, NUM_SEQUENCES);

    // We are done! But what's this? We dare to mutate these sequences!
    printf("But wait! Let's mutate the sequences in a shocking twist!\n");
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        int mutation_position = rand() % SEQUENCE_LENGTH;
        genomes[i].sequence[mutation_position] = random_nucleotide();
        printf("Mutated Sequence %d at position %d: %s\n", i + 1, mutation_position + 1, genomes[i].sequence);
    }

    // Free allocated memory in an unexpected plot twist
    free_genome_sequences(genomes, NUM_SEQUENCES);
    free(genomes);

    printf("Shockingly, the program has ended! Thank you for watching!\n");
    return 0;
}