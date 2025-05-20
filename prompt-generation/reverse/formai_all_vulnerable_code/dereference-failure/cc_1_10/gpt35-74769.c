//FormAI DATASET v1.0 Category: Graph representation ; Style: content
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
  int data;
  struct node* next;
} Node;

Node** createGraph(int n) {
  Node** graph = (Node**)malloc(sizeof(Node*) * n);

  for(int i = 0; i < n; i++) {
    graph[i] = NULL;
  }

  return graph;
}

void addEdge(Node** graph, int u, int v) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode -> next = NULL;
  newNode -> data = v;

  if(graph[u] == NULL) {
    graph[u] = newNode;
  } else {
    Node* temp = graph[u];

    while(temp -> next != NULL) {
      temp = temp -> next;
    }

    temp -> next = newNode;
  }
}

void printGraph(Node** graph, int n) {
  printf("Graph:\n");

  for(int i = 0; i < n; i++) {
    printf("%d: ", i);

    if(graph[i] != NULL) {
      Node* temp = graph[i];

      while(temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
      }
    }

    printf("\n");
  }
}

int main() {
  int n = 5;
  Node** graph = createGraph(n);

  addEdge(graph, 0, 1);
  addEdge(graph, 0, 4);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 4);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);

  printGraph(graph, n);

  return 0;
}