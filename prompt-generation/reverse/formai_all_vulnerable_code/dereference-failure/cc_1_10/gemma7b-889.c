//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTS 10

typedef struct Vertex {
    int index;
    struct Vertex** neighbors;
    char name[20];
} Vertex;

Vertex** graph;

void initializeGraph() {
    graph = (Vertex**)malloc(MAX_VERTS * sizeof(Vertex));
    for (int i = 0; i < MAX_VERTS; i++) {
        graph[i] = NULL;
    }
}

void addVertex(char* name) {
    Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));
    newVertex->index = graph[0]->index + 1;
    newVertex->neighbors = NULL;
    newVertex->name[0] = '\0';
    strcpy(newVertex->name, name);
    graph[newVertex->index] = newVertex;
}

void addEdge(int srcIndex, int destIndex) {
    Vertex* srcVertex = graph[srcIndex];
    Vertex* destVertex = graph[destIndex];
    srcVertex->neighbors = (Vertex**)realloc(srcVertex->neighbors, (srcVertex->neighbors ? 1 : 0) * sizeof(Vertex*) + 1);
    srcVertex->neighbors[srcVertex->neighbors ? 0 : 0] = destVertex;
}

void traverseGraph() {
    for (int i = 0; i < MAX_VERTS; i++) {
        if (graph[i]) {
            printf("%s ", graph[i]->name);
        }
    }
    printf("\n");
}

int main() {
    initializeGraph();
    addVertex("Alice");
    addVertex("Bob");
    addVertex("Charlie");
    addEdge(0, 1);
    addEdge(1, 2);
    traverseGraph();

    return 0;
}