//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 100000

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *read;
    int length;
    int position;
} Read;

Sequence generateRandomSequence(int length) {
    Sequence seq = {NULL, length};
    seq.sequence = (char *)malloc(length + 1);
    for (int i = 0; i < length; i++) {
        seq.sequence[i] = 'A' + rand() % 4;
    }
    seq.sequence[length] = '\0';
    return seq;
}

Read generateRandomRead(Sequence *sequence, int maxReadLength) {
    Read read = {NULL, 0, 0};
    int readLength = rand() % maxReadLength + 1;
    read.length = readLength;
    read.read = (char *)malloc(readLength + 1);
    for (int i = 0; i < readLength; i++) {
        read.read[i] = sequence->sequence[rand() % sequence->length];
    }
    read.read[readLength] = '\0';
    return read;
}

void printSequence(Sequence seq) {
    printf("Sequence: %s\n", seq.sequence);
    printf("Length: %d\n", seq.length);
}

void printRead(Read read) {
    printf("Read: %s\n", read.read);
    printf("Length: %d\n", read.length);
    printf("Position: %d\n", read.position);
}

int main() {
    srand(time(NULL));

    Sequence genome = generateRandomSequence(MAX_SEQUENCE_LENGTH);
    printf("Genome sequence:\n");
    printSequence(genome);

    int numReads = rand() % MAX_NUM_READS + 1;
    Read *reads = (Read *)malloc(numReads * sizeof(Read));

    for (int i = 0; i < numReads; i++) {
        reads[i] = generateRandomRead(&genome, MAX_READ_LENGTH);
        printf("Read %d:\n", i + 1);
        printRead(reads[i]);
    }

    free(genome.sequence);
    free(reads);

    return 0;
}