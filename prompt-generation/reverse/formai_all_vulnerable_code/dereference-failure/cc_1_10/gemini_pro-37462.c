//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the graph structure
typedef struct graph {
    int num_vertices;
    int num_edges;
    int **adj_matrix;
    pthread_mutex_t lock;
} graph;

// Create a new graph
graph *create_graph(int num_vertices) {
    graph *g = (graph *)malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->num_edges = 0;
    g->adj_matrix = (int **)malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++) {
        g->adj_matrix[i] = (int *)malloc(num_vertices * sizeof(int));
        for (int j = 0; j < num_vertices; j++) {
            g->adj_matrix[i][j] = 0;
        }
    }
    pthread_mutex_init(&g->lock, NULL);
    return g;
}

// Add an edge to the graph
void add_edge(graph *g, int src, int dest) {
    pthread_mutex_lock(&g->lock);
    g->adj_matrix[src][dest] = 1;
    g->num_edges++;
    pthread_mutex_unlock(&g->lock);
}

// Print the graph
void print_graph(graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        for (int j = 0; j < g->num_vertices; j++) {
            printf("%d ", g->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Free the graph
void free_graph(graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        free(g->adj_matrix[i]);
    }
    free(g->adj_matrix);
    free(g);
}

// Function to be executed by each thread
void *thread_function(void *arg) {
    graph *g = (graph *)arg;

    // Generate a random edge
    int src = rand() % g->num_vertices;
    int dest = rand() % g->num_vertices;

    // Add the edge to the graph
    add_edge(g, src, dest);

    return NULL;
}

// Main function
int main() {
    // Create a graph with 10 vertices
    graph *g = create_graph(10);

    // Create 10 threads
    pthread_t threads[10];

    // Create the threads
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, thread_function, g);
    }

    // Join the threads
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the graph
    print_graph(g);

    // Free the graph
    free_graph(g);

    return 0;
}