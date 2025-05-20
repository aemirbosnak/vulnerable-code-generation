//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define NUM_READS 100000

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int start;
    int end;
} Read;

int main() {
    srand(time(NULL));

    // Generate random DNA sequence
    Sequence genome = {0};
    genome.sequence = malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
    genome.length = MAX_SEQUENCE_LENGTH;

    for (int i = 0; i < genome.length; i++) {
        genome.sequence[i] = rand() % 4 + 'A';
    }

    // Generate reads
    Read *reads = malloc(NUM_READS * sizeof(Read));

    for (int i = 0; i < NUM_READS; i++) {
        reads[i].sequence = malloc(MAX_READ_LENGTH * sizeof(char));
        reads[i].start = rand() % genome.length;
        reads[i].end = reads[i].start + MAX_READ_LENGTH - 1;

        if (reads[i].end > genome.length - 1) {
            reads[i].end = genome.length - 1;
        }

        for (int j = 0; j < MAX_READ_LENGTH; j++) {
            reads[i].sequence[j] = genome.sequence[reads[i].start + j];
        }
    }

    // Print reads
    for (int i = 0; i < NUM_READS; i++) {
        printf("Read %d: %s\n", i + 1, reads[i].sequence);
    }

    // Clean up
    for (int i = 0; i < NUM_READS; i++) {
        free(reads[i].sequence);
    }
    free(reads);
    free(genome.sequence);

    return 0;
}