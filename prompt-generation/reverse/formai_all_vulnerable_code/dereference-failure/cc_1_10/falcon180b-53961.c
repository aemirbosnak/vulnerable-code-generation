//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHROMOSOMES 100
#define MAX_BASES 1000
#define MAX_READS 1000

typedef struct {
    char *name;
    int length;
    char *sequence;
} Chromosome;

typedef struct {
    int start;
    int end;
    char strand;
    int length;
    char *sequence;
} Read;

Chromosome *createChromosome(char *name, int length) {
    Chromosome *chromosome = (Chromosome *) malloc(sizeof(Chromosome));
    chromosome->name = name;
    chromosome->length = length;
    chromosome->sequence = (char *) malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        chromosome->sequence[i] = 'A' + rand() % 4;
    }
    chromosome->sequence[length] = '\0';
    return chromosome;
}

Read *createRead(int start, int end, char strand, int length) {
    Read *read = (Read *) malloc(sizeof(Read));
    read->start = start;
    read->end = end;
    read->strand = strand;
    read->length = length;
    read->sequence = (char *) malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        read->sequence[i] = 'A' + rand() % 4;
    }
    read->sequence[length] = '\0';
    return read;
}

void printChromosome(Chromosome *chromosome) {
    printf("Chromosome: %s\n", chromosome->name);
    printf("Length: %d\n", chromosome->length);
    printf("Sequence: %s\n", chromosome->sequence);
}

void printRead(Read *read) {
    printf("Read: %d - %d (%c)\n", read->start, read->end, read->strand);
    printf("Length: %d\n", read->length);
    printf("Sequence: %s\n", read->sequence);
}

int main() {
    srand(time(NULL));

    Chromosome *chromosome1 = createChromosome("Chromosome 1", 1000);
    Chromosome *chromosome2 = createChromosome("Chromosome 2", 500);

    Read *read1 = createRead(0, 200, '+', 100);
    Read *read2 = createRead(400, 600, '-', 200);

    printChromosome(chromosome1);
    printChromosome(chromosome2);

    printRead(read1);
    printRead(read2);

    free(chromosome1->sequence);
    free(chromosome1);
    free(chromosome2->sequence);
    free(chromosome2);

    free(read1->sequence);
    free(read1);
    free(read2->sequence);
    free(read2);

    return 0;
}