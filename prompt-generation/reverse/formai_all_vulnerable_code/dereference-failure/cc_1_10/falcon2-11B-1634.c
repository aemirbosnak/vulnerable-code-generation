//Falcon2-11B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    FILE *inFile = fopen("genome.txt", "r");
    FILE *outFile = fopen("simulated_genome.txt", "w");

    int numBases = 1000000;
    int numErrors = 100;
    int numSimulations = 10;

    int *genome = (int *)malloc(numBases * sizeof(int));
    int *simulated_genome = (int *)malloc(numBases * sizeof(int));
    int *errors = (int *)malloc(numErrors * sizeof(int));

    for (int i = 0; i < numBases; i++) {
        genome[i] = rand() % 4; // 0 = A, 1 = C, 2 = G, 3 = T
    }

    for (int j = 0; j < numSimulations; j++) {
        for (int k = 0; k < numErrors; k++) {
            int randomIndex = rand() % numBases;
            int randomError = rand() % 4;

            int originalBase = genome[randomIndex];
            int newBase = randomError == originalBase? (rand() % 4) : originalBase;
            genome[randomIndex] = newBase;
            errors[k]++;
        }

        for (int i = 0; i < numBases; i++) {
            if (genome[i]!= simulated_genome[i]) {
                fprintf(outFile, "%d\n", i);
            }
        }

        for (int k = 0; k < numErrors; k++) {
            fprintf(outFile, "%d\n", errors[k]);
        }

        fprintf(outFile, "\n");

        for (int i = 0; i < numBases; i++) {
            simulated_genome[i] = genome[i];
        }

        free(genome);
        genome = (int *)malloc(numBases * sizeof(int));
        free(simulated_genome);
        simulated_genome = (int *)malloc(numBases * sizeof(int));
        free(errors);
        errors = (int *)malloc(numErrors * sizeof(int));
    }

    fclose(inFile);
    fclose(outFile);

    free(genome);
    free(simulated_genome);
    free(errors);

    return 0;
}