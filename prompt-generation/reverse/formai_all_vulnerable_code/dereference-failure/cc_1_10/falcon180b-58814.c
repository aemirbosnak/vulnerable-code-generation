//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26

typedef struct {
    char *sequence;
    int length;
} Genome;

void generateRandomSequence(Genome *genome) {
    int i;
    for (i = 0; i < MAX_SEQUENCE_LENGTH; i++) {
        genome->sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }
    genome->length = MAX_SEQUENCE_LENGTH;
}

int compareGenomes(const void *a, const void *b) {
    Genome *genomeA = (Genome *)a;
    Genome *genomeB = (Genome *)b;

    int result = strcmp(genomeA->sequence, genomeB->sequence);

    if (result == 0) {
        return 0;
    } else if (result < 0) {
        return -1;
    } else {
        return 1;
    }
}

int main() {
    srand(time(NULL));

    Genome genomeA, genomeB;
    generateRandomSequence(&genomeA);
    generateRandomSequence(&genomeB);

    int comparisonResult = compareGenomes(&genomeA, &genomeB);

    if (comparisonResult == 0) {
        printf("The genomes are identical.\n");
    } else if (comparisonResult < 0) {
        printf("Genome A is less than Genome B.\n");
    } else {
        printf("Genome A is greater than Genome B.\n");
    }

    return 0;
}