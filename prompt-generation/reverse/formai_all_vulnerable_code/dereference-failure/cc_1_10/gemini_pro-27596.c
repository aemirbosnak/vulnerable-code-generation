//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_READ_LENGTH 1000
#define MAX_NUM_READS 1000000

typedef struct {
    char *sequence;
    int length;
} Read;

typedef struct {
    Read *reads;
    int num_reads;
} Genome;

Genome *generate_genome(int num_bases) {
    Genome *genome = malloc(sizeof(Genome));

    genome->reads = malloc(sizeof(Read) * MAX_NUM_READS);
    genome->num_reads = 0;

    // Generate random sequences for each read
    for (int i = 0; i < MAX_NUM_READS; i++) {
        int read_length = rand() % MAX_READ_LENGTH + 1;
        genome->reads[i].sequence = malloc(sizeof(char) * read_length);
        genome->reads[i].length = read_length;

        for (int j = 0; j < read_length; j++) {
            genome->reads[i].sequence[j] = rand() % 4 + 'A';
        }
    }

    return genome;
}

void write_genome_to_file(Genome *genome, char *filename) {
    FILE *fp = fopen(filename, "w");

    for (int i = 0; i < genome->num_reads; i++) {
        fprintf(fp, ">read%d\n", i);
        fprintf(fp, "%s\n", genome->reads[i].sequence);
    }

    fclose(fp);
}

void free_genome(Genome *genome) {
    for (int i = 0; i < genome->num_reads; i++) {
        free(genome->reads[i].sequence);
    }

    free(genome->reads);
    free(genome);
}

int main() {
    // Set random seed
    srand(time(NULL));

    // Generate a simulated genome
    Genome *genome = generate_genome(1000000);

    // Write the simulated genome to a file
    write_genome_to_file(genome, "simulated_genome.fasta");

    // Free the memory allocated for the simulated genome
    free_genome(genome);

    return 0;
}