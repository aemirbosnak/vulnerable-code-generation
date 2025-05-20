//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define NUM_READS 10000

typedef struct {
    char *sequence;
    int length;
} Genome;

typedef struct {
    char *sequence;
    int start;
    int end;
} Read;

void generate_genome(Genome *genome) {
    srand(time(NULL));
    genome->sequence = malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
    for (int i = 0; i < MAX_SEQUENCE_LENGTH; i++) {
        genome->sequence[i] = rand() % 4; // A, C, G, or T
    }
    genome->length = MAX_SEQUENCE_LENGTH;
}

void generate_reads(Read *reads, int num_reads, Genome *genome) {
    for (int i = 0; i < num_reads; i++) {
        reads[i].sequence = malloc(MAX_READ_LENGTH * sizeof(char));
        reads[i].start = rand() % genome->length;
        reads[i].end = reads[i].start + MAX_READ_LENGTH - 1;
        if (reads[i].end > genome->length - 1) {
            reads[i].end = genome->length - 1;
        }
        for (int j = reads[i].start; j <= reads[i].end; j++) {
            reads[i].sequence[j - reads[i].start] = genome->sequence[j];
        }
    }
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->length; i++) {
        printf("%c", genome->sequence[i]);
    }
    printf("\n");
}

void print_reads(Read *reads, int num_reads) {
    for (int i = 0; i < num_reads; i++) {
        printf("Read %d: %s\n", i + 1, reads[i].sequence);
    }
}

int main() {
    Genome genome;
    generate_genome(&genome);

    Read reads[NUM_READS];
    generate_reads(reads, NUM_READS, &genome);

    print_genome(&genome);
    print_reads(reads, NUM_READS);

    free(genome.sequence);
    for (int i = 0; i < NUM_READS; i++) {
        free(reads[i].sequence);
    }

    return 0;
}