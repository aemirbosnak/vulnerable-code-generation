//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100000
#define NUM_BASES 4
#define MUT_RATE 0.1

char* generate_genome() {
    char* genome = malloc(sizeof(char) * (GENOME_LENGTH + 1));
    genome[GENOME_LENGTH] = '\0';

    for (int i = 0; i < GENOME_LENGTH; i++) {
        int r = rand() % NUM_BASES;
        switch (r) {
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

void print_genome(char* genome) {
    printf("%s\n", genome);
}

void mutate_genome(char* genome) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        float r = (float) rand() / RAND_MAX;
        if (r < MUT_RATE) {
            switch (genome[i]) {
                case 'A':
                    genome[i] = 'C';
                    break;
                case 'C':
                    genome[i] = 'G';
                    break;
                case 'G':
                    genome[i] = 'T';
                    break;
                case 'T':
                    genome[i] = 'A';
                    break;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    char* genome = generate_genome();

    printf("Original genome:\n");
    print_genome(genome);

    printf("\nMutated genome:\n");
    mutate_genome(genome);
    print_genome(genome);

    free(genome);

    return 0;
}