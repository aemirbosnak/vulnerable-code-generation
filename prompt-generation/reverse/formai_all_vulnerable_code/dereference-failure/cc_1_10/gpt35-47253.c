//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GENOME_LENGTH 1000
#define SEQUENCE_LENGTH 200

char* generateRandomGenome() {
    char* genome = malloc(GENOME_LENGTH * sizeof(char));
    int i;
    for (i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = "ACGT"[rand() % 4];
    }
    return genome;
}

char* generateRandomSequence() {
    char* sequence = malloc(SEQUENCE_LENGTH * sizeof(char));
    int i;
    for (i = 0; i < SEQUENCE_LENGTH; i++) {
        sequence[i] = "ACGT"[rand() % 4];
    }
    return sequence;
}

int hammingDistance(char* s1, char* s2) {
    int distance = 0;
    int i;
    for (i = 0; i < strlen(s1); i++) {
        if (s1[i] != s2[i]) {
            distance++;
        }
    }
    return distance;
}

int main() {
    srand(time(NULL));

    char* genome = generateRandomGenome();
    char* sequence = generateRandomSequence();

    printf("Generated genome: %s\n", genome);
    printf("Generated sequence: %s\n\n", sequence);

    int i;
    for (i = 0; i < GENOME_LENGTH - SEQUENCE_LENGTH + 1; i++) {
        char* substring = malloc((SEQUENCE_LENGTH + 1) * sizeof(char));
        strncpy(substring, genome + i, SEQUENCE_LENGTH);
        substring[SEQUENCE_LENGTH] = '\0';

        int distance = hammingDistance(sequence, substring);

        printf("Substring %d: %s - Hamming distance: %d\n", i+1, substring, distance);
        free(substring);
    }

    free(genome);
    free(sequence);

    return 0;
}