//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_READ_LENGTH 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *generateRandomSequence(int length) {
    Sequence *seq = malloc(sizeof(Sequence));
    seq->sequence = malloc(length + 1);
    seq->length = length;

    for (int i = 0; i < length; i++) {
        seq->sequence[i] = 'A' + rand() % 4;
    }
    seq->sequence[length] = '\0';

    return seq;
}

void printSequence(Sequence *seq) {
    printf("%s\n", seq->sequence);
}

int main() {
    srand(time(NULL));

    Sequence *genome = generateRandomSequence(MAX_SEQUENCE_LENGTH);
    printf("Genome sequence:\n");
    printSequence(genome);

    int numReads = 10;
    int readLength = MAX_READ_LENGTH;

    for (int i = 0; i < numReads; i++) {
        Sequence *read = malloc(sizeof(Sequence));
        read->sequence = malloc(readLength + 1);
        read->length = readLength;

        int startIndex = rand() % (MAX_SEQUENCE_LENGTH - readLength);
        for (int j = 0; j < readLength; j++) {
            read->sequence[j] = genome->sequence[startIndex + j];
        }
        read->sequence[readLength] = '\0';

        printf("Read %d:\n", i + 1);
        printSequence(read);
    }

    return 0;
}