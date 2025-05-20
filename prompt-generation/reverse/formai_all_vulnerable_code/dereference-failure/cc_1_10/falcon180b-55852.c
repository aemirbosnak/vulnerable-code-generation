//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DNA_SEQUENCE_LENGTH 1000000
#define DNA_BASES 4

typedef struct {
    char *dna_sequence;
    int sequence_length;
} DNA;

DNA *generate_random_dna_sequence(int length) {
    DNA *dna = malloc(sizeof(DNA));
    dna->dna_sequence = malloc(length + 1);
    dna->sequence_length = length;

    for (int i = 0; i < length; i++) {
        dna->dna_sequence[i] = 'A' + rand() % DNA_BASES;
    }
    dna->dna_sequence[length] = '\0';

    return dna;
}

int main() {
    srand(time(NULL));

    int num_sequences = 10;
    int max_sequence_length = 1000;
    int min_sequence_length = 100;

    DNA **sequences = malloc(num_sequences * sizeof(DNA*));

    for (int i = 0; i < num_sequences; i++) {
        int sequence_length = rand() % (max_sequence_length - min_sequence_length + 1) + min_sequence_length;
        sequences[i] = generate_random_dna_sequence(sequence_length);
    }

    for (int i = 0; i < num_sequences; i++) {
        printf("Sequence %d:\n%s\n", i + 1, sequences[i]->dna_sequence);
    }

    for (int i = 0; i < num_sequences; i++) {
        free(sequences[i]->dna_sequence);
        free(sequences[i]);
    }
    free(sequences);

    return 0;
}