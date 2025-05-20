//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTS 100

typedef struct Graph
{
    int **adjList;
    int numVertices;
} Graph;

Graph* createGraph()
{
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->adjList = NULL;

    return graph;
}

void addVertex(Graph* graph)
{
    graph->numVertices++;
    graph->adjList = realloc(graph->adjList, graph->numVertices * sizeof(int*));
    graph->adjList[graph->numVertices - 1] = NULL;
}

void addEdge(Graph* graph, int u, int v)
{
    graph->adjList[u] = realloc(graph->adjList[u], (graph->numVertices + 1) * sizeof(int));
    graph->adjList[u][graph->numVertices] = v;
}

void graphColoring(Graph* graph)
{
    int* colors = malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++)
    {
        colors[i] = -1;
    }

    int chromaticNumber = 0;
    for (int i = 0; i < graph->numVertices; i++)
    {
        int availableColors = 0;
        for (int j = 0; j < graph->numVertices; j++)
        {
            if (colors[j] != -1 && graph->adjList[i][j] && colors[j] == colors[i])
            {
                availableColors = 0;
            }
            else
            {
                availableColors++;
            }
        }

        colors[i] = availableColors;
        chromaticNumber = fmax(chromaticNumber, colors[i]);
    }

    printf("The chromatic number of the graph is: %d\n", chromaticNumber);
}

int main()
{
    Graph* graph = createGraph();
    addVertex(graph);
    addVertex(graph);
    addVertex(graph);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);

    graphColoring(graph);

    return 0;
}