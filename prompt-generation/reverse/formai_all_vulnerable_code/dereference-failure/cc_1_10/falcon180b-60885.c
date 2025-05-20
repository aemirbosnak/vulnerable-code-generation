//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100

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
        sequence[i] = (char) rand() % 4 + 'A';
    }
    sequence[length] = '\0';
}

Genome *generate_genome(int num_sequences, int max_sequence_length) {
    Genome *genome = malloc(sizeof(Genome));
    genome->num_sequences = num_sequences;
    genome->sequences = malloc(num_sequences * sizeof(Sequence));

    for (int i = 0; i < num_sequences; i++) {
        Sequence *sequence = &genome->sequences[i];
        sequence->length = rand() % max_sequence_length + 1;
        sequence->sequence = malloc(sequence->length + 1);
        generate_random_sequence(sequence->sequence, sequence->length);
    }

    return genome;
}

void print_sequence(Sequence *sequence) {
    printf("%s\n", sequence->sequence);
}

int main() {
    srand(time(NULL));

    Genome *genome = generate_genome(10, MAX_SEQUENCE_LENGTH);

    for (int i = 0; i < genome->num_sequences; i++) {
        print_sequence(&genome->sequences[i]);
    }

    for (int i = 0; i < genome->num_sequences; i++) {
        free(genome->sequences[i].sequence);
    }
    free(genome->sequences);
    free(genome);

    return 0;
}