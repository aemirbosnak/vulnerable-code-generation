//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure of the genome
struct Genome {
    char* name;
    int length;
    int* sequence;
};

// Function to generate a random DNA sequence
char getRandomBase() {
    char bases[] = {'A', 'C', 'G', 'T'};
    return bases[rand() % 4];
}

// Function to generate a random genome
struct Genome* generateRandomGenome(int length) {
    struct Genome* genome = (struct Genome*) malloc(sizeof(struct Genome));
    genome->name = (char*) malloc(100 * sizeof(char));
    genome->sequence = (int*) malloc(length * sizeof(int));
    genome->length = length;

    // Generate a random name for the genome
    sprintf(genome->name, "Genome_%d", rand());

    // Generate a random DNA sequence
    for (int i = 0; i < length; i++) {
        genome->sequence[i] = getRandomBase();
    }

    return genome;
}

// Function to print the genome sequence
void printGenome(struct Genome* genome) {
    printf("Name: %s\n", genome->name);
    printf("Length: %d\n", genome->length);
    printf("Sequence: ");
    for (int i = 0; i < genome->length; i++) {
        printf("%c", genome->sequence[i]);
    }
    printf("\n");
}

// Function to simulate the sequencing process
void simulateSequencing(struct Genome* genome, int readLength, int numReads) {
    // Initialize the random number generator
    srand(time(NULL));

    // Simulate the reads
    for (int i = 0; i < numReads; i++) {
        int start = rand() % genome->length;
        int end = start + readLength - 1;
        if (end >= genome->length) {
            end = genome->length - 1;
        }

        // Print the read information
        printf("Read %d:\n", i + 1);
        printf("Start position: %d\n", start);
        printf("End position: %d\n", end);
        printf("Sequence: ");
        for (int j = start; j <= end; j++) {
            printf("%c", genome->sequence[j]);
        }
        printf("\n");
    }
}

int main() {
    int length = 1000000;
    int readLength = 100;
    int numReads = 10;

    // Generate a random genome
    struct Genome* genome = generateRandomGenome(length);

    // Print the genome information
    printGenome(genome);

    // Simulate the sequencing process
    simulateSequencing(genome, readLength, numReads);

    return 0;
}