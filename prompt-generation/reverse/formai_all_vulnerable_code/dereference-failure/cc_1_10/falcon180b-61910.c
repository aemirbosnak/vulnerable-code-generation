//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 10000
#define MAX_READ_LENGTH 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    int start;
    int end;
} Read;

Sequence *generateRandomSequence(int length) {
    Sequence *seq = malloc(sizeof(Sequence));
    seq->length = length;
    seq->sequence = malloc(sizeof(char) * length);

    for (int i = 0; i < length; i++) {
        seq->sequence[i] = 'A' + rand() % 4;
    }

    return seq;
}

Read *generateRandomRead(int length, Sequence *sequence) {
    Read *read = malloc(sizeof(Read));
    read->start = rand() % sequence->length;
    read->end = read->start + length - 1;

    if (read->end >= sequence->length) {
        read->end = sequence->length - 1;
    }

    return read;
}

int main() {
    srand(time(NULL));

    Sequence *sequence = generateRandomSequence(MAX_SEQUENCE_LENGTH);
    int numReads = 10;
    Read **reads = malloc(sizeof(Read *) * numReads);

    for (int i = 0; i < numReads; i++) {
        reads[i] = generateRandomRead(MAX_READ_LENGTH, sequence);
    }

    for (int i = 0; i < numReads; i++) {
        printf("Read %d: ", i + 1);
        for (int j = reads[i]->start; j <= reads[i]->end; j++) {
            printf("%c", sequence->sequence[j]);
        }
        printf("\n");
    }

    for (int i = 0; i < numReads; i++) {
        free(reads[i]);
    }
    free(reads);
    free(sequence->sequence);
    free(sequence);

    return 0;
}