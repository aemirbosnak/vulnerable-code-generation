//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQ_LEN 10000
#define MAX_ERR_RATE 0.1

typedef struct {
    char *seq;
    int len;
    float err_rate;
} genome_t;

genome_t *generate_genome(int len, float err_rate) {
    genome_t *genome = malloc(sizeof(genome_t));
    genome->seq = malloc(len + 1);
    genome->len = len;
    genome->err_rate = err_rate;

    for (int i = 0; i < len; i++) {
        int base = rand() % 4;
        switch (base) {
            case 0:
                genome->seq[i] = 'A';
                break;
            case 1:
                genome->seq[i] = 'C';
                break;
            case 2:
                genome->seq[i] = 'G';
                break;
            case 3:
                genome->seq[i] = 'T';
                break;
        }
    }

    genome->seq[len] = '\0';

    return genome;
}

void introduce_errors(genome_t *genome) {
    for (int i = 0; i < genome->len; i++) {
        if ((float)rand() / RAND_MAX < genome->err_rate) {
            int base = rand() % 4;
            switch (base) {
                case 0:
                    genome->seq[i] = 'A';
                    break;
                case 1:
                    genome->seq[i] = 'C';
                    break;
                case 2:
                    genome->seq[i] = 'G';
                    break;
                case 3:
                    genome->seq[i] = 'T';
                    break;
            }
        }
    }
}

void print_genome(genome_t *genome) {
    printf("%s\n", genome->seq);
}

void free_genome(genome_t *genome) {
    free(genome->seq);
    free(genome);
}

int main() {
    // Generate a genome of length 10000 with an error rate of 0.1%
    genome_t *genome = generate_genome(10000, 0.001);

    // Introduce errors into the genome
    introduce_errors(genome);

    // Print the genome to the console
    print_genome(genome);

    // Free the memory allocated for the genome
    free_genome(genome);

    return 0;
}