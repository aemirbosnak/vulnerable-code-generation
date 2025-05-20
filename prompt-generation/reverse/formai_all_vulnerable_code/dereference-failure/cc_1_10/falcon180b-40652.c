//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_GENOME_LENGTH 1000000

typedef struct {
    char *genome;
    int length;
} Genome;

void generate_genome(Genome *genome) {
    genome->genome = malloc(MAX_GENOME_LENGTH * sizeof(char));
    genome->length = rand() % MAX_GENOME_LENGTH + 1;

    for (int i = 0; i < genome->length; i++) {
        genome->genome[i] = rand() % 4; // A, C, G, T
    }
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->length; i++) {
        printf("%c", genome->genome[i]);
    }
    printf("\n");
}

void compare_genomes(Genome *genome1, Genome *genome2) {
    int match_count = 0;

    for (int i = 0; i < genome1->length && i < genome2->length; i++) {
        if (genome1->genome[i] == genome2->genome[i]) {
            match_count++;
        } else {
            break;
        }
    }

    printf("Match count: %d\n", match_count);
}

int main() {
    srand(time(NULL));

    Genome genome1, genome2;

    generate_genome(&genome1);
    generate_genome(&genome2);

    printf("Genome 1:\n");
    print_genome(&genome1);

    printf("Genome 2:\n");
    print_genome(&genome2);

    compare_genomes(&genome1, &genome2);

    free(genome1.genome);
    free(genome2.genome);

    return 0;
}