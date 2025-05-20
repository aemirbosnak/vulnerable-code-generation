//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_SEQUENCE_COUNT 1000
#define MAX_MUTATION_RATE 0.01
#define MAX_MUTATION_LENGTH 10

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} Sequence;

void generate_random_sequence(Sequence* sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % 4;
    }
    sequence->length = length;
}

void mutate_sequence(Sequence* sequence, double mutation_rate) {
    int mutation_count = rand() % (int)(MAX_MUTATION_RATE * sequence->length);
    for (int i = 0; i < mutation_count; i++) {
        int position = rand() % sequence->length;
        int mutation_length = rand() % MAX_MUTATION_LENGTH + 1;
        for (int j = 0; j < mutation_length; j++) {
            sequence->sequence[position + j] = 'A' + rand() % 4;
        }
    }
}

int compare_sequences(const void* a, const void* b) {
    const Sequence* sequence_a = (const Sequence*)a;
    const Sequence* sequence_b = (const Sequence*)b;
    return strcmp(sequence_a->sequence, sequence_b->sequence);
}

int main() {
    srand(time(NULL));

    int sequence_count = rand() % MAX_SEQUENCE_COUNT + 1;
    Sequence* sequences = malloc(sequence_count * sizeof(Sequence));

    for (int i = 0; i < sequence_count; i++) {
        generate_random_sequence(&sequences[i], rand() % MAX_SEQUENCE_LENGTH + 1);
    }

    qsort(sequences, sequence_count, sizeof(Sequence), compare_sequences);

    for (int i = 0; i < sequence_count; i++) {
        printf("%s\n", sequences[i].sequence);
    }

    free(sequences);
    return 0;
}