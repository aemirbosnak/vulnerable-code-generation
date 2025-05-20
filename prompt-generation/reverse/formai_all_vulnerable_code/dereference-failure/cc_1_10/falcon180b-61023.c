//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int length;
    int start;
    int end;
} Read;

Sequence *generateRandomSequence(int length) {
    char *sequence = (char *) malloc(length + 1);
    int i;
    for (i = 0; i < length; i++) {
        sequence[i] = rand() % 4 + 'A';
    }
    sequence[length] = '\0';
    Sequence *seq = (Sequence *) malloc(sizeof(Sequence));
    seq->sequence = sequence;
    seq->length = length;
    return seq;
}

Read *generateRandomRead(int length, Sequence *sequence) {
    int start = rand() % sequence->length;
    int end = start + length - 1;
    if (end >= sequence->length) {
        end = sequence->length - 1;
    }
    char *readSequence = (char *) malloc((end - start + 1) * sizeof(char));
    strncpy(readSequence, sequence->sequence + start, end - start + 1);
    readSequence[end - start] = '\0';
    Read *read = (Read *) malloc(sizeof(Read));
    read->sequence = readSequence;
    read->length = length;
    read->start = start;
    read->end = end;
    return read;
}

void printSequence(Sequence *sequence) {
    int i;
    for (i = 0; i < sequence->length; i++) {
        printf("%c", toupper(sequence->sequence[i]));
    }
    printf("\n");
}

void printRead(Read *read, Sequence *sequence) {
    int i;
    printf("Read: ");
    for (i = 0; i < read->length; i++) {
        printf("%c", toupper(read->sequence[i]));
    }
    printf("\n");
    printf("Start position: %d\n", read->start);
    printf("End position: %d\n", read->end);
}

int main() {
    srand(time(NULL));
    Sequence *sequence = generateRandomSequence(1000000);
    printf("Original sequence:\n");
    printSequence(sequence);
    int numReads = 10;
    int readLength = 100;
    Read **reads = (Read **) malloc(numReads * sizeof(Read *));
    int i;
    for (i = 0; i < numReads; i++) {
        reads[i] = generateRandomRead(readLength, sequence);
        printRead(reads[i], sequence);
    }
    free(sequence->sequence);
    free(sequence);
    for (i = 0; i < numReads; i++) {
        free(reads[i]->sequence);
        free(reads[i]);
    }
    free(reads);
    return 0;
}