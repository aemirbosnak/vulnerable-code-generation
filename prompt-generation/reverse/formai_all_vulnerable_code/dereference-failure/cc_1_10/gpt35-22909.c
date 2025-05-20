//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SEQUENCE_LENGTH 10000

typedef struct {
    char *sequence;
    float qualityScore;
} Sequence;

void generateRandomSequence(char *sequence) {
    int i;
    for (i = 0; i < SEQUENCE_LENGTH; i++) {
        int randomNucleotide = rand() % 4;
        switch(randomNucleotide) {
            case 0:
                sequence[i] = 'A';
                break;
            case 1:
                sequence[i] = 'C';
                break;
            case 2:
                sequence[i] = 'G';
                break;
            case 3:
                sequence[i] = 'T';
                break;
        }
    }
}

float calculateQualityScore(char *sequence) {
    float score = 0;
    int i;
    for (i = 0; i < SEQUENCE_LENGTH; i++) {
        switch (sequence[i]) {
            case 'A':
                score += 0.25;
                break;
            case 'C':
                score += 0.5;
                break;
            case 'G':
                score += 0.75;
                break;
            case 'T':
                score += 1;
                break;
        }
    }
    return score / SEQUENCE_LENGTH;
}

void mutateSequence(char *sequence) {
    int numMutations = SEQUENCE_LENGTH * 0.01; // introduce 1% mutations
    int i;
    for (i = 0; i < numMutations; i++) {
        int randomPosition = rand() % SEQUENCE_LENGTH;
        int randomNucleotide = rand() % 4;
        switch(randomNucleotide) {
            case 0:
                sequence[randomPosition] = 'A';
                break;
            case 1:
                sequence[randomPosition] = 'C';
                break;
            case 2:
                sequence[randomPosition] = 'G';
                break;
            case 3:
                sequence[randomPosition] = 'T';
                break;
        }
    }
}

int main() {

    srand(time(NULL)); // seed random number generator

    Sequence originalSequence;
    originalSequence.sequence = malloc(sizeof(char) * SEQUENCE_LENGTH);
    generateRandomSequence(originalSequence.sequence);
    originalSequence.qualityScore = calculateQualityScore(originalSequence.sequence);

    printf("Original Sequence: ");
    int i;
    for (i = 0; i < SEQUENCE_LENGTH; i++) {
        printf("%c", originalSequence.sequence[i]);
    }
    printf("\nQuality Score: %f\n", originalSequence.qualityScore);

    Sequence mutatedSequence = originalSequence;
    mutateSequence(mutatedSequence.sequence);
    mutatedSequence.qualityScore = calculateQualityScore(mutatedSequence.sequence);

    printf("Mutated Sequence: ");
    for (i = 0; i < SEQUENCE_LENGTH; i++) {
        printf("%c", mutatedSequence.sequence[i]);
    }
    printf("\nQuality Score: %f\n", mutatedSequence.qualityScore);

    free(originalSequence.sequence);
    free(mutatedSequence.sequence);

    return 0;
}