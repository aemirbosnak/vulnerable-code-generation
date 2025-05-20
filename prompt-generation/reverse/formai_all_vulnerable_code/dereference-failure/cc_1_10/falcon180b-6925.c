//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_BASE_TYPES 4

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    Sequence *sequences;
    int num_sequences;
} Genome;

void generate_random_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % MAX_BASE_TYPES;
    }
    sequence[length] = '\0';
}

Genome *create_genome(int num_sequences, int sequence_length) {
    Genome *genome = malloc(sizeof(Genome));
    genome->num_sequences = num_sequences;
    genome->sequences = malloc(sizeof(Sequence) * num_sequences);

    for (int i = 0; i < num_sequences; i++) {
        genome->sequences[i].sequence = malloc(sizeof(char) * sequence_length + 1);
        genome->sequences[i].length = sequence_length;
        generate_random_sequence(genome->sequences[i].sequence, sequence_length);
    }

    return genome;
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->num_sequences; i++) {
        printf("Sequence %d: %s\n", i, genome->sequences[i].sequence);
    }
}

void free_genome(Genome *genome) {
    for (int i = 0; i < genome->num_sequences; i++) {
        free(genome->sequences[i].sequence);
    }
    free(genome->sequences);
    free(genome);
}

int main() {
    srand(time(NULL));

    Genome *genome = create_genome(10, 1000);
    print_genome(genome);
    free_genome(genome);

    return 0;
}