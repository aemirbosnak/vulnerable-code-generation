//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the vertex structure
typedef struct Vertex {
  int value;
  struct Vertex *next;
} Vertex;

// Define the graph structure
typedef struct Graph {
  int numVertices;
  Vertex **vertices;
} Graph;

// Create a new graph
Graph *createGraph(int numVertices) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->numVertices = numVertices;

  // Create an array of vertices
  graph->vertices = (Vertex **)malloc(numVertices * sizeof(Vertex *));

  // Initialize the vertices
  for (int i = 0; i < numVertices; i++) {
    graph->vertices[i] = NULL;
  }

  return graph;
}

// Add a vertex to the graph
void addVertex(Graph *graph, int value) {
  // Create a new vertex
  Vertex *vertex = (Vertex *)malloc(sizeof(Vertex));
  vertex->value = value;
  vertex->next = NULL;

  // Add the vertex to the graph
  graph->vertices[graph->numVertices++] = vertex;
}

// Add a edge
void addEdge(Graph *graph, int src, int dest) {
  // Get the source and destination vertices
  Vertex *srcVertex = graph->vertices[src];
  Vertex *destVertex = graph->vertices[dest];

  // Create a new edge
  Vertex *edge = (Vertex *)malloc(sizeof(Vertex));
  edge->value = dest;
  edge->next = srcVertex->next;

  // Add the edge to the source vertex
  srcVertex->next = edge;
}

// Print the graph
void printGraph(Graph *graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    Vertex *vertex = graph->vertices[i];

    printf("Vertex %d: ", vertex->value);
    while (vertex->next != NULL) {
      printf("%d -> ", vertex->next->value);
      vertex = vertex->next;
    }
    printf("\n");
  }
}

// Free the graph
void freeGraph(Graph *graph) {
  // Free the vertices
  for (int i = 0; i < graph->numVertices; i++) {
    Vertex *vertex = graph->vertices[i];
    while (vertex != NULL) {
      Vertex *nextVertex = vertex->next;
      free(vertex);
      vertex = nextVertex;
    }
  }

  // Free the graph
  free(graph);
}

int main() {
  // Create a graph
  Graph *graph = createGraph(5);

  // Add vertices to the graph
  addVertex(graph, 0);
  addVertex(graph, 1);
  addVertex(graph, 2);
  addVertex(graph, 3);
  addVertex(graph, 4);

  // Add edges to the graph
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);

  // Print the graph
  printGraph(graph);

  // Free the graph
  freeGraph(graph);

  return 0;
}