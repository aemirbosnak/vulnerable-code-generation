//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DNA_LENGTH 1000
#define MAX_READ_LENGTH 100
#define NUM_READS 10

typedef struct {
    char* sequence;
    int length;
} DNA;

DNA* generateRandomDNA(int length) {
    DNA* dna = (DNA*)malloc(sizeof(DNA));
    dna->length = length;
    dna->sequence = (char*)malloc(sizeof(char) * (length + 1)); // +1 for null terminator

    const char* nucleotides = "ACGT";
    for (int i = 0; i < length; i++) {
        dna->sequence[i] = nucleotides[rand() % 4];
    }
    dna->sequence[length] = '\0'; // null terminate the string
    
    return dna;
}

char** simulateSequencingReads(DNA* dna, int numReads, int readLength) {
    char** reads = (char**)malloc(sizeof(char*) * numReads);
    for (int i = 0; i < numReads; i++) {
        reads[i] = (char*)malloc(sizeof(char) * (readLength + 1));
        int start = rand() % (dna->length - readLength + 1);
        strncpy(reads[i], dna->sequence + start, readLength);
        reads[i][readLength] = '\0'; // null terminate the string
    }
    return reads;
}

void freeDNA(DNA* dna) {
    free(dna->sequence);
    free(dna);
}

void freeReads(char** reads, int numReads) {
    for (int i = 0; i < numReads; i++) {
        free(reads[i]);
    }
    free(reads);
}

void printDNA(const DNA* dna) {
    printf("DNA Sequence (%d bp): %s\n", dna->length, dna->sequence);
}

void printReads(char** reads, int numReads) {
    for (int i = 0; i < numReads; i++) {
        printf("Read %d: %s\n", i + 1, reads[i]);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int dnaLength = MAX_DNA_LENGTH;
    DNA* dna = generateRandomDNA(dnaLength);
    
    printf("Generated DNA Sequence:\n");
    printDNA(dna);

    char** reads = simulateSequencingReads(dna, NUM_READS, MAX_READ_LENGTH);
    
    printf("\nSimulated Sequencing Reads:\n");
    printReads(reads, NUM_READS);

    // Clean up allocated memory
    freeDNA(dna);
    freeReads(reads, NUM_READS);

    return 0;
}