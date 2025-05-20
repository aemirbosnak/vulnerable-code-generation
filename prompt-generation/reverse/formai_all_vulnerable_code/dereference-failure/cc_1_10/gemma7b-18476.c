//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Vertices 10

typedef struct Vertex {
    char name[20];
    struct Vertex* adjacentVertices;
} Vertex;

void createVertex(char* name) {
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    strcpy(vertex->name, name);
    vertex->adjacentVertices = NULL;
}

void connectVertices(Vertex* vertex1, Vertex* vertex2) {
    vertex1->adjacentVertices = vertex2;
}

void drawTopology(Vertex* vertex) {
    printf("%s:", vertex->name);
    for (Vertex* adjacentVertex = vertex->adjacentVertices; adjacentVertex; adjacentVertex = adjacentVertex->adjacentVertices) {
        printf(" - %s", adjacentVertex->name);
    }
    printf("\n");
}

int main() {
    Vertex* vertices[MAX_Vertices];
    for (int i = 0; i < MAX_Vertices; i++) {
        vertices[i] = NULL;
    }

    createVertex("A");
    createVertex("B");
    createVertex("C");
    createVertex("D");
    createVertex("E");

    connectVertices(vertices[0], vertices[1]);
    connectVertices(vertices[0], vertices[2]);
    connectVertices(vertices[1], vertices[3]);
    connectVertices(vertices[2], vertices[4]);

    drawTopology(vertices[0]);

    return 0;
}