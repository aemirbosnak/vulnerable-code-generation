//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000

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
        sequence[i] = rand() % 4 + 'A';
    }
    sequence[length] = '\0';
}

int compare_sequences(const void *a, const void *b) {
    Sequence *seq1 = (Sequence *)a;
    Sequence *seq2 = (Sequence *)b;

    return strcmp(seq1->sequence, seq2->sequence);
}

void print_sequence(Sequence *sequence) {
    printf("%s\n", sequence->sequence);
}

int main() {
    srand(time(NULL));

    Genome genome;
    genome.num_sequences = 10;
    genome.sequences = malloc(genome.num_sequences * sizeof(Sequence));

    for (int i = 0; i < genome.num_sequences; i++) {
        Sequence *sequence = &genome.sequences[i];
        sequence->length = rand() % MAX_SEQUENCE_LENGTH + 1;
        sequence->sequence = malloc(sequence->length + 1);
        generate_random_sequence(sequence->sequence, sequence->length);
    }

    qsort(genome.sequences, genome.num_sequences, sizeof(Sequence), compare_sequences);

    for (int i = 0; i < genome.num_sequences; i++) {
        Sequence *sequence = &genome.sequences[i];
        print_sequence(sequence);
    }

    for (int i = 0; i < genome.num_sequences; i++) {
        free(genome.sequences[i].sequence);
    }
    free(genome.sequences);

    return 0;
}