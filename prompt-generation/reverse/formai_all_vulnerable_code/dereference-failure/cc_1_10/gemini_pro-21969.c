//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char* name;
    int length;
    char* sequence;
} Chromosome;

typedef struct {
    int num_chromosomes;
    Chromosome* chromosomes;
} Genome;

Genome* create_genome(int num_chromosomes) {
    Genome* genome = (Genome*) malloc(sizeof(Genome));
    if (genome == NULL) {
        perror("malloc");
        return NULL;
    }

    genome->num_chromosomes = num_chromosomes;
    genome->chromosomes = (Chromosome*) malloc(num_chromosomes * sizeof(Chromosome));
    if (genome->chromosomes == NULL) {
        perror("malloc");
        free(genome);
        return NULL;
    }

    for (int i = 0; i < num_chromosomes; i++) {
        genome->chromosomes[i].name = NULL;
        genome->chromosomes[i].length = 0;
        genome->chromosomes[i].sequence = NULL;
    }

    return genome;
}

void free_genome(Genome* genome) {
    if (genome == NULL) {
        return;
    }

    for (int i = 0; i < genome->num_chromosomes; i++) {
        if (genome->chromosomes[i].name != NULL) {
            free(genome->chromosomes[i].name);
        }
        if (genome->chromosomes[i].sequence != NULL) {
            free(genome->chromosomes[i].sequence);
        }
    }

    free(genome->chromosomes);
    free(genome);
}

Chromosome* create_chromosome(char* name, int length) {
    Chromosome* chromosome = (Chromosome*) malloc(sizeof(Chromosome));
    if (chromosome == NULL) {
        perror("malloc");
        return NULL;
    }

    chromosome->name = strdup(name);
    if (chromosome->name == NULL) {
        perror("strdup");
        free(chromosome);
        return NULL;
    }

    chromosome->length = length;
    chromosome->sequence = (char*) malloc(length + 1);
    if (chromosome->sequence == NULL) {
        perror("malloc");
        free(chromosome->name);
        free(chromosome);
        return NULL;
    }

    return chromosome;
}

void free_chromosome(Chromosome* chromosome) {
    if (chromosome == NULL) {
        return;
    }

    if (chromosome->name != NULL) {
        free(chromosome->name);
    }
    if (chromosome->sequence != NULL) {
        free(chromosome->sequence);
    }

    free(chromosome);
}

void generate_sequence(Chromosome* chromosome) {
    int i;
    static const char* nucleotides = "ACGT";
    static const int num_nucleotides = 4;

    if (chromosome == NULL || chromosome->sequence == NULL) {
        return;
    }

    for (i = 0; i < chromosome->length; i++) {
        chromosome->sequence[i] = nucleotides[rand() % num_nucleotides];
    }
    chromosome->sequence[i] = '\0';
}

void print_genome(Genome* genome) {
    int i;

    if (genome == NULL) {
        return;
    }

    for (i = 0; i < genome->num_chromosomes; i++) {
        printf("Chromosome %s: %d bp\n", genome->chromosomes[i].name, genome->chromosomes[i].length);
        printf("Sequence: %s\n\n", genome->chromosomes[i].sequence);
    }
}

int main(int argc, char** argv) {
    int num_chromosomes, i;

    if (argc != 2) {
        printf("Usage: %s <num_chromosomes>\n", argv[0]);
        return 1;
    }

    num_chromosomes = atoi(argv[1]);

    srand(time(NULL));

    Genome* genome = create_genome(num_chromosomes);
    if (genome == NULL) {
        return 1;
    }

    for (i = 0; i < num_chromosomes; i++) {
        char name[16];
        int length;

        sprintf(name, "Chromosome %d", i + 1);
        length = rand() % 1000000 + 1;

        genome->chromosomes[i] = *create_chromosome(name, length);
        generate_sequence(&genome->chromosomes[i]);
    }

    print_genome(genome);

    free_genome(genome);

    return 0;
}