//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>

// Define the graph structure
typedef struct graph {
    int num_vertices;
    int num_edges;
    int **adj_matrix;
} graph_t;

// Define the thread data structure
typedef struct thread_data {
    graph_t *graph;
    int vertex;
} thread_data_t;

// Define the semaphore
sem_t sem;

// Define the thread function
void *thread_function(void *data) {
    // Get the thread data
    thread_data_t *thread_data = (thread_data_t *)data;

    // Get the graph and vertex from the thread data
    graph_t *graph = thread_data->graph;
    int vertex = thread_data->vertex;

    // Iterate over the adjacency list of the vertex
    for (int i = 0; i < graph->num_vertices; i++) {
        // If there is an edge between the vertex and the current vertex
        if (graph->adj_matrix[vertex][i] == 1) {
            // Acquire the semaphore
            sem_wait(&sem);

            // Print the edge
            printf("Edge: %d -> %d\n", vertex, i);

            // Release the semaphore
            sem_post(&sem);
        }
    }

    // Exit the thread
    pthread_exit(NULL);
}

// Create a graph
graph_t *create_graph(int num_vertices, int num_edges) {
    // Allocate memory for the graph
    graph_t *graph = malloc(sizeof(graph_t));

    // Set the number of vertices and edges
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;

    // Allocate memory for the adjacency matrix
    graph->adj_matrix = malloc(sizeof(int *) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_matrix[i] = malloc(sizeof(int) * num_vertices);
    }

    // Initialize the adjacency matrix to 0
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }

    // Return the graph
    return graph;
}

// Add an edge to the graph
void add_edge(graph_t *graph, int vertex1, int vertex2) {
    // Set the corresponding element in the adjacency matrix to 1
    graph->adj_matrix[vertex1][vertex2] = 1;
}

// Print the graph
void print_graph(graph_t *graph) {
    // Iterate over the adjacency matrix
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            // If there is an edge between the vertex and the current vertex
            if (graph->adj_matrix[i][j] == 1) {
                // Print the edge
                printf("Edge: %d -> %d\n", i, j);
            }
        }
    }
}

// Free the graph
void free_graph(graph_t *graph) {
    // Free the adjacency matrix
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);

    // Free the graph
    free(graph);
}

// Main function
int main() {
    // Create a graph
    graph_t *graph = create_graph(5, 6);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    // Initialize the semaphore
    sem_init(&sem, 0, 1);

    // Create threads
    pthread_t threads[graph->num_vertices];
    for (int i = 0; i < graph->num_vertices; i++) {
        thread_data_t *thread_data = malloc(sizeof(thread_data_t));
        thread_data->graph = graph;
        thread_data->vertex = i;
        pthread_create(&threads[i], NULL, thread_function, (void *)thread_data);
    }

    // Join threads
    for (int i = 0; i < graph->num_vertices; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the semaphore
    sem_destroy(&sem);

    // Free the graph
    free_graph(graph);

    return 0;
}