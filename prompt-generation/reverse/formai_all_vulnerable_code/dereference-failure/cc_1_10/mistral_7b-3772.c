//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 100000
#define LENGTH 50

typedef struct {
    char seq[LENGTH];
    int count;
} Sequence;

void generate_sequence(Sequence* seq) {
    int i;
    for (i = 0; i < LENGTH; i++) {
        seq->seq[i] = 'A' + rand() % 4;
    }
    seq->count = 1;
}

void compare_sequences(Sequence* seq1, Sequence* seq2) {
    int i, match = 0;
    for (i = 0; i < LENGTH && seq1->seq[i] != '\0'; i++) {
        if (seq1->seq[i] == seq2->seq[i]) {
            match++;
        }
    }
    seq1->count += seq2->count;
}

void print_sequence(Sequence* seq) {
    int i;
    printf("Sequence %d: %s\n", seq->count, seq->seq);
}

int main() {
    Sequence* sequences = malloc(N * sizeof(Sequence));
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        generate_sequence(&sequences[i]);
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            compare_sequences(&sequences[i], &sequences[j]);
        }
    }

    for (int i = 0; i < N; i++) {
        print_sequence(&sequences[i]);
    }

    free(sequences);

    return 0;
}