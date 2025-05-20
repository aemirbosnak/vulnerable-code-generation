//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000
#define MAX_READ_LENGTH 100
#define NUM_READS 100

char* generate_random_dna_sequence(int length) {
    char *sequence = (char*)malloc(length + 1);
    const char nucleotide[] = {'A', 'C', 'G', 'T'};
    for (int i = 0; i < length; i++) {
        sequence[i] = nucleotide[rand() % 4];
    }
    sequence[length] = '\0';
    return sequence;
}

void simulate_reads(char *genome, char **reads, int num_reads, int read_length) {
    int genome_length = strlen(genome);
    for (int i = 0; i < num_reads; i++) {
        int start_pos = rand() % (genome_length - read_length + 1);
        strncpy(reads[i], genome + start_pos, read_length);
        reads[i][read_length] = '\0';
    }
}

void display_reads(char **reads, int num_reads) {
    printf("Simulated DNA Reads:\n");
    for (int i = 0; i < num_reads; i++) {
        printf("Read %d: %s\n", i + 1, reads[i]);
    }
}

void clean_up(char **reads, int num_reads) {
    for (int i = 0; i < num_reads; i++) {
        free(reads[i]);
    }
}

int main() {
    srand(time(0)); // Seed random number generator
    int genome_length = MAX_GENOME_LENGTH;
    
    char *genome = generate_random_dna_sequence(genome_length);
    printf("Generated Genome: %s\n", genome);

    char **reads = (char**)malloc(NUM_READS * sizeof(char*));
    for (int i = 0; i < NUM_READS; i++) {
        reads[i] = (char*)malloc((MAX_READ_LENGTH + 1) * sizeof(char));
    }

    simulate_reads(genome, reads, NUM_READS, MAX_READ_LENGTH);
    display_reads(reads, NUM_READS);

    clean_up(reads, NUM_READS);
    free(genome);
    
    return 0;
}