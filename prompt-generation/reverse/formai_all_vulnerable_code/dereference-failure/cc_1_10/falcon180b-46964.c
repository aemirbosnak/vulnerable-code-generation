//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26
#define MAX_GENOME_LENGTH 1000000

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    Sequence *sequences;
    int num_sequences;
    int total_length;
} Genome;

void generate_random_genome(Genome *genome) {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < genome->num_sequences; i++) {
        genome->sequences[i].length = rand() % MAX_SEQUENCE_LENGTH + 1;
        genome->sequences[i].sequence = malloc(genome->sequences[i].length * sizeof(char));
        for (j = 0; j < genome->sequences[i].length; j++) {
            genome->sequences[i].sequence[j] = 'A' + rand() % MAX_ALPHABET_SIZE;
        }
    }
    genome->total_length = 0;
    for (i = 0; i < genome->num_sequences; i++) {
        genome->total_length += genome->sequences[i].length;
    }
}

void print_genome(Genome *genome) {
    int i, j;
    for (i = 0; i < genome->num_sequences; i++) {
        printf("Sequence %d:\n", i+1);
        for (j = 0; j < genome->sequences[i].length; j++) {
            printf("%c", genome->sequences[i].sequence[j]);
        }
        printf("\n");
    }
}

int main() {
    Genome genome;
    genome.num_sequences = 10;
    genome.sequences = malloc(genome.num_sequences * sizeof(Sequence));
    generate_random_genome(&genome);
    print_genome(&genome);
    return 0;
}