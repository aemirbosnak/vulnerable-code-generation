//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_NODES 5                     // Number of nodes (threads)
#define DATA_CHUNKS 10                  // Number of data chunks to process

typedef struct {
    int node_id;                       // Node ID
    int *data;                         // Pointer to the data array
    int start_index;                  // Starting index for processing in the data array
    int end_index;                    // Ending index for processing in the data array
} NodeData;

// Function that each thread will run
void* process_data(void* arg) {
    NodeData *node_data = (NodeData*)arg;
    printf("Node %d processing data from %d to %d\n", node_data->node_id, 
        node_data->start_index, node_data->end_index);
    
    // Simulate processing of data chunks
    for (int i = node_data->start_index; i < node_data->end_index; i++) {
        printf("Node %d processing chunk %d\n", node_data->node_id, node_data->data[i]);
        // Simulating processing time
        usleep(100000); // sleeping for 0.1 seconds
    }
    
    free(node_data);   // Free the allocated memory for node data
    pthread_exit(NULL);
}

// Main function
int main() {
    pthread_t threads[NUM_NODES];     // Array of thread identifiers
    int data[DATA_CHUNKS];             // Data to be processed
    int chunks_per_node = DATA_CHUNKS / NUM_NODES;  // Calculate chunks per node

    // Initialize data
    for (int i = 0; i < DATA_CHUNKS; i++) {
        data[i] = i + 1;               // Sample data initialization
    }

    // Create threads (nodes) to process data
    for (int i = 0; i < NUM_NODES; i++) {
        NodeData *node_data = malloc(sizeof(NodeData)); // Allocate memory for node data
        node_data->node_id = i + 1;     // Node ID
        node_data->data = data;          // Pointer to data
        node_data->start_index = i * chunks_per_node; // Start index
        node_data->end_index = (i + 1) * chunks_per_node; // End index

        // Create the thread for this node
        if (pthread_create(&threads[i], NULL, process_data, (void*)node_data) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i + 1);
            return 1;
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_NODES; i++) {
        pthread_join(threads[i], NULL);
        printf("Node %d has completed processing\n", i + 1);
    }

    printf("All nodes completed processing successfully!\n");
    return 0;
}