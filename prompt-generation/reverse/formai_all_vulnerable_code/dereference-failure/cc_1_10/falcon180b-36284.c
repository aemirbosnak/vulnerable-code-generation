//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_NODES 10000
#define MAX_EDGES 100000

typedef struct {
    int id;
    int degree;
    int *neighbors;
} Node;

typedef struct {
    int source;
    int destination;
    int weight;
} Edge;

Node *create_node(int id) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->id = id;
    node->degree = 0;
    node->neighbors = NULL;
    return node;
}

void add_edge(Node *graph, int source, int destination, int weight) {
    Edge *edge = (Edge *) malloc(sizeof(Edge));
    edge->source = source;
    edge->destination = destination;
    edge->weight = weight;
    graph->neighbors = (int *) realloc(graph->neighbors, sizeof(int) * (graph->degree + 1));
    graph->neighbors[graph->degree] = destination;
    graph->degree++;
}

void print_graph(Node *graph) {
    printf("Node %d has %d neighbors:\n", graph->id, graph->degree);
    for (int i = 0; i < graph->degree; i++) {
        printf("%d ", graph->neighbors[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Node *graph = create_node(0);

    for (int i = 1; i < MAX_NODES; i++) {
        add_edge(graph, 0, i, rand() % 100);
    }

    printf("Random graph with %d nodes and %d edges:\n", MAX_NODES, MAX_EDGES);
    print_graph(graph);

    return 0;
}