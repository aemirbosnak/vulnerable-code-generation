//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    int length;
    char *sequence;
} Gene;

Gene *createGene(int length) {
    Gene *gene = (Gene *)malloc(sizeof(Gene));
    gene->name = (char *)malloc(20 * sizeof(char));
    gene->sequence = (char *)malloc((length + 1) * sizeof(char));
    gene->length = length;

    sprintf(gene->name, "Gene_%d", rand() % 1000);
    for (int i = 0; i < length; i++) {
        gene->sequence[i] = 'A' + rand() % 4;
    }
    gene->sequence[length] = '\0';

    return gene;
}

void printGene(Gene *gene) {
    printf("Name: %s\n", gene->name);
    printf("Length: %d\n", gene->length);
    printf("Sequence: %s\n", gene->sequence);
}

int main() {
    srand(time(NULL));

    int numGenes;
    printf("Enter the number of genes to simulate: ");
    scanf("%d", &numGenes);

    Gene **genes = (Gene **)malloc(numGenes * sizeof(Gene *));

    for (int i = 0; i < numGenes; i++) {
        int length = rand() % 1000 + 1;
        genes[i] = createGene(length);
        printGene(genes[i]);
    }

    free(genes);

    return 0;
}