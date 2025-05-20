//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define GENOME_LENGTH 100 // sets the length of the genome
#define MUTATION_PROBABILITY 5 // sets the mutation probability to 5%
#define MAX_READS 10 // sets the maximum reads to 10

// Generates a random nucleotide (A, T, C, or G)
char random_nucleotide() {
    int random_number = rand() % 4;
    switch(random_number) {
        case 0:
            return 'A';
        case 1:
            return 'T';
        case 2:
            return 'C';
        case 3:
            return 'G';
        default:
            return 'X';
    }
}

// Generates a random genome of length GENOME_LENGTH
char* generate_genome() {
    char* genome = malloc(GENOME_LENGTH * sizeof(char));
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = random_nucleotide();
    }
    return genome;
}

// Simulates a mutation event - changes a random nucleotide in the genome
void mutate_genome(char* genome) {
    int mutation_index = rand() % GENOME_LENGTH;
    genome[mutation_index] = random_nucleotide();
}

// Simulates a read from the genome - returns a string of length max_read_length starting at a random index
char* read_genome(char* genome, int max_read_length) {
    int read_start_index = rand() % (GENOME_LENGTH - max_read_length);
    char* read = malloc((max_read_length + 1) * sizeof(char));
    strncpy(read, &genome[read_start_index], max_read_length);
    read[max_read_length] = '\0';
    return read;
}


int main() {
    srand(time(NULL));  // sets the seed for the random number generator

    char* original_genome = generate_genome();  // generates the original genome
    printf("Original genome: %s\n", original_genome);

    for(int i = 1; i <= MAX_READS; i++) {
        char* read = read_genome(original_genome, rand() % GENOME_LENGTH);  // generates a random read from the genome
        printf("Read #%d: %s\n", i, read);
        free(read);

        int mutation_chance = rand() % 100;  // determines whether or not to mutate the genome
        if(mutation_chance < MUTATION_PROBABILITY) {
            mutate_genome(original_genome);
            printf("Genome mutated!\n");
        }
    }

    free(original_genome);

    return 0;
}