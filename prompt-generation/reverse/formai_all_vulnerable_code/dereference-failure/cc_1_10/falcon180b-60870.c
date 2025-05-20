//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000
#define NUM_BASES 4

char *bases = "ACGT";

int main() {
    int i, j, sequence_length;
    char *sequence;
    char *genome;
    char *subsequence;
    time_t seed;
    srand(time(&seed));

    // Initialize genome with random bases
    genome = (char*) malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
    for (i = 0; i < MAX_SEQUENCE_LENGTH; i++) {
        genome[i] = bases[rand() % NUM_BASES];
    }

    // Ask user for desired sequence length
    printf("Enter desired sequence length: ");
    scanf("%d", &sequence_length);

    // Generate random subsequence of desired length
    sequence = (char*) malloc((sequence_length + 1) * sizeof(char));
    for (i = 0; i < sequence_length; i++) {
        sequence[i] = bases[rand() % NUM_BASES];
    }
    sequence[sequence_length] = '\0';

    // Search for subsequence in genome
    subsequence = strstr(genome, sequence);

    // Output results
    if (subsequence!= NULL) {
        printf("Subsequence '%s' found at position %d.\n", sequence, subsequence - genome + 1);
    } else {
        printf("Subsequence '%s' not found.\n", sequence);
    }

    free(sequence);
    free(genome);

    return 0;
}