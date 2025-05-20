//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 14

typedef struct Edge {
    int dest;
    struct Edge *next;
} Edge;

typedef struct Vertex {
    int id;
    char name[10];
    Edge *edges;
} Vertex;

Vertex graph[MAX_VERTICES];
int numVertices = 0;

void addEdge(int src, int dest) {
    Edge *newEdge = (Edge *) malloc(sizeof(Edge));
    newEdge->dest = dest;
    newEdge->next = graph[src].edges;
    graph[src].edges = newEdge;
}

void printGraph() {
    int i;
    for (i = 0; i < numVertices; i++) {
        printf("%s: ", graph[i].name);
        Edge *e = graph[i].edges;
        while (e != NULL) {
            printf("-> %d ", e->dest);
            e = e->next;
        }
        printf("\n");
    }
}

int main() {
    numVertices = 13;

    // Set vertex names
    strcpy(graph[0].name, "1");
    strcpy(graph[1].name, "2");
    strcpy(graph[2].name, "3");
    strcpy(graph[3].name, "4");
    strcpy(graph[4].name, "5");
    strcpy(graph[5].name, "6");
    strcpy(graph[6].name, "7");
    strcpy(graph[7].name, "8");
    strcpy(graph[8].name, "9");
    strcpy(graph[9].name, "10");
    strcpy(graph[10].name, "11");
    strcpy(graph[11].name, "12");
    strcpy(graph[12].name, "13");

    // Add edges
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(3, 4);
    addEdge(3, 5);
    addEdge(5, 6);
    addEdge(5, 7);
    addEdge(8, 9);
    addEdge(9, 10);
    addEdge(10, 11);
    addEdge(11, 12);
    addEdge(12, 13);

    // Print graph
    printGraph();

    return 0;
}