//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_NUM_SEQUENCES 1000
#define MAX_NUM_THREADS 16
#define MIN_SEQUENCE_LENGTH 10
#define MAX_SEQUENCE_LENGTH_DIFF 100
#define MIN_IDENTITY_PERCENTAGE 70
#define MAX_IDENTITY_PERCENTAGE 100
#define MIN_COVERAGE_PERCENTAGE 50
#define MAX_COVERAGE_PERCENTAGE 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    Sequence *sequences;
    int num_sequences;
    float identity_percentage;
    float coverage_percentage;
} Genome;

void generate_random_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = rand() % 4 + 'A';
    }
    sequence[length] = '\0';
}

int compare_sequences(const void *a, const void *b) {
    Sequence *seq1 = (Sequence*)a;
    Sequence *seq2 = (Sequence*)b;

    if (seq1->length > seq2->length) {
        return 1;
    } else if (seq1->length < seq2->length) {
        return -1;
    } else {
        return 0;
    }
}

void print_sequences(Sequence *sequences, int num_sequences) {
    for (int i = 0; i < num_sequences; i++) {
        printf("%s\n", sequences[i].sequence);
    }
}

int main() {
    srand(time(NULL));

    int num_sequences;
    printf("Enter the number of sequences: ");
    scanf("%d", &num_sequences);

    Sequence *sequences = malloc(num_sequences * sizeof(Sequence));
    for (int i = 0; i < num_sequences; i++) {
        int length = rand() % (MAX_SEQUENCE_LENGTH - MIN_SEQUENCE_LENGTH + 1) + MIN_SEQUENCE_LENGTH;
        sequences[i].sequence = malloc(length + 1);
        generate_random_sequence(sequences[i].sequence, length);
        sequences[i].length = length;
    }

    qsort(sequences, num_sequences, sizeof(Sequence), compare_sequences);

    printf("Sequences:\n");
    print_sequences(sequences, num_sequences);

    free(sequences);

    return 0;
}