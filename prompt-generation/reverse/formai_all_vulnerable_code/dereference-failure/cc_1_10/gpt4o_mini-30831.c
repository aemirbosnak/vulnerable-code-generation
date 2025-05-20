//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000
#define NUM_SAMPLES 100

typedef struct {
    char id[10];
    char sequence[MAX_GENOME_LENGTH];
} Genome;

Genome* create_genome(const char* id, const char* base_sequence) {
    Genome* new_genome = (Genome*)malloc(sizeof(Genome));
    strcpy(new_genome->id, id);
    if (base_sequence) {
        strncpy(new_genome->sequence, base_sequence, MAX_GENOME_LENGTH);
    } else {
        for (int i = 0; i < MAX_GENOME_LENGTH - 1; i++) {
            new_genome->sequence[i] = "ACGT"[rand() % 4]; // Random ACGT
        }
        new_genome->sequence[MAX_GENOME_LENGTH - 1] = '\0'; // Null-terminate
    }
    return new_genome;
}

void destroy_genome(Genome* genome) {
    if (genome) {
        free(genome);
    }
}

void print_genome(const Genome* genome) {
    printf("Genome ID: %s\n", genome->id);
    printf("Sequence: %s\n", genome->sequence);
}

void mutate_genome(Genome* genome) {
    for (int i = 0; i < MAX_GENOME_LENGTH; i++) {
        if (rand() % 20 == 0) { // 5% mutation chance
            genome->sequence[i] = "ACGT"[rand() % 4]; // New random nucleotide
        }
    }
}

void simulate_sequencing(Genome* genome) {
    printf("Simulating sequencing for Genome ID: %s\n", genome->id);
    int read_length = 50;
    int num_reads = MAX_GENOME_LENGTH / read_length;

    for (int i = 0; i < num_reads; i++) {
        int start = i * read_length;
        char read[read_length + 1];
        strncpy(read, &genome->sequence[start], read_length);
        read[read_length] = '\0'; // Null-terminate the read
        printf("Read %d: %s\n", i + 1, read);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    Genome* genomes[NUM_SAMPLES];

    // Generate artificial genomes
    for (int i = 0; i < NUM_SAMPLES; i++) {
        char id[10];
        snprintf(id, sizeof(id), "G%d", i + 1);
        genomes[i] = create_genome(id, NULL); // Generating random sequences
    }

    // Simulate mutation and sequencing process
    for (int i = 0; i < NUM_SAMPLES; i++) {
        print_genome(genomes[i]);
        mutate_genome(genomes[i]);
        simulate_sequencing(genomes[i]);
        printf("\n");
    }

    // Cleanup
    for (int i = 0; i < NUM_SAMPLES; i++) {
        destroy_genome(genomes[i]);
    }

    return 0;
}