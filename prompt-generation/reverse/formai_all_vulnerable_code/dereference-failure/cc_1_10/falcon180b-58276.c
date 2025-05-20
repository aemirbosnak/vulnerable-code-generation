//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 1000

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int length;
    int position;
} Read;

void generateRandomSequence(Sequence *sequence, int length) {
    char *bases = "ACGT";
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = bases[rand() % 4];
    }
    sequence->length = length;
}

void generateReads(Sequence *genome, Read *reads, int numReads, int readLength) {
    for (int i = 0; i < numReads; i++) {
        reads[i].sequence = malloc(readLength * sizeof(char));
        reads[i].length = readLength;
        reads[i].position = rand() % genome->length;
        for (int j = 0; j < readLength; j++) {
            reads[i].sequence[j] = genome->sequence[reads[i].position + j];
        }
    }
}

int main() {
    srand(time(NULL));

    Sequence genome;
    generateRandomSequence(&genome, MAX_SEQUENCE_LENGTH);

    Read reads[MAX_NUM_READS];
    generateReads(&genome, reads, MAX_NUM_READS, MAX_READ_LENGTH);

    for (int i = 0; i < MAX_NUM_READS; i++) {
        printf("Read %d: %s\n", i, reads[i].sequence);
    }

    return 0;
}