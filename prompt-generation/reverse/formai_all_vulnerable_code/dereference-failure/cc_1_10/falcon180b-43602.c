//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 100000
#define MAX_BASE_TYPES 4

typedef struct {
    char *sequence;
    int length;
} Genome;

Genome *generateRandomGenome(int length) {
    Genome *genome = malloc(sizeof(Genome));
    genome->sequence = malloc(length + 1);
    genome->length = length;

    for (int i = 0; i < length; i++) {
        int base = rand() % MAX_BASE_TYPES;
        switch (base) {
            case 0:
                genome->sequence[i] = 'A';
                break;
            case 1:
                genome->sequence[i] = 'C';
                break;
            case 2:
                genome->sequence[i] = 'G';
                break;
            case 3:
                genome->sequence[i] = 'T';
                break;
            default:
                genome->sequence[i] = 'N';
        }
    }

    genome->sequence[length] = '\0';

    return genome;
}

int main() {
    srand(time(NULL));

    int numGenomes = 10;
    Genome **genomes = malloc(numGenomes * sizeof(Genome*));

    for (int i = 0; i < numGenomes; i++) {
        int length = rand() % MAX_SEQUENCE_LENGTH + 1;
        genomes[i] = generateRandomGenome(length);
    }

    for (int i = 0; i < numGenomes; i++) {
        printf("Genome %d:\n", i+1);
        printf("Sequence: %s\n", genomes[i]->sequence);
        printf("Length: %d\n\n", genomes[i]->length);
    }

    for (int i = 0; i < numGenomes; i++) {
        free(genomes[i]->sequence);
        free(genomes[i]);
    }
    free(genomes);

    return 0;
}