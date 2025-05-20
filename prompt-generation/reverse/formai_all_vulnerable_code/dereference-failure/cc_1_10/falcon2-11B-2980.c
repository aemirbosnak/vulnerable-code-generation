//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

typedef struct {
    int num_nodes;
    int num_edges;
    Edge *edges;
} Graph;

void add_edge(Graph *graph, int src, int dest, int weight) {
    if (graph->num_nodes == MAX_NODES) {
        fprintf(stderr, "Error: Graph is full\n");
        exit(1);
    }
    if (graph->num_edges == MAX_EDGES) {
        fprintf(stderr, "Error: Graph is full\n");
        exit(1);
    }
    graph->edges[graph->num_edges].src = src;
    graph->edges[graph->num_edges].dest = dest;
    graph->edges[graph->num_edges].weight = weight;
    graph->num_edges++;
}

void display_graph(Graph *graph) {
    printf("Graph:\n");
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("Node %d:\n", i);
        for (int j = 0; j < graph->num_edges; j++) {
            if (graph->edges[j].src == i) {
                printf(" -> Node %d (weight %d)\n", graph->edges[j].dest, graph->edges[j].weight);
            }
        }
    }
}

int main() {
    Graph graph;
    graph.num_nodes = 0;
    graph.num_edges = 0;
    graph.edges = NULL;

    add_edge(&graph, 0, 1, 10);
    add_edge(&graph, 0, 2, 5);
    add_edge(&graph, 1, 2, 8);
    add_edge(&graph, 1, 3, 7);
    add_edge(&graph, 2, 3, 6);

    display_graph(&graph);

    return 0;
}