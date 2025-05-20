//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000 // maximum length of the DNA sequence
#define MAX_READ_LENGTH 100 // maximum length of each read
#define NUM_READS 10000 // number of reads to simulate
#define ERROR_RATE 0.01 // error rate for each base call

typedef struct {
    char *sequence; // the DNA sequence
    int length; // length of the sequence
} DNA;

DNA *generateRandomDNA(int length) {
    DNA *dna = (DNA *) malloc(sizeof(DNA));
    dna->sequence = (char *) malloc(length + 1);
    dna->length = length;

    // initialize the sequence with random nucleotides
    for (int i = 0; i < length; i++) {
        dna->sequence[i] = 'A' + rand() % 4; // A, C, G, or T
    }
    dna->sequence[length] = '\0';

    return dna;
}

void freeDNA(DNA *dna) {
    free(dna->sequence);
    free(dna);
}

void printDNA(DNA *dna) {
    printf("%s\n", dna->sequence);
}

int main() {
    srand(time(NULL));

    // generate the reference DNA sequence
    DNA *reference = generateRandomDNA(MAX_SEQUENCE_LENGTH);
    printf("Reference DNA sequence:\n");
    printDNA(reference);

    // simulate reads with errors
    DNA **reads = (DNA **) malloc(NUM_READS * sizeof(DNA *));
    for (int i = 0; i < NUM_READS; i++) {
        int readLength = rand() % MAX_READ_LENGTH + 1; // random read length between 1 and MAX_READ_LENGTH
        DNA *read = generateRandomDNA(readLength);

        // introduce errors into the read sequence
        for (int j = 0; j < readLength; j++) {
            if (rand() % 100 < ERROR_RATE) { // with probability ERROR_RATE
                read->sequence[j] = 'A' + rand() % 4; // randomly change the nucleotide
            }
        }

        reads[i] = read;
    }

    // print the reads
    printf("Simulated reads:\n");
    for (int i = 0; i < NUM_READS; i++) {
        printDNA(reads[i]);
    }

    // free memory
    freeDNA(reference);
    for (int i = 0; i < NUM_READS; i++) {
        freeDNA(reads[i]);
    }
    free(reads);

    return 0;
}