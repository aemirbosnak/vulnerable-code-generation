//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    int length;
} Gene;

typedef struct {
    int num_genes;
    Gene *genes;
} Genome;

void generate_genome(Genome *genome, int num_genes, int max_length) {
    genome->num_genes = num_genes;
    genome->genes = malloc(sizeof(Gene) * num_genes);

    for (int i = 0; i < num_genes; i++) {
        char *name = malloc(sizeof(char) * (rand() % max_length) + 1);
        for (int j = 0; j < strlen(name); j++) {
            name[j] = rand() % 26 + 'a';
        }
        name[strlen(name)] = '\0';

        genome->genes[i].name = name;
        genome->genes[i].length = rand() % max_length;
    }
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->num_genes; i++) {
        printf("%s (%d)\n", genome->genes[i].name, genome->genes[i].length);
    }
}

int main() {
    srand(time(NULL));

    Genome genome;
    int num_genes;
    printf("Enter the number of genes in the genome: ");
    scanf("%d", &num_genes);

    printf("Enter the maximum length of a gene name: ");
    int max_length;
    scanf("%d", &max_length);

    generate_genome(&genome, num_genes, max_length);
    print_genome(&genome);

    return 0;
}