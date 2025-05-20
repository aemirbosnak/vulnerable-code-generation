//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINKS 5
#define MAX_NODES 10

typedef struct Node {
    char name[MAX_NODES];
    struct Node* links[MAX_LINKS];
    int numLinks;
} Node;

void drawNetwork(Node* node) {
    printf("%s:", node->name);
    for (int i = 0; i < node->numLinks; i++) {
        printf(" - %s", node->links[i]->name);
    }
    printf("\n");
}

int main() {
    Node* nodes[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++) {
        nodes[i] = NULL;
    }

    // Create a few nodes
    nodes[0] = malloc(sizeof(Node));
    nodes[0]->name[0] = 'A';
    nodes[0]->numLinks = 2;

    nodes[1] = malloc(sizeof(Node));
    nodes[1]->name[0] = 'B';
    nodes[1]->numLinks = 3;

    nodes[2] = malloc(sizeof(Node));
    nodes[2]->name[0] = 'C';
    nodes[2]->numLinks = 1;

    // Connect the nodes
    nodes[0]->links[0] = nodes[1];
    nodes[0]->links[1] = nodes[2];
    nodes[1]->links[0] = nodes[0];
    nodes[1]->links[1] = nodes[2];
    nodes[1]->links[2] = nodes[2];
    nodes[2]->links[0] = nodes[0];

    // Draw the network
    drawNetwork(nodes[0]);

    return 0;
}