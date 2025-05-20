//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct Node {
    char name;
    struct Node* neighbors;
} Node;

void print_topology(Node* node) {
    printf("%c: ", node->name);
    for (Node* neighbor = node->neighbors; neighbor; neighbor = neighbor->neighbors) {
        printf("%c ", neighbor->name);
    }
    printf("\n");
}

int main() {
    Node* nodes[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++) {
        nodes[i] = NULL;
    }

    // Create a few nodes
    nodes[0] = malloc(sizeof(Node));
    nodes[0]->name = 'A';
    nodes[0]->neighbors = NULL;

    nodes[1] = malloc(sizeof(Node));
    nodes[1]->name = 'B';
    nodes[1]->neighbors = NULL;

    nodes[2] = malloc(sizeof(Node));
    nodes[2]->name = 'C';
    nodes[2]->neighbors = NULL;

    // Connect the nodes
    nodes[0]->neighbors = nodes[1];
    nodes[1]->neighbors = nodes[2];

    // Print the topology
    print_topology(nodes[0]);

    print_topology(nodes[1]);

    print_topology(nodes[2]);

    return 0;
}