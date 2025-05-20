//FormAI DATASET v1.0 Category: Graph representation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int value;
   struct node* next;
} Node;

typedef struct graph {
   int size;
   Node** nodes;
} Graph;

Graph* createGraph(int size) {
   Graph* graph = (Graph*) malloc(sizeof(Graph));
   graph->size = size;
   graph->nodes = (Node**) malloc(size * sizeof(Node*));
   for (int i = 0; i < size; i++) {
      graph->nodes[i] = NULL;
   }
   return graph;
}

void addEdge(Graph* graph, int src, int dest) {
   Node* newNode = (Node*) malloc(sizeof(Node));
   newNode->value = dest;
   newNode->next = graph->nodes[src];
   graph->nodes[src] = newNode;
}

void printGraph(Graph* graph) {
   for (int i = 0; i < graph->size; i++) {
      printf("Node %d: ", i);
      Node* temp = graph->nodes[i];
      while (temp) {
         printf("%d -> ", temp->value);
         temp = temp->next;
      }
      printf("NULL\n");
   }
}

int main() {
   Graph* graph = createGraph(5);
   addEdge(graph, 0, 1);
   addEdge(graph, 0, 4);
   addEdge(graph, 1, 2);
   addEdge(graph, 1, 3);
   addEdge(graph, 1, 4);
   addEdge(graph, 2, 3);
   addEdge(graph, 3, 4);
   printGraph(graph);
   return 0;
}