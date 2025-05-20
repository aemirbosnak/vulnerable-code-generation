//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The size of the genome
#define GENOME_SIZE 100

// Generate a random genome sequence
char* generateGenome() {
    char* genome = malloc(sizeof(char) * (GENOME_SIZE + 1));
    int i;
    for (i = 0; i < GENOME_SIZE; i++) {
        genome[i] = "ACGT"[rand() % 4];
    }
    genome[GENOME_SIZE] = '\0';
    return genome;
}

// Calculate the similarity between two genome sequences
float calculateSimilarity(char* genome1, char* genome2) {
    int i;
    int matches = 0;
    for (i = 0; i < GENOME_SIZE; i++) {
        if (genome1[i] == genome2[i]) {
            matches++;
        }
    }
    return (float) matches / GENOME_SIZE;
}

// Main function that runs the program
int main() {
    srand(time(NULL));

    // Generate two random genome sequences
    char* genome1 = generateGenome();
    char* genome2 = generateGenome();

    // Calculate the similarity between the two genome sequences
    float similarity = calculateSimilarity(genome1, genome2);

    // Print out the genome sequences and the similarity
    printf("Genome 1: %s\n", genome1);
    printf("Genome 2: %s\n", genome2);
    printf("Similarity: %f\n", similarity);

    // Free the allocated memory
    free(genome1);
    free(genome2);

    return 0;
}