//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// A C Graph representation example program in a scientific style.

// The following code snippet demonstrates how to represent a graph using an adjacency list.
// An adjacency list is a data structure that stores the connections between nodes in a graph.
// Each node in the graph is represented by a vertex, and each connection between two vertices is represented by an edge.
// The adjacency list is stored as an array of linked lists, where each linked list represents the edges that are connected to a particular vertex.

// Define the structure of a vertex.
typedef struct Vertex {
  int value;
  struct Vertex *next;
} Vertex;

// Define the structure of a graph.
typedef struct Graph {
  int numVertices;
  Vertex **vertices;
} Graph;

// Create a new graph.
Graph *createGraph(int numVertices) {
  Graph *graph = malloc(sizeof(Graph));
  graph->numVertices = numVertices;
  graph->vertices = malloc(sizeof(Vertex *) * numVertices);
  for (int i = 0; i < numVertices; i++) {
    graph->vertices[i] = NULL;
  }
  return graph;
}

// Add a vertex to a graph.
void addVertex(Graph *graph, int value) {
  Vertex *vertex = malloc(sizeof(Vertex));
  vertex->value = value;
  vertex->next = NULL;
  graph->vertices[graph->numVertices++] = vertex;
}

// Add an edge to a graph.
void addEdge(Graph *graph, int source, int destination) {
  Vertex *sourceVertex = graph->vertices[source];
  Vertex *destinationVertex = graph->vertices[destination];
  Vertex *newEdge = malloc(sizeof(Vertex));
  newEdge->value = destinationVertex->value;
  newEdge->next = sourceVertex->next;
  sourceVertex->next = newEdge;
}

// Print a graph.
void printGraph(Graph *graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    Vertex *vertex = graph->vertices[i];
    printf("Vertex %d: ", vertex->value);
    while (vertex != NULL) {
      printf("%d ", vertex->value);
      vertex = vertex->next;
    }
    printf("\n");
  }
}

// Main function.
int main() {
  // Create a graph with 5 vertices.
  Graph *graph = createGraph(5);

  // Add vertices to the graph.
  addVertex(graph, 1);
  addVertex(graph, 2);
  addVertex(graph, 3);
  addVertex(graph, 4);
  addVertex(graph, 5);

  // Add edges to the graph.
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);

  // Print the graph.
  printGraph(graph);

  return 0;
}