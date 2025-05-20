//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_ERRORS 10
#define MATCH 1
#define MISMATCH -1
#define GAP -2

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    int start;
    int end;
    int score;
} Alignment;

Sequence *generateSequence(int length) {
    Sequence *seq = (Sequence *) malloc(sizeof(Sequence));
    seq->sequence = (char *) malloc((length + 1) * sizeof(char));
    seq->length = length;

    for (int i = 0; i < length; i++) {
        seq->sequence[i] = (char) ('A' + rand() % 4);
    }
    seq->sequence[length] = '\0';

    return seq;
}

Alignment *localAlignment(Sequence *seq1, Sequence *seq2, int maxErrors) {
    int i, j, k, score = 0;
    Alignment *align = (Alignment *) malloc(sizeof(Alignment));

    for (i = 0, j = 0; i < seq1->length && j < seq2->length; i++, j++) {
        if (seq1->sequence[i] == seq2->sequence[j]) {
            score++;
        } else {
            if (score > maxErrors) {
                break;
            }
        }
    }

    align->start = i - score;
    align->end = j - score;
    align->score = score;

    return align;
}

void printAlignment(Alignment *align, Sequence *seq1, Sequence *seq2) {
    int i, j;

    for (i = 0, j = align->start; i < seq1->length && j < seq2->length; i++, j++) {
        if (seq1->sequence[i] == seq2->sequence[j]) {
            printf("|");
        } else {
            printf(" ");
        }
    }

    printf("\n%s\n%s\n", seq1->sequence + align->start, seq2->sequence + align->start);
}

int main() {
    srand(time(NULL));

    Sequence *seq1 = generateSequence(MAX_SEQUENCE_LENGTH);
    Sequence *seq2 = generateSequence(MAX_SEQUENCE_LENGTH);

    Alignment *align = localAlignment(seq1, seq2, MAX_ERRORS);

    printf("Sequence 1: %s\n", seq1->sequence);
    printf("Sequence 2: %s\n", seq2->sequence);
    printf("Alignment:\n");
    printAlignment(align, seq1, seq2);

    free(seq1->sequence);
    free(seq1);
    free(seq2->sequence);
    free(seq2);
    free(align);

    return 0;
}