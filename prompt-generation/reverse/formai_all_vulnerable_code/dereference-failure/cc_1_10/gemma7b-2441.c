//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct Graph {
  int numVertices;
  int **adjList;
  char **vertexNames;
} Graph;

Graph* createGraph() {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->numVertices = 0;
  graph->adjList = NULL;
  graph->vertexNames = NULL;
  return graph;
}

void addVertex(Graph* graph, char* vertexName) {
  graph->numVertices++;
  graph->vertexNames = (char**)realloc(graph->vertexNames, graph->numVertices * sizeof(char*));
  graph->adjList = (int**)realloc(graph->adjList, graph->numVertices * sizeof(int*));
  graph->vertexNames[graph->numVertices - 1] = vertexName;
  graph->adjList[graph->numVertices - 1] = NULL;
}

void addEdge(Graph* graph, char* sourceVertex, char* destinationVertex) {
  int sourceIndex = findVertexIndex(graph, sourceVertex);
  int destinationIndex = findVertexIndex(graph, destinationVertex);
  graph->adjList[sourceIndex][destinationIndex] = 1;
}

int findVertexIndex(Graph* graph, char* vertexName) {
  for (int i = 0; i < graph->numVertices; i++) {
    if (strcmp(graph->vertexNames[i], vertexName) == 0) {
      return i;
    }
  }
  return -1;
}

void traverseGraph(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    printf("%s: ", graph->vertexNames[i]);
    for (int j = 0; graph->adjList[i][j] != NULL; j++) {
      printf("%s ", graph->vertexNames[graph->adjList[i][j]]);
    }
    printf("\n");
  }
}

int main() {
  Graph* graph = createGraph();
  addVertex(graph, "A");
  addVertex(graph, "B");
  addVertex(graph, "C");
  addEdge(graph, "A", "B");
  addEdge(graph, "A", "C");
  addEdge(graph, "B", "C");
  traverseGraph(graph);

  free(graph);
  return 0;
}