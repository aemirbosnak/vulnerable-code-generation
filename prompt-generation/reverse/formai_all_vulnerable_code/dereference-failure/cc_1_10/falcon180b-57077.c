//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000000 // Maximum length of a genome
#define MAX_GENOME_SIZE 100 // Maximum number of genomes

typedef struct {
    char* sequence; // Genome sequence
    int length; // Length of the genome sequence
} Genome;

Genome* generateGenome(int length) {
    Genome* genome = (Genome*)malloc(sizeof(Genome));
    genome->length = length;
    genome->sequence = (char*)malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        genome->sequence[i] = 'A' + rand() % 4; // A, C, G, or T
    }
    return genome;
}

int compareGenomes(Genome* genome1, Genome* genome2) {
    int matches = 0;
    for (int i = 0; i < genome1->length && i < genome2->length; i++) {
        if (genome1->sequence[i] == genome2->sequence[i]) {
            matches++;
        }
    }
    return matches;
}

int main() {
    srand(time(NULL));

    int numGenomes = rand() % MAX_GENOME_SIZE + 1; // Random number of genomes between 1 and 100
    Genome** genomes = (Genome**)malloc(numGenomes * sizeof(Genome*));

    for (int i = 0; i < numGenomes; i++) {
        int length = rand() % MAX_GENOME_LENGTH + 1; // Random length between 1 and 1,000,000
        genomes[i] = generateGenome(length);
    }

    for (int i = 0; i < numGenomes - 1; i++) {
        for (int j = i + 1; j < numGenomes; j++) {
            int matches = compareGenomes(genomes[i], genomes[j]);
            printf("Genome %d and %d have %d matches\n", i + 1, j + 1, matches);
        }
    }

    for (int i = 0; i < numGenomes; i++) {
        free(genomes[i]->sequence);
        free(genomes[i]);
    }
    free(genomes);

    return 0;
}