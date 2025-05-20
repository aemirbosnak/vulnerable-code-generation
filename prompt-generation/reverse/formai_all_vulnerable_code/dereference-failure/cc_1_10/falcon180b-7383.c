//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define MAX_NAME 20

typedef struct edge {
    int from;
    int to;
    int weight;
} Edge;

typedef struct node {
    int id;
    char name[MAX_NAME];
    int degree;
    Edge edges[MAX_EDGES];
} Node;

void addEdge(Node* graph, int from, int to, int weight) {
    Edge edge = {from, to, weight};
    graph->edges[graph->degree++] = edge;
}

int main() {
    Node graph[MAX_NODES];
    int numNodes, numEdges;

    // Get number of nodes and edges from user
    printf("Enter number of nodes: ");
    scanf("%d", &numNodes);
    printf("Enter number of edges: ");
    scanf("%d", &numEdges);

    // Initialize graph with nodes and edges
    for (int i = 0; i < numNodes; i++) {
        printf("Enter node name: ");
        scanf("%s", graph[i].name);
        graph[i].id = i;
        graph[i].degree = 0;
    }

    for (int i = 0; i < numEdges; i++) {
        int from, to, weight;
        printf("Enter edge %d: ", i + 1);
        scanf("%d %d %d", &from, &to, &weight);
        addEdge(graph + from, from, to, weight);
    }

    // Print graph
    printf("Graph:\n");
    for (int i = 0; i < numNodes; i++) {
        printf("%s (%d):\n", graph[i].name, i);
        for (int j = 0; j < graph[i].degree; j++) {
            printf("\t%d (%d)\n", graph[i].edges[j].to, graph[i].edges[j].weight);
        }
    }

    return 0;
}