//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    int start;
    int end;
} Read;

Sequence generateRandomSequence(int length) {
    Sequence seq = {0};
    seq.length = length;
    seq.sequence = malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        seq.sequence[i] = rand() % 4 + 'A'; // generate random nucleotide (A, C, G, T)
    }
    return seq;
}

Read generateRandomRead(int readLength, Sequence seq) {
    Read read = {0};
    read.start = rand() % seq.length; // random start position
    read.end = read.start + readLength - 1; // read length - 1 to ensure end position is within sequence bounds
    return read;
}

void printSequence(Sequence seq) {
    for (int i = 0; i < seq.length; i++) {
        printf("%c", seq.sequence[i]);
    }
    printf("\n");
}

void printRead(Read read, Sequence seq) {
    for (int i = read.start; i <= read.end; i++) {
        printf("%c", seq.sequence[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // initialize random seed with current time

    Sequence genome = generateRandomSequence(MAX_SEQUENCE_LENGTH); // generate random genome sequence
    printf("Genome sequence:\n");
    printSequence(genome);

    int numReads = 10; // number of reads to generate
    Read *reads = malloc(numReads * sizeof(Read)); // allocate memory for reads array

    for (int i = 0; i < numReads; i++) {
        reads[i] = generateRandomRead(MAX_READ_LENGTH, genome); // generate random read from genome sequence
        printf("Read %d: ", i+1);
        printRead(reads[i], genome);
    }

    free(genome.sequence); // free memory used by genome sequence
    free(reads); // free memory used by reads array

    return 0;
}