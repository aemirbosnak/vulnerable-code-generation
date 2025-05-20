//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 100000
#define MAX_READ_LENGTH 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int length;
    int position;
} Read;

Sequence *generateSequence(int length) {
    Sequence *seq = malloc(sizeof(Sequence));
    seq->sequence = calloc(length + 1, sizeof(char));
    seq->length = length;

    for (int i = 0; i < length; i++) {
        seq->sequence[i] = 'A' + rand() % 4;
    }

    return seq;
}

Read *generateRead(Sequence *sequence, int readLength) {
    Read *read = malloc(sizeof(Read));
    read->sequence = calloc(readLength + 1, sizeof(char));
    read->length = readLength;
    read->position = rand() % sequence->length;

    for (int i = 0; i < readLength; i++) {
        read->sequence[i] = sequence->sequence[read->position + i];
    }

    return read;
}

void printSequence(Sequence *sequence) {
    for (int i = 0; i < sequence->length; i++) {
        printf("%c", sequence->sequence[i]);
    }
    printf("\n");
}

void printRead(Read *read) {
    for (int i = 0; i < read->length; i++) {
        printf("%c", read->sequence[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Sequence *sequence = generateSequence(MAX_SEQUENCE_LENGTH);
    Read *read = generateRead(sequence, MAX_READ_LENGTH);

    printSequence(sequence);
    printRead(read);

    free(sequence->sequence);
    free(sequence);
    free(read->sequence);
    free(read);

    return 0;
}