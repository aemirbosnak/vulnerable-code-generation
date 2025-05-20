//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQ_LENGTH 1000
#define MAX_ALPHABET_SIZE 26
#define MAX_NUM_SEQS 1000

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    Sequence *sequences;
    int num_seqs;
} Genome;

void generate_random_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }
    sequence[length] = '\0';
}

Genome *create_genome(int num_seqs, int max_seq_length) {
    Genome *genome = (Genome *) malloc(sizeof(Genome));
    genome->sequences = (Sequence *) malloc(num_seqs * sizeof(Sequence));
    genome->num_seqs = num_seqs;

    for (int i = 0; i < num_seqs; i++) {
        genome->sequences[i].sequence = (char *) malloc((max_seq_length + 1) * sizeof(char));
        genome->sequences[i].length = rand() % max_seq_length + 1;
        generate_random_sequence(genome->sequences[i].sequence, genome->sequences[i].length);
    }

    return genome;
}

void print_sequence(Sequence *seq) {
    printf("%s\n", seq->sequence);
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->num_seqs; i++) {
        print_sequence(&genome->sequences[i]);
    }
}

int main() {
    srand(time(NULL));

    int num_seqs = rand() % MAX_NUM_SEQS + 1;
    int max_seq_length = rand() % MAX_SEQ_LENGTH + 1;

    Genome *genome = create_genome(num_seqs, max_seq_length);
    print_genome(genome);

    free(genome->sequences);
    free(genome);

    return 0;
}