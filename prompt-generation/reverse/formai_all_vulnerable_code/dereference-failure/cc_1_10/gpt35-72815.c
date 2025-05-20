//FormAI DATASET v1.0 Category: Data structures visualization ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

struct Stack {
  int top;
  int node[MAX];
  char edge[MAX][MAX];
};

struct Graph {
  int vertices;
  struct Stack* stack;
};

struct Stack* createStack() {
  struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
  stack->top = -1;
  return stack;
}

void push(struct Stack* stack, int value) {
  stack->node[++stack->top] = value;
}

int pop(struct Stack* stack) {
  return stack->node[stack->top--];
}

bool isEmpty(struct Stack* stack) {
  return stack->top == -1;
}

struct Graph* createGraph(int vertices) {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->vertices = vertices;

  graph->stack = createStack();

  for (int i=0; i<vertices; i++) {
    for (int j=0; j<vertices; j++) {
      graph->stack->edge[i][j] = 0;
    }
  }

  return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
  graph->stack->edge[src][dest] = 1;
}

void displayGraph(struct Graph* graph) {
  printf("   ");
  for (int i=0; i<graph->vertices; i++) {
    printf("%d ", i);
  }
  printf("\n");

  for (int i=0; i<graph->vertices; i++) {
    printf("%d: ", i);

    for (int j=0; j<graph->vertices; j++) {
      printf("%d ", graph->stack->edge[i][j]);
    }

    printf("\n");
  }
}

void depthFirstTraversal(struct Graph* graph, int vertex, bool visited[]) {
  visited[vertex] = true;
  push(graph->stack, vertex);

  printf("%d ", vertex);

  for (int i=0; i<graph->vertices; i++) {
    if(graph->stack->edge[vertex][i] == 1 && !visited[i]) {
      depthFirstTraversal(graph, i, visited);
    }
  }

  if(!isEmpty(graph->stack)) {
    pop(graph->stack);
  }
}

void depthFirstSearch(struct Graph* graph, int vertex) {
  bool visited[MAX] = {false};

  depthFirstTraversal(graph, vertex, visited);
}

int main() {
  struct Graph* graph = createGraph(5);

  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 0);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 3);

  displayGraph(graph);

  printf("\nDepth first search starting from vertex 2: ");
  depthFirstSearch(graph, 2);

  return 0;
}