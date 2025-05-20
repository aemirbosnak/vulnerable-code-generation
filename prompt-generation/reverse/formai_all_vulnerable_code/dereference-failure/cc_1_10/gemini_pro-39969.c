//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_READ_LENGTH 100

typedef struct {
    char *sequence;
    int length;
} Read;

typedef struct {
    Read *reads;
    int num_reads;
} Genome;

Genome *simulate_genome(int num_reads, int read_length) {
    Genome *genome = malloc(sizeof(Genome));
    genome->reads = malloc(sizeof(Read) * num_reads);
    genome->num_reads = num_reads;

    srand(time(NULL));

    for (int i = 0; i < num_reads; i++) {
        genome->reads[i].sequence = malloc(sizeof(char) * read_length);
        genome->reads[i].length = read_length;

        for (int j = 0; j < read_length; j++) {
            switch (rand() % 4) {
                case 0:
                    genome->reads[i].sequence[j] = 'A';
                    break;
                case 1:
                    genome->reads[i].sequence[j] = 'C';
                    break;
                case 2:
                    genome->reads[i].sequence[j] = 'G';
                    break;
                case 3:
                    genome->reads[i].sequence[j] = 'T';
                    break;
            }
        }
    }

    return genome;
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->num_reads; i++) {
        printf("%s\n", genome->reads[i].sequence);
    }
}

void free_genome(Genome *genome) {
    for (int i = 0; i < genome->num_reads; i++) {
        free(genome->reads[i].sequence);
    }

    free(genome->reads);
    free(genome);
}

int main() {
    int num_reads = 100;
    int read_length = 100;

    Genome *genome = simulate_genome(num_reads, read_length);
    print_genome(genome);
    free_genome(genome);

    return 0;
}