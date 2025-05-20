//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_NUM_SEQUENCES 100
#define NUM_BASES 4

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} Sequence;

typedef struct {
    Sequence* sequences;
    int num_sequences;
} Genome;

void init_genome(Genome* genome, int num_sequences) {
    genome->num_sequences = num_sequences;
    genome->sequences = (Sequence*) malloc(num_sequences * sizeof(Sequence));

    for (int i = 0; i < num_sequences; i++) {
        genome->sequences[i].length = rand() % MAX_SEQUENCE_LENGTH + 1;
        genome->sequences[i].sequence[0] = 'A';
        for (int j = 1; j < genome->sequences[i].length; j++) {
            genome->sequences[i].sequence[j] = 'A' + rand() % NUM_BASES;
        }
        genome->sequences[i].sequence[genome->sequences[i].length - 1] = '\0';
    }
}

void print_genome(Genome* genome) {
    for (int i = 0; i < genome->num_sequences; i++) {
        printf("Sequence %d: %s\n", i, genome->sequences[i].sequence);
    }
}

void free_genome(Genome* genome) {
    for (int i = 0; i < genome->num_sequences; i++) {
        free(genome->sequences[i].sequence);
    }
    free(genome->sequences);
}

int main() {
    srand(time(NULL));

    Genome genome;
    init_genome(&genome, 10);

    print_genome(&genome);

    free_genome(&genome);

    return 0;
}