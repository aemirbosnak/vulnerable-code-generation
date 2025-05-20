//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000
#define NUM_BASES 4

char generate_random_base() {
    int random_num = rand() % NUM_BASES;
    switch(random_num) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
        default:
            return 'N';
    }
}

char* generate_random_genome(int length) {
    char* genome = malloc((length + 1) * sizeof(char));
    for(int i = 0; i < length; i++) {
        genome[i] = generate_random_base();
    }
    genome[length] = '\0';
    return genome;
}

void print_genome(char* genome) {
    printf("%s\n", genome);
}

void mutate_genome(char* genome, float mutation_rate) {
    int genome_length = strlen(genome);
    for(int i = 0; i < genome_length; i++) {
        float random_num = (float) rand() / RAND_MAX;
        if(random_num < mutation_rate) {
            genome[i] = generate_random_base();
        }
    }
}

int main() {
    srand(time(NULL));
    char* genome = generate_random_genome(MAX_GENOME_LENGTH);
    printf("Original Genome:\n");
    print_genome(genome);

    float mutation_rate = 0.1;
    mutate_genome(genome, mutation_rate);
    printf("\nMutated Genome with %.2f mutation rate:\n", mutation_rate);
    print_genome(genome);
    free(genome);

    return 0;
}