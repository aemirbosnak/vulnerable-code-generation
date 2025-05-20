//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100
#define MUTATION_RATE 0.2

char random_nucleotide() {
    int nucleotide = rand() % 4;
    switch(nucleotide) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
        default:
            return 'N';
    }
}

char* generate_genome() {
    char* genome = (char*)malloc(GENOME_LENGTH * sizeof(char));
    for(int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = random_nucleotide();
    }
    return genome;
}

char mutate_nucleotide(char nucleotide) {
    if((rand() / (double)RAND_MAX) < MUTATION_RATE) {
        return random_nucleotide();
    }
    else {
        return nucleotide;
    }
}

char* mutate_genome(char* genome) {
    char* mutated_genome = (char*)malloc(GENOME_LENGTH * sizeof(char));
    for(int i = 0; i < GENOME_LENGTH; i++) {
        mutated_genome[i] = mutate_nucleotide(genome[i]);
    }
    return mutated_genome;
}

int main() {
    srand(time(NULL)); // Seed random number generator with current time

    printf("Generating original genome...\n");
    char* original_genome = generate_genome();
    printf("Original genome: %s\n", original_genome);

    printf("Mutating genome...\n");
    char* mutated_genome = mutate_genome(original_genome);
    printf("Mutated genome: %s\n", mutated_genome);

    free(original_genome);
    free(mutated_genome);
    return 0;
}