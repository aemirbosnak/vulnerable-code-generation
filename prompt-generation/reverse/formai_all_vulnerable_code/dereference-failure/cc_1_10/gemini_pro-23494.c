//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Graph data structure
typedef struct {
    int n;          // Number of vertices
    int m;          // Number of edges
    int **adj;      // Adjacency matrix
    int *colors;    // Color assignment (0-based)
    int *degrees;   // Degree of each vertex
} Graph;

// 1. Graph Creation
Graph *create_graph(int n, int m) {
    Graph *graph = malloc(sizeof(Graph));
    graph->n = n;
    graph->m = m;
    graph->adj = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph->adj[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            graph->adj[i][j] = 0;
    }
    graph->colors = malloc(n * sizeof(int));
    graph->degrees = malloc(n * sizeof(int));
    return graph;
}

// 2. Graph Destruction
void destroy_graph(Graph *graph) {
    for (int i = 0; i < graph->n; i++)
        free(graph->adj[i]);
    free(graph->adj);
    free(graph->colors);
    free(graph->degrees);
    free(graph);
}

// 3. Graph Coloring
int color_graph(Graph *graph) {
    // Initialize color assignment
    for (int i = 0; i < graph->n; i++)
        graph->colors[i] = -1;

    // Sort vertices by degree in non-increasing order
    for (int i = 0; i < graph->n; i++)
        graph->degrees[i] = 0;
    for (int i = 0; i < graph->n; i++) {
        for (int j = 0; j < graph->n; j++)
            graph->degrees[i] += graph->adj[i][j];
    }
    int *sorted = malloc(graph->n * sizeof(int));
    for (int i = 0; i < graph->n; i++)
        sorted[i] = i;
    for (int i = 0; i < graph->n; i++) {
        for (int j = i + 1; j < graph->n; j++) {
            if (graph->degrees[sorted[i]] < graph->degrees[sorted[j]]) {
                int temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }

    // Greedy coloring algorithm
    int max_color = 0;
    for (int i = 0; i < graph->n; i++) {
        int vertex = sorted[i];
        int color = 0;
        while (1) {
            int valid = 1;
            for (int j = 0; j < graph->n; j++) {
                if (graph->adj[vertex][j] && graph->colors[j] == color) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                graph->colors[vertex] = color;
                if (color > max_color)
                    max_color = color;
                break;
            }
            color++;
        }
    }
    free(sorted);
    return max_color + 1;
}

// 4. Test Driver
int main() {
    // Generate a random graph (n = 10, m = 20)
    Graph *graph = create_graph(10, 20);
    srand(time(NULL));
    for (int i = 0; i < graph->m; i++) {
        int u = rand() % graph->n;
        int v = rand() % graph->n;
        graph->adj[u][v] = 1;
        graph->adj[v][u] = 1;
    }

    // Color the graph
    int num_colors = color_graph(graph);

    // Print the colored graph
    printf("Graph colored with %d colors:\n", num_colors);
    for (int i = 0; i < graph->n; i++) {
        printf("Vertex %d: Color %d\n", i, graph->colors[i]);
    }

    // Destroy the graph
    destroy_graph(graph);

    return 0;
}