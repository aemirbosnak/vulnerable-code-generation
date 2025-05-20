//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Vertex
{
    char name[20];
    struct Vertex* adjacentVertices[MAX_VERTICES];
    int numAdjacentVertices;
} Vertex;

void mapNetworkTopology(Vertex* vertex)
{
    int i;
    for (i = 0; i < vertex->numAdjacentVertices; i++)
    {
        printf("%s is connected to %s\n", vertex->name, vertex->adjacentVertices[i]->name);
    }
}

int main()
{
    Vertex* vertexList[MAX_VERTICES];
    int numVertices = 0;

    // Create a vertex
    Vertex* newVertex = malloc(sizeof(Vertex));
    strcpy(newVertex->name, "A");
    newVertex->numAdjacentVertices = 0;
    vertexList[numVertices++] = newVertex;

    // Create more vertices
    for (int i = 0; i < 9; i++)
    {
        newVertex = malloc(sizeof(Vertex));
        strcpy(newVertex->name, "B" + i);
        newVertex->numAdjacentVertices = 0;
        vertexList[numVertices++] = newVertex;
    }

    // Connect vertices
    newVertex = vertexList[0];
    newVertex->adjacentVertices[0] = vertexList[1];
    newVertex->adjacentVertices[1] = vertexList[2];
    newVertex->adjacentVertices[2] = vertexList[3];

    newVertex = vertexList[1];
    newVertex->adjacentVertices[0] = vertexList[0];
    newVertex->adjacentVertices[1] = vertexList[3];
    newVertex->adjacentVertices[2] = vertexList[4];

    newVertex = vertexList[2];
    newVertex->adjacentVertices[0] = vertexList[0];
    newVertex->adjacentVertices[1] = vertexList[4];
    newVertex->adjacentVertices[2] = vertexList[5];

    newVertex = vertexList[3];
    newVertex->adjacentVertices[0] = vertexList[0];
    newVertex->adjacentVertices[1] = vertexList[1];
    newVertex->adjacentVertices[2] = vertexList[6];

    newVertex = vertexList[4];
    newVertex->adjacentVertices[0] = vertexList[1];
    newVertex->adjacentVertices[1] = vertexList[2];
    newVertex->adjacentVertices[2] = vertexList[7];

    newVertex = vertexList[5];
    newVertex->adjacentVertices[0] = vertexList[2];
    newVertex->adjacentVertices[1] = vertexList[8];
    newVertex->adjacentVertices[2] = vertexList[9];

    // Map the network topology
    for (int i = 0; i < numVertices; i++)
    {
        mapNetworkTopology(vertexList[i]);
    }

    return 0;
}