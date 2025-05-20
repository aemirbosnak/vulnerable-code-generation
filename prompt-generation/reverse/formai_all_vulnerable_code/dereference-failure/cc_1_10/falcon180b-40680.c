//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_ERRORS 10

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
    Sequence *sequence = malloc(sizeof(Sequence));
    sequence->length = length;
    sequence->sequence = malloc(length * sizeof(char));

    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % 4;
    }

    return sequence;
}

Read *generateRandomRead(Sequence *sequence, int readLength, int maxErrors) {
    Read *read = malloc(sizeof(Read));
    read->sequence = malloc((readLength + 1) * sizeof(char));
    read->length = readLength;

    srand(time(NULL));
    int startPosition = rand() % (sequence->length - readLength);
    for (int i = 0; i < readLength; i++) {
        read->sequence[i] = sequence->sequence[startPosition + i];
        if (rand() % 100 < maxErrors) {
            read->sequence[i] = 'A' + rand() % 4;
        }
    }
    read->sequence[readLength] = '\0';
    read->position = startPosition;

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
    Sequence *genome = generateRandomSequence(MAX_SEQUENCE_LENGTH);
    Read *read1 = generateRandomRead(genome, MAX_READ_LENGTH, MAX_ERRORS);
    Read *read2 = generateRandomRead(genome, MAX_READ_LENGTH, MAX_ERRORS);

    printf("Genome sequence:\n");
    printSequence(genome);

    printf("Read 1:\n");
    printRead(read1);

    printf("Read 2:\n");
    printRead(read2);

    free(genome->sequence);
    free(genome);
    free(read1->sequence);
    free(read1);
    free(read2->sequence);
    free(read2);

    return 0;
}