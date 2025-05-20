//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 100000

typedef struct {
    int length;
    char *sequence;
} Sequence;

Sequence *generate_random_sequence(int length) {
    Sequence *sequence = malloc(sizeof(Sequence));
    sequence->length = length;
    sequence->sequence = malloc(length * sizeof(char));

    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % 4;
    }

    return sequence;
}

int compare_sequences(Sequence *seq1, Sequence *seq2) {
    int score = 0;
    int mismatch_penalty = -1;
    int gap_penalty = -2;

    for (int i = 0; i < seq1->length; i++) {
        if (seq1->sequence[i] == seq2->sequence[i]) {
            score += 1;
        } else {
            score += mismatch_penalty;
        }
    }

    return score;
}

void print_sequence(Sequence *sequence) {
    for (int i = 0; i < sequence->length; i++) {
        printf("%c", sequence->sequence[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Sequence *sequence1 = generate_random_sequence(MAX_SEQUENCE_LENGTH);
    Sequence *sequence2 = generate_random_sequence(MAX_SEQUENCE_LENGTH);

    int score = compare_sequences(sequence1, sequence2);

    printf("Sequence 1: ");
    print_sequence(sequence1);
    printf("Score: %d\n", score);

    printf("Sequence 2: ");
    print_sequence(sequence2);

    free(sequence1->sequence);
    free(sequence1);
    free(sequence2->sequence);
    free(sequence2);

    return 0;
}