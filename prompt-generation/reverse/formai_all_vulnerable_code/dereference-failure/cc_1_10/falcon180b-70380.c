//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *generate_random_sequence(int length) {
    Sequence *seq = malloc(sizeof(Sequence));
    seq->sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        seq->sequence[i] = 'A' + rand() % 4;
    }
    seq->length = length;
    return seq;
}

void print_sequence(Sequence *seq) {
    for (int i = 0; i < seq->length; i++) {
        printf("%c", seq->sequence[i]);
    }
    printf("\n");
}

void reverse_sequence(Sequence *seq) {
    for (int i = 0; i < seq->length / 2; i++) {
        char temp = seq->sequence[i];
        seq->sequence[i] = seq->sequence[seq->length - i - 1];
        seq->sequence[seq->length - i - 1] = temp;
    }
}

void complement_sequence(Sequence *seq) {
    for (int i = 0; i < seq->length; i++) {
        if (seq->sequence[i] == 'A') {
            seq->sequence[i] = 'T';
        } else if (seq->sequence[i] == 'C') {
            seq->sequence[i] = 'G';
        } else if (seq->sequence[i] == 'G') {
            seq->sequence[i] = 'C';
        } else if (seq->sequence[i] == 'T') {
            seq->sequence[i] = 'A';
        }
    }
}

int main() {
    srand(time(NULL));

    Sequence *seq1 = generate_random_sequence(MAX_SEQUENCE_LENGTH);
    Sequence *seq2 = generate_random_sequence(MAX_SEQUENCE_LENGTH);

    printf("Original sequences:\n");
    print_sequence(seq1);
    print_sequence(seq2);

    reverse_sequence(seq1);
    reverse_sequence(seq2);

    printf("Reversed sequences:\n");
    print_sequence(seq1);
    print_sequence(seq2);

    complement_sequence(seq1);
    complement_sequence(seq2);

    printf("Complement sequences:\n");
    print_sequence(seq1);
    print_sequence(seq2);

    free(seq1->sequence);
    free(seq1);
    free(seq2->sequence);
    free(seq2);

    return 0;
}