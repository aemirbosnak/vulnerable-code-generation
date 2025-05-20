//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_NODES 10
#define MAX_CONN 5

typedef struct {
    int id;
    char *connections[MAX_CONN];
} Node;

Node *nodes[MAX_NODES];
int node_count = 0;

// Function to simulate discovering connections for a node
void *discover_connections(void *arg) {
    Node *node = (Node *)arg;

    // Simulating network connection discovery
    printf("Node %d: Discovering connections...\n", node->id);
    sleep(rand() % 3 + 1); // Simulate delay

    for (int i = 0; i < MAX_CONN; i++) {
        if (rand() % 2) { // Randomly decide to connect
            node->connections[i] = malloc(10);
            sprintf(node->connections[i], "Node%d", rand() % MAX_NODES);
            printf("Node %d: Found connection to %s\n", node->id, node->connections[i]);
        } else {
            node->connections[i] = NULL; // No connection
        }
    }
    return NULL;
}

// Function to create and initialize nodes
void create_nodes() {
    srand(time(NULL));

    for (int i = 0; i < MAX_NODES; i++) {
        nodes[i] = (Node *)malloc(sizeof(Node));
        nodes[i]->id = i;
        memset(nodes[i]->connections, 0, sizeof(nodes[i]->connections));
        node_count++;
    }
}

// Function to clean up node memory
void cleanup_nodes() {
    for (int i = 0; i < node_count; i++) {
        for (int j = 0; j < MAX_CONN; j++) {
            if (nodes[i]->connections[j] != NULL) {
                free(nodes[i]->connections[j]);
            }
        }
        free(nodes[i]);
    }
}

// Main function to initiate the network topology mapping
int main() {
    pthread_t threads[MAX_NODES];

    create_nodes(); // Create and initialize nodes

    // Create threads to discover connections for each node
    for (int i = 0; i < node_count; i++) {
        if (pthread_create(&threads[i], NULL, discover_connections, (void *)nodes[i]) != 0) {
            fprintf(stderr, "Error creating thread for node %d\n", nodes[i]->id);
            cleanup_nodes();
            return 1;
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < node_count; i++) {
        pthread_join(threads[i], NULL);
    }

    // Display results
    printf("\nNetwork topology discovered:\n");
    for (int i = 0; i < node_count; i++) {
        printf("Node %d connections:", nodes[i]->id);
        for (int j = 0; j < MAX_CONN; j++) {
            if (nodes[i]->connections[j] != NULL) {
                printf(" %s,", nodes[i]->connections[j]);
            }
        }
        printf("\b \n"); // Remove the last comma
    }

    cleanup_nodes(); // Free allocated memory
    return 0;
}