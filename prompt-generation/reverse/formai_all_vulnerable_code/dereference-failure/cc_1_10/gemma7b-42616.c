//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

typedef struct GraphNode {
  int data;
  struct GraphNode* next;
} GraphNode;

typedef struct Graph {
  GraphNode* head;
  GraphNode** adjacencyList;
} Graph;

Graph* createGraph() {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->head = NULL;
  graph->adjacencyList = NULL;
  return graph;
}

void addVertex(Graph* graph, int data) {
  GraphNode* newNode = (GraphNode*)malloc(sizeof(GraphNode));
  newNode->data = data;
  newNode->next = NULL;

  if (graph->head == NULL) {
    graph->head = newNode;
  } else {
    graph->adjacencyList[data] = newNode;
  }
}

void addEdge(Graph* graph, int src, int dest) {
  GraphNode* srcNode = graph->adjacencyList[src];
  GraphNode* destNode = graph->adjacencyList[dest];

  if (srcNode && destNode) {
    srcNode->next = destNode;
  }
}

void traverseGraph(Graph* graph) {
  GraphNode* current = graph->head;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  Graph* graph = createGraph();
  addVertex(graph, 0);
  addVertex(graph, 1);
  addVertex(graph, 2);
  addEdge(graph, 0, 1);
  addEdge(graph, 1, 2);

  traverseGraph(graph);

  return 0;
}