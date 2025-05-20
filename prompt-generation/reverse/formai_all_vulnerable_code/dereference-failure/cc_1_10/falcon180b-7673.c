//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_ERRORS 3

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int start;
    int end;
} Read;

Sequence *generateSequence(int length) {
    Sequence *seq = malloc(sizeof(Sequence));
    seq->length = length;
    seq->sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        seq->sequence[i] = 'A' + rand() % 4;
    }
    seq->sequence[length] = '\0';
    return seq;
}

Read *generateRead(Sequence *sequence, int readLength) {
    Read *read = malloc(sizeof(Read));
    int start = rand() % (sequence->length - readLength + 1);
    read->start = start;
    read->end = start + readLength - 1;
    read->sequence = malloc(readLength + 1);
    strncpy(read->sequence, &sequence->sequence[start], readLength);
    read->sequence[readLength] = '\0';
    return read;
}

int compareSequences(Sequence *seq1, Sequence *seq2, int maxErrors) {
    int errors = 0;
    for (int i = 0; i < seq1->length && i < seq2->length; i++) {
        if (seq1->sequence[i]!= seq2->sequence[i]) {
            errors++;
        }
        if (errors > maxErrors) {
            break;
        }
    }
    return errors;
}

int main() {
    srand(time(NULL));

    Sequence *referenceSequence = generateSequence(MAX_SEQUENCE_LENGTH);
    Sequence *querySequence = generateSequence(MAX_SEQUENCE_LENGTH);

    int maxErrors = MAX_ERRORS;

    printf("Reference Sequence: %s\n", referenceSequence->sequence);
    printf("Query Sequence: %s\n", querySequence->sequence);

    int errors = compareSequences(referenceSequence, querySequence, maxErrors);

    printf("Number of errors: %d\n", errors);

    return 0;
}