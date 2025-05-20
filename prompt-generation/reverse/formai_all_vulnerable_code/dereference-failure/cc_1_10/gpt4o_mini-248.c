//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define SEQUENCE_LENGTH 1000
#define NUM_THREADS 4
#define NUM_GENOMES 10
#define MAX_MUTATIONS 5

char *genomes[NUM_GENOMES];
pthread_mutex_t mutex;

void *simulate_genome(void *param) {
    int index = *(int *)param;
    char *genome = (char *)malloc(SEQUENCE_LENGTH + 1);
    const char *nucleotides = "ACGT";
    
    // Generate a random genome sequence
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        genome[i] = nucleotides[rand() % 4];
    }
    genome[SEQUENCE_LENGTH] = '\0';

    // Simulate random mutations
    int num_mutations = rand() % (MAX_MUTATIONS + 1);
    
    for (int i = 0; i < num_mutations; i++) {
        int mutation_index = rand() % SEQUENCE_LENGTH;
        genome[mutation_index] = nucleotides[rand() % 4];
    }

    pthread_mutex_lock(&mutex);
    genomes[index] = genome;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t threads[NUM_THREADS];
    int thread_indices[NUM_THREADS];

    pthread_mutex_init(&mutex, NULL);
  
    // Create genomes in a multi-threaded manner
    for (int i = 0; i < NUM_GENOMES; i += NUM_THREADS) {
        for (int j = 0; j < NUM_THREADS && (i + j) < NUM_GENOMES; j++) {
            thread_indices[j] = i + j;
            pthread_create(&threads[j], NULL, simulate_genome, &thread_indices[j]);
        }

        // Join the threads
        for (int j = 0; j < NUM_THREADS && (i + j) < NUM_GENOMES; j++) {
            pthread_join(threads[j], NULL);
        }
    }

    // Print generated genomes
    printf("Generated genomes:\n");
    for (int i = 0; i < NUM_GENOMES; i++) {
        printf("Genome %d: %s\n", i, genomes[i]);
        free(genomes[i]);  // Free allocated memory
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}