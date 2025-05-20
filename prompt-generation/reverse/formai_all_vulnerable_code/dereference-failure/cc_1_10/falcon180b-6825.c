//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHROMOSOMES 50
#define MAX_GENE_LENGTH 1000

struct gene {
    char name[20];
    int length;
    char sequence[MAX_GENE_LENGTH];
};

struct chromosome {
    char name[20];
    int num_genes;
    struct gene genes[MAX_GENE_LENGTH];
};

void generate_gene(struct gene* gene) {
    int i;
    for (i = 0; i < gene->length; i++) {
        gene->sequence[i] = rand() % 4 + 'A';
    }
}

void generate_chromosome(struct chromosome* chromosome) {
    int i;
    for (i = 0; i < chromosome->num_genes; i++) {
        generate_gene(&chromosome->genes[i]);
    }
}

int main() {
    int num_chromosomes;
    printf("Enter the number of chromosomes: ");
    scanf("%d", &num_chromosomes);

    struct chromosome* chromosomes = (struct chromosome*) malloc(num_chromosomes * sizeof(struct chromosome));

    int i;
    for (i = 0; i < num_chromosomes; i++) {
        chromosomes[i].num_genes = rand() % 50 + 1;
        printf("Enter the name of chromosome %d: ", i+1);
        scanf("%s", chromosomes[i].name);
    }

    srand(time(NULL));
    int total_genes = 0;
    for (i = 0; i < num_chromosomes; i++) {
        total_genes += chromosomes[i].num_genes;
    }

    int gene_index = 0;
    for (i = 0; i < num_chromosomes; i++) {
        printf("Generating genes for chromosome %s...\n", chromosomes[i].name);
        int remaining_genes = chromosomes[i].num_genes;
        while (remaining_genes > 0) {
            generate_gene(&chromosomes[i].genes[gene_index]);
            printf("Gene %d generated: %s\n", gene_index+1, chromosomes[i].genes[gene_index].name);
            gene_index++;
            remaining_genes--;
        }
    }

    printf("\nTotal genes generated: %d\n", total_genes);

    return 0;
}