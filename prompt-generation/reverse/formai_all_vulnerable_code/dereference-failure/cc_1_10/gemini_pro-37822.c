//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_READ_LENGTH 100
#define MAX_ERROR_RATE 0.1
#define MAX_COVERAGE 10

typedef struct {
    char *sequence;
    int length;
} Read;

typedef struct {
    Read *reads;
    int num_reads;
} Genome;

Genome *generate_genome(int length) {
    Genome *genome = malloc(sizeof(Genome));
    genome->reads = malloc(sizeof(Read) * MAX_COVERAGE);
    genome->num_reads = 0;

    srand(time(NULL));

    for (int i = 0; i < MAX_COVERAGE; i++) {
        Read read;
        read.length = rand() % MAX_READ_LENGTH + 1;
        read.sequence = malloc(read.length + 1);

        for (int j = 0; j < read.length; j++) {
            int base = rand() % 4;
            switch (base) {
                case 0:
                    read.sequence[j] = 'A';
                    break;
                case 1:
                    read.sequence[j] = 'C';
                    break;
                case 2:
                    read.sequence[j] = 'G';
                    break;
                case 3:
                    read.sequence[j] = 'T';
                    break;
            }
        }

        read.sequence[read.length] = '\0';

        genome->reads[genome->num_reads] = read;
        genome->num_reads++;
    }

    return genome;
}

void free_genome(Genome *genome) {
    for (int i = 0; i < genome->num_reads; i++) {
        free(genome->reads[i].sequence);
    }

    free(genome->reads);
    free(genome);
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->num_reads; i++) {
        printf("%s\n", genome->reads[i].sequence);
    }
}

int main() {
    Genome *genome = generate_genome(1000);

    print_genome(genome);

    free_genome(genome);

    return 0;
}