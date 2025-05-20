//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 100
#define MIN_COLOR 0
#define MAX_COLOR 6

typedef struct Graph {
    int num_vertices;
    int** adj_matrix;
} Graph;

void create_graph(Graph* graph, int num_vertices) {
    graph->num_vertices = num_vertices;
    graph->adj_matrix = malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_matrix[i] = malloc(num_vertices * sizeof(int));
        for (int j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }
}

void add_edge(Graph* graph, int src, int dest) {
    graph->adj_matrix[src][dest] = 1;
    graph->adj_matrix[dest][src] = 1;
}

void free_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
}

int** find_neighbors(Graph* graph, int vertex) {
    int** neighbors = malloc(graph->num_vertices * sizeof(int*));
    int count = 0;

    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adj_matrix[vertex][i] == 1) {
            neighbors[count] = &graph->adj_matrix[i][0];
            count++;
        }
    }

    return neighbors;
}

bool is_safe_to_color(Graph* graph, int vertex, int color) {
    int** neighbors = find_neighbors(graph, vertex);

    for (int i = 0; i < graph->num_vertices; i++) {
        if (neighbors[i] != NULL && graph->adj_matrix[vertex][*neighbors[i]] == 1 && graph->adj_matrix[*neighbors[i]][vertex] == 1 && graph->adj_matrix[*neighbors[i]][vertex] != color) {
            free(neighbors);
            return false;
        }
    }

    free(neighbors);
    return true;
}

int graph_coloring(Graph* graph) {
    int* coloring = calloc(graph->num_vertices, sizeof(int));

    for (int vertex = 0; vertex < graph->num_vertices; vertex++) {
        int color = MIN_COLOR;

        while (!is_safe_to_color(graph, vertex, color)) {
            color++;
            if (color > MAX_COLOR) {
                free(coloring);
                return -1;
            }
        }

        coloring[vertex] = color;
    }

    free(coloring);
    return 1;
}

int main() {
    Graph graph;
    create_graph(&graph, 7);

    add_edge(&graph, 0, 1);
    add_edge(&graph, 0, 2);
    add_edge(&graph, 1, 3);
    add_edge(&graph, 1, 4);
    add_edge(&graph, 2, 3);
    add_edge(&graph, 2, 5);
    add_edge(&graph, 3, 4);
    add_edge(&graph, 3, 5);
    add_edge(&graph, 4, 5);

    int result = graph_coloring(&graph);

    if (result == -1) {
        printf("Graph cannot be colored with given colors.\n");
    } else {
        printf("Graph colored successfully.\n");
    }

    free_graph(&graph);
    return 0;
}