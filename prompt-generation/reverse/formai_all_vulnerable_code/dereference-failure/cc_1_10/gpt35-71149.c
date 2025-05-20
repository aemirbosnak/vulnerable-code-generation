//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DEFAULT_GENOME_SIZE 1000
#define DEFAULT_SIMULATION_TIME 10
#define MUTATION_RATE 0.01

typedef struct Genome {
    int size;
    char *sequence;
} Genome;

Genome createGenome(int size);
void printGenome(Genome genome);
void mutate(Genome *genome);
void simulateMutation(Genome genome, int simulationTime);

int main() {

    int genomeSize = DEFAULT_GENOME_SIZE;
    int simulationTime = DEFAULT_SIMULATION_TIME;
    
    Genome genome = createGenome(genomeSize);
    
    printf("Original Genome Sequence:\n");
    printGenome(genome);

    simulateMutation(genome, simulationTime);

    free(genome.sequence);
    return 0;
}

Genome createGenome(int size) {
    Genome genome;
    genome.size = size;
    genome.sequence = malloc(size * sizeof(char));
    for(int i = 0; i < size; i++) {
        genome.sequence[i] = "ATCG"[rand() % 4];
    }
    return genome;
}

void printGenome(Genome genome) {
    printf("%s\n", genome.sequence);
}

void mutate(Genome *genome) {
    int mutationIndex = rand() % genome->size;
    genome->sequence[mutationIndex] = "ATCG"[rand() % 4];
}

void simulateMutation(Genome genome, int simulationTime) {
    printf("\nSimulating Mutation...\n");
    for(int i = 0; i < simulationTime; i++) {
        mutate(&genome);
        printf("Mutated Sequence %d:\n", i+1);
        printGenome(genome);
        if((double)rand() / RAND_MAX < MUTATION_RATE) {
            printf("Error in transmission. Sequence is corrupted.\n");
            break;
        }
    }
}