//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_LENGTH 100
#define NUM_SEQUENCERS 4

typedef struct {
    char *genome;
    int start;
    int end;
    char *result;
} SequencerData;

void *sequencer(void *data) {
    SequencerData *seq_data = (SequencerData *)data;

    printf("Sequencer working on genome segment [%d-%d]\n", seq_data->start, seq_data->end);
    for (int i = seq_data->start; i < seq_data->end; i++) {
        // Simulating some processing by adding a character
        seq_data->result[i - seq_data->start] = seq_data->genome[i];
        usleep(100000); // Simulate time taken to process
    }
    printf("Sequencer completed segment [%d-%d]\n", seq_data->start, seq_data->end);
    return NULL;
}

void simulateGenomeSequencing(char *genome) {
    int length = strlen(genome);
    pthread_t threads[NUM_SEQUENCERS];
    SequencerData seq_data[NUM_SEQUENCERS];
    char *results[NUM_SEQUENCERS];

    int segment_length = length / NUM_SEQUENCERS;

    for (int i = 0; i < NUM_SEQUENCERS; i++) {
        results[i] = (char *)malloc(segment_length + 1);
        memset(results[i], 0, segment_length + 1);

        seq_data[i].genome = genome;
        seq_data[i].start = i * segment_length;
        // Make sure the last segment takes the remainder
        seq_data[i].end = (i == NUM_SEQUENCERS - 1) ? length : (i + 1) * segment_length;
        seq_data[i].result = results[i];

        pthread_create(&threads[i], NULL, sequencer, &seq_data[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_SEQUENCERS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Combine results
    printf("\nComplete Genome Sequence:\n");
    for (int i = 0; i < NUM_SEQUENCERS; i++) {
        printf("%s", results[i]);
        free(results[i]);
    }
    printf("\n");
}

int main() {
    char genome[MAX_LENGTH];

    printf("Enter a genome sequence (max %d characters): ", MAX_LENGTH - 1);
    fgets(genome, MAX_LENGTH, stdin);
    genome[strcspn(genome, "\n")] = 0; // Remove newline character

    simulateGenomeSequencing(genome);

    return 0;
}