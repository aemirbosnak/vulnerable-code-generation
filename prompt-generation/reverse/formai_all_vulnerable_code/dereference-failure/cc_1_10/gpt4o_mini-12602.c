//GPT-4o-mini DATASET v1.0 Category: Graph Coloring Problem ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTICES 10 // Maximum number of vertices
#define MAX_COLORS 5    // Maximum number of colors

typedef struct {
    int vertex;
    int *colors;
    int num_vertices;
    int **adjacency_matrix;
} ThreadData;

int graph[MAX_VERTICES][MAX_VERTICES] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 0, 1},
    {0, 1, 0, 1, 0},
    {1, 0, 1, 0, 1},
    {0, 1, 0, 1, 0}
};

bool isSafe(int v, int c, int colors[], int **adjacency_matrix, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        if (adjacency_matrix[v][i] && c == colors[i]) {
            return false;
        }
    }
    return true;
}

void *colorGraph(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int vertex = data->vertex;
    int *colors = data->colors;
    int num_vertices = data->num_vertices;
    int **adjacency_matrix = data->adjacency_matrix;

    for (int c = 1; c <= MAX_COLORS; c++) {
        if (isSafe(vertex, c, colors, adjacency_matrix, num_vertices)) {
            colors[vertex] = c;
            if (vertex == num_vertices - 1) {
                // Print the color configuration when all vertices are colored
                printf("Coloring solution: ");
                for (int i = 0; i < num_vertices; i++) {
                    printf("Vertex %d -> Color %d | ", i, colors[i]);
                }
                printf("\n");
            } else {
                ThreadData newData;
                newData.vertex = vertex + 1;
                newData.colors = colors;
                newData.num_vertices = num_vertices;
                newData.adjacency_matrix = adjacency_matrix;

                pthread_t thread;
                pthread_create(&thread, NULL, colorGraph, (void *)&newData);
                pthread_join(thread, NULL);
            }
            colors[vertex] = 0; // Backtrack
        }
    }
    return NULL;
}

int main() {
    int num_vertices = 5;
    int *colors = (int *)malloc(num_vertices * sizeof(int));
    for (int i = 0; i < num_vertices; i++)
        colors[i] = 0;

    // Create adjacency matrix from graph array
    int **adjacency_matrix = (int **)malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++) {
        adjacency_matrix[i] = (int *)malloc(num_vertices * sizeof(int));
        memcpy(adjacency_matrix[i], graph[i], num_vertices * sizeof(int));
    }

    ThreadData initialData;
    initialData.vertex = 0;
    initialData.colors = colors;
    initialData.num_vertices = num_vertices;
    initialData.adjacency_matrix = adjacency_matrix;

    pthread_t initial_thread;
    pthread_create(&initial_thread, NULL, colorGraph, (void *)&initialData);
    pthread_join(initial_thread, NULL);

    // Cleanup
    for (int i = 0; i < num_vertices; i++) {
        free(adjacency_matrix[i]);
    }
    free(adjacency_matrix);
    free(colors);

    return 0;
}