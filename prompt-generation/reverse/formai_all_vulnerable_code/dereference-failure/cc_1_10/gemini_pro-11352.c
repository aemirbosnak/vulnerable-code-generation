//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct {
    int num_nodes;
    int num_edges;
    int **adj_matrix;
} Graph;

Graph *create_graph(int num_nodes) {
    Graph *graph = malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->num_edges = 0;
    graph->adj_matrix = malloc(sizeof(int *) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        graph->adj_matrix[i] = malloc(sizeof(int) * num_nodes);
        memset(graph->adj_matrix[i], 0, sizeof(int) * num_nodes);
    }
    return graph;
}

void destroy_graph(Graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);
}

void add_edge(Graph *graph, int node1, int node2) {
    graph->adj_matrix[node1][node2] = 1;
    graph->adj_matrix[node2][node1] = 1;
    graph->num_edges++;
}

int is_safe(Graph *graph, int colors[], int node, int color) {
    for (int i = 0; i < graph->num_nodes; i++) {
        if (graph->adj_matrix[node][i] == 1 && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

int graph_coloring(Graph *graph, int colors[], int node, int num_colors) {
    if (node == graph->num_nodes) {
        return 1;
    }

    for (int i = 0; i < num_colors; i++) {
        if (is_safe(graph, colors, node, i)) {
            colors[node] = i;
            if (graph_coloring(graph, colors, node + 1, num_colors)) {
                return 1;
            }
        }
    }
    colors[node] = -1;
    return 0;
}

int main() {
    int num_nodes;
    int num_colors;
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    Graph *graph = create_graph(num_nodes);
    int *colors = malloc(sizeof(int) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        colors[i] = -1;
    }

    int num_edges;
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    for (int i = 0; i < num_edges; i++) {
        int node1, node2;
        printf("Enter the nodes for edge %d: ", i + 1);
        scanf("%d %d", &node1, &node2);
        add_edge(graph, node1 - 1, node2 - 1);
    }

    if (graph_coloring(graph, colors, 0, num_colors)) {
        printf("Nodes can be colored with %d colors:\n", num_colors);
        for (int i = 0; i < num_nodes; i++) {
            printf("Node %d: Color %d\n", i + 1, colors[i] + 1);
        }
    } else {
        printf("Nodes cannot be colored with %d colors.\n", num_colors);
    }

    destroy_graph(graph);
    free(colors);
    return 0;
}