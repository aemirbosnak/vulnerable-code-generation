//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1000
#define MAX_SEQUENCES 100
#define MAX_BASE_TYPES 4

// Base types
#define A 0
#define C 1
#define G 2
#define T 3

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    Sequence *sequences;
    int num_sequences;
} Genome;

void generate_sequence(Sequence *sequence) {
    int i;
    for (i = 0; i < sequence->length; i++) {
        sequence->sequence[i] = rand() % MAX_BASE_TYPES;
    }
}

void print_sequence(Sequence *sequence) {
    int i;
    for (i = 0; i < sequence->length; i++) {
        printf("%c", "ACGT"[sequence->sequence[i]]);
    }
    printf("\n");
}

void generate_genome(Genome *genome) {
    int i;
    for (i = 0; i < genome->num_sequences; i++) {
        generate_sequence(&genome->sequences[i]);
    }
}

void print_genome(Genome *genome) {
    int i;
    for (i = 0; i < genome->num_sequences; i++) {
        print_sequence(&genome->sequences[i]);
    }
}

int main() {
    srand(time(NULL));
    Genome genome;
    genome.num_sequences = MAX_SEQUENCES;
    genome.sequences = malloc(genome.num_sequences * sizeof(Sequence));
    if (!genome.sequences) {
        printf("Error: Could not allocate memory for genome.\n");
        return 1;
    }
    int i;
    for (i = 0; i < genome.num_sequences; i++) {
        genome.sequences[i].sequence = malloc(MAX_LENGTH * sizeof(char));
        if (!genome.sequences[i].sequence) {
            printf("Error: Could not allocate memory for sequence.\n");
            return 1;
        }
        genome.sequences[i].length = rand() % MAX_LENGTH + 1;
        generate_sequence(&genome.sequences[i]);
    }
    print_genome(&genome);
    return 0;
}