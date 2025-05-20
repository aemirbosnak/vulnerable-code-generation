//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQ_LENGTH 1000000
#define MAX_NUM_SEQS 10000
#define MAX_NUM_ERRORS 1000

typedef struct {
    char *seq;
    int length;
} sequence_t;

typedef struct {
    sequence_t *seqs;
    int num_seqs;
    int total_length;
} genome_t;

genome_t genome;

void generate_sequence(sequence_t *seq) {
    int i;
    for (i = 0; i < seq->length; i++) {
        switch (rand() % 4) {
            case 0:
                seq->seq[i] = 'A';
                break;
            case 1:
                seq->seq[i] = 'C';
                break;
            case 2:
                seq->seq[i] = 'G';
                break;
            case 3:
                seq->seq[i] = 'T';
                break;
        }
    }
}

void generate_genome(int num_seqs, int seq_length) {
    int i;

    genome.seqs = malloc(sizeof(sequence_t) * num_seqs);
    genome.num_seqs = num_seqs;
    genome.total_length = seq_length * num_seqs;

    for (i = 0; i < num_seqs; i++) {
        genome.seqs[i].seq = malloc(sizeof(char) * seq_length);
        genome.seqs[i].length = seq_length;
        generate_sequence(&genome.seqs[i]);
    }
}

void introduce_errors(int num_errors) {
    int i, j;
    for (i = 0; i < num_errors; i++) {
        int seq_index = rand() % genome.num_seqs;
        int pos = rand() % genome.seqs[seq_index].length;
        switch (rand() % 4) {
            case 0:
                genome.seqs[seq_index].seq[pos] = 'A';
                break;
            case 1:
                genome.seqs[seq_index].seq[pos] = 'C';
                break;
            case 2:
                genome.seqs[seq_index].seq[pos] = 'G';
                break;
            case 3:
                genome.seqs[seq_index].seq[pos] = 'T';
                break;
        }
    }
}

void print_genome() {
    int i;
    for (i = 0; i < genome.num_seqs; i++) {
        printf("%s\n", genome.seqs[i].seq);
    }
}

int main(int argc, char **argv) {
    int num_seqs, seq_length, num_errors;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <num_seqs> <seq_length> <num_errors>\n", argv[0]);
        return 1;
    }

    num_seqs = atoi(argv[1]);
    seq_length = atoi(argv[2]);
    num_errors = atoi(argv[3]);

    srand(time(NULL));

    generate_genome(num_seqs, seq_length);
    introduce_errors(num_errors);
    print_genome();

    return 0;
}