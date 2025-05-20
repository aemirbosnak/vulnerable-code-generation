//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000
#define NUM_GENOMES 10
#define SEQUENCE_LENGTH 50

// Function prototypes
void generateRandomSequence(char *sequence, int length);
void printGenome(char genomes[NUM_GENOMES][SEQUENCE_LENGTH]);
void saveGenomesToFile(char genomes[NUM_GENOMES][SEQUENCE_LENGTH]);

int main() {
    srand(time(NULL)); // Seed for random number generation
    char genomes[NUM_GENOMES][SEQUENCE_LENGTH];

    printf("Surprise! Let's generate some random genome sequences!\n");
    
    for (int i = 0; i < NUM_GENOMES; i++) {
        generateRandomSequence(genomes[i], SEQUENCE_LENGTH);
        printf("Genome %d generated: %s\n", i + 1, genomes[i]);
    }
    
    saveGenomesToFile(genomes);
    printf("All genomes are saved to 'genomes.txt'. Check it out!\n");
    
    return 0;
}

// Function to generate a random sequence of DNA
void generateRandomSequence(char *sequence, int length) {
    const char bases[] = "ACGT";
    for (int i = 0; i < length; i++) {
        sequence[i] = bases[rand() % 4]; // Randomly pick A, C, G, or T
    }
    sequence[length] = '\0'; // Null-terminate the string
}

// Function to print all generated genomes
void printGenome(char genomes[NUM_GENOMES][SEQUENCE_LENGTH]) {
    printf("Here are all the generated genomes:\n");
    for (int i = 0; i < NUM_GENOMES; i++) {
        printf("Genome %d: %s\n", i + 1, genomes[i]);
    }
}

// Function to save genomes to a file
void saveGenomesToFile(char genomes[NUM_GENOMES][SEQUENCE_LENGTH]) {
    FILE *file = fopen("genomes.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < NUM_GENOMES; i++) {
        fprintf(file, "Genome %d: %s\n", i + 1, genomes[i]);
    }

    fclose(file);
}