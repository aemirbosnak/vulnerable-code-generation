//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define NUM_BASES 4
#define NUM_AMINO_ACIDS 20

typedef struct {
    char *name;
    char *sequence;
    int length;
} Gene;

Gene *generate_random_gene(int length) {
    Gene *gene = (Gene *) malloc(sizeof(Gene));
    gene->name = (char *) malloc(100 * sizeof(char));
    gene->sequence = (char *) malloc((length + 1) * sizeof(char));
    gene->length = length;

    for (int i = 0; i < length; i++) {
        gene->sequence[i] = "ACGT"[rand() % NUM_BASES];
    }
    gene->sequence[length] = '\0';

    sprintf(gene->name, "Gene_%d", rand());

    return gene;
}

void print_gene(Gene *gene) {
    printf("Name: %s\n", gene->name);
    printf("Sequence: %s\n", gene->sequence);
    printf("Length: %d\n", gene->length);
}

int main() {
    srand(time(NULL));

    int num_genes = rand() % 100 + 1;
    Gene **genes = (Gene **) malloc(num_genes * sizeof(Gene *));

    for (int i = 0; i < num_genes; i++) {
        int length = rand() % MAX_SEQUENCE_LENGTH + 1;
        genes[i] = generate_random_gene(length);
        print_gene(genes[i]);
    }

    free(genes);

    return 0;
}