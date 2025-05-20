//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_COLORS 10
#define MAX_NODES 100

typedef struct {
    int num_nodes;
    int num_edges;
    int** adjacency_matrix;
} Graph;

Graph* create_graph(int num_nodes, int num_edges) {
    Graph* graph = malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->num_edges = num_edges;
    graph->adjacency_matrix = malloc(sizeof(int*) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        graph->adjacency_matrix[i] = malloc(sizeof(int) * num_nodes);
        for (int j = 0; j < num_nodes; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }
    return graph;
}

void add_edge(Graph* graph, int node1, int node2) {
    graph->adjacency_matrix[node1][node2] = 1;
    graph->adjacency_matrix[node2][node1] = 1;
}

bool is_safe(Graph* graph, int node, int color, int* colors) {
    for (int i = 0; i < graph->num_nodes; i++) {
        if (graph->adjacency_matrix[node][i] == 1 && colors[i] == color) {
            return false;
        }
    }
    return true;
}

bool color_graph(Graph* graph, int* colors, int node) {
    if (node == graph->num_nodes) {
        return true;
    }
    for (int color = 1; color <= MAX_COLORS; color++) {
        if (is_safe(graph, node, color, colors)) {
            colors[node] = color;
            if (color_graph(graph, colors, node + 1)) {
                return true;
            }
            colors[node] = 0;
        }
    }
    return false;
}

void print_graph(Graph* graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        for (int j = 0; j < graph->num_nodes; j++) {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int num_nodes = rand() % MAX_NODES + 1;
    int num_edges = rand() % (num_nodes * (num_nodes - 1) / 2) + 1;
    Graph* graph = create_graph(num_nodes, num_edges);
    for (int i = 0; i < num_edges; i++) {
        int node1 = rand() % num_nodes;
        int node2 = rand() % num_nodes;
        add_edge(graph, node1, node2);
    }
    int* colors = malloc(sizeof(int) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        colors[i] = 0;
    }
    if (color_graph(graph, colors, 0)) {
        printf("Graph can be colored with %d colors.\n", MAX_COLORS);
        for (int i = 0; i < num_nodes; i++) {
            printf("Node %d: color %d\n", i, colors[i]);
        }
    } else {
        printf("Graph cannot be colored with %d colors.\n", MAX_COLORS);
    }
    return 0;
}