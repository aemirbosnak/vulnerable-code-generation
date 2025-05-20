//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 10
#define MAX_Edges 20

typedef struct Edge
{
    int src, dest;
    struct Edge* next;
} Edge;

typedef struct Graph
{
    int numVertices;
    Edge** adjList;
} Graph;

Graph* createGraph(int numVertices)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (Edge**)malloc(numVertices * sizeof(Edge*));

    for (int i = 0; i < numVertices; i++)
    {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest)
{
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->src = src;
    newEdge->dest = dest;
    newEdge->next = NULL;

    Edge* lastEdge = graph->adjList[src];
    if (lastEdge == NULL)
    {
        graph->adjList[src] = newEdge;
    }
    else
    {
        lastEdge->next = newEdge;
    }
}

void printGraph(Graph* graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        Edge* edge = graph->adjList[i];
        printf("Vertex %d: ", i);
        while (edge)
        {
            printf("-> Vertex %d ", edge->dest);
            edge = edge->next;
        }
        printf("\n");
    }
}

int main()
{
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}