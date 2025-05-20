//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Vertices 10

typedef struct Vertex
{
    char name[20];
    struct Vertex* next;
} Vertex;

typedef struct Graph
{
    Vertex** adjList;
    int numVertices;
} Graph;

Graph* createGraph()
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->adjList = (Vertex**)malloc(MAX_Vertices * sizeof(Vertex));
    graph->numVertices = 0;
    return graph;
}

void addVertex(Graph* graph, char* name)
{
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    strcpy(vertex->name, name);
    vertex->next = NULL;

    graph->adjList[graph->numVertices++] = vertex;
}

void printGraph(Graph* graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        printf("%s ", graph->adjList[i]->name);
    }
    printf("\n");
}

int main()
{
    Graph* graph = createGraph();
    addVertex(graph, "Alice");
    addVertex(graph, "Bob");
    addVertex(graph, "Charlie");
    addVertex(graph, "Dave");

    printGraph(graph);

    return 0;
}