//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_VERTICES 10
#define MAX_COLORS 5

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int num_vertices;
pthread_mutex_t mutex;

typedef struct {
    int vertex;
    int *colors;
} ThreadData;

void *color_graph(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int vertex = data->vertex;
    int *colors = data->colors;

    // Find colors that are already used by adjacent vertices
    int available_colors[MAX_COLORS] = {1, 1, 1, 1, 1};

    for (int i = 0; i < num_vertices; i++) {
        if (graph[vertex][i] && colors[i] != -1) { // If vertex i is adjacent and colored
            available_colors[colors[i]] = 0; // Mark color as unavailable
        }
    }

    // Find the first available color
    for (int c = 0; c < MAX_COLORS; c++) {
        if (available_colors[c]) {
            pthread_mutex_lock(&mutex);
            colors[vertex] = c; // Color the vertex
            pthread_mutex_unlock(&mutex);
            break;
        }
    }

    free(data);
    pthread_exit(NULL);
}

void create_graph() {
    num_vertices = 6;
    // Example graph representation (adjacency matrix)
    graph[0][1] = 1; graph[0][2] = 1;
    graph[1][0] = 1; graph[1][3] = 1;
    graph[2][0] = 1; graph[2][3] = 1; graph[2][4] = 1;
    graph[3][1] = 1; graph[3][2] = 1; graph[3][5] = 1;
    graph[4][2] = 1; 
    graph[5][3] = 1;
}

void print_colors(int *colors) {
    printf("Vertex colors:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d -> Color %d\n", i, colors[i]);
    }
}

int main() {
    pthread_t threads[MAX_VERTICES];
    ThreadData *data;
    colors[0] = -1; // Initialize colors
    colors[1] = -1;
    colors[2] = -1;
    colors[3] = -1;
    colors[4] = -1;
    colors[5] = -1;

    // Create the graph and initialize mutex
    create_graph();
    pthread_mutex_init(&mutex, NULL);

    // Spawn threads for each vertex to color them
    for (int i = 0; i < num_vertices; i++) {
        data = (ThreadData *)malloc(sizeof(ThreadData));
        data->vertex = i;
        data->colors = colors;
        pthread_create(&threads[i], NULL, color_graph, (void *)data);
    }

    // Join threads
    for (int i = 0; i < num_vertices; i++) {
        pthread_join(threads[i], NULL);
    }

    print_colors(colors);
    pthread_mutex_destroy(&mutex);
    return 0;
}