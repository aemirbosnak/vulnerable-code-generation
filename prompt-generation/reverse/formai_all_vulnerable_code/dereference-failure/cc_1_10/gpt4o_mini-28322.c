//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

#define GENOME_SIZE 1000
#define NUM_THREADS 10
#define CHUNK_SIZE (GENOME_SIZE / NUM_THREADS)

typedef struct {
    char* genome_chunk;
    int thread_id;
} thread_data_t;

void* simulate_sequencing(void* arg) {
    thread_data_t* data = (thread_data_t*)arg;
    char* genome_chunk = data->genome_chunk;
    int thread_id = data->thread_id;
    
    printf("Thread %d: Sequencing chunk '%s'\n", thread_id, genome_chunk);
    
    // Simulating time taken for sequencing
    srand(time(0) + thread_id);
    int processing_time = rand() % 3 + 1;  // Simulate processing time between 1 and 3 seconds
    sleep(processing_time);
    
    printf("Thread %d: Completed sequencing of chunk.\n", thread_id);
    
    return NULL;
}

int main() {
    // Generate a sample genome sequence (A, T, C, G)
    char* genome = malloc(GENOME_SIZE + 1);
    const char* nucleotides = "ATCG";
    
    for (int i = 0; i < GENOME_SIZE; i++) {
        genome[i] = nucleotides[rand() % 4];
    }
    genome[GENOME_SIZE] = '\0';
    
    printf("Generated Genome Sequence: %s\n\n", genome);
    
    pthread_t threads[NUM_THREADS];
    thread_data_t thread_data[NUM_THREADS];
    
    for (int i = 0; i < NUM_THREADS; i++) {
        // Allocate memory for each chunk
        char* chunk = malloc(CHUNK_SIZE + 1);
        strncpy(chunk, genome + (i * CHUNK_SIZE), CHUNK_SIZE);
        chunk[CHUNK_SIZE] = '\0';
        
        thread_data[i].genome_chunk = chunk;
        thread_data[i].thread_id = i;
        
        // Create thread to simulate sequencing
        pthread_create(&threads[i], NULL, simulate_sequencing, &thread_data[i]);
    }
    
    // Join the threads after completion
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        free(thread_data[i].genome_chunk);  // Free allocated memory for each chunk
    }
    
    free(genome);  // Free the generated genome
    printf("All threads have completed sequencing.\n");
    
    return 0;
}