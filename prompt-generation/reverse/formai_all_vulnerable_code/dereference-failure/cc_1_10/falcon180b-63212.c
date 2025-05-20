//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 500

// Define the nucleotide bases
#define A 0
#define C 1
#define G 2
#define T 3

typedef struct {
    char *name;
    int length;
    int *sequence;
} Sequence;

typedef struct {
    char *name;
    int length;
    int *sequence;
} Read;

void generateSequence(Sequence *seq, int length) {
    seq->length = length;
    seq->sequence = (int *) malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        seq->sequence[i] = rand() % 4;
    }
}

void printSequence(Sequence seq) {
    for (int i = 0; i < seq.length; i++) {
        switch (seq.sequence[i]) {
            case A:
                printf("A");
                break;
            case C:
                printf("C");
                break;
            case G:
                printf("G");
                break;
            case T:
                printf("T");
                break;
            default:
                printf("N");
                break;
        }
    }
    printf("\n");
}

void generateRead(Read *read, Sequence seq, int readLength) {
    read->length = readLength;
    read->sequence = (int *) malloc(readLength * sizeof(int));
    for (int i = 0; i < readLength; i++) {
        int pos = rand() % seq.length;
        read->sequence[i] = seq.sequence[pos];
    }
}

void printRead(Read read) {
    for (int i = 0; i < read.length; i++) {
        switch (read.sequence[i]) {
            case A:
                printf("A");
                break;
            case C:
                printf("C");
                break;
            case G:
                printf("G");
                break;
            case T:
                printf("T");
                break;
            default:
                printf("N");
                break;
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    // Generate a reference sequence
    Sequence refSeq;
    generateSequence(&refSeq, MAX_SEQUENCE_LENGTH);

    // Generate some reads
    Read reads[10];
    for (int i = 0; i < 10; i++) {
        Read read;
        generateRead(&read, refSeq, MAX_READ_LENGTH);
        printf("Read %d:\n", i + 1);
        printRead(read);
    }

    return 0;
}