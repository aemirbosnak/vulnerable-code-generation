//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEQUENCE_LENGTH 1000
#define NUM_SEQUENCES 5
#define BASES "ACGT"

typedef struct {
    char *sequence;
    int quality_scores[SEQUENCE_LENGTH];
} GenomeSequence;

void generate_random_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = BASES[rand() % 4];
    }
    sequence[length] = '\0'; // Null-terminate the string
}

void generate_quality_scores(int *scores, int length) {
    for (int i = 0; i < length; i++) {
        scores[i] = rand() % 41; // Quality score between 0 and 40
    }
}

void print_sequence(GenomeSequence *genome) {
    printf("Sequence: %s\n", genome->sequence);
    printf("Quality Scores: ");
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        printf("%d ", genome->quality_scores[i]);
    }
    printf("\n");
}

void mutate_sequence(char *sequence, double mutation_rate) {
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        if ((double)rand() / RAND_MAX < mutation_rate) {
            sequence[i] = BASES[rand() % 4]; // Mutate to a random base
        }
    }
}

void create_genome_sequence(GenomeSequence *genome) {
    genome->sequence = (char *)malloc(SEQUENCE_LENGTH + 1);
    generate_random_sequence(genome->sequence, SEQUENCE_LENGTH);
    generate_quality_scores(genome->quality_scores, SEQUENCE_LENGTH);
}

void free_genome_sequence(GenomeSequence *genome) {
    free(genome->sequence);
}

int main() {
    srand(time(NULL)); // Seed random number generator

    GenomeSequence genomes[NUM_SEQUENCES];

    for (int i = 0; i < NUM_SEQUENCES; i++) {
        create_genome_sequence(&genomes[i]);
        print_sequence(&genomes[i]);
        double mutation_rate = 0.01; // 1% chance of mutation
        mutate_sequence(genomes[i].sequence, mutation_rate);
        printf("After Mutation:\n");
        print_sequence(&genomes[i]);
        free_genome_sequence(&genomes[i]);
    }

    return 0;
}