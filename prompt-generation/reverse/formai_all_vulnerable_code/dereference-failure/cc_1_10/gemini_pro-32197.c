//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
    int id;
    int x;
    int y;
} Node;

typedef struct {
    int id;
    int source;
    int destination;
    int weight;
} Edge;

typedef struct {
    int num_nodes;
    int num_edges;
    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];
} Graph;

Graph *create_graph(int num_nodes, int num_edges) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->num_edges = num_edges;

    for (int i = 0; i < num_nodes; i++) {
        graph->nodes[i].id = i;
        graph->nodes[i].x = rand() % 100;
        graph->nodes[i].y = rand() % 100;
    }

    for (int i = 0; i < num_edges; i++) {
        graph->edges[i].id = i;
        graph->edges[i].source = rand() % num_nodes;
        graph->edges[i].destination = rand() % num_nodes;
        graph->edges[i].weight = rand() % 10;
    }

    return graph;
}

void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("Node %d: (%d, %d)\n", graph->nodes[i].id, graph->nodes[i].x, graph->nodes[i].y);
    }

    for (int i = 0; i < graph->num_edges; i++) {
        printf("Edge %d: (%d, %d, %d)\n", graph->edges[i].id, graph->edges[i].source, graph->edges[i].destination, graph->edges[i].weight);
    }
}

int main() {
    Graph *graph = create_graph(10, 20);
    print_graph(graph);
    return 0;
}