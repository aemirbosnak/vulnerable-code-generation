//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26
#define MAX_NUM_SEQUENCES 1000

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} Sequence;

typedef struct {
    Sequence *sequences;
    int num_sequences;
} SequenceSet;

void init_random_sequence(Sequence *sequence) {
    srand(time(NULL));
    for (int i = 0; i < MAX_SEQUENCE_LENGTH; i++) {
        sequence->sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }
    sequence->length = MAX_SEQUENCE_LENGTH;
}

void print_sequence(Sequence *sequence) {
    printf("Sequence: %s\n", sequence->sequence);
    printf("Length: %d\n", sequence->length);
}

void init_random_sequence_set(SequenceSet *sequence_set) {
    sequence_set->sequences = malloc(MAX_NUM_SEQUENCES * sizeof(Sequence));
    sequence_set->num_sequences = 0;

    for (int i = 0; i < MAX_NUM_SEQUENCES; i++) {
        init_random_sequence(&sequence_set->sequences[i]);
        sequence_set->num_sequences++;
    }
}

void print_sequence_set(SequenceSet *sequence_set) {
    printf("Number of sequences: %d\n", sequence_set->num_sequences);

    for (int i = 0; i < sequence_set->num_sequences; i++) {
        print_sequence(&sequence_set->sequences[i]);
    }
}

int main() {
    SequenceSet sequence_set;
    init_random_sequence_set(&sequence_set);
    print_sequence_set(&sequence_set);

    return 0;
}