//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define GENOME_SIZE 100000

typedef struct gene {
    char nucleotide;
    int position;
} Gene;

int get_random_nucleotide_index() {
    int nucleotide_indexes[] = {0, 1, 2, 3};
    int random_index = rand() % 4;
    return nucleotide_indexes[random_index];
}

char get_random_nucleotide() {
    char nucleotides[] = {'A', 'C', 'G', 'T'};
    int random_index = get_random_nucleotide_index();
    return nucleotides[random_index];
}

Gene* create_empty_genome() {
    Gene* genome = malloc(GENOME_SIZE * sizeof(Gene));
    for (int i = 0; i < GENOME_SIZE; i++) {
        genome[i].nucleotide = ' ';
        genome[i].position = i;
    }
    return genome;
}

Gene* create_random_genome() {
    Gene* genome = create_empty_genome();
    for (int i = 0; i < GENOME_SIZE; i++) {
        genome[i].nucleotide = get_random_nucleotide();
    }
    return genome;
}

Gene* copy_genome(Gene* genome) {
    Gene* copy = create_empty_genome();
    memcpy(copy, genome, GENOME_SIZE * sizeof(Gene));
    return copy;
}

char* genome_to_string(Gene* genome) {
    char* genome_string = malloc((GENOME_SIZE + 1) * sizeof(char));
    for (int i = 0; i < GENOME_SIZE; i++) {
        genome_string[i] = genome[i].nucleotide;
    }
    genome_string[GENOME_SIZE] = '\0';
    return genome_string;
}

void print_genome(Gene* genome) {
    char* genome_string = genome_to_string(genome);
    printf("%s\n", genome_string);
    free(genome_string);
}

void mutate_genome(Gene* genome) {
    int mutation_rate = 1000; // 0.1% mutation rate
    for (int i = 0; i < GENOME_SIZE; i++) {
        int random_int = rand() % 10000;
        if (random_int < mutation_rate) {
            genome[i].nucleotide = get_random_nucleotide();
        }
    }
}

int main() {
    srand(time(NULL));

    // create an empty genome
    Gene* empty_genome = create_empty_genome();

    // create a random genome
    Gene* random_genome = create_random_genome();
    printf("Random genome:\n");
    print_genome(random_genome);

    // copy the random genome and mutate it
    Gene* mutated_genome = copy_genome(random_genome);
    mutate_genome(mutated_genome);
    printf("Mutated genome:\n");
    print_genome(mutated_genome);

    // free memory
    free(empty_genome);
    free(random_genome);
    free(mutated_genome);

    return 0;
}