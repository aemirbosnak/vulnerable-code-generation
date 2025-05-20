//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_Vertices 10

typedef struct Node {
  int index;
  struct Node* next;
  struct Node* prev;
} Node;

typedef struct Graph {
  int numVertices;
  Node** adjList;
} Graph;

Graph* createGraph(int numVertices) {
  Graph* graph = malloc(sizeof(Graph));
  graph->numVertices = numVertices;
  graph->adjList = malloc(numVertices * sizeof(Node*));
  for (int i = 0; i < numVertices; i++) {
    graph->adjList[i] = NULL;
  }
  return graph;
}

void addEdge(Graph* graph, int src, int dest) {
  Node* newNode = malloc(sizeof(Node));
  newNode->index = dest;
  newNode->next = graph->adjList[src];
  graph->adjList[src] = newNode;
}

void colorGraph(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    Node* current = graph->adjList[i];
    while (current) {
      int visited = 0;
      Node* neighbor = current->next;
      while (neighbor) {
        if (neighbor->index != current->index) {
          if (visited == 0) {
            visited = 1;
            printf("Vertex %d is colored %d\n", current->index, 1);
          } else {
            printf("Vertex %d is colored %d\n", current->index, 2);
          }
        }
        neighbor = neighbor->next;
      }
    }
  }
}

int main() {
  Graph* graph = createGraph(MAX_Vertices);
  addEdge(graph, 0, 1);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);
  addEdge(graph, 4, 5);
  colorGraph(graph);
  return 0;
}