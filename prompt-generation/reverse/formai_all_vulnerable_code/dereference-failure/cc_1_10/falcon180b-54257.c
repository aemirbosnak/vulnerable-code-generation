//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 1000000

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *read;
    int length;
} Read;

Sequence *generateSequence(int length) {
    Sequence *seq = (Sequence *)malloc(sizeof(Sequence));
    seq->sequence = (char *)malloc(length + 1);
    seq->length = length;

    for (int i = 0; i < length; i++) {
        seq->sequence[i] = 'A' + rand() % 4;
    }

    seq->sequence[length] = '\0';

    return seq;
}

Read *generateRead(Sequence *sequence, int readLength) {
    Read *read = (Read *)malloc(sizeof(Read));
    read->length = readLength;

    int startIndex = rand() % (sequence->length - readLength + 1);
    read->read = (char *)malloc(readLength + 1);

    for (int i = 0; i < readLength; i++) {
        read->read[i] = sequence->sequence[startIndex + i];
    }

    read->read[readLength] = '\0';

    return read;
}

void printSequence(Sequence *sequence) {
    printf("Sequence: %s\n", sequence->sequence);
}

void printRead(Read *read) {
    printf("Read: %s\n", read->read);
}

int main() {
    srand(time(NULL));

    Sequence *sequence = generateSequence(MAX_SEQUENCE_LENGTH);
    printf("Generated sequence of length %d:\n", sequence->length);
    printSequence(sequence);

    int numReads = MAX_NUM_READS;
    Read **reads = (Read **)malloc(numReads * sizeof(Read *));

    for (int i = 0; i < numReads; i++) {
        reads[i] = generateRead(sequence, MAX_READ_LENGTH);
        printf("Generated read %d of length %d:\n", i + 1, reads[i]->length);
        printRead(reads[i]);
    }

    for (int i = 0; i < numReads; i++) {
        free(reads[i]->read);
        free(reads[i]);
    }
    free(reads);

    free(sequence->sequence);
    free(sequence);

    return 0;
}