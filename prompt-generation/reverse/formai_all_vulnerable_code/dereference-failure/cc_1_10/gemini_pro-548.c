//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10
#define MAX_NODES 100

typedef struct {
    int num_nodes;
    int num_edges;
    int **adj_matrix;
} Graph;

typedef struct {
    int num_colors;
    int *color_assignment;
} Coloring;

Graph *create_graph(int num_nodes, int num_edges) {
    Graph *graph = malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->num_edges = num_edges;
    graph->adj_matrix = malloc(sizeof(int *) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        graph->adj_matrix[i] = malloc(sizeof(int) * num_nodes);
        for (int j = 0; j < num_nodes; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }
    return graph;
}

void add_edge(Graph *graph, int node1, int node2) {
    graph->adj_matrix[node1][node2] = 1;
    graph->adj_matrix[node2][node1] = 1;
}

Coloring *greedy_coloring(Graph *graph) {
    Coloring *coloring = malloc(sizeof(Coloring));
    coloring->num_colors = 0;
    coloring->color_assignment = malloc(sizeof(int) * graph->num_nodes);
    for (int i = 0; i < graph->num_nodes; i++) {
        coloring->color_assignment[i] = -1;
    }
    for (int i = 0; i < graph->num_nodes; i++) {
        if (coloring->color_assignment[i] == -1) {
            int available_colors[MAX_COLORS];
            for (int j = 0; j < MAX_COLORS; j++) {
                available_colors[j] = 1;
            }
            for (int j = 0; j < graph->num_nodes; j++) {
                if (graph->adj_matrix[i][j] == 1) {
                    available_colors[coloring->color_assignment[j]] = 0;
                }
            }
            int color = -1;
            for (int j = 0; j < MAX_COLORS; j++) {
                if (available_colors[j] == 1) {
                    color = j;
                    break;
                }
            }
            coloring->color_assignment[i] = color;
            coloring->num_colors++;
        }
    }
    return coloring;
}

int main() {
    Graph *graph = create_graph(5, 5);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    Coloring *coloring = greedy_coloring(graph);
    printf("Number of colors used: %d\n", coloring->num_colors);
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("Node %d: color %d\n", i, coloring->color_assignment[i]);
    }
    return 0;
}