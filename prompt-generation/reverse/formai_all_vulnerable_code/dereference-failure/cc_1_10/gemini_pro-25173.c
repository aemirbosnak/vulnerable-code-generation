//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_READ_LENGTH 100
#define MAX_GENOME_LENGTH 1000000

typedef struct {
    char* sequence;
    int length;
} Read;

typedef struct {
    char* sequence;
    int length;
} Genome;

Read* generate_read(int length) {
    Read* read = malloc(sizeof(Read));
    read->sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        read->sequence[i] = "ACGT"[rand() % 4];
    }
    read->sequence[length] = '\0';
    read->length = length;
    return read;
}

Genome* generate_genome(int length) {
    Genome* genome = malloc(sizeof(Genome));
    genome->sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        genome->sequence[i] = "ACGT"[rand() % 4];
    }
    genome->sequence[length] = '\0';
    genome->length = length;
    return genome;
}

int main() {
    srand(time(NULL));

    int genome_length = 1000000;
    int read_length = 100;
    int num_reads = 10000;

    Genome* genome = generate_genome(genome_length);
    Read** reads = malloc(num_reads * sizeof(Read*));
    for (int i = 0; i < num_reads; i++) {
        reads[i] = generate_read(read_length);
    }

    // Simulate sequencing by randomly selecting reads from the genome and adding them to the list of reads.
    for (int i = 0; i < num_reads; i++) {
        int start_index = rand() % (genome_length - read_length);
        strncpy(reads[i]->sequence, genome->sequence + start_index, read_length);
    }

    // Print the simulated reads.
    for (int i = 0; i < num_reads; i++) {
        printf("%s\n", reads[i]->sequence);
    }

    // Free the memory allocated for the genome and reads.
    free(genome->sequence);
    free(genome);
    for (int i = 0; i < num_reads; i++) {
        free(reads[i]->sequence);
        free(reads[i]);
    }
    free(reads);

    return 0;
}