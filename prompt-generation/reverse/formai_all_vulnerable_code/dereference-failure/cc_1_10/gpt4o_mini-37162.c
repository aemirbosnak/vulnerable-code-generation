//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEQUENCE_LENGTH 1000
#define NUM_SEQUENCES 10

const char nucleotides[] = {'A', 'C', 'G', 'T'};

void generate_random_sequence(char *sequence, size_t length) {
    for (size_t i = 0; i < length; i++) {
        sequence[i] = nucleotides[rand() % 4];
    }
    sequence[length] = '\0'; // Null-terminate the string
}

void simulate_genome_sequencing(char **sequences, size_t num_sequences, size_t sequence_length) {
    printf("Simulated Genome Sequencing...\n\n");
    for (size_t i = 0; i < num_sequences; i++) {
        printf("Sequence %zu: %s\n", i + 1, sequences[i]);
    }
}

void free_sequences(char **sequences, size_t num_sequences) {
    for (size_t i = 0; i < num_sequences; i++) {
        free(sequences[i]);
    }
    free(sequences);
}

char** allocate_sequences(size_t num_sequences, size_t sequence_length) {
    char **sequences = malloc(num_sequences * sizeof(char *));
    for (size_t i = 0; i < num_sequences; i++) {
        sequences[i] = malloc((sequence_length + 1) * sizeof(char)); // +1 for null-terminator
    }
    return sequences;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    char **sequences = allocate_sequences(NUM_SEQUENCES, SEQUENCE_LENGTH);
    
    for (size_t i = 0; i < NUM_SEQUENCES; i++) {
        generate_random_sequence(sequences[i], SEQUENCE_LENGTH);
    }

    simulate_genome_sequencing(sequences, NUM_SEQUENCES, SEQUENCE_LENGTH);
    
    free_sequences(sequences, NUM_SEQUENCES);
    return 0;
}