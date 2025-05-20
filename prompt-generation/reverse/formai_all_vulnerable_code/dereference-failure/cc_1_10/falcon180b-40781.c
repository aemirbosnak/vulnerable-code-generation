//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_COLORS 10

typedef struct {
    int id;
    int color;
} Node;

typedef struct {
    int num_nodes;
    int num_colors;
    Node* nodes;
} Graph;

Graph* create_graph(int num_nodes) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->num_colors = num_nodes;
    graph->nodes = (Node*)malloc(sizeof(Node) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        graph->nodes[i].id = i;
        graph->nodes[i].color = i;
    }
    return graph;
}

void print_graph(Graph* graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("%d: %d\n", graph->nodes[i].id, graph->nodes[i].color);
    }
}

bool is_valid_color(Graph* graph, int node_id, int color) {
    for (int i = 0; i < graph->num_nodes; i++) {
        if (graph->nodes[i].color == color) {
            return false;
        }
    }
    return true;
}

bool color_graph(Graph* graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        if (!is_valid_color(graph, i, i)) {
            return false;
        }
        graph->nodes[i].color = i;
    }
    return true;
}

int main() {
    Graph* graph = create_graph(5);
    print_graph(graph);
    color_graph(graph);
    print_graph(graph);
    return 0;
}