//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    int length;
    int start;
    int end;
} Gene;

typedef struct {
    Gene *genes;
    int num_genes;
} Chromosome;

typedef struct {
    Chromosome *chromosomes;
    int num_chromosomes;
} Genome;

void generate_gene(Gene *gene) {
    gene->name = (char *)malloc(10 * sizeof(char));
    sprintf(gene->name, "Gene%d", rand() % 100);
    gene->length = rand() % 1000;
    gene->start = rand() % 100000;
    gene->end = gene->start + gene->length - 1;
}

void generate_chromosome(Chromosome *chromosome) {
    chromosome->genes = (Gene *)malloc(10 * sizeof(Gene));
    chromosome->num_genes = rand() % 10;

    for (int i = 0; i < chromosome->num_genes; i++) {
        generate_gene(&chromosome->genes[i]);
    }
}

void generate_genome(Genome *genome) {
    genome->chromosomes = (Chromosome *)malloc(10 * sizeof(Chromosome));
    genome->num_chromosomes = rand() % 10;

    for (int i = 0; i < genome->num_chromosomes; i++) {
        generate_chromosome(&genome->chromosomes[i]);
    }
}

void print_gene(Gene *gene) {
    printf("Name: %s\n", gene->name);
    printf("Length: %d\n", gene->length);
    printf("Start: %d\n", gene->start);
    printf("End: %d\n", gene->end);
}

void print_chromosome(Chromosome *chromosome) {
    printf("Number of genes: %d\n", chromosome->num_genes);

    for (int i = 0; i < chromosome->num_genes; i++) {
        print_gene(&chromosome->genes[i]);
    }
}

void print_genome(Genome *genome) {
    printf("Number of chromosomes: %d\n", genome->num_chromosomes);

    for (int i = 0; i < genome->num_chromosomes; i++) {
        print_chromosome(&genome->chromosomes[i]);
    }
}

int main() {
    srand(time(NULL));

    Genome genome;
    generate_genome(&genome);
    print_genome(&genome);

    return 0;
}