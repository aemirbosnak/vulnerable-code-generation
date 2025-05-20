//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define GENOME_LENGTH 1000
#define MUTATION_RATE 0.01
#define REPLICATION_COUNT 100
#define MAX_GENERATIONS 20

char* generate_genome() {
    char* genome = malloc((GENOME_LENGTH + 1) * sizeof(char));
    for (int i = 0; i < GENOME_LENGTH; i++) {
        int base = rand() % 4;
        switch (base) {
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'C';
                break;
            case 2:
                genome[i] = 'G';
                break;
            case 3:
                genome[i] = 'T';
                break;
        }
    }
    genome[GENOME_LENGTH] = '\0';
    return genome;
}

void mutate(char* genome) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        if ((double)rand()/(double)RAND_MAX < MUTATION_RATE) {
            int base = rand() % 4;
            switch (base) {
                case 0:
                    genome[i] = 'A';
                    break;
                case 1:
                    genome[i] = 'C';
                    break;
                case 2:
                    genome[i] = 'G';
                    break;
                case 3:
                    genome[i] = 'T';
                    break;
            }
        }
    }
}

char* replicate(char* genome) {
    char* new_genome = malloc((GENOME_LENGTH + 1) * sizeof(char));
    for (int i = 0; i < GENOME_LENGTH; i++) {
        new_genome[i] = genome[i];
    }
    mutate(new_genome);
    new_genome[GENOME_LENGTH] = '\0';
    return new_genome;
}

void free_genome_population(char** genome_population, int population_size) {
    for (int i = 0; i < population_size; i++) {
        free(genome_population[i]);
    }
    free(genome_population);
}

void print_genome_population(char** genome_population, int population_size) {
    for (int i = 0; i < population_size; i++) {
        printf("%d: %s\n", i, genome_population[i]);
    }
}

int compare_genomes(const void* a, const void* b) {
    char* genome_a = *(char**)a;
    char* genome_b = *(char**)b;
    int fitness_a = 0;
    int fitness_b = 0;
    for (int i = 0; i < GENOME_LENGTH; i++) {
        if (genome_a[i] == 'A') {
            fitness_a++;
        } else if (genome_a[i] == 'C') {
            fitness_a += 2;
        } else if (genome_a[i] == 'G') {
            fitness_a += 3;
        }
        if (genome_b[i] == 'A') {
            fitness_b++;
        } else if (genome_b[i] == 'C') {
            fitness_b += 2;
        } else if (genome_b[i] == 'G') {
            fitness_b += 3;
        }
    }
    return fitness_b - fitness_a; // sort in descending order of fitness
}

int main() {
    srand(time(NULL));
    char** genome_population = malloc(REPLICATION_COUNT * sizeof(char*));
    for (int i = 0; i < REPLICATION_COUNT; i++) {
        genome_population[i] = generate_genome();
    }
    for (int generation = 0; generation < MAX_GENERATIONS; generation++) {
        printf("Generation %d\n", generation);
        qsort(genome_population, REPLICATION_COUNT, sizeof(char*), compare_genomes);
        printf("Top 5 genomes:\n");
        print_genome_population(genome_population, 5);

        char** new_genome_population = malloc(REPLICATION_COUNT * sizeof(char*));
        int i = 0;
        while (i < REPLICATION_COUNT) {
            char* parent = genome_population[rand() % (REPLICATION_COUNT/2)];
            char* child = replicate(parent);
            new_genome_population[i] = child;
            i++;
            if (i < REPLICATION_COUNT) {
                parent = genome_population[rand() % (REPLICATION_COUNT/2)];
                child = replicate(parent);
                new_genome_population[i] = child;
                i++;
            }
        }

        free_genome_population(genome_population, REPLICATION_COUNT);
        genome_population = new_genome_population;
    }
    printf("Final Genome Population:");
    print_genome_population(genome_population, REPLICATION_COUNT);
    free_genome_population(genome_population, REPLICATION_COUNT);
    return 0;
}