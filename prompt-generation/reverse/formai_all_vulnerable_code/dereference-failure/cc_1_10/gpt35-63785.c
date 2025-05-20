//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define GENOME_LENGTH 1000

char generate_base() {
    char base;
    int random_number = rand() % 4;

    switch (random_number) {
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
            base = '/';
    }

    return base;
}

char* generate_genome() {
    char* genome = malloc((GENOME_LENGTH + 1) * sizeof(char));

    for (int i=0; i<GENOME_LENGTH; i++) {
        genome[i] = generate_base();
    }

    genome[GENOME_LENGTH] = '\0';

    return genome;
}

void print_genome(char* genome) {
    printf("%s\n", genome);
}

int main() {
    srand(time(0));

    char* genome = generate_genome();
    print_genome(genome);

    free(genome);
    return 0;
}