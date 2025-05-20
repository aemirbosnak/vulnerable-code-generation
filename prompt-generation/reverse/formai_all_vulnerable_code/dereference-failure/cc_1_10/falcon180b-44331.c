//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26
#define MAX_NUMBER_OF_SEQUENCES 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    Sequence *sequences;
    int number_of_sequences;
} Genome;

void generate_random_sequence(char *sequence, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        sequence[i] = 'a' + rand() % MAX_ALPHABET_SIZE;
    }
    sequence[length] = '\0';
}

int compare_sequences(const void *a, const void *b) {
    Sequence *sequence_a = (Sequence *)a;
    Sequence *sequence_b = (Sequence *)b;

    return strcmp(sequence_a->sequence, sequence_b->sequence);
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->number_of_sequences; i++) {
        printf("%s\n", genome->sequences[i].sequence);
    }
}

int main() {
    Genome genome;
    genome.number_of_sequences = 0;
    genome.sequences = malloc(MAX_NUMBER_OF_SEQUENCES * sizeof(Sequence));

    int number_of_sequences;
    printf("Enter the number of sequences: ");
    scanf("%d", &number_of_sequences);

    for (int i = 0; i < number_of_sequences; i++) {
        Sequence sequence;
        sequence.sequence = malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
        sequence.length = 0;

        printf("Enter the length of sequence %d: ", i+1);
        scanf("%d", &sequence.length);

        generate_random_sequence(sequence.sequence, sequence.length);
        genome.sequences[genome.number_of_sequences++] = sequence;
    }

    qsort(genome.sequences, genome.number_of_sequences, sizeof(Sequence), compare_sequences);

    print_genome(&genome);

    for (int i = 0; i < genome.number_of_sequences; i++) {
        free(genome.sequences[i].sequence);
    }
    free(genome.sequences);

    return 0;
}