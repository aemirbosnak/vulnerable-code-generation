//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 10000
#define MAX_BASE_TYPES 4
#define MAX_READ_LENGTH 100

typedef struct {
    char *sequence;
    int length;
} Genome;

typedef struct {
    int start;
    int end;
} Read;

Genome *generateRandomGenome(int length) {
    Genome *genome = (Genome *)malloc(sizeof(Genome));
    genome->sequence = (char *)malloc(length + 1);
    genome->length = length;

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        genome->sequence[i] = 'A' + rand() % MAX_BASE_TYPES;
    }
    genome->sequence[length] = '\0';

    return genome;
}

Read *generateRandomRead(Genome *genome, int readLength) {
    Read *read = (Read *)malloc(sizeof(Read));
    read->start = rand() % genome->length;
    read->end = read->start + readLength - 1;

    if (read->end >= genome->length) {
        read->end = genome->length - 1;
    }

    return read;
}

void printGenome(Genome *genome) {
    printf("Genome sequence: %s\n", genome->sequence);
    printf("Genome length: %d\n", genome->length);
}

void printRead(Read *read, Genome *genome) {
    int startIndex = read->start;
    int endIndex = read->end;

    printf("Read sequence: ");
    for (int i = startIndex; i <= endIndex; i++) {
        printf("%c", genome->sequence[i]);
    }
    printf("\n");

    printf("Read length: %d\n", endIndex - startIndex + 1);
}

int main() {
    int genomeLength = MAX_SEQUENCE_LENGTH;
    int readLength = MAX_READ_LENGTH;

    Genome *genome = generateRandomGenome(genomeLength);
    Read *read = generateRandomRead(genome, readLength);

    printGenome(genome);
    printRead(read, genome);

    free(genome->sequence);
    free(genome);
    free(read);

    return 0;
}