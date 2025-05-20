//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_LINKS 100

struct Node {
    int id;
    double x, y;
    int degree;
    struct Link *links;
};

struct Link {
    int id;
    struct Node *node1, *node2;
    double weight;
};

int numNodes = 0, numLinks = 0;
struct Node *nodes = NULL;
struct Link *links = NULL;

void init() {
    numNodes = 0;
    numLinks = 0;
    nodes = (struct Node *) malloc(MAX_NODES * sizeof(struct Node));
    links = (struct Link *) malloc(MAX_LINKS * sizeof(struct Link));
}

void addNode(int id, double x, double y) {
    struct Node *node = &nodes[numNodes++];
    node->id = id;
    node->x = x;
    node->y = y;
    node->degree = 0;
    node->links = NULL;
}

void addLink(int id, int node1, int node2, double weight) {
    struct Link *link = &links[numLinks++];
    link->id = id;
    link->node1 = &nodes[node1];
    link->node2 = &nodes[node2];
    link->weight = weight;
}

void printGraph() {
    for (int i = 0; i < numNodes; i++) {
        printf("%d (%f, %f)\n", nodes[i].id, nodes[i].x, nodes[i].y);
    }
    for (int i = 0; i < numLinks; i++) {
        printf("Link %d: %d -> %d (%f)\n", links[i].id, links[i].node1->id, links[i].node2->id, links[i].weight);
    }
}

int main() {
    init();
    addNode(1, 0, 0);
    addNode(2, 1, 0);
    addNode(3, 2, 0);
    addNode(4, 3, 0);
    addLink(1, 1, 2, 1);
    addLink(2, 2, 3, 1);
    addLink(3, 3, 4, 1);
    addLink(4, 4, 1, 1);
    printGraph();
    return 0;
}