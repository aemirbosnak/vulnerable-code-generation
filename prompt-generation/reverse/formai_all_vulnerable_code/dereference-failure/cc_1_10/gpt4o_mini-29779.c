//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEQUENCE_LENGTH 1000
#define NUM_SEQUENCES 10
#define BASES "ACGT"

void generate_random_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = BASES[rand() % 4];
    }
    sequence[length] = '\0';  // Null-terminate the string
}

void simulate_sequencing(char **sequences, int num_sequences, int length) {
    printf("Simulating genome sequencing...\n");
    for (int i = 0; i < num_sequences; i++) {
        printf("Sequence %d: %s\n", i + 1, sequences[i]);
    }
    printf("\nSequencing simulation complete.\n");
}

void introduce_mutations(char *sequence, int mutation_rate) {
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        if (rand() % 100 < mutation_rate) {
            sequence[i] = BASES[rand() % 4];  // Randomly change the base
        }
    }
}

void print_sequences(char **sequences, int num_sequences) {
    for (int i = 0; i < num_sequences; i++) {
        printf("Original Sequence %d: %s\n", i + 1, sequences[i]);
    }
}

void free_sequences(char **sequences, int num_sequences) {
    for (int i = 0; i < num_sequences; i++) {
        free(sequences[i]);
    }
    free(sequences);
}

int main() {
    srand(time(NULL));
    
    char **sequences = malloc(NUM_SEQUENCES * sizeof(char *));
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        sequences[i] = malloc((SEQUENCE_LENGTH + 1) * sizeof(char));
        generate_random_sequence(sequences[i], SEQUENCE_LENGTH);
    }

    printf("Generated DNA Sequences:\n");
    print_sequences(sequences, NUM_SEQUENCES);

    int mutation_rate = 5; // Percentage of mutations
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        introduce_mutations(sequences[i], mutation_rate);
    }

    printf("\nDNA Sequences After Mutation:\n");
    print_sequences(sequences, NUM_SEQUENCES);

    simulate_sequencing(sequences, NUM_SEQUENCES, SEQUENCE_LENGTH);

    free_sequences(sequences, NUM_SEQUENCES);

    return 0;
}