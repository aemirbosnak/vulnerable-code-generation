//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000
#define MAX_SEQUENCE_LENGTH 100
#define NUM_SEQUENCES 10

void generate_random_sequence(char *sequence, int length) {
    const char nucleotides[] = {'A', 'T', 'C', 'G'};
    for (int i = 0; i < length; i++) {
        sequence[i] = nucleotides[rand() % 4];
    }
    sequence[length] = '\0';
}

void mutate_sequence(char *sequence, int mutation_rate) {
    for (int i = 0; i < strlen(sequence); i++) {
        if (rand() % 100 < mutation_rate) {
            sequence[i] = "ATCG"[rand() % 4]; // Mutate to a random base
        }
    }
}

void simulate_genome_sequencing(char **sequences, int num_sequences, int mutation_rate) {
    for (int i = 0; i < num_sequences; i++) {
        printf("Original Sequence %d: %s\n", i+1, sequences[i]);
        mutate_sequence(sequences[i], mutation_rate);
        printf("Mutated Sequence %d: %s\n", i+1, sequences[i]);
    }
}

int main() {
    srand(time(NULL));
    char *sequences[NUM_SEQUENCES];

    // Generate random sequences of nucleotide
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        sequences[i] = (char *)malloc((MAX_SEQUENCE_LENGTH + 1) * sizeof(char));
        generate_random_sequence(sequences[i], MAX_SEQUENCE_LENGTH);
    }

    int mutation_rate;
    printf("Enter mutation rate (0-100): ");
    scanf("%d", &mutation_rate);
    
    if (mutation_rate < 0 || mutation_rate > 100) {
        fprintf(stderr, "Mutation rate must be between 0 and 100!\n");
        return 1;
    }

    printf("\nSimulating genome sequencing...\n");
    simulate_genome_sequencing(sequences, NUM_SEQUENCES, mutation_rate);

    // Free allocated memory
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        free(sequences[i]);
    }

    return 0;
}