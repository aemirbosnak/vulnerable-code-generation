//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct graph {
    int numVertices;
    int numEdges;
    struct node **adjLists;
} graph;

graph *createGraph(int vertices) {
    graph *g = malloc(sizeof(graph));
    g->numVertices = vertices;
    g->numEdges = 0;
    g->adjLists = malloc(vertices * sizeof(node *));

    for (int i = 0; i < vertices; i++) {
        g->adjLists[i] = NULL;
    }

    return g;
}

void addEdge(graph *g, int src, int dest) {
    node *newNode = malloc(sizeof(node));
    newNode->data = dest;
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;
    g->numEdges++;
}

void printGraph(graph *g) {
    for (int i = 0; i < g->numVertices; i++) {
        node *tmp = g->adjLists[i];
        printf("Vertex %d: ", i);
        while (tmp) {
            printf("%d -> ", tmp->data);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

int main() {
    // Create two graphs, one for Romeo and one for Juliet
    graph *romeo = createGraph(5);
    graph *juliet = createGraph(5);

    // Add the edges for Romeo
    addEdge(romeo, 0, 1);
    addEdge(romeo, 0, 2);
    addEdge(romeo, 1, 3);
    addEdge(romeo, 2, 4);

    // Add the edges for Juliet
    addEdge(juliet, 0, 1);
    addEdge(juliet, 0, 2);
    addEdge(juliet, 1, 3);
    addEdge(juliet, 2, 4);

    // Print the graphs
    printf("Romeo's Graph:\n");
    printGraph(romeo);

    printf("Juliet's Graph:\n");
    printGraph(juliet);

    return 0;
}