//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Number of vertices in the graph
#define V 4

// Number of threads to use
#define NUM_THREADS 4

// Graph represented as an adjacency matrix
int graph[V][V] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};

// Colors represented as an array of integers
int colors[V];

// Mutex to protect the colors array
pthread_mutex_t colors_mutex;

// Function to check if a vertex can be colored with a given color
bool is_safe(int vertex, int color) {
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}

// Function to color a vertex with a given color
void color_vertex(int vertex, int color) {
    pthread_mutex_lock(&colors_mutex);
    colors[vertex] = color;
    pthread_mutex_unlock(&colors_mutex);
}

// Function to find a valid coloring for the graph
void* find_coloring(void* arg) {
    int* vertices = (int*)arg;
    int vertex = vertices[0];
    int color = vertices[1];

    // Check if the vertex can be colored with the given color
    if (is_safe(vertex, color)) {
        // Color the vertex
        color_vertex(vertex, color);
    }

    // Free the memory allocated for the vertices array
    free(vertices);

    return NULL;
}

int main() {
    // Initialize the colors array
    for (int i = 0; i < V; i++) {
        colors[i] = 0;
    }

    // Initialize the mutex
    pthread_mutex_init(&colors_mutex, NULL);

    // Create the threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < V; i++) {
        // Create a new vertices array for each thread
        int* vertices = malloc(sizeof(int) * 2);
        vertices[0] = i;
        vertices[1] = i + 1;

        // Create a new thread to color the vertex
        pthread_create(&threads[i], NULL, find_coloring, vertices);
    }

    // Join the threads
    for (int i = 0; i < V; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the colors of the vertices
    printf("Colors: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", colors[i]);
    }
    printf("\n");

    // Destroy the mutex
    pthread_mutex_destroy(&colors_mutex);

    return 0;
}