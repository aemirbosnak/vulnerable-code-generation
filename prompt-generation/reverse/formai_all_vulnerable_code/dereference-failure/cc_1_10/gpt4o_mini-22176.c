//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_SEQUENCES 5
#define SEQUENCE_LENGTH 100
#define MAX_BUFF 256

char *sequences[NUM_SEQUENCES];

void *generate_sequence(void *param) {
    int sequence_id = *(int *)param;
    char *sequence = (char *)malloc(sizeof(char) * (SEQUENCE_LENGTH + 1));
    const char nucleotides[] = "ACGT";

    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        sequence[i] = nucleotides[rand() % 4];
    }
    sequence[SEQUENCE_LENGTH] = '\0'; // Null terminate the sequence

    sequences[sequence_id] = sequence;
    printf("Generated Sequence %d: %s\n", sequence_id, sequence);
    return NULL;
}

void *process_sequence(void *param) {
    int sequence_id = *(int *)param;
    char *sequence = sequences[sequence_id];

    int a_count = 0, c_count = 0, g_count = 0, t_count = 0;
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        switch (sequence[i]) {
            case 'A': a_count++; break;
            case 'C': c_count++; break;
            case 'G': g_count++; break;
            case 'T': t_count++; break;
        }
    }

    printf("Processed Sequence %d: A:%d C:%d G:%d T:%d\n", sequence_id, a_count, c_count, g_count, t_count);
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t threads[NUM_SEQUENCES];
    int sequence_ids[NUM_SEQUENCES];

    // Generate sequences asynchronously
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        sequence_ids[i] = i;
        pthread_create(&threads[i], NULL, generate_sequence, &sequence_ids[i]);
    }

    // Wait for sequence generation to complete
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        pthread_join(threads[i], NULL);
    }

    // Process sequences asynchronously
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        pthread_create(&threads[i], NULL, process_sequence, &sequence_ids[i]);
    }

    // Wait for sequence processing to complete
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        free(sequences[i]);
    }

    return 0;
}