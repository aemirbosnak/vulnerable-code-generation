//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 100000

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int length;
    int position;
} Read;

Sequence *generateRandomSequence(int length) {
    Sequence *sequence = (Sequence *) malloc(sizeof(Sequence));
    sequence->length = length;
    sequence->sequence = (char *) malloc(length * sizeof(char));

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % 4;
    }

    return sequence;
}

Read *generateRandomRead(int length, int numReads, Sequence *sequence) {
    Read *read = (Read *) malloc(sizeof(Read));
    read->length = length;
    read->sequence = (char *) malloc(length * sizeof(char));
    read->position = rand() % (sequence->length - length);

    for (int i = 0; i < length; i++) {
        read->sequence[i] = sequence->sequence[read->position + i];
    }

    return read;
}

void printSequence(Sequence *sequence) {
    printf("Sequence: ");
    for (int i = 0; i < sequence->length; i++) {
        printf("%c", sequence->sequence[i]);
    }
    printf("\n");
}

void printRead(Read *read) {
    printf("Read: ");
    for (int i = 0; i < read->length; i++) {
        printf("%c", read->sequence[i]);
    }
    printf("\n");
}

int main() {
    Sequence *sequence = generateRandomSequence(MAX_SEQUENCE_LENGTH);
    Read *reads[MAX_NUM_READS];

    for (int i = 0; i < MAX_NUM_READS; i++) {
        reads[i] = generateRandomRead(MAX_READ_LENGTH, MAX_NUM_READS, sequence);
    }

    for (int i = 0; i < MAX_NUM_READS; i++) {
        printRead(reads[i]);
    }

    for (int i = 0; i < MAX_NUM_READS; i++) {
        free(reads[i]->sequence);
        free(reads[i]);
    }

    free(sequence->sequence);
    free(sequence);

    return 0;
}