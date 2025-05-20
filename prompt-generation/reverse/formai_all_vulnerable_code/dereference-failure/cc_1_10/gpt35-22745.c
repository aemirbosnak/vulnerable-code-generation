//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define N 100     // Length of genome
#define L 10      // Length of read
#define ERR 0.01  // Error rate

// Function to generate random genome
char *generateGenome() {
    char *genome = (char *) malloc(N * sizeof(char));
    int i;
    for (i = 0; i < N; i++) {
        int base = rand() % 4;
        switch (base) {
            case 0: genome[i] = 'A'; break;
            case 1: genome[i] = 'C'; break;
            case 2: genome[i] = 'G'; break;
            case 3: genome[i] = 'T'; break;
        }
    }
    return genome;
}

// Function to generate random read
char *generateRead() {
    char *read = (char *) malloc(L * sizeof(char));
    int i;
    for (i = 0; i < L; i++) {
        int base = rand() % 4;
        switch (base) {
            case 0: read[i] = 'A'; break;
            case 1: read[i] = 'C'; break;
            case 2: read[i] = 'G'; break;
            case 3: read[i] = 'T'; break;
        }
        // introduce errors
        if ((double) rand() / RAND_MAX < ERR) {
            base = rand() % 3;
            switch (base) {
                case 0: read[i] = 'A'; break;
                case 1: read[i] = 'C'; break;
                case 2: read[i] = 'G'; break;
                case 3: read[i] = 'T'; break;
            }
        }
    }
    return read;
}

int main() {
    srand(time(NULL));  // Seed random number generator

    // Generate random genome
    char *genome = generateGenome();

    // Generate random reads
    char **reads = (char **) malloc(N * sizeof(char *));
    int i, j;
    for (i = 0; i < N - L + 1; i++) {
        reads[i] = (char *) malloc((L+1) * sizeof(char));
        for (j = 0; j < L; j++) {
            reads[i][j] = genome[i+j];
        }
        reads[i][L] = '\0';
        // introduce errors
        if ((double) rand() / RAND_MAX < ERR) {
            int pos = rand() % L;
            int base = rand() % 3;
            switch (base) {
                case 0: reads[i][pos] = 'A'; break;
                case 1: reads[i][pos] = 'C'; break;
                case 2: reads[i][pos] = 'G'; break;
                case 3: reads[i][pos] = 'T'; break;
            }
        }
    }
    // Print generated genome and reads
    printf("Generated Genome:\n%s\n", genome);
    printf("Generated Reads:\n");
    for (i = 0; i < N - L + 1; i++) {
        printf("%s\n", reads[i]);
    }

    // Free memory
    free(genome);
    for (i = 0; i < N - L + 1; i++) {
        free(reads[i]);
    }
    free(reads);

    return 0;
}