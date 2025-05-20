//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define GENOME_LENGTH 1000
#define NUM_READS 10
#define READ_LENGTH 100

typedef struct {
    int id;
    char* genome;
    int genome_length;
    char** reads;
    int num_reads;
    int read_length;
} GenomeSequencerArgs;

void* genome_sequencer(void* arg) {
    GenomeSequencerArgs* args = (GenomeSequencerArgs*)arg;

    // Generate random reads
    for (int i = 0; i < args->num_reads; i++) {
        // Pick a random start index for the read
        int start_idx = rand() % (args->genome_length - args->read_length + 1);
        // Copy read from genome
        char* read = calloc(args->read_length + 1, sizeof(char));
        memcpy(read, &(args->genome[start_idx]), args->read_length);
        args->reads[i] = read;
    }

    printf("Genome Sequencing Complete: Genome ID %d\n", args->id);
    return NULL;
}

int main() {
    srand(time(NULL));

    // Generate a random genome
    char* genome = calloc(GENOME_LENGTH + 1, sizeof(char));
    for (int i = 0; i < GENOME_LENGTH; i++) {
        // Generate a random nucleotide
        int nucleotide_idx = rand() % 4;
        char nucleotide;
        if (nucleotide_idx == 0) {
            nucleotide = 'A';
        } else if (nucleotide_idx == 1) {
            nucleotide = 'C';
        } else if (nucleotide_idx == 2) {
            nucleotide = 'G';
        } else {
            nucleotide = 'T';
        }
        genome[i] = nucleotide;
    }

    // Create args for genome sequencer threads
    GenomeSequencerArgs args[NUM_READS];
    for (int i = 0; i < NUM_READS; i++) {
        args[i].id = i + 1;
        args[i].genome = genome;
        args[i].genome_length = GENOME_LENGTH;
        args[i].num_reads = 1;
        args[i].read_length = READ_LENGTH;
        args[i].reads = calloc(1, sizeof(char*));
    }

    // Create genome sequencer threads
    pthread_t threads[NUM_READS];
    for (int i = 0; i < NUM_READS; i++) {
        pthread_create(&threads[i], NULL, genome_sequencer, &args[i]);
    }

    // Wait for genome sequencer threads to finish
    for (int i = 0; i < NUM_READS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print reads
    printf("Reads:\n");
    for (int i = 0; i < NUM_READS; i++) {
        printf("Read %d: %s\n", i + 1, args[i].reads[0]);
    }

    // Free memory
    free(genome);
    for (int i = 0; i < NUM_READS; i++) {
        free(args[i].reads[0]);
        free(args[i].reads);
    }

    return 0;
}