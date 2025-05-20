//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct Node {
    int index;
    struct Node **neighbors;
} Node;

void create_topology(Node **graph, int numVertices) {
    *graph = (Node *)malloc(sizeof(Node) * numVertices);
    for (int i = 0; i < numVertices; i++) {
        (*graph)[i].index = i;
        (*graph)[i].neighbors = NULL;
    }
}

void add_neighbor(Node **graph, int index, int neighborIndex) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->index = neighborIndex;
    newNode->neighbors = NULL;

    (*graph)[index].neighbors = newNode;
}

void print_topology(Node *graph) {
    for (int i = 0; i < graph->index; i++) {
        printf("Vertex %d: ", graph[i].index);
        for (Node *neighbor = graph[i].neighbors; neighbor; neighbor = neighbor->neighbors) {
            printf("Neighbor: %d ", neighbor->index);
        }
        printf("\n");
    }
}

int main() {
    int numVertices = 5;
    Node **graph;
    create_topology(&graph, numVertices);
    add_neighbor(graph, 0, 1);
    add_neighbor(graph, 0, 2);
    add_neighbor(graph, 1, 2);
    add_neighbor(graph, 2, 3);
    add_neighbor(graph, 3, 4);
    print_topology(graph);

    return 0;
}