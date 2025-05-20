//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_COLORS 10
#define MAX_VERTICES 100

typedef struct {
    int num_vertices;
    int num_edges;
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

typedef struct {
    int num_colors;
    int colors[MAX_VERTICES];
} Coloring;

Graph* create_graph(int num_vertices, int num_edges) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }

    return graph;
}

void add_edge(Graph* graph, int vertex1, int vertex2) {
    graph->adjacency_matrix[vertex1][vertex2] = 1;
    graph->adjacency_matrix[vertex2][vertex1] = 1;
}

bool is_safe(Graph* graph, Coloring* coloring, int vertex, int color) {
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adjacency_matrix[vertex][i] == 1 && coloring->colors[i] == color) {
            return false;
        }
    }

    return true;
}

bool graph_coloring(Graph* graph, Coloring* coloring, int vertex) {
    if (vertex == graph->num_vertices) {
        return true;
    }

    for (int color = 1; color <= coloring->num_colors; color++) {
        if (is_safe(graph, coloring, vertex, color)) {
            coloring->colors[vertex] = color;

            if (graph_coloring(graph, coloring, vertex + 1)) {
                return true;
            }

            coloring->colors[vertex] = 0;
        }
    }

    return false;
}

void print_coloring(Graph* graph, Coloring* coloring) {
    printf("Vertex\tColor\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d\t%d\n", i, coloring->colors[i]);
    }
}

int main() {
    Graph* graph = create_graph(4, 3);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);

    Coloring coloring;
    coloring.num_colors = 3;

    if (graph_coloring(graph, &coloring, 0)) {
        print_coloring(graph, &coloring);
    } else {
        printf("Graph cannot be colored with %d colors.\n", coloring.num_colors);
    }

    return 0;
}