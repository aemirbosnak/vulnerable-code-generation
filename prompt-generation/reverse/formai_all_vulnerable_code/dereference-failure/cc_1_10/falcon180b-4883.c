//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_COLORS 10

typedef struct {
    int node;
    int color;
} GraphNode;

typedef struct {
    int num_nodes;
    int num_edges;
    GraphNode *nodes;
} Graph;

void create_graph(Graph *graph) {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        graph->nodes[i].node = i;
        graph->nodes[i].color = -1;
    }
}

void add_edge(Graph *graph, int node1, int node2) {
    graph->nodes[node1].color = -2;
    graph->nodes[node2].color = -2;
}

bool is_valid_color(Graph *graph, int node, int color) {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        if (graph->nodes[i].node == node && graph->nodes[i].color == color) {
            return false;
        }
    }
    return true;
}

void color_graph(Graph *graph) {
    int i, j, k;
    bool found;
    for (i = 0; i < MAX_NODES; i++) {
        if (graph->nodes[i].color == -1) {
            graph->nodes[i].color = 0;
            found = true;
            while (found) {
                found = false;
                for (j = 0; j < MAX_NODES; j++) {
                    if (graph->nodes[j].color == -2 && is_valid_color(graph, j, graph->nodes[i].color + 1)) {
                        graph->nodes[j].color = graph->nodes[i].color + 1;
                        found = true;
                    }
                }
            }
        }
    }
}

void print_graph(Graph *graph) {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        printf("%d:%d ", graph->nodes[i].node, graph->nodes[i].color);
    }
}

int main() {
    Graph graph;
    create_graph(&graph);
    add_edge(&graph, 0, 1);
    add_edge(&graph, 1, 2);
    color_graph(&graph);
    print_graph(&graph);
    return 0;
}