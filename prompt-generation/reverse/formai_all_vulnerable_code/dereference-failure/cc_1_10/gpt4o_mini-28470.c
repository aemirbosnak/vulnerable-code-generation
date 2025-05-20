//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEQUENCE_LENGTH 100
#define ERROR_RATE 0.02
#define NUM_GENOMES 5

const char nucleotides[4] = {'A', 'C', 'G', 'T'};

char random_nucleotide() {
    return nucleotides[rand() % 4];
}

void generate_sequence(char *sequence) {
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        sequence[i] = random_nucleotide();
    }
    sequence[SEQUENCE_LENGTH] = '\0';
}

void introduce_errors(char *sequence) {
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        if ((double)rand() / RAND_MAX < ERROR_RATE) {
            sequence[i] = random_nucleotide();
        }
    }
}

void print_sequence(const char *sequence, const char *label) {
    printf("%s: %s\n", label, sequence);
}

int main() {
    srand(time(NULL));  // Seed the random number generator

    char **genomes = malloc(NUM_GENOMES * sizeof(char *));
    for (int i = 0; i < NUM_GENOMES; i++) {
        genomes[i] = malloc((SEQUENCE_LENGTH + 1) * sizeof(char));
        generate_sequence(genomes[i]);
        introduce_errors(genomes[i]);
        char label[20];
        snprintf(label, sizeof(label), "Genome %d", i + 1);
        print_sequence(genomes[i], label);
    }

    for (int i = 0; i < NUM_GENOMES; i++) {
        free(genomes[i]);
    }
    free(genomes);

    return 0;
}