//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the genome
#define GENOME_SIZE 1000000

// Define the number of nucleotides
#define NUM_NUCLEOTIDES 4

// Define the nucleotides
enum { A, C, G, T };

// Define the structure of the genome
typedef struct {
    char *sequence;
    int length;
} Genome;

// Function to generate a random nucleotide
char randomNucleotide() {
    return (char) rand() % NUM_NUCLEOTIDES;
}

// Function to generate a random genome
Genome generateRandomGenome(int length) {
    Genome genome;
    genome.sequence = malloc(length + 1);
    genome.length = length;

    // Fill the genome with random nucleotides
    for (int i = 0; i < length; i++) {
        genome.sequence[i] = randomNucleotide();
    }
    genome.sequence[length] = '\0';

    return genome;
}

// Function to print a genome
void printGenome(Genome genome) {
    printf("Genome: %s\n", genome.sequence);
    printf("Length: %d\n", genome.length);
}

// Function to compare two genomes
int compareGenomes(Genome genome1, Genome genome2) {
    int lengthDiff = abs(genome1.length - genome2.length);
    int matchCount = 0;

    // Compare the genomes nucleotide by nucleotide
    for (int i = 0; i < genome1.length && i < genome2.length; i++) {
        if (genome1.sequence[i] == genome2.sequence[i]) {
            matchCount++;
        }
    }

    // Calculate the percentage of matching nucleotides
    float percentMatch = ((float) matchCount / genome1.length) * 100.0;

    return percentMatch;
}

int main() {
    srand(time(NULL));

    // Generate two random genomes
    Genome genome1 = generateRandomGenome(GENOME_SIZE);
    Genome genome2 = generateRandomGenome(GENOME_SIZE);

    // Print the genomes
    printf("Genome 1:\n");
    printGenome(genome1);
    printf("Genome 2:\n");
    printGenome(genome2);

    // Compare the genomes
    int percentMatch = compareGenomes(genome1, genome2);
    printf("Percentage of matching nucleotides: %.2f%%\n", percentMatch);

    return 0;
}