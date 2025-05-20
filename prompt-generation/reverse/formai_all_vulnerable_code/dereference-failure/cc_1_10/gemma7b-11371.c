//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Vertex
{
    int index;
    struct Vertex* next;
} Vertex;

void createGraph(Vertex* graph, int numVertices)
{
    graph = (Vertex*)malloc(numVertices * sizeof(Vertex));
    for (int i = 0; i < numVertices; i++)
    {
        graph[i].index = i;
        graph[i].next = NULL;
    }
}

void addEdge(Vertex* graph, int srcIndex, int destIndex)
{
    Vertex* newNode = (Vertex*)malloc(sizeof(Vertex));
    newNode->index = destIndex;
    newNode->next = NULL;

    graph[srcIndex].next = newNode;
}

void traverseGraph(Vertex* graph)
{
    for (Vertex* vertex = graph; vertex; vertex = vertex->next)
    {
        printf("Vertex %d: ", vertex->index);
        for (Vertex* neighbor = vertex->next; neighbor; neighbor = neighbor->next)
        {
            printf("-> Neighbor %d ", neighbor->index);
        }
        printf("\n");
    }
}

int main()
{
    Vertex* graph;
    createGraph(graph, MAX_VERTICES);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    traverseGraph(graph);

    return 0;
}