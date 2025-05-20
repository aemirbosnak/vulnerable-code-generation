//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Node {
    int index;
    struct Node** connections;
    char name[20];
} Node;

void draw_topology(Node** graph, int numVertices) {
    int i, j;
    for (i = 0; i < numVertices; i++) {
        printf("%s (", graph[i]->name);
        for (j = 0; graph[i]->connections[j] != NULL; j++) {
            printf("%s ", graph[i]->connections[j]->name);
        }
        printf(")\n");
    }
}

int main() {
    Node** graph = (Node**)malloc(MAX_VERTICES * sizeof(Node));
    int numVertices = 0;

    // Create a new vertex
    Node* newVertex = (Node*)malloc(sizeof(Node));
    newVertex->index = numVertices++;
    strcpy(newVertex->name, "Alice");
    graph[newVertex->index] = newVertex;

    // Create a new vertex
    newVertex = (Node*)malloc(sizeof(Node));
    newVertex->index = numVertices++;
    strcpy(newVertex->name, "Bob");
    graph[newVertex->index] = newVertex;

    // Connect Alice and Bob
    newVertex = graph[0];
    newVertex->connections = (Node**)malloc((numVertices - 1) * sizeof(Node*));
    newVertex->connections[0] = graph[1];

    // Connect Bob and Charlie
    newVertex = graph[1];
    newVertex->connections = (Node**)malloc((numVertices - 1) * sizeof(Node*));
    newVertex->connections[0] = graph[2];

    // Draw the topology
    draw_topology(graph, numVertices);

    return 0;
}