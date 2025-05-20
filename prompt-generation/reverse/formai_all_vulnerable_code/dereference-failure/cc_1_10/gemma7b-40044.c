//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 10

typedef struct Graph
{
    int **adjList;
    int numVertices;
} Graph;

Graph* createGraph()
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->adjList = (int**)malloc(MAX_Vertices * sizeof(int*));
    graph->numVertices = 0;

    for (int i = 0; i < MAX_Vertices; i++)
    {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addVertex(Graph* graph, int vertex)
{
    graph->numVertices++;

    graph->adjList[vertex] = (int*)malloc(sizeof(int) * graph->numVertices);

    for (int i = 0; i < graph->numVertices; i++)
    {
        graph->adjList[vertex][i] = -1;
    }
}

void addEdge(Graph* graph, int source, int destination)
{
    graph->adjList[source][destination] = 1;
}

void traverseGraph(Graph* graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        for (int j = 0; j < graph->numVertices; j++)
        {
            if (graph->adjList[i][j] == 1)
            {
                printf("Edge from vertex %d to vertex %d\n", i, j);
            }
        }
    }
}

int main()
{
    Graph* graph = createGraph();

    addVertex(graph, 0);
    addVertex(graph, 1);
    addVertex(graph, 2);
    addVertex(graph, 3);
    addVertex(graph, 4);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    traverseGraph(graph);

    return 0;
}