//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000
#define POPULATION_SIZE 100
#define MUTATION_RATE 0.01

typedef struct {
    char genome[MAX_GENOME_LENGTH];
} Organism;

void initialize_genome(Organism *organism) {
    const char *nucleotides = "ACGT";
    for (int i = 0; i < MAX_GENOME_LENGTH; i++) {
        organism->genome[i] = nucleotides[rand() % 4];
    }
}

void mutate_genome(Organism *organism) {
    for (int i = 0; i < MAX_GENOME_LENGTH; i++) {
        if ((double)rand() / RAND_MAX < MUTATION_RATE) {
            const char *nucleotides = "ACGT";
            organism->genome[i] = nucleotides[rand() % 4];
        }
    }
}

void print_genome(const Organism *organism) {
    for (int i = 0; i < MAX_GENOME_LENGTH; i++) {
        putchar(organism->genome[i]);
    }
    putchar('\n');
}

void simulate_population(int generations) {
    Organism population[POPULATION_SIZE];

    // Initialize random seed
    srand(time(NULL));

    // Initial population generation
    for (int i = 0; i < POPULATION_SIZE; i++) {
        initialize_genome(&population[i]);
    }

    // Simulation of generations
    for (int gen = 0; gen < generations; gen++) {
        printf("Generation %d:\n", gen + 1);
        for (int i = 0; i < POPULATION_SIZE; i++) {
            print_genome(&population[i]);
        }

        // Mutate genomes for the next generation
        for (int i = 0; i < POPULATION_SIZE; i++) {
            mutate_genome(&population[i]);
        }

        // Simulating the post-apocalyptic challenges (e.g., selection) can be added here.
        // For simplicity, the population is maintained by simple mutation.
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_generations>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int generations = atoi(argv[1]);
    if (generations <= 0) {
        fprintf(stderr, "Please provide a positive integer for generations.\n");
        return EXIT_FAILURE;
    }

    printf("Welcome to the Genome Survivor's Simulator!\n");
    printf("Simulating post-apocalyptic evolution over %d generations...\n", generations);

    simulate_population(generations);

    printf("Simulation complete. The remnants of life have been sequenced!\n");
    
    return EXIT_SUCCESS;
}