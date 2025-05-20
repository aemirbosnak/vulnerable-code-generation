//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define MAX_NAME 50

struct Edge {
    int src;
    int dest;
    int weight;
};

struct Node {
    char name[MAX_NAME];
    int num_edges;
    struct Edge *edges;
};

void add_edge(struct Node *node, int src, int dest, int weight) {
    struct Edge *new_edge = (struct Edge*)malloc(sizeof(struct Edge));
    new_edge->src = src;
    new_edge->dest = dest;
    new_edge->weight = weight;
    node->num_edges++;
    node->edges = (struct Edge*)realloc(node->edges, node->num_edges * sizeof(struct Edge));
    node->edges[node->num_edges - 1] = *new_edge;
}

int main() {
    int num_nodes, num_edges;
    scanf("%d %d", &num_nodes, &num_edges);

    struct Node *nodes = (struct Node*)malloc(num_nodes * sizeof(struct Node));
    for (int i = 0; i < num_nodes; i++) {
        scanf("%s", nodes[i].name);
        nodes[i].num_edges = 0;
        nodes[i].edges = NULL;
    }

    for (int i = 0; i < num_edges; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        add_edge(&nodes[src - 1], src, dest, weight);
    }

    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %s\n", i + 1, nodes[i].name);
        for (int j = 0; j < nodes[i].num_edges; j++) {
            printf("\tEdge %d: %d -> %d (weight: %d)\n", j + 1, nodes[i].edges[j].src, nodes[i].edges[j].dest, nodes[i].edges[j].weight);
        }
    }

    return 0;
}