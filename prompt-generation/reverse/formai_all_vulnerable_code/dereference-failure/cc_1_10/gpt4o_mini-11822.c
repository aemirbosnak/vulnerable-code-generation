//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

// Number of CPU cores to simulate
#define NUM_CORES 4

// Structure to hold data for each worker
typedef struct {
    int core_id;
    double usage;
} CoreData;

CoreData core_data[NUM_CORES];

// Function to measure CPU usage for a specific core (simulated)
void* measure_cpu_usage(void* arg) {
    int core_id = *((int*)arg);
    free(arg);

    // Simulate measurement using sleep intervals and random CPU usage
    while (1) {
        // Simulate retrieval of CPU usage between 0-100%
        core_data[core_id].usage = (double)(rand() % 101);
        sleep(1); // Update every second
    }
    
    return NULL;
}

// Function to aggregate CPU usage from all workers
void aggregate_usage() {
    while (1) {
        double total_usage = 0; 
        for (int i = 0; i < NUM_CORES; i++) {
            total_usage += core_data[i].usage;
        }
        
        double average_usage = total_usage / NUM_CORES;
        printf("Average CPU Usage across all cores: %.2f%%\n", average_usage);
        fflush(stdout);
        sleep(3); // Aggregation interval
    }
}

int main() {
    pthread_t threads[NUM_CORES];

    // Initialize core data
    for (int i = 0; i < NUM_CORES; i++) {
        core_data[i].core_id = i;
        core_data[i].usage = 0.0;
        
        // Create a thread to measure CPU usage for each core
        int* core_id = malloc(sizeof(int));
        *core_id = i;
        if (pthread_create(&threads[i], NULL, measure_cpu_usage, core_id) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    // Start the aggregation process in the main thread
    aggregate_usage();

    // Wait for all worker threads to finish (they won't in this example)
    for (int i = 0; i < NUM_CORES; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}