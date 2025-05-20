//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 100
#define MUTATION_RATE 0.01

int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int random_selection(double *weights, int size) {
    double r = (double)rand() / RAND_MAX;
    double cumulative_weight = 0.0;
    for (int i = 0; i < size; i++) {
        cumulative_weight += weights[i];
        if (r < cumulative_weight) {
            return i;
        }
    }
    return size - 1;
}

void mutate(char *genome, int size) {
    for (int i = 0; i < size; i++) {
        double mutation_prob = (double)rand() / RAND_MAX;
        if (mutation_prob < MUTATION_RATE) {
            genome[i] = random_int(65, 90);
        }
    }
}

void crossover(char *parent1, char *parent2, char *child, int size) {
    int crossover_point = random_int(1, size - 1);
    for (int i = 0; i < crossover_point; i++) {
        child[i] = parent1[i];
    }
    for (int i = crossover_point; i < size; i++) {
        child[i] = parent2[i];
    }
}

void generate_initial_population(char **population, double *fitness, int population_size, int genome_size) {
    for (int i = 0; i < population_size; i++) {
        population[i] = (char*)malloc(sizeof(char) * genome_size);
        for (int j = 0; j < genome_size; j++) {
            population[i][j] = random_int(65, 90);
        }
        fitness[i] = 0.0;
    }
}

double calculate_fitness(char *genome, int size) {
    double fitness = 0.0;
    for (int i = 0; i < size; i++) {
        if (genome[i] == 'G' || genome[i] == 'C') {
            fitness += 1.0;
        } else {
            fitness += 0.5;
        }
    }
    return fitness;
}

void evaluate_population(char **population, double *fitness, int population_size, int genome_size) {
    for (int i = 0; i < population_size; i++) {
        fitness[i] = calculate_fitness(population[i], genome_size);
    }
}

void select_parents(char **population, double *fitness, int population_size, int genome_size, char **parents) {
    double *weights = (double*)malloc(sizeof(double) * population_size);
    double total_fitness = 0.0;
    for (int i = 0; i < population_size; i++) {
        total_fitness += fitness[i];
    }
    for (int i = 0; i < population_size; i++) {
        weights[i] = fitness[i] / total_fitness;
    }
    for (int i = 0; i < 2; i++) {
        int parent_index = random_selection(weights, population_size);
        parents[i] = population[parent_index];
    }
    free(weights);
}

void generate_new_population(char **population, double *fitness, int population_size, int genome_size) {
    char **new_population = (char**)malloc(sizeof(char*) * population_size);
    for (int i = 0; i < population_size; i++) {
        char **parents = (char**)malloc(sizeof(char*) * 2);
        select_parents(population, fitness, population_size, genome_size, parents);
        char *child = (char*)malloc(sizeof(char) * genome_size);
        crossover(parents[0], parents[1], child, genome_size);
        mutate(child, genome_size);
        new_population[i] = child;
        free(parents);
    }
    for (int i = 0; i < population_size; i++) {
        free(population[i]);
    }
    free(population);
    population = new_population;
}

int main() {
    srand(time(NULL));
    char **population = (char**)malloc(sizeof(char*) * 10);
    double *fitness = (double*)malloc(sizeof(double) * 10);
    generate_initial_population(population, fitness, 10, GENOME_SIZE);
    int generations = 0;
    while (generations < 1000) {
        evaluate_population(population, fitness, 10, GENOME_SIZE);
        printf("Generation %d: %.2f\n", generations + 1, fitness[0]);
        generate_new_population(population, fitness, 10, GENOME_SIZE);
        generations++;
    }
    free(population);
    free(fitness);
    return 0;
}