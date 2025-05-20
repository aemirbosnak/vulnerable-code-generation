//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GENOME_SIZE 1000

char alphabet[4] = {'A', 'C', 'G', 'T'};

typedef struct chromosome {
    char* genome;
    int length;
} Chromosome;

Chromosome mutate(Chromosome c) {
    int mutations = rand() % 11;
    for (int i = 0; i < mutations; i++) {
        int index = rand() % c.length;
        int replacement = rand() % 4;
        c.genome[index] = alphabet[replacement];
    }
    return c;
}

Chromosome crossover(Chromosome c1, Chromosome c2) {
    int crossover_point = rand() % c1.length;
    for (int i = crossover_point; i < c1.length; i++) {
        char temp = c1.genome[i];
        c1.genome[i] = c2.genome[i];
        c2.genome[i] = temp;
    }
    if (rand() % 2 == 0) {
        return mutate(c1);
    } else {
        return mutate(c2);
    }
}

Chromosome createRandomChromosome() {
    Chromosome c;
    c.length = GENOME_SIZE;
    c.genome = (char*)malloc(sizeof(char) * GENOME_SIZE);
    for (int i = 0; i < GENOME_SIZE; i++) {
        int random_index = rand() % 4;
        c.genome[i] = alphabet[random_index];
    }
    return c;
}

void printChromosome(Chromosome c) {
    for (int i = 0; i < c.length; i++) {
        printf("%c", c.genome[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Chromosome c1 = createRandomChromosome();
    Chromosome c2 = createRandomChromosome();

    printf("Parent 1: ");
    printChromosome(c1);

    printf("Parent 2: ");
    printChromosome(c2);

    Chromosome c3 = crossover(c1, c2);

    printf("Offspring: ");
    printChromosome(c3);

    return 0;
}