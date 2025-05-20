//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Graph
{
    int **adjList;
    int numVertices;
    int numEdges;
} Graph;

Graph* createGraph(int numVertices, int numEdges)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->adjList = (int**)malloc(numVertices * sizeof(int*));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;

    for (int i = 0; i < numVertices; i++)
    {
        graph->adjList[i] = (int*)malloc(numVertices * sizeof(int));
    }

    return graph;
}

void addEdge(Graph* graph, int u, int v)
{
    graph->adjList[u][v] = 1;
}

int colorGraph(Graph* graph)
{
    int* color = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++)
    {
        color[i] = -1;
    }

    int chromaticNumber = 0;
    for (int i = 0; i < graph->numVertices; i++)
    {
        int availableColors = 0;
        for (int j = 0; j < graph->numVertices; j++)
        {
            if (graph->adjList[i][j] && color[j] != -1)
            {
                availableColors--;
            }
        }

        color[i] = availableColors;
        chromaticNumber = fmax(chromaticNumber, color[i]);
    }

    free(color);
    return chromaticNumber;
}

int main()
{
    Graph* graph = createGraph(5, 5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    int chromaticNumber = colorGraph(graph);

    printf("Chromatic number of the graph: %d", chromaticNumber);

    return 0;
}