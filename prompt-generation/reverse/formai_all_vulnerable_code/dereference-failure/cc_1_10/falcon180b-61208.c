//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQ_LEN 10000
#define NUM_BASES 4
#define NUM_CODON 64

typedef struct {
    char *name;
    char *seq;
} Sequence;

Sequence *create_sequence(char *name, int len) {
    Sequence *seq = (Sequence *)malloc(sizeof(Sequence));
    seq->name = name;
    seq->seq = (char *)malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        seq->seq[i] = rand() % NUM_BASES + 1;
    }
    return seq;
}

void print_sequence(Sequence *seq) {
    printf("%s\n", seq->name);
    printf("Sequence: ");
    for (int i = 0; i < strlen(seq->seq); i++) {
        printf("%c", seq->seq[i]);
    }
    printf("\n");
}

void simulate_genome_sequencing(Sequence *genome, Sequence *read, int read_len) {
    int start_pos = rand() % strlen(genome->seq);
    char *substr = (char *)malloc(read_len * sizeof(char));
    for (int i = 0; i < read_len; i++) {
        substr[i] = genome->seq[start_pos + i];
    }
    read->seq = substr;
}

int main() {
    srand(time(NULL));

    Sequence *genome = create_sequence("Genome", 1000000);
    Sequence *read = create_sequence("Read", 100);

    simulate_genome_sequencing(genome, read, 100);

    print_sequence(genome);
    print_sequence(read);

    return 0;
}