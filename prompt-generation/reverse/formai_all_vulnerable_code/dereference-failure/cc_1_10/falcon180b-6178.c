//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define NUM_READS 1000

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence genome;
Sequence *reads;

void generate_genome() {
    genome.sequence = malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
    genome.length = 0;

    // Generate random genome
    for (int i = 0; i < MAX_SEQUENCE_LENGTH; i++) {
        genome.sequence[i] = rand() % 4; // A, C, G, T
        if (genome.sequence[i]!= 3) { // Ignore N's
            genome.length++;
        }
    }
}

void generate_reads() {
    reads = malloc(NUM_READS * sizeof(Sequence));

    for (int i = 0; i < NUM_READS; i++) {
        reads[i].sequence = malloc(MAX_READ_LENGTH * sizeof(char));
        reads[i].length = 0;

        // Generate random read
        for (int j = 0; j < MAX_READ_LENGTH; j++) {
            reads[i].sequence[j] = rand() % 4; // A, C, G, T
            if (reads[i].sequence[j]!= 3) { // Ignore N's
                reads[i].length++;
            }
        }
    }
}

void print_genome() {
    for (int i = 0; i < genome.length; i++) {
        printf("%c", genome.sequence[i]);
    }
    printf("\n");
}

void print_reads() {
    for (int i = 0; i < NUM_READS; i++) {
        printf("Read %d: ", i + 1);
        for (int j = 0; j < reads[i].length; j++) {
            printf("%c", reads[i].sequence[j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    generate_genome();
    generate_reads();

    print_genome();
    print_reads();

    return 0;
}