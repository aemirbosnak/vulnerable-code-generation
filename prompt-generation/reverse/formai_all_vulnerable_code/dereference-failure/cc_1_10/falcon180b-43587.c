//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct {
    char *name;
    int length;
    int *sequence;
} Genome;

Genome *create_genome(int length) {
    Genome *genome = (Genome *)malloc(sizeof(Genome));
    genome->name = (char *)malloc(20 * sizeof(char));
    sprintf(genome->name, "Genome %d", rand() % 1000);
    genome->length = length;
    genome->sequence = (int *)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        genome->sequence[i] = rand() % 4;
    }
    return genome;
}

void print_genome(Genome *genome) {
    printf("Name: %s\n", genome->name);
    printf("Length: %d\n", genome->length);
    for (int i = 0; i < genome->length; i++) {
        switch (genome->sequence[i]) {
            case 0:
                printf("A");
                break;
            case 1:
                printf("C");
                break;
            case 2:
                printf("G");
                break;
            case 3:
                printf("T");
                break;
        }
    }
    printf("\n");
}

void free_genome(Genome *genome) {
    free(genome->name);
    free(genome->sequence);
    free(genome);
}

int main() {
    srand(time(NULL));
    int num_genomes = 10;
    Genome **genomes = (Genome **)malloc(num_genomes * sizeof(Genome *));
    for (int i = 0; i < num_genomes; i++) {
        int length = rand() % 1000 + 1;
        Genome *genome = create_genome(length);
        genomes[i] = genome;
        print_genome(genome);
    }
    for (int i = 0; i < num_genomes; i++) {
        free_genome(genomes[i]);
    }
    free(genomes);
    return 0;
}