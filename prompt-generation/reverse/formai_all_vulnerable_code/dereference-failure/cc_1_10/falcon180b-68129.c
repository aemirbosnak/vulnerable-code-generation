//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 4

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} Sequence;

typedef struct {
    Sequence *sequences;
    int num_sequences;
} Genome;

void initialize_genome(Genome *genome, int num_sequences) {
    genome->num_sequences = num_sequences;
    genome->sequences = (Sequence *) malloc(num_sequences * sizeof(Sequence));
    for (int i = 0; i < num_sequences; i++) {
        genome->sequences[i].length = 0;
        genome->sequences[i].sequence[0] = '\0';
    }
}

void add_sequence(Genome *genome, int index, char *sequence) {
    strncpy(genome->sequences[index].sequence, sequence, MAX_SEQUENCE_LENGTH);
    genome->sequences[index].length = strlen(genome->sequences[index].sequence);
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
}

int main() {
    Genome genome;
    initialize_genome(&genome, 3);

    add_sequence(&genome, 0, "ATCGGTACTCGGTCTAGC");
    add_sequence(&genome, 1, "GGTACCTAGGCTAGCGTG");
    add_sequence(&genome, 2, "CGATCGGTACTCGGTCTA");

    print_genome(&genome);

    free_genome(&genome);

    return 0;
}