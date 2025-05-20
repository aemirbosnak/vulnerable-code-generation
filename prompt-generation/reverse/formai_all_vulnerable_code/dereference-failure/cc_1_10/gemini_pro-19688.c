//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_COLORS 10

typedef struct Graph {
    int num_vertices;
    int num_edges;
    int **adj_matrix;
} Graph;

Graph *create_graph(int num_vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    graph->adj_matrix = (int **)malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_matrix[i] = (int *)malloc(num_vertices * sizeof(int));
        for (int j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }
    return graph;
}

void add_edge(Graph *graph, int vertex_1, int vertex_2) {
    graph->adj_matrix[vertex_1][vertex_2] = 1;
    graph->adj_matrix[vertex_2][vertex_1] = 1;
    graph->num_edges++;
}

bool is_safe(Graph *graph, int vertex, int color, int *colors) {
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adj_matrix[vertex][i] == 1 && colors[i] == color) {
            return false;
        }
    }
    return true;
}

bool graph_coloring(Graph *graph, int *colors, int vertex) {
    if (vertex == graph->num_vertices) {
        return true;
    }

    for (int color = 1; color <= MAX_COLORS; color++) {
        if (is_safe(graph, vertex, color, colors)) {
            colors[vertex] = color;
            if (graph_coloring(graph, colors, vertex + 1)) {
                return true;
            } else {
                colors[vertex] = 0;
            }
        }
    }
    return false;
}

void print_colors(Graph *graph, int *colors) {
    printf("The colors assigned to the vertices are:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: %d\n", i, colors[i]);
    }
}

int main() {
    int num_vertices;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);

    Graph *graph = create_graph(num_vertices);

    int num_edges;
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &num_edges);

    for (int i = 0; i < num_edges; i++) {
        int vertex_1, vertex_2;
        printf("Enter the vertices connected by edge %d: ", i + 1);
        scanf("%d %d", &vertex_1, &vertex_2);
        add_edge(graph, vertex_1, vertex_2);
    }

    int *colors = (int *)calloc(num_vertices, sizeof(int));

    if (graph_coloring(graph, colors, 0)) {
        printf("The graph can be colored using %d colors.\n", MAX_COLORS);
        print_colors(graph, colors);
    } else {
        printf("The graph cannot be colored using %d colors.\n", MAX_COLORS);
    }

    free(graph);
    free(colors);
    return 0;
}