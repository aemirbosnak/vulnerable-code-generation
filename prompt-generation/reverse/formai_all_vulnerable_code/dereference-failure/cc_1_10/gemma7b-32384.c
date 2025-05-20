//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 10

typedef struct Graph
{
    int numVertices;
    int **adjList;
} Graph;

Graph* createGraph(int numVertices)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (int**)malloc(numVertices * sizeof(int*));
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

int graphColoring(Graph* graph)
{
    int colors[MAX_V] = {0};
    for (int i = 0; i < graph->numVertices; i++)
    {
        int usedColors = 0;
        for (int j = 0; j < graph->numVertices; j++)
        {
            if (graph->adjList[i][j] && colors[j] != 0)
            {
                usedColors++;
            }
        }
        colors[i] = 1 - usedColors;
    }

    int maxColor = colors[0];
    for (int i = 1; i < graph->numVertices; i++)
    {
        if (colors[i] > maxColor)
        {
            maxColor = colors[i];
        }
    }
    return maxColor;
}

int main()
{
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);

    int maxColor = graphColoring(graph);
    printf("Maximum number of colors: %d", maxColor);

    return 0;
}