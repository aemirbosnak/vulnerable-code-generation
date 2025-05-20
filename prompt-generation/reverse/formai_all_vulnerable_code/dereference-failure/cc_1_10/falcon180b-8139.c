//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 10000

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

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = rand() % 4;
    }

    return sequence;
}

Read *generateRandomReads(Sequence *sequence, int numReads, int readLength) {
    Read *reads = malloc(numReads * sizeof(Read));

    for (int i = 0; i < numReads; i++) {
        reads[i].sequence = malloc(readLength * sizeof(char));
        reads[i].length = readLength;
        reads[i].position = rand() % (sequence->length - readLength + 1);

        for (int j = 0; j < readLength; j++) {
            int baseIndex = (reads[i].position + j) % sequence->length;
            reads[i].sequence[j] = sequence->sequence[baseIndex];
        }
    }

    return reads;
}

void printSequence(Sequence *sequence) {
    for (int i = 0; i < sequence->length; i++) {
        printf("%c", sequence->sequence[i]);
    }
    printf("\n");
}

void printReads(Read *reads, int numReads) {
    for (int i = 0; i < numReads; i++) {
        printf("Read %d: ", i + 1);
        for (int j = 0; j < reads[i].length; j++) {
            printf("%c", reads[i].sequence[j]);
        }
        printf("\n");
    }
}

int main() {
    Sequence *sequence = generateRandomSequence(MAX_SEQUENCE_LENGTH);
    Read *reads = generateRandomReads(sequence, MAX_NUM_READS, MAX_READ_LENGTH);

    printSequence(sequence);
    printReads(reads, MAX_NUM_READS);

    for (int i = 0; i < MAX_NUM_READS; i++) {
        free(reads[i].sequence);
    }
    free(reads);

    free(sequence->sequence);
    free(sequence);

    return 0;
}