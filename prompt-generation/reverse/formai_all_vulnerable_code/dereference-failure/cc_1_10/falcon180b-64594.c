//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALLELES 5
#define POPULATION_SIZE 100

typedef struct {
    char *sequence;
    int length;
} Genome;

typedef struct {
    Genome *genomes;
    int num_genomes;
} Population;

void initialize_population(Population *population) {
    population->genomes = (Genome *) malloc(population->num_genomes * sizeof(Genome));
    for (int i = 0; i < population->num_genomes; i++) {
        population->genomes[i].sequence = (char *) malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
        population->genomes[i].length = rand() % MAX_SEQUENCE_LENGTH + 1;
        for (int j = 0; j < population->genomes[i].length; j++) {
            population->genomes[i].sequence[j] = rand() % 26 + 'A';
        }
    }
}

void print_genome(Genome *genome) {
    printf("Sequence: %s\n", genome->sequence);
    printf("Length: %d\n", genome->length);
}

void simulate_genome_sequencing(Population *population) {
    for (int i = 0; i < population->num_genomes; i++) {
        Genome *genome = &population->genomes[i];
        printf("Sequencing genome %d:\n", i+1);
        print_genome(genome);
    }
}

int main() {
    srand(time(NULL));

    Population population;
    population.num_genomes = POPULATION_SIZE;
    initialize_population(&population);

    simulate_genome_sequencing(&population);

    return 0;
}