//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DNA_ALPHABET "ACGT"
#define MAX_CHROMOSOME_SIZE 1000
#define NUM_CHROMOSOMES 2

typedef struct chromosome {
    char sequence[MAX_CHROMOSOME_SIZE];
    int length;
} chromosome;

chromosome *create_chromosomes();
void random_sequence_generator(char *seq, int length);
void print_chromosomes(chromosome *chromosomes, int num_chromosomes);

int main() {
    srand(time(NULL));
    chromosome *chromosomes = create_chromosomes();
    printf("Welcome to FunSeq, the genome sequencing simulator!\n");
    printf("Get ready for some side-splitting, awe-inspiring, and jaw-dropping DNA sequences!\n");
    printf("We'll create %d chromosomes with random sequences, each of length %d.\n", NUM_CHROMOSOMES, MAX_CHROMOSOME_SIZE);
    print_chromosomes(chromosomes, NUM_CHROMOSOMES);

    free(chromosomes);
    return 0;
}

chromosome *create_chromosomes() {
    chromosome *chromosomes = malloc(NUM_CHROMOSOMES * sizeof(chromosome));
    for (int i = 0; i < NUM_CHROMOSOMES; i++) {
        random_sequence_generator(chromosomes[i].sequence, MAX_CHROMOSOME_SIZE);
        chromosomes[i].length = strlen(chromosomes[i].sequence);
    }
    return chromosomes;
}

void random_sequence_generator(char *seq, int length) {
    for (int i = 0; i < length; i++) {
        seq[i] = DNA_ALPHABET[rand() % 4];
    }
    seq[length] = '\0';
}

void print_chromosomes(chromosome *chromosomes, int num_chromosomes) {
    printf("\nHere are the hilarious chromosomes we've created:\n");
    for (int i = 0; i < num_chromosomes; i++) {
        printf("\nChromosome %d: %s\n", i+1, chromosomes[i].sequence);
        printf("Length: %d\n", chromosomes[i].length);
    }
}