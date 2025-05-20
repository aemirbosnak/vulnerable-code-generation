//Falcon2-11B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 10000
#define MAX_CHARS_PER_SEQUENCE 4

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} Sequence;

typedef struct {
    char chr[MAX_CHARS_PER_SEQUENCE];
    int frequency;
} Chromosome;

int main() {
    Sequence* sequences = (Sequence*)malloc(MAX_SEQUENCE_LENGTH * sizeof(Sequence));
    Chromosome* chromosomes = (Chromosome*)malloc(MAX_CHARS_PER_SEQUENCE * sizeof(Chromosome));

    int num_sequences = 0;
    int num_chromosomes = 0;

    // Generate random sequences
    srand(time(NULL));
    for (int i = 0; i < MAX_SEQUENCE_LENGTH; i++) {
        sequences[i].sequence[i] = 'A' + rand() % 25;
        sequences[i].length++;
    }

    // Generate random chromosomes
    for (int i = 0; i < MAX_CHARS_PER_SEQUENCE; i++) {
        chromosomes[i].chr[i] = 'A' + rand() % 25;
        chromosomes[i].frequency++;
    }

    // Calculate the total number of sequences and chromosomes
    for (int i = 0; i < MAX_SEQUENCE_LENGTH; i++) {
        num_sequences += sequences[i].length;
    }
    for (int i = 0; i < MAX_CHARS_PER_SEQUENCE; i++) {
        num_chromosomes += chromosomes[i].frequency;
    }

    // Print the results
    printf("Total sequences: %d\n", num_sequences);
    printf("Total chromosomes: %d\n", num_chromosomes);

    // Free memory
    for (int i = 0; i < MAX_SEQUENCE_LENGTH; i++) {
        free(sequences[i].sequence);
    }
    free(sequences);

    for (int i = 0; i < MAX_CHARS_PER_SEQUENCE; i++) {
        free(chromosomes[i].chr);
    }
    free(chromosomes);

    return 0;
}