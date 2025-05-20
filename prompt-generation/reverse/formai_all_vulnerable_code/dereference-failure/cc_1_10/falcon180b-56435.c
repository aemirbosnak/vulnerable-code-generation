//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 100
#define MAX_ALPHABET_SIZE 26

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
        sequence[i] = 'a' + rand() % MAX_ALPHABET_SIZE;
    }
    sequence[length] = '\0';
}

int compare_sequences(const void *a, const void *b) {
    Sequence *seq_a = (Sequence *)a;
    Sequence *seq_b = (Sequence *)b;

    return strcmp(seq_a->sequence, seq_b->sequence);
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->num_sequences; i++) {
        printf("%s\n", genome->sequences[i].sequence);
    }
}

int main() {
    srand(time(NULL));

    Genome genome;
    genome.num_sequences = 2;
    genome.sequences = malloc(genome.num_sequences * sizeof(Sequence));

    generate_random_sequence(genome.sequences[0].sequence, MAX_SEQUENCE_LENGTH);
    generate_random_sequence(genome.sequences[1].sequence, MAX_SEQUENCE_LENGTH);

    qsort(genome.sequences, genome.num_sequences, sizeof(Sequence), compare_sequences);

    print_genome(&genome);

    free(genome.sequences);

    return 0;
}