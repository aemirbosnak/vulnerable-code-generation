//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Vertices 10

typedef struct Vertex
{
    int index;
    struct Vertex* next;
} Vertex;

void TopologicalSort(Vertex* graph)
{
    int nVertices = graph->index + 1;
    int* inDegree = (int*)malloc(nVertices * sizeof(int));
    for (int i = 0; i < nVertices; i++)
    {
        inDegree[i] = 0;
    }

    for (Vertex* vertex = graph; vertex; vertex = vertex->next)
    {
        inDegree[vertex->index]++;
    }

    int* outDegree = (int*)malloc(nVertices * sizeof(int));
    for (int i = 0; i < nVertices; i++)
    {
        outDegree[i] = 0;
    }

    for (Vertex* vertex = graph; vertex; vertex = vertex->next)
    {
        outDegree[vertex->index]++;
    }

    int* visited = (int*)malloc(nVertices * sizeof(int));
    for (int i = 0; i < nVertices; i++)
    {
        visited[i] = 0;
    }

    int i = 0;
    while (!visited[i])
    {
        for (Vertex* vertex = graph; vertex; vertex = vertex->next)
        {
            if (visited[vertex->index] == 0 && inDegree[vertex->index] == outDegree[vertex->index])
            {
                visited[vertex->index] = 1;
                printf("Vertex %d visited\n", vertex->index);
                i++;
            }
        }
    }

    free(inDegree);
    free(outDegree);
    free(visited);
}

int main()
{
    Vertex* graph = (Vertex*)malloc(sizeof(Vertex));
    graph->index = 0;
    graph->next = NULL;

    Vertex* vertex1 = (Vertex*)malloc(sizeof(Vertex));
    vertex1->index = 1;
    vertex1->next = NULL;

    Vertex* vertex2 = (Vertex*)malloc(sizeof(Vertex));
    vertex2->index = 2;
    vertex2->next = NULL;

    Vertex* vertex3 = (Vertex*)malloc(sizeof(Vertex));
    vertex3->index = 3;
    vertex3->next = NULL;

    vertex1->next = vertex2;
    vertex2->next = vertex3;
    vertex3->next = graph;

    TopologicalSort(graph);

    return 0;
}