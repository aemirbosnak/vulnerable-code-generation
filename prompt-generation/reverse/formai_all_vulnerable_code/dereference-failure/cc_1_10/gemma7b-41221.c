//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTS 10

typedef struct Graph {
  int numVertices;
  int **adjList;
} Graph;

Graph *createGraph(int numVertices)
{
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->numVertices = numVertices;
  graph->adjList = (int **)malloc(numVertices * sizeof(int *));
  for (int i = 0; i < numVertices; i++)
    graph->adjList[i] = (int *)malloc(numVertices * sizeof(int));
  return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
  graph->adjList[src][dest] = 1;
}

void traverseGraph(Graph *graph)
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
  Graph *graph = createGraph(5);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);
  traverseGraph(graph);
  return 0;
}