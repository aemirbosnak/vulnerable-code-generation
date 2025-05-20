//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char *name;
    int length;
    int *sequence;
} Genome;

void generate_random_genome(Genome *genome, int length) {
    genome->sequence = malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        genome->sequence[i] = rand() % 4;
    }
    genome->length = length;
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->length; i++) {
        printf("%d", genome->sequence[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int num_genomes = atoi(argv[1]);
    int genome_length = atoi(argv[2]);

    Genome **genomes = malloc(num_genomes * sizeof(Genome *));
    for (int i = 0; i < num_genomes; i++) {
        genomes[i] = malloc(sizeof(Genome));
        genomes[i]->name = malloc(10 * sizeof(char));
        sprintf(genomes[i]->name, "Genome%d", i);
        generate_random_genome(genomes[i], genome_length);
    }

    for (int i = 0; i < num_genomes; i++) {
        print_genome(genomes[i]);
    }

    for (int i = 0; i < num_genomes; i++) {
        free(genomes[i]->name);
        free(genomes[i]->sequence);
        free(genomes[i]);
    }
    free(genomes);

    return 0;
}