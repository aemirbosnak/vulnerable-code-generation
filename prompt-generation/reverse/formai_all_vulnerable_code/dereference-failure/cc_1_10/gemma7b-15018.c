//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_Vertices 10
#define MAX_Edges 20

typedef struct Node {
  int index;
  struct Node* next;
} Node;

typedef struct Graph {
  Node** graph;
  int numVertices;
  int numEdges;
} Graph;

Graph* createGraph() {
  Graph* graph = malloc(sizeof(Graph));
  graph->graph = malloc(MAX_Vertices * sizeof(Node*));
  graph->numVertices = 0;
  graph->numEdges = 0;
  return graph;
}

void addVertex(Graph* graph) {
  graph->numVertices++;
  graph->graph[graph->numVertices - 1] = malloc(sizeof(Node));
  graph->graph[graph->numVertices - 1]->index = graph->numVertices - 1;
  graph->graph[graph->numVertices - 1]->next = NULL;
}

void addEdge(Graph* graph, int src, int dest) {
  graph->numEdges++;
  Node* newNode = malloc(sizeof(Node));
  newNode->index = dest;
  newNode->next = NULL;
  graph->graph[src]->next = newNode;
}

void traverseGraph(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    Node* current = graph->graph[i];
    printf("Vertex %d: ", graph->graph[i]->index);
    while (current) {
      printf("-> Vertex %d ", current->index);
      current = current->next;
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