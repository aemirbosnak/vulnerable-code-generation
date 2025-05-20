//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_GENome_SIZE 100000
#define ALPHABET_SIZE 4

typedef struct {
    char genome[MAX_GENome_SIZE];
    int length;
} Genome;

void readGenomeFile(FILE *fp, Genome *genome) {
    char ch;
    int pos = 0;

    while ((ch = fgetc(fp)) != EOF) {
        genome->genome[pos++] = ch;
        if (genome->length < pos) genome->length = pos;
    }
}

void printGenome(Genome genome) {
    for (int i = 0; i < genome.length; i++) {
        printf("%c", genome.genome[i]);
    }
    printf("\n");
}

int compareGenomes(Genome refGenome, Genome compareGenome, int *mismatches) {
    for (int i = 0; i < refGenome.length; i++) {
        if (refGenome.genome[i] != compareGenome.genome[i]) {
            mismatches[(*mismatches)++] = i;
        }
    }
    return (*mismatches);
}

int main(int argc, char *argv[]) {
    Genome refGenome, compareGenome;
    int mismatches[100];
    int numMismatches;

    if (argc != 3) {
        printf("Usage: %s referenceGenome.txt compareGenome.txt\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *refFile = fopen(argv[1], "r");
    FILE *cmpFile = fopen(argv[2], "r");

    if (refFile == NULL || cmpFile == NULL) {
        printf("Error opening files.\n");
        exit(EXIT_FAILURE);
    }

    readGenomeFile(refFile, &refGenome);
    readGenomeFile(cmpFile, &compareGenome);

    fclose(refFile);
    fclose(cmpFile);

    printGenome(refGenome);
    printGenome(compareGenome);

    numMismatches = compareGenomes(refGenome, compareGenome, mismatches);

    printf("Number of mismatches: %d\n", numMismatches);
    for (int i = 0; i < numMismatches; i++) {
        printf("Mismatch at position %d\n", mismatches[i]);
    }

    return EXIT_SUCCESS;
}