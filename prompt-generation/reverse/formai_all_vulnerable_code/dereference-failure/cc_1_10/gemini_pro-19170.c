//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

typedef struct {
    int num_vertices;
    int num_edges;
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
} graph_t;

typedef struct {
    int color;
    bool visited;
} vertex_t;

typedef struct {
    vertex_t vertices[MAX_VERTICES];
    int num_colors;
} coloring_t;

graph_t *create_graph(int num_vertices, int num_edges) {
    graph_t *graph = malloc(sizeof(graph_t));
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }

    return graph;
}

void add_edge(graph_t *graph, int vertex1, int vertex2) {
    graph->adjacency_matrix[vertex1][vertex2] = 1;
    graph->adjacency_matrix[vertex2][vertex1] = 1;
}

coloring_t *create_coloring(graph_t *graph) {
    coloring_t *coloring = malloc(sizeof(coloring_t));
    coloring->num_colors = 0;

    for (int i = 0; i < graph->num_vertices; i++) {
        coloring->vertices[i].color = -1;
        coloring->vertices[i].visited = false;
    }

    return coloring;
}

bool is_safe(graph_t *graph, coloring_t *coloring, int vertex, int color) {
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adjacency_matrix[vertex][i] == 1 && coloring->vertices[i].color == color) {
            return false;
        }
    }

    return true;
}

bool graph_color(graph_t *graph, coloring_t *coloring, int vertex) {
    if (vertex == graph->num_vertices) {
        return true;
    }

    for (int color = 0; color < MAX_COLORS; color++) {
        coloring->vertices[vertex].color = color;

        if (is_safe(graph, coloring, vertex, color)) {
            if (graph_color(graph, coloring, vertex + 1)) {
                return true;
            }

            coloring->vertices[vertex].color = -1;
        }
    }

    return false;
}

void print_coloring(graph_t *graph, coloring_t *coloring) {
    for (int vertex = 0; vertex < graph->num_vertices; vertex++) {
        printf("Vertex %d has color %d\n", vertex, coloring->vertices[vertex].color);
    }
}

int main() {
    graph_t *graph = create_graph(4, 3);
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);

    coloring_t *coloring = create_coloring(graph);

    if (graph_color(graph, coloring, 0)) {
        print_coloring(graph, coloring);
    } else {
        printf("No valid coloring found\n");
    }

    return 0;
}