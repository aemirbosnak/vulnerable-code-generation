//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VERTS 100
#define MAX_EDGES 200

typedef struct {
    char name[20];
    int index;
} Vertex;

typedef struct {
    int from;
    int to;
    int weight;
} Edge;

Vertex vertices[MAX_VERTS];
Edge edges[MAX_EDGES];
int numVertices = 0;
int numEdges = 0;

int findVertex(char *name) {
    for (int i = 0; i < numVertices; i++) {
        if (strcmp(vertices[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void addVertex(char *name) {
    int index = findVertex(name);
    if (index == -1) {
        strcpy(vertices[numVertices].name, name);
        numVertices++;
    }
}

void addEdge(char *from, char *to, int weight) {
    int fromIndex = findVertex(from);
    int toIndex = findVertex(to);
    if (fromIndex == -1 || toIndex == -1) {
        printf("Invalid vertex name\n");
        return;
    }
    Edge edge;
    strcpy(edge.from, from);
    strcpy(edge.to, to);
    edge.weight = weight;
    edges[numEdges++] = edge;
}

void displayGraph() {
    printf("Vertices:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%s\n", vertices[i].name);
    }
    printf("Edges:\n");
    for (int i = 0; i < numEdges; i++) {
        printf("%s -> %s : %d\n", edges[i].from, edges[i].to, edges[i].weight);
    }
}

int main() {
    addVertex("A");
    addVertex("B");
    addVertex("C");
    addVertex("D");
    addVertex("E");
    addEdge("A", "B", 3);
    addEdge("B", "C", 2);
    addEdge("C", "D", 4);
    addEdge("D", "E", 5);
    addEdge("E", "A", 1);
    displayGraph();
    return 0;
}