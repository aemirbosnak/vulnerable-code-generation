//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUCLEOTIDES 4
#define READ_LENGTH 50
#define SEED_LENGTH 20
#define NUM_READS 10

typedef struct {
    char seq[READ_LENGTH + 1];
    int start;
    int end;
} Read;

void generate_random_sequence(char *seq, int length) {
    int i;
    char nucleotides[NUCLEOTIDES][2] = {"AC", "AG", "AT", "CT"};

    for (i = 0; i < length; i++) {
        seq[i] = nucleotides[rand() % NUCLEOTIDES][0];
    }

    seq[length] = '\0';
}

void initialize_reads(Read *reads, int num_reads) {
    int i;

    for (i = 0; i < num_reads; i++) {
        reads[i].start = rand() % (SEED_LENGTH - READ_LENGTH + 1);
        reads[i].end = reads[i].start + READ_LENGTH;
        generate_random_sequence(reads[i].seq, READ_LENGTH);
    }
}

void simulate_sequencing(Read *reads, int num_reads, char *genome, int genome_length) {
    int i, j, k, mismatches = 0;
    char reference[SEED_LENGTH + 1];

    // Initialize the reference sequence
    generate_random_sequence(reference, SEED_LENGTH);
    reference[SEED_LENGTH] = '\0';

    // Compare each read against the reference sequence
    for (i = 0; i < num_reads; i++) {
        for (j = reads[i].start, k = 0; j < reads[i].end; j++, k++) {
            if (genome[j] != reads[i].seq[k]) {
                mismatches++;
            }
        }
    }

    printf("Mismatches: %d\n", mismatches);

    // Free memory
    free(reads);
}

int main() {
    int genome_length = SEED_LENGTH * 2;
    char *genome = malloc(genome_length * sizeof(char));

    generate_random_sequence(genome, genome_length);

    Read *reads = malloc(NUM_READS * sizeof(Read));

    initialize_reads(reads, NUM_READS);
    simulate_sequencing(reads, NUM_READS, genome, genome_length);

    free(reads);
    free(genome);

    return 0;
}