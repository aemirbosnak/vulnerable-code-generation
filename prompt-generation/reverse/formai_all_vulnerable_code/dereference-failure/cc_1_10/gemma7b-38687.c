//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Graph
{
    int **adjList;
    int numVertices;
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
    int* colors = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++)
    {
        colors[i] = -1;
    }

    for (int i = 0; i < graph->numVertices; i++)
    {
        int available = 1;
        for (int j = 0; j < graph->numVertices; j++)
        {
            if (graph->adjList[i][j] && colors[j] != -1)
            {
                if (colors[j] == colors[i])
                {
                    available = 0;
                }
            }
        }

        if (available)
        {
            colors[i] = 0;
        }
        else
        {
            colors[i] = -1;
        }
    }

    int maxColor = 0;
    for (int i = 0; i < graph->numVertices; i++)
    {
        if (colors[i] != -1)
        {
            maxColor = fmax(maxColor, colors[i] + 1);
        }
    }

    free(colors);
    return maxColor;
}

int main()
{
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);

    int maxColor = graphColoring(graph);

    printf("The maximum number of colors is: %d\n", maxColor);

    return 0;
}