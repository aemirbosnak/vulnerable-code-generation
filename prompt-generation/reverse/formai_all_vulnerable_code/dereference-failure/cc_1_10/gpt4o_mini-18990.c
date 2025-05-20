//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_COLORS 5

int graph[MAX_NODES][MAX_NODES];  // Adjacency matrix representation of the graph
int colors[MAX_NODES];             // Array to hold the color of each node
int num_nodes;                     // Number of nodes in the graph
pthread_mutex_t lock;              // Mutex for synchronization

typedef struct {
    int node;
    int color;
} ThreadData;

// Function to check if it is safe to color the node with the given color
bool isSafe(int node, int color) {
    for (int i = 0; i < num_nodes; i++) {
        if (graph[node][i] == 1 && colors[i] == color) {
            return false;
        }
    }
    return true;
}

// Function to color the graph using threads
void *colorNode(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int node = data->node;

    for (int c = 1; c <= MAX_COLORS; c++) {
        pthread_mutex_lock(&lock);
        if (isSafe(node, c)) {
            colors[node] = c;
            printf("Node %d colored with color %d\n", node, c);
            pthread_mutex_unlock(&lock);
            free(data);
            pthread_exit(NULL);
        }
        pthread_mutex_unlock(&lock);
    }
    free(data);
    pthread_exit(NULL);
}

// Function to initialize the graph
void initializeGraph() {
    // Here we create a simple example graph
    graph[0][1] = 1; graph[1][0] = 1;
    graph[0][2] = 1; graph[2][0] = 1;
    graph[1][2] = 1; graph[2][1] = 1;
    graph[1][3] = 1; graph[3][1] = 1;
    graph[2][4] = 1; graph[4][2] = 1;
    graph[3][4] = 1; graph[4][3] = 1;

    num_nodes = 5; // Total number of nodes in the graph
}

// Main function
int main() {
    pthread_t threads[MAX_NODES];
    pthread_mutex_init(&lock, NULL);
    initializeGraph();

    // Initialize colors array
    for (int i = 0; i < num_nodes; i++) {
        colors[i] = 0;
    }

    // Create threads for coloring each node in the graph
    for (int i = 0; i < num_nodes; i++) {
        ThreadData *data = (ThreadData *)malloc(sizeof(ThreadData));
        data->node = i;
        pthread_create(&threads[i], NULL, colorNode, (void *)data);
    }

    // Join threads
    for (int i = 0; i < num_nodes; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the final color of each node
    printf("Final colors:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: Color %d\n", i, colors[i]);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}