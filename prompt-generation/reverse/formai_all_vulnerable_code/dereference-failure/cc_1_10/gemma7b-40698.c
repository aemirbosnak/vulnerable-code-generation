//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

void mapNetworkTopology(Node** graph) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph[i] = NULL;
    }

    for (Node* node = graph[0]; node; node = node->next) {
        graph[node->vertex] = node;
    }
}

int main() {
    Node* graph[MAX_VERTICES];

    // Create a shocked network topology
    graph[0] = malloc(sizeof(Node));
    graph[0]->vertex = 0;
    graph[0]->next = graph[1];

    graph[1] = malloc(sizeof(Node));
    graph[1]->vertex = 1;
    graph[1]->next = graph[2];

    graph[2] = malloc(sizeof(Node));
    graph[2]->vertex = 2;
    graph[2]->next = graph[3];

    graph[3] = malloc(sizeof(Node));
    graph[3]->vertex = 3;
    graph[3]->next = NULL;

    // Map the network topology
    mapNetworkTopology(graph);

    // Print the mapped topology
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph[i]) {
            printf("Vertex %d is connected to:", i);
            for (Node* node = graph[i]; node; node = node->next) {
                printf(" Vertex %d", node->vertex);
            }
            printf("\n");
        }
    }

    return 0;
}