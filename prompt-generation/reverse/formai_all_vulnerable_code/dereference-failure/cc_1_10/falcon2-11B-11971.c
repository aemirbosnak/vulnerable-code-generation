//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 10
#define MAX_EDGES 10

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

typedef struct {
    int id;
    int num_edges;
    Edge* edges;
} Graph;

void add_edge(Graph* graph, int src, int dest, int weight) {
    Edge* new_edge = malloc(sizeof(Edge));
    new_edge->src = src;
    new_edge->dest = dest;
    new_edge->weight = weight;

    if (graph->num_edges < MAX_EDGES) {
        graph->edges[graph->num_edges] = *new_edge;
        graph->num_edges++;
    } else {
        printf("Too many edges in the graph!\n");
        exit(1);
    }
}

void print_graph(Graph* graph) {
    printf("Graph:\n");
    for (int i = 0; i < graph->num_edges; i++) {
        Edge edge = graph->edges[i];
        printf("(%d, %d) - %d\n", edge.src, edge.dest, edge.weight);
    }
}

int main() {
    srand(time(NULL));

    Graph* graph = malloc(sizeof(Graph));
    graph->num_edges = 0;

    int num_nodes = rand() % MAX_NODES + 1;
    int num_edges = rand() % MAX_EDGES + 1;

    for (int i = 0; i < num_nodes; i++) {
        graph->edges[graph->num_edges].src = i;
        graph->edges[graph->num_edges].dest = rand() % num_nodes;
        graph->edges[graph->num_edges].weight = rand() % 10;

        graph->num_edges++;
    }

    for (int i = 0; i < num_edges; i++) {
        int src = rand() % num_nodes;
        int dest = rand() % num_nodes;
        int weight = rand() % 10;

        add_edge(graph, src, dest, weight);
    }

    print_graph(graph);

    free(graph->edges);
    free(graph);

    return 0;
}