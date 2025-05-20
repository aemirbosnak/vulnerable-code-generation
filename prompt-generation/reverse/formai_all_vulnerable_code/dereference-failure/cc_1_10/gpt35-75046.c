//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 100
#define NUM_BASES 4

char *random_genome() {
    char *genome = malloc(GENOME_SIZE * sizeof(char));
    srand(time(NULL));
    for(int i=0; i<GENOME_SIZE; i++) {
        int base_choice = rand() % NUM_BASES;
        switch(base_choice) {
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
    return genome;
}

int main() {
    char *genome = random_genome();
    printf("Original genome: ");
    for(int i=0; i<GENOME_SIZE; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");

    char *mutated_genome = malloc(GENOME_SIZE * sizeof(char));
    int num_mutations = 0;
    srand(time(NULL));
    for(int i=0; i<GENOME_SIZE; i++) {
        mutated_genome[i] = genome[i];
        int mutation_choice = rand() % 100;
        if(mutation_choice < 10) {
            int base_choice = rand() % NUM_BASES;
            switch(base_choice) {
                case 0:
                    mutated_genome[i] = 'A';
                    break;
                case 1:
                    mutated_genome[i] = 'C';
                    break;
                case 2:
                    mutated_genome[i] = 'G';
                    break;
                case 3:
                    mutated_genome[i] = 'T';
                    break;
            }
            num_mutations++;
        }
    }

    printf("Mutated genome: ");
    for(int i=0; i<GENOME_SIZE; i++) {
        printf("%c", mutated_genome[i]);
    }
    printf("\n");

    printf("Number of mutations: %d\n", num_mutations);

    free(genome);
    free(mutated_genome);

    return 0;
}