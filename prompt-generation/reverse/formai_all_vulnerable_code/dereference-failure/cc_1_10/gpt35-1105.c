//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000
#define MUTATION_RATE 0.01f

typedef struct {
    char* nucleotides;
    float* probabilities;
} Gene;

typedef struct {
    int num_genes;
    Gene* genes;
} Genome;

void init_genome(Genome* genome) {
    genome->num_genes = 0;
    genome->genes = NULL;
}

void add_gene(Genome* genome, Gene gene) {
    genome->num_genes++;
    genome->genes = (Gene*) realloc(genome->genes, genome->num_genes * sizeof(Gene));
    genome->genes[genome->num_genes - 1] = gene;
}

void mutate_genome(Genome* genome) {
    srand((unsigned) time(NULL));
    for (int i = 0; i < genome->num_genes; i++) {
        Gene gene = genome->genes[i];
        for (int j = 0; j < GENOME_LENGTH; j++) {
            if ((float)rand() / RAND_MAX <= MUTATION_RATE) {
                gene.nucleotides[j] = (rand() % 4) + 'A';
            }
            gene.probabilities[j] = (float)rand()/(float)RAND_MAX;
        }
        genome->genes[i] = gene;
    }
}

void print_genome(Genome genome) {
    for (int i = 0; i < genome.num_genes; i++) {
        Gene gene = genome.genes[i];
        printf("Gene %d: ", i);
        for (int j = 0; j < GENOME_LENGTH; j++) {
            printf("%c", gene.nucleotides[j]);
        }
        printf("\n");
    }
}

int main() {
    srand((unsigned) time(NULL));
    Genome genome;
    init_genome(&genome);
    for (int i = 0; i < 10; i++) {
        Gene gene;
        gene.nucleotides = (char*) malloc(GENOME_LENGTH * sizeof(char));
        gene.probabilities = (float*) malloc(GENOME_LENGTH * sizeof(float));
        for (int j = 0; j < GENOME_LENGTH; j++) {
            gene.nucleotides[j] = (rand() % 4) + 'A';
            gene.probabilities[j] = (float)rand()/(float)RAND_MAX;
        }
        add_gene(&genome, gene);
    }
    printf("Initial Genome:\n");
    print_genome(genome);
    mutate_genome(&genome);
    printf("\nMutated Genome:\n");
    print_genome(genome);
    return 0;
}