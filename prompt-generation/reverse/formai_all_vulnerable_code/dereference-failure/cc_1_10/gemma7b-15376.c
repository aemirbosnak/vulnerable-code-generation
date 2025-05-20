//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_VERTS 10
#define MAX_EDGES 20

typedef struct Vertex {
  int index;
  struct Vertex* adjacent;
} Vertex;

typedef struct Graph {
  Vertex** vertices;
  int numVertices;
  int numEdges;
} Graph;

Graph* createGraph() {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->vertices = (Vertex**)malloc(MAX_VERTS * sizeof(Vertex));
  graph->numVertices = 0;
  graph->numEdges = 0;
  return graph;
}

void addVertex(Graph* graph) {
  graph->vertices[graph->numVertices++] = (Vertex*)malloc(sizeof(Vertex));
  graph->vertices[graph->numVertices - 1]->index = graph->numVertices - 1;
  graph->vertices[graph->numVertices - 1]->adjacent = NULL;
}

void addEdge(Graph* graph, int src, int dest) {
  Vertex* srcVertex = graph->vertices[src];
  Vertex* destVertex = graph->vertices[dest];
  srcVertex->adjacent = destVertex;
  graph->numEdges++;
}

void traverseGraph(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    Vertex* currentVertex = graph->vertices[i];
    printf("Vertex %d: ", currentVertex->index);
    for (Vertex* neighborVertex = currentVertex->adjacent; neighborVertex; neighborVertex = neighborVertex->adjacent) {
      printf("-> Neighbor Vertex %d ", neighborVertex->index);
    }
    printf("\n");
  }
}

int main() {
  Graph* graph = createGraph();
  addVertex(graph);
  addVertex(graph);
  addVertex(graph);
  addEdge(graph, 0, 1);
  addEdge(graph, 1, 2);
  traverseGraph(graph);

  return 0;
}