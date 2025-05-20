//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_GENOME_SIZE 1000000
#define MAX_READ_LENGTH 100
#define MAX_READS 1000
#define MAX_MISMATCHES 10
#define MAX_GAPS 50

typedef struct {
    char *name;
    char *sequence;
    int length;
} Read;

typedef struct {
    char *name;
    char *sequence;
    int length;
    int num_reads;
    Read *reads;
} Genome;

void generate_genome(Genome *genome) {
    srand(time(NULL));
    genome->name = (char *)malloc(sizeof(char) * 10);
    sprintf(genome->name, "Genome_%d", rand() % 1000);
    genome->length = rand() % MAX_GENOME_SIZE + 1;
    genome->sequence = (char *)malloc(sizeof(char) * genome->length);
    for (int i = 0; i < genome->length; i++) {
        genome->sequence[i] = rand() % 4;
    }
    genome->num_reads = rand() % MAX_READS + 1;
    genome->reads = (Read *)malloc(sizeof(Read) * genome->num_reads);
    for (int i = 0; i < genome->num_reads; i++) {
        genome->reads[i].name = (char *)malloc(sizeof(char) * 10);
        sprintf(genome->reads[i].name, "Read_%d", i);
        genome->reads[i].length = rand() % MAX_READ_LENGTH + 1;
        genome->reads[i].sequence = (char *)malloc(sizeof(char) * genome->reads[i].length);
        for (int j = 0; j < genome->reads[i].length; j++) {
            genome->reads[i].sequence[j] = rand() % 4;
        }
    }
}

void print_genome(Genome *genome) {
    printf("Genome name: %s\n", genome->name);
    printf("Genome length: %d\n", genome->length);
    printf("Genome sequence: %s\n", genome->sequence);
    printf("Number of reads: %d\n", genome->num_reads);
    for (int i = 0; i < genome->num_reads; i++) {
        printf("Read name: %s\n", genome->reads[i].name);
        printf("Read length: %d\n", genome->reads[i].length);
        printf("Read sequence: %s\n", genome->reads[i].sequence);
        printf("\n");
    }
}

void free_genome(Genome *genome) {
    free(genome->name);
    free(genome->sequence);
    for (int i = 0; i < genome->num_reads; i++) {
        free(genome->reads[i].name);
        free(genome->reads[i].sequence);
    }
    free(genome->reads);
}

int main() {
    Genome genome;
    generate_genome(&genome);
    print_genome(&genome);
    free_genome(&genome);
    return 0;
}