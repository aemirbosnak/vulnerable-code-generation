//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct Node {
    int id;
    int degree;
    struct Node **neighbors;
} Node;

typedef struct Edge {
    int src;
    int dest;
    int weight;
} Edge;

Node *createNode(int id) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->id = id;
    node->degree = 0;
    node->neighbors = (Node **)malloc(MAX_EDGES * sizeof(Node *));
    return node;
}

void addEdge(Node *graph, int src, int dest, int weight) {
    Edge *edge = (Edge *)malloc(sizeof(Edge));
    edge->src = src;
    edge->dest = dest;
    edge->weight = weight;
    graph->neighbors[graph->degree++] = (Node *)edge;
}

void printGraph(Node *graph) {
    printf("Node %d has %d neighbors:\n", graph->id, graph->degree);
    for (int i = 0; i < graph->degree; i++) {
        Edge *edge = (Edge *)graph->neighbors[i];
        printf("Neighbor %d with weight %d\n", edge->dest, edge->weight);
    }
}

int main() {
    srand(time(NULL));

    Node *graph = createNode(0);
    for (int i = 1; i < MAX_NODES; i++) {
        addEdge(graph, 0, i, rand() % 100);
        Node *node = createNode(i);
        for (int j = 0; j < MAX_EDGES; j++) {
            int neighbor = rand() % MAX_NODES;
            if (neighbor!= 0 && neighbor!= i) {
                addEdge(node, i, neighbor, rand() % 100);
            }
        }
        graph->neighbors[graph->degree++] = node;
    }

    printf("Original Graph:\n");
    printGraph(graph);

    return 0;
}