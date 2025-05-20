//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100
#define MUTATION_RATE 0.01

/* Generate a random genome sequence */
char* generate_genome_sequence() {
    char* sequence = (char*) malloc((GENOME_LENGTH + 1) * sizeof(char));
    int i;

    for (i = 0; i < GENOME_LENGTH; i++) {
        /* Randomly choose a DNA base: A, C, T, or G */
        int base = rand() % 4;

        /* Assign the corresponding character to the sequence */
        switch (base) {
            case 0:
                sequence[i] = 'A';
                break;
            case 1:
                sequence[i] = 'C';
                break;
            case 2:
                sequence[i] = 'T';
                break;
            case 3:
                sequence[i] = 'G';
                break;
        }
    }

    sequence[GENOME_LENGTH] = '\0';

    return sequence;
}

/* Mutate a genome sequence with a certain probability */
void mutate_genome_sequence(char* sequence) {
    int i;

    for (i = 0; i < GENOME_LENGTH; i++) {
        /* Randomly decide whether to mutate this base */
        float mutation = (float) rand() / RAND_MAX;

        if (mutation < MUTATION_RATE) {
            /* Randomly choose a new DNA base: A, C, T, or G */
            int base = rand() % 4;

            /* Assign the corresponding character to the sequence */
            switch (base) {
                case 0:
                    sequence[i] = 'A';
                    break;
                case 1:
                    sequence[i] = 'C';
                    break;
                case 2:
                    sequence[i] = 'T';
                    break;
                case 3:
                    sequence[i] = 'G';
                    break;
            }
        }
    }
}

int main() {
    srand(time(NULL)); /* Initialize the random seed */
    char* sequence1 = generate_genome_sequence();
    char* sequence2 = generate_genome_sequence();

    printf("Genome Sequence 1: %s\n", sequence1);
    printf("Genome Sequence 2: %s\n", sequence2);

    mutate_genome_sequence(sequence1);
    mutate_genome_sequence(sequence2);

    printf("\nMutated Genome Sequence 1: %s\n", sequence1);
    printf("Mutated Genome Sequence 2: %s\n", sequence2);

    free(sequence1);
    free(sequence2);

    return 0;
}