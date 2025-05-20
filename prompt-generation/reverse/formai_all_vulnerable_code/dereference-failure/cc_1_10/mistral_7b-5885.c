//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

typedef struct Edge {
    int destination;
    struct Edge *next;
} Edge;

typedef struct Vertex {
    char name[20];
    Edge *adjList;
} Vertex;

Vertex graph[MAX_VERTICES];
int numVertices = 0, numEdges = 0;

void addEdge(int source, int destination) {
    Edge *newEdge = (Edge *) malloc(sizeof(Edge));
    newEdge->destination = destination;
    newEdge->next = graph[source].adjList;
    graph[source].adjList = newEdge;

    numEdges++;
}

void printGraph() {
    printf("Adjacency List Representation of the Graph:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%s: ", graph[i].name);
        Edge *temp = graph[i].adjList;
        while (temp != NULL) {
            printf("-> %s", graph[temp->destination].name);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    strcpy(graph[0].name, "A");
    strcpy(graph[1].name, "B");
    strcpy(graph[2].name, "C");
    strcpy(graph[3].name, "D");

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 3);

    numVertices = 4;

    printGraph();

    return 0;
}