//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    char *sequence;
    int length;
} Genome;

Genome *create_genome(int id, int length) {
    Genome *genome = malloc(sizeof(Genome));
    genome->id = id;
    genome->length = length;
    genome->sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        genome->sequence[i] = 'A' + rand() % 4;
    }
    genome->sequence[length] = '\0';
    return genome;
}

void destroy_genome(Genome *genome) {
    free(genome->sequence);
    free(genome);
}

void print_genome(Genome *genome) {
    printf("Genome %d:\n", genome->id);
    printf("Length: %d\n", genome->length);
    printf("Sequence: %s\n", genome->sequence);
}

int main() {
    srand(time(NULL));

    int num_genomes = 10;
    int genome_length = 100;

    Genome **genomes = malloc(num_genomes * sizeof(Genome *));
    for (int i = 0; i < num_genomes; i++) {
        genomes[i] = create_genome(i, genome_length);
    }

    for (int i = 0; i < num_genomes; i++) {
        print_genome(genomes[i]);
    }

    for (int i = 0; i < num_genomes; i++) {
        destroy_genome(genomes[i]);
    }
    free(genomes);

    return 0;
}