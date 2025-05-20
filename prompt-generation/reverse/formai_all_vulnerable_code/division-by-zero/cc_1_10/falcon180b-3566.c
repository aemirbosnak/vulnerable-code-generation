//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHROMOSOMES 50
#define MAX_GENES 100
#define MAX_BASES 1000

typedef struct {
    char *name;
    int length;
    char *sequence;
} Chromosome;

typedef struct {
    char *name;
    int start;
    int end;
} Gene;

void generate_random_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = rand() % 4 + 'A';
    }
    sequence[length] = '\0';
}

int main() {
    srand(time(0));

    int num_chromosomes;
    printf("Enter the number of chromosomes (max %d): ", MAX_CHROMOSOMES);
    scanf("%d", &num_chromosomes);

    Chromosome chromosomes[num_chromosomes];

    for (int i = 0; i < num_chromosomes; i++) {
        chromosomes[i].name = (char *) malloc(10 * sizeof(char));
        sprintf(chromosomes[i].name, "Chr%d", i + 1);
        chromosomes[i].length = rand() % MAX_BASES + 1;
        chromosomes[i].sequence = (char *) malloc(chromosomes[i].length * sizeof(char));
        generate_random_sequence(chromosomes[i].sequence, chromosomes[i].length);
    }

    int num_genes;
    printf("Enter the number of genes (max %d): ", MAX_GENES);
    scanf("%d", &num_genes);

    Gene genes[num_genes];

    for (int i = 0; i < num_genes; i++) {
        genes[i].name = (char *) malloc(10 * sizeof(char));
        sprintf(genes[i].name, "Gene%d", i + 1);
        genes[i].start = rand() % chromosomes[0].length;
        genes[i].end = rand() % chromosomes[0].length;
    }

    for (int i = 0; i < num_chromosomes; i++) {
        printf("Chromosome %s:\n", chromosomes[i].name);
        for (int j = 0; j < chromosomes[i].length; j++) {
            printf("%c", chromosomes[i].sequence[j]);
        }
        printf("\n");
    }

    for (int i = 0; i < num_genes; i++) {
        printf("Gene %s (%d-%d):\n", genes[i].name, genes[i].start, genes[i].end);
        for (int j = genes[i].start; j <= genes[i].end; j++) {
            printf("%c", chromosomes[0].sequence[j]);
        }
        printf("\n");
    }

    return 0;
}