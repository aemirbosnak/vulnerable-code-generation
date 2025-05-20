//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Define the graph structure using adjacency matrix
typedef struct {
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

// Function to initialize the graph with given number of vertices
Graph *init_graph(int num_vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->matrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge between two vertices
void add_edge(Graph *graph, int source, int destination) {
    graph->matrix[source][destination] = 1;
    graph->matrix[destination][source] = 1;
}

// Utility function to check if a given coloring is valid or not
bool is_valid_coloring(Graph *graph, int coloring[], int num_vertices, int vertex) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph->matrix[vertex][i] && coloring[i] == coloring[vertex]) {
            return false;
        }
    }
    return true;
}

// Function to find the maximum color for the given graph
int find_max_color(Graph *graph, int num_vertices) {
    int max = 0;
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (graph->matrix[i][j]) {
                max = (max > graph->matrix[i][j] ? max : graph->matrix[i][j]);
            }
        }
    }
    return max;
}

// Function to implement the greedy coloring algorithm
void greedy_coloring(Graph *graph, int coloring[], int num_vertices) {
    int max_color = find_max_color(graph, num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        int color = 0;
        bool assigned = false;

        while (!assigned) {
            if (is_valid_coloring(graph, coloring, num_vertices, i) && color <= max_color) {
                coloring[i] = color;
                assigned = true;
            }
            color++;
        }
    }
}

// Function to print the coloring of vertices in the graph
void print_coloring(int coloring[], int num_vertices) {
    printf("Coloring for vertices:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, coloring[i]);
    }
}

// Main function to test the graph coloring implementation
int main() {
    int num_vertices = 5;

    Graph *graph = init_graph(num_vertices);

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 4);

    int *coloring = (int *)calloc(num_vertices, sizeof(int));

    printf("Greedy Coloring Algorithm:\n");
    greedy_coloring(graph, coloring, num_vertices);
    print_coloring(coloring, num_vertices);

    free(coloring);
    free(graph);

    return 0;
}