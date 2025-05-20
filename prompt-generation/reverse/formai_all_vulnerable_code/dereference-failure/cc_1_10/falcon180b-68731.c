//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DNA_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 100000

typedef struct {
    char *sequence;
    int length;
} DNAStr;

typedef struct {
    DNAStr *dna_sequence;
    int num_reads;
    int read_length;
} Genome;

void generate_random_dna_sequence(DNAStr *dna_sequence, int length) {
    for (int i = 0; i < length; i++) {
        dna_sequence->sequence[i] = 'A' + rand() % 4;
    }
    dna_sequence->length = length;
}

void generate_random_genome(Genome *genome, int num_reads, int read_length) {
    genome->dna_sequence = (DNAStr *) malloc(sizeof(DNAStr) * num_reads);
    for (int i = 0; i < num_reads; i++) {
        generate_random_dna_sequence(&genome->dna_sequence[i], read_length);
    }
    genome->num_reads = num_reads;
    genome->read_length = read_length;
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->num_reads; i++) {
        printf("%s\n", genome->dna_sequence[i].sequence);
    }
}

int main() {
    srand(time(NULL));

    Genome genome;
    int num_reads, read_length;

    printf("Enter the number of reads: ");
    scanf("%d", &num_reads);

    printf("Enter the read length: ");
    scanf("%d", &read_length);

    genome.num_reads = num_reads;
    genome.read_length = read_length;
    genome.dna_sequence = (DNAStr *) malloc(sizeof(DNAStr) * num_reads);

    for (int i = 0; i < num_reads; i++) {
        generate_random_dna_sequence(&genome.dna_sequence[i], read_length);
    }

    printf("Genome:\n");
    print_genome(&genome);

    return 0;
}