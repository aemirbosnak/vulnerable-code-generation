//Falcon2-11B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void simulateGenome(int numBases, int numSequences, int numReads) {
    char **bases = (char **)malloc(numSequences * sizeof(char *));
    int *lengths = (int *)malloc(numSequences * sizeof(int));
    char **reads = (char **)malloc(numReads * sizeof(char *));
    int *qualities = (int *)malloc(numReads * sizeof(int));

    // Generate random bases for each sequence
    srand(time(NULL));
    for (int i = 0; i < numSequences; i++) {
        bases[i] = (char *)malloc(numBases * sizeof(char));
        for (int j = 0; j < numBases; j++) {
            bases[i][j] = 'A' + (rand() % 4);
        }
        lengths[i] = numBases;
    }

    // Generate reads from the sequences
    for (int i = 0; i < numReads; i++) {
        int length = (rand() % (lengths[rand() % numSequences] - 10)) + 10;
        reads[i] = (char *)malloc(length * sizeof(char));
        for (int j = 0; j < length; j++) {
            reads[i][j] = bases[rand() % numSequences][rand() % lengths[i]];
        }
        qualities[i] = rand() % 101;
    }

    // Print the results
    for (int i = 0; i < numReads; i++) {
        printf("%s\t%d\t%d\n", reads[i], qualities[i], lengths[i]);
    }

    for (int i = 0; i < numSequences; i++) {
        free(bases[i]);
    }
    free(bases);

    for (int i = 0; i < numReads; i++) {
        free(reads[i]);
    }
    free(reads);

    free(lengths);
    free(qualities);
}

int main() {
    int numBases = 1000;
    int numSequences = 100;
    int numReads = 1000;

    simulateGenome(numBases, numSequences, numReads);

    return 0;
}