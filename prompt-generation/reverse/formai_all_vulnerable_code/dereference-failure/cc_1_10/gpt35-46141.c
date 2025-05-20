//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: innovative
// A unique C Program solving the Graph Coloring problem in a innovative style
// This program uses a genetic algorithm to optimize an initial random solution

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POPULATION_SIZE 50
#define MAX_GENERATIONS 1000
#define MUTATION_RATE 0.05
#define CROSSOVER_RATE 0.9

int num_nodes; //number of nodes in the graph
int** adjacency_matrix; //adjacency matrix of the graph
int current_generation = 0; //current generation number

typedef struct {
    int* colors; //array of node colors
    int fitness; //fitness of the individual
} Individual;

Individual population[POPULATION_SIZE]; //population of individuals

// Function to generate a random integer within a given range
int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to generate a random solution
int* generate_random_solution(int num_nodes) {
    int* colors = calloc(num_nodes, sizeof(int));
    for (int i = 0; i < num_nodes; i++) {
        colors[i] = random_int(1, num_nodes);
    }
    return colors;
}

// Function to calculate fitness of an individual
int calculate_fitness(Individual ind) {
    int conflicts = 0;
    for (int i = 0; i < num_nodes; i++) {
        for (int j = i+1; j < num_nodes; j++) {
            if (adjacency_matrix[i][j] && ind.colors[i] == ind.colors[j]) {
                conflicts++;
            }
        }
    }
    return conflicts;
}

// Function to initialize the population with random solutions
void initialize_population() {
    for (int i = 0; i < POPULATION_SIZE; i++) {
        population[i].colors = generate_random_solution(num_nodes);
        population[i].fitness = calculate_fitness(population[i]);
    }
}

// Function to select parents for crossover using tournament selection
int tournament_selection() {
    int best_index = random_int(0, POPULATION_SIZE-1);
    for (int i = 1; i < 3; i++) {
        int idx = random_int(0, POPULATION_SIZE-1);
        if (population[idx].fitness < population[best_index].fitness) {
            best_index = idx;
        }
    }
    return best_index;
}

// Function to perform crossover between two parents
Individual crossover(int parent1_idx, int parent2_idx) {
    Individual child;
    child.colors = calloc(num_nodes, sizeof(int));
    int crossover_point = random_int(1, num_nodes-1);
    for (int i = 0; i < crossover_point; i++) {
        child.colors[i] = population[parent1_idx].colors[i];
    }
    for (int i = crossover_point; i < num_nodes; i++) {
        child.colors[i] = population[parent2_idx].colors[i];
    }
    child.fitness = calculate_fitness(child);
    return child;
}

// Function to perform mutation on an individual
void mutate(Individual* ind) {
    for (int i = 0; i < num_nodes; i++) {
        if (rand() < MUTATION_RATE*RAND_MAX) {
            ind->colors[i] = random_int(1, num_nodes);
        }
    }
    ind->fitness = calculate_fitness(*ind);
}

// Function that returns a pointer to the individual with the best fitness in the population
Individual* get_best_individual() {
    int best_index = 0;
    for (int i = 0; i < POPULATION_SIZE; i++) {
        if (population[i].fitness < population[best_index].fitness) {
            best_index = i;
        }
    }
    return &population[best_index];
}

// Function to print the best individual of the current generation
void print_best_individual() {
    Individual* best = get_best_individual();
    printf("Generation: %d\t Fitness: %d\n", current_generation, best->fitness);
}

// Function to evolve the population by performing selection, crossover and mutation
void evolve_population() {
    Individual new_population[POPULATION_SIZE];

    // Elitism - Keep the best individual in the new population
    new_population[0] = *get_best_individual();

    int i = 1;
    while (i < POPULATION_SIZE) {
        // Tournament selection of two parents
        int parent1_idx = tournament_selection();
        int parent2_idx = tournament_selection();

        // Perform crossover
        if (rand() < CROSSOVER_RATE*RAND_MAX) {
            Individual child = crossover(parent1_idx, parent2_idx);
            new_population[i] = child;
            i++;
        }

        // Perform mutation
        mutate(&population[parent1_idx]);
        mutate(&population[parent2_idx]);
    }

    // Replace old population with new population
    for (int i = 1; i < POPULATION_SIZE; i++) {
        population[i] = new_population[i];
    }
}

int main() {
    srand((unsigned int)time(NULL));

    // Create a sample graph - Complete graph with 5 nodes
    num_nodes = 5;
    adjacency_matrix = calloc(num_nodes, sizeof(int*));
    for (int i = 0; i < num_nodes; i++) {
        adjacency_matrix[i] = calloc(num_nodes, sizeof(int));
    }
    for (int i = 0; i < num_nodes; i++) {
        for (int j = i+1; j < num_nodes; j++) {
            adjacency_matrix[i][j] = 1;
            adjacency_matrix[j][i] = 1;
        }
    }

    // Initialize the population with random solutions
    initialize_population();

    // Evolve the population for a fixed number of generations
    while (current_generation < MAX_GENERATIONS) {
        evolve_population();
        print_best_individual();
        current_generation++;
    }

    // Free memory
    for (int i = 0; i < num_nodes; i++) {
        free(adjacency_matrix[i]);
    }
    free(adjacency_matrix);
    for (int i = 0; i < POPULATION_SIZE; i++) {
        free(population[i].colors);
    }

    return 0;
}