//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10
#define MAX_EDGES 20

typedef struct Vertex
{
    int index;
    struct Vertex* adjacentVertices[MAX_VERTICES];
    char name[MAX_EDGES];
} Vertex;

typedef struct Edge
{
    int sourceIndex;
    int destinationIndex;
    char name[MAX_EDGES];
} Edge;

void printTopology(Vertex* vertices, Edge* edges)
{
    for (int i = 0; i < vertices->index; i++)
    {
        printf("Vertex %d: %s\n", vertices[i].index, vertices[i].name);
        for (int j = 0; edges[j].sourceIndex == vertices[i].index; j++)
        {
            printf("Edge: %s - %s (%s)\n", edges[j].sourceIndex, edges[j].destinationIndex, edges[j].name);
        }
    }
}

int main()
{
    Vertex* vertices = (Vertex*)malloc(sizeof(Vertex) * MAX_VERTICES);
    Edge* edges = (Edge*)malloc(sizeof(Edge) * MAX_EDGES);

    vertices[0].index = 0;
    vertices[0].name[0] = 'A';

    vertices[1].index = 1;
    vertices[1].name[0] = 'B';

    vertices[2].index = 2;
    vertices[2].name[0] = 'C';

    edges[0].sourceIndex = 0;
    edges[0].destinationIndex = 1;
    edges[0].name[0] = '1';

    edges[1].sourceIndex = 1;
    edges[1].destinationIndex = 2;
    edges[1].name[0] = '2';

    printTopology(vertices, edges);

    free(vertices);
    free(edges);

    return 0;
}