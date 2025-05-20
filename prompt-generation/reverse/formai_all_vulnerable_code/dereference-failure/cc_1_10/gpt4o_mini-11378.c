//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQUENCE_LENGTH 1000
#define NUM_SEQUENCES 5
#define MAX_MISMATCHES 5
#define MUTATION_RATE 0.1

char *generate_sequence(int length) {
    char *sequence = (char *)malloc(length + 1);
    const char *nucleotides = "ACGT";
    for (int i = 0; i < length; i++) {
        sequence[i] = nucleotides[rand() % 4];
    }
    sequence[length] = '\0'; // Null-terminate the string
    return sequence;
}

char mutate_nucleotide(char nucleotide) {
    const char *nucleotides = "ACGT";
    char mutated;
    do {
        mutated = nucleotides[rand() % 4];
    } while (mutated == nucleotide);
    return mutated;
}

char *simulate_mutation(char *original, float mutation_rate) {
    char *mutated_sequence = (char *)malloc(SEQUENCE_LENGTH + 1);
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        if ((float)rand() / RAND_MAX < mutation_rate) {
            mutated_sequence[i] = mutate_nucleotide(original[i]);
        } else {
            mutated_sequence[i] = original[i];
        }
    }
    mutated_sequence[SEQUENCE_LENGTH] = '\0';
    return mutated_sequence;
}

int count_mismatches(char *seq1, char *seq2) {
    int mismatches = 0;
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        if (seq1[i] != seq2[i]) {
            mismatches++;
        }
    }
    return mismatches;
}

void print_sequences(char **sequences) {
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        printf("Sequence %d: %s\n", i + 1, sequences[i]);
    }
}

void cleanup_sequences(char **sequences) {
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        free(sequences[i]);
    }
}

int main() {
    srand(time(NULL));

    char *original_sequence = generate_sequence(SEQUENCE_LENGTH);
    char *sequences[NUM_SEQUENCES];

    printf("Original Sequence: %s\n", original_sequence);

    for (int i = 0; i < NUM_SEQUENCES; i++) {
        sequences[i] = simulate_mutation(original_sequence, MUTATION_RATE);
    }

    print_sequences(sequences);

    for (int i = 0; i < NUM_SEQUENCES; i++) {
        int mismatches = count_mismatches(original_sequence, sequences[i]);
        printf("Sequence %d mismatches with original: %d\n", i + 1, mismatches);
    }

    cleanup_sequences(sequences);
    free(original_sequence);

    return 0;
}