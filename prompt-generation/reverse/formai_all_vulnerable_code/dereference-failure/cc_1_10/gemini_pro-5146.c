//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct graph {
  int num_vertices;
  struct node **adj_lists;
};

// Create a new graph
struct graph *create_graph(int num_vertices) {
  struct graph *graph = malloc(sizeof(struct graph));
  graph->num_vertices = num_vertices;
  graph->adj_lists = malloc(sizeof(struct node *) * num_vertices);

  // Initialize the adjacency lists to NULL
  for (int i = 0; i < num_vertices; i++) {
    graph->adj_lists[i] = NULL;
  }

  return graph;
}

// Add an edge to the graph
void add_edge(struct graph *graph, int src, int dest) {
  // Create a new node
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = dest;
  new_node->next = NULL;

  // Add the new node to the adjacency list of the source vertex
  new_node->next = graph->adj_lists[src];
  graph->adj_lists[src] = new_node;
}

// Print the graph
void print_graph(struct graph *graph) {
  for (int i = 0; i < graph->num_vertices; i++) {
    struct node *temp = graph->adj_lists[i];
    printf("Vertex %d: ", i);
    while (temp) {
      printf("%d -> ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}

// Depth-first search
void dfs(struct graph *graph, int start) {
  // Create a stack
  struct node *stack[graph->num_vertices];
  int top = -1;

  // Push the start vertex onto the stack
  stack[++top] = graph->adj_lists[start];

  // While the stack is not empty
  while (top >= 0) {
    // Pop the top vertex from the stack
    struct node *current = stack[top--];

    // Visit the vertex
    printf("Visiting vertex %d\n", current->data);

    // Push the neighbors of the current vertex onto the stack
    struct node *temp = current->next;
    while (temp) {
      stack[++top] = graph->adj_lists[temp->data];
      temp = temp->next;
    }
  }
}

// Breadth-first search
void bfs(struct graph *graph, int start) {
  // Create a queue
  struct node *queue[graph->num_vertices];
  int front = -1;
  int rear = -1;

  // Enqueue the start vertex
  queue[++rear] = graph->adj_lists[start];

  // While the queue is not empty
  while (front != rear) {
    // Dequeue the front vertex from the queue
    struct node *current = queue[++front];

    // Visit the vertex
    printf("Visiting vertex %d\n", current->data);

    // Enqueue the neighbors of the current vertex
    struct node *temp = current->next;
    while (temp) {
      queue[++rear] = graph->adj_lists[temp->data];
      temp = temp->next;
    }
  }
}

int main() {
  // Create a graph
  struct graph *graph = create_graph(5);

  // Add edges to the graph
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 2);
  add_edge(graph, 1, 3);
  add_edge(graph, 2, 3);
  add_edge(graph, 2, 4);
  add_edge(graph, 3, 4);

  // Print the graph
  print_graph(graph);

  // Depth-first search
  printf("Depth-first search:\n");
  dfs(graph, 0);

  // Breadth-first search
  printf("Breadth-first search:\n");
  bfs(graph, 0);

  return 0;
}