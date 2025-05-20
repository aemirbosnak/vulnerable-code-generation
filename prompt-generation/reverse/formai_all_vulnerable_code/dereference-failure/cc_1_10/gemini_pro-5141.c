//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define the Romeo and Juliet nodes
typedef struct node {
  char *name;
  struct node *next;
} node;

// Create a new Romeo and Juliet node
node *create_node(char *name) {
  node *new_node = malloc(sizeof(node));
  new_node->name = name;
  new_node->next = NULL;
  return new_node;
}

// Insert a new Romeo and Juliet node into a graph
void insert_node(node **head, char *name) {
  node *new_node = create_node(name);
  new_node->next = *head;
  *head = new_node;
}

// Print a Romeo and Juliet graph
void print_graph(node *head) {
  while (head != NULL) {
    printf("%s ", head->name);
    head = head->next;
  }
  printf("\n");
}

// Free a Romeo and Juliet graph
void free_graph(node *head) {
  while (head != NULL) {
    node *next_node = head->next;
    free(head);
    head = next_node;
  }
}

// Main function
int main() {
  // Create a Romeo and Juliet graph
  node *romeo = create_node("Romeo");
  node *juliet = create_node("Juliet");
  node *tybalt = create_node("Tybalt");
  node *mercutio = create_node("Mercutio");
  node *nurse = create_node("Nurse");
  node *friar_laurence = create_node("Friar Laurence");

  insert_node(&romeo->next, juliet);
  insert_node(&juliet->next, tybalt);
  insert_node(&tybalt->next, mercutio);
  insert_node(&mercutio->next, nurse);
  insert_node(&nurse->next, friar_laurence);

  // Print the Romeo and Juliet graph
  print_graph(romeo);

  // Free the Romeo and Juliet graph
  free_graph(romeo);

  return 0;
}