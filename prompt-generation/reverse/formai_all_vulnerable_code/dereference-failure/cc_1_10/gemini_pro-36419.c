//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define a node for a linked list
struct node {
  int data;
  struct node *next;
};

// Define a tree node
struct tree_node {
  int data;
  struct tree_node *left;
  struct tree_node *right;
};

// Define a graph node
struct graph_node {
  int data;
  struct graph_node *next;
  struct graph_node **edges;
};

// Create a new node for a linked list
struct node *create_node(int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Create a new node for a tree
struct tree_node *create_tree_node(int data) {
  struct tree_node *new_node = (struct tree_node *)malloc(sizeof(struct tree_node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

// Create a new node for a graph
struct graph_node *create_graph_node(int data) {
  struct graph_node *new_node = (struct graph_node *)malloc(sizeof(struct graph_node));
  new_node->data = data;
  new_node->next = NULL;
  new_node->edges = NULL;
  return new_node;
}

// Insert a node into a linked list
void insert_node(struct node **head, int data) {
  struct node *new_node = create_node(data);
  new_node->next = *head;
  *head = new_node;
}

// Insert a node into a tree
void insert_tree_node(struct tree_node **root, int data) {
  if (*root == NULL) {
    *root = create_tree_node(data);
  } else if (data <= (*root)->data) {
    insert_tree_node(&(*root)->left, data);
  } else {
    insert_tree_node(&(*root)->right, data);
  }
}

// Insert a node into a graph
void insert_graph_node(struct graph_node **graph, int data) {
  struct graph_node *new_node = create_graph_node(data);
  new_node->next = *graph;
  *graph = new_node;
}

// Print a linked list
void print_list(struct node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

// Print a tree
void print_tree(struct tree_node *root) {
  if (root == NULL) {
    return;
  }
  print_tree(root->left);
  printf("%d ", root->data);
  print_tree(root->right);
}

// Print a graph
void print_graph(struct graph_node *graph) {
  while (graph != NULL) {
    printf("%d: ", graph->data);
    for (int i = 0; graph->edges[i] != NULL; i++) {
      printf("%d ", graph->edges[i]->data);
    }
    printf("\n");
    graph = graph->next;
  }
}

int main() {
  // Create a linked list
  struct node *head = NULL;
  insert_node(&head, 1);
  insert_node(&head, 2);
  insert_node(&head, 3);

  // Print the linked list
  print_list(head);

  // Create a tree
  struct tree_node *root = NULL;
  insert_tree_node(&root, 4);
  insert_tree_node(&root, 2);
  insert_tree_node(&root, 6);
  insert_tree_node(&root, 1);
  insert_tree_node(&root, 3);
  insert_tree_node(&root, 5);
  insert_tree_node(&root, 7);

  // Print the tree
  print_tree(root);

  // Create a graph
  struct graph_node *graph = NULL;
  insert_graph_node(&graph, 0);
  insert_graph_node(&graph, 1);
  insert_graph_node(&graph, 2);
  insert_graph_node(&graph, 3);
  graph[0].edges = malloc(2 * sizeof(struct graph_node *));
  graph[0].edges[0] = &graph[1];
  graph[0].edges[1] = &graph[2];
  graph[1].edges = malloc(1 * sizeof(struct graph_node *));
  graph[1].edges[0] = &graph[2];
  graph[2].edges = malloc(1 * sizeof(struct graph_node *));
  graph[2].edges[0] = &graph[3];
  graph[3].edges = malloc(1 * sizeof(struct graph_node *));
  graph[3].edges[0] = &graph[0];

  // Print the graph
  print_graph(graph);

  return 0;
}