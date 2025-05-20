//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_BASES 4
#define GENOME_LENGTH 100

char* generate_genome() {
    char* genome = (char*) malloc(sizeof(char) * (GENOME_LENGTH + 1));
    int i;
    for(i = 0; i < GENOME_LENGTH; i++) {
        int base_choice = rand() % NUM_BASES;
        char base;
        switch(base_choice) {
            case 0:
                base = 'A';
                break;
            case 1:
                base = 'C';
                break;
            case 2:
                base = 'G';
                break;
            case 3:
                base = 'T';
                break;
            default:
                base = 'N';
                break;
        }
        genome[i] = base;
    }
    genome[GENOME_LENGTH] = '\0';
    return genome;
}

void print_genome(char* genome) {
    int i;
    for(i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}

void mutate_genome(char* genome, int num_mutations) {
    int i;
    for(i = 0; i < num_mutations; i++) {
        int mutation_index = rand() % GENOME_LENGTH;
        int base_choice = rand() % NUM_BASES;
        char base;
        switch(base_choice) {
            case 0:
                base = 'A';
                break;
            case 1:
                base = 'C';
                break;
            case 2:
                base = 'G';
                break;
            case 3:
                base = 'T';
                break;
            default:
                base = 'N';
                break;
        }
        genome[mutation_index] = base;
    }
}

int main() {
    srand(time(NULL));
    char* genome = generate_genome();
    printf("Original Genome:\n");
    print_genome(genome);

    int num_mutations = rand() % 20 + 1;
    mutate_genome(genome, num_mutations);
    printf("\nMutated Genome (with %d mutations):\n", num_mutations);
    print_genome(genome);

    free(genome);
    return 0;
}