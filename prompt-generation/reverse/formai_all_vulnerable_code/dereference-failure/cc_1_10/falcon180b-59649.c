//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the length of the genome
#define GENOME_LENGTH 1000000

// Define the number of nucleotides
#define NUM_NUCLEOTIDES 4

// Define the nucleotides
char nucleotides[] = {'A', 'C', 'G', 'T'};

// Define the structure of a genome
typedef struct {
    char *sequence;
    int length;
} Genome;

// Function to generate a random genome
Genome *generate_genome() {
    Genome *genome = malloc(sizeof(Genome));
    genome->sequence = malloc(GENOME_LENGTH);
    genome->length = GENOME_LENGTH;

    // Initialize the sequence with random nucleotides
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome->sequence[i] = nucleotides[rand() % NUM_NUCLEOTIDES];
    }

    return genome;
}

// Function to print a genome
void print_genome(Genome *genome) {
    for (int i = 0; i < genome->length; i++) {
        printf("%c", genome->sequence[i]);
    }
    printf("\n");
}

// Function to compare two genomes
int compare_genomes(Genome *genome1, Genome *genome2) {
    int difference_count = 0;
    for (int i = 0; i < genome1->length; i++) {
        if (genome1->sequence[i]!= genome2->sequence[i]) {
            difference_count++;
        }
    }
    return difference_count;
}

int main() {
    srand(time(NULL));

    // Generate two random genomes
    Genome *genome1 = generate_genome();
    Genome *genome2 = generate_genome();

    // Print the genomes
    printf("Genome 1:\n");
    print_genome(genome1);
    printf("Genome 2:\n");
    print_genome(genome2);

    // Compare the genomes and print the result
    int difference_count = compare_genomes(genome1, genome2);
    if (difference_count == 0) {
        printf("The genomes are identical.\n");
    } else {
        printf("The genomes have %d differences.\n", difference_count);
    }

    // Free the memory used by the genomes
    free(genome1->sequence);
    free(genome1);
    free(genome2->sequence);
    free(genome2);

    return 0;
}