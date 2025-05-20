//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Vertices 10
#define MAX_Edges 100

typedef struct Node {
    int index;
    struct Node* next;
} Node;

typedef struct Edge {
    int src, dest;
    struct Edge* next;
} Edge;

void traverse_graph(Node* node) {
    printf("Node %d: ", node->index);
    Node* current = node->next;
    while (current) {
        printf("-> Node %d ", current->index);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* nodes[MAX_Vertices] = { NULL };
    Edge* edges[MAX_Edges] = { NULL };

    // Create a graph
    nodes[0] = malloc(sizeof(Node));
    nodes[0]->index = 0;
    nodes[1] = malloc(sizeof(Node));
    nodes[1]->index = 1;
    nodes[2] = malloc(sizeof(Node));
    nodes[2]->index = 2;
    nodes[3] = malloc(sizeof(Node));
    nodes[3]->index = 3;

    edges[0] = malloc(sizeof(Edge));
    edges[0]->src = 0;
    edges[0]->dest = 1;
    edges[1] = malloc(sizeof(Edge));
    edges[1]->src = 1;
    edges[1]->dest = 2;
    edges[2] = malloc(sizeof(Edge));
    edges[2]->src = 2;
    edges[2]->dest = 3;

    // Traverse the graph
    traverse_graph(nodes[0]);

    return 0;
}