//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    char name[20];
    struct Node *next;
};

struct Graph {
    int numNodes;
    int numEdges;
    struct Node *nodes;
    struct Node *edges;
};

void addNode(struct Graph *graph, char *name) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next = graph->nodes;
    graph->nodes = newNode;
    graph->numNodes++;
}

void addEdge(struct Graph *graph, char *node1, char *node2) {
    struct Node *newEdge = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newEdge->name, node1);
    newEdge->next = graph->edges;
    graph->edges = newEdge;
    graph->numEdges++;
}

void printGraph(struct Graph *graph) {
    printf("Nodes:\n");
    struct Node *currentNode = graph->nodes;
    while (currentNode!= NULL) {
        printf("%s\n", currentNode->name);
        currentNode = currentNode->next;
    }

    printf("\nEdges:\n");
    struct Node *currentEdge = graph->edges;
    while (currentEdge!= NULL) {
        printf("%s -> %s\n", currentEdge->name, currentEdge->next->name);
        currentEdge = currentEdge->next;
    }
}

int main() {
    struct Graph graph;
    graph.numNodes = 0;
    graph.numEdges = 0;
    graph.nodes = NULL;
    graph.edges = NULL;

    addNode(&graph, "A");
    addNode(&graph, "B");
    addEdge(&graph, "A", "B");

    printGraph(&graph);

    return 0;
}