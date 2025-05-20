//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DNA_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_NUMBER_OF_READS 1000

typedef struct {
    char *sequence;
    int length;
} DNA_Sequence;

typedef struct {
    char *sequence;
    int length;
    int position;
} Read;

DNA_Sequence *generateRandomDNA(int length) {
    DNA_Sequence *dna = (DNA_Sequence *)malloc(sizeof(DNA_Sequence));
    dna->sequence = (char *)malloc(length * sizeof(char));
    dna->length = length;

    for (int i = 0; i < length; i++) {
        dna->sequence[i] = 'A' + rand() % 4;
    }

    return dna;
}

Read *generateRandomRead(DNA_Sequence *dna, int readLength) {
    Read *read = (Read *)malloc(sizeof(Read));
    read->sequence = (char *)malloc((readLength + 1) * sizeof(char));
    read->length = readLength;
    read->position = rand() % dna->length;

    for (int i = 0; i < readLength; i++) {
        read->sequence[i] = dna->sequence[read->position + i];
    }
    read->sequence[readLength] = '\0';

    return read;
}

void printDNA(DNA_Sequence *dna) {
    printf("DNA sequence: %s\n", dna->sequence);
    printf("Length: %d\n", dna->length);
}

void printRead(Read *read) {
    printf("Read sequence: %s\n", read->sequence);
    printf("Length: %d\n", read->length);
    printf("Position: %d\n", read->position);
}

int main() {
    srand(time(NULL));

    DNA_Sequence *dna = generateRandomDNA(MAX_DNA_SEQUENCE_LENGTH);
    Read *reads[MAX_NUMBER_OF_READS];

    for (int i = 0; i < MAX_NUMBER_OF_READS; i++) {
        reads[i] = generateRandomRead(dna, MAX_READ_LENGTH);
        printRead(reads[i]);
    }

    for (int i = 0; i < MAX_NUMBER_OF_READS; i++) {
        free(reads[i]->sequence);
        free(reads[i]);
    }

    free(dna->sequence);
    free(dna);

    return 0;
}