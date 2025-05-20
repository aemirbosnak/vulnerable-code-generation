//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 10000
#define NUM_SEQUENCES 10
#define MAX_MUTATIONS 5

typedef struct {
    char *sequence;
    int length;
    int mutations[MAX_MUTATIONS];
} GenomeSequence;

void generate_random_sequence(char *sequence, int length) {
    const char *nucleotides = "ACGT";
    for (int i = 0; i < length; i++) {
        sequence[i] = nucleotides[rand() % 4];
    }
    sequence[length] = '\0'; // Null-terminate the string
}

void mutate_sequence(char *original, char *mutated, int length, int num_mutations) {
    strcpy(mutated, original); // Copy original sequence
    for (int i = 0; i < num_mutations; i++) {
        int pos = rand() % length; 
        mutated[pos] = "ACGT"[rand() % 4]; // Change to a random nucleotide
    }
}

void print_genome_info(GenomeSequence *genome) {
    printf("Genome Sequence: %s\n", genome->sequence);
    printf("Length: %d\n", genome->length);
    printf("Mutations Applied: ");
    for (int i = 0; i < MAX_MUTATIONS; i++) {
        if (genome->mutations[i] != -1) {
            printf("%d ", genome->mutations[i]);
        }
    }
    printf("\n\n");
}

void initialize_genome_sequence(GenomeSequence *genome) {
    genome->sequence = (char *)malloc(MAX_SEQUENCE_LENGTH + 1); // Allocate memory for sequence
    genome->length = rand() % MAX_SEQUENCE_LENGTH + 1; // Random length
    genome->mutations[0] = -1; // Initialize mutation array
}

void free_genome_sequence(GenomeSequence *genome) {
    free(genome->sequence); // Free allocated memory
}

int main() {
    srand(time(NULL)); // Seed random number generator
    GenomeSequence genomes[NUM_SEQUENCES];

    // Initialize and generate sequences
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        initialize_genome_sequence(&genomes[i]);
        generate_random_sequence(genomes[i].sequence, genomes[i].length);
        
        // Simulate mutations
        int num_mutations = rand() % MAX_MUTATIONS; // Random number of mutations
        genomes[i].mutations[0] = num_mutations; // Store number of mutations
        for (int j = 1; j <= num_mutations; j++) {
            genomes[i].mutations[j] = rand() % genomes[i].length; // Random mutation position
        }
        
        char mutated_sequence[MAX_SEQUENCE_LENGTH + 1];
        mutate_sequence(genomes[i].sequence, mutated_sequence, genomes[i].length, num_mutations);
        strcpy(genomes[i].sequence, mutated_sequence); // Overwrite original with mutated
        
        print_genome_info(&genomes[i]);
        free_genome_sequence(&genomes[i]); // Free memory after use
    }

    return 0;
}