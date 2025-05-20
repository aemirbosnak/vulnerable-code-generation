//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the linked list
typedef struct node {
  char* name;
  char* number;
  struct node* next;
} node_t;

// The head of the linked list
node_t* head = NULL;

// Insert a new node into the linked list
void insert(char* name, char* number) {
  // Create a new node
  node_t* new_node = malloc(sizeof(node_t));

  // Copy the name and number into the new node
  new_node->name = strdup(name);
  new_node->number = strdup(number);

  // Insert the new node at the beginning of the linked list
  new_node->next = head;
  head = new_node;
}

// Search for a name in the linked list
node_t* search(char* name) {
  // Iterate over the linked list
  node_t* current = head;
  while (current != NULL) {
    // If the name matches, return the node
    if (!strcmp(current->name, name)) {
      return current;
    }

    // Move to the next node
    current = current->next;
  }

  // The name was not found
  return NULL;
}

// Print the linked list
void print_list() {
  // Iterate over the linked list
  node_t* current = head;
  while (current != NULL) {
    // Print the name and number
    printf("%s: %s\n", current->name, current->number);

    // Move to the next node
    current = current->next;
  }
}

// Free the linked list
void free_list() {
  // Iterate over the linked list
  node_t* current = head;
  while (current != NULL) {
    // Free the name and number
    free(current->name);
    free(current->number);

    // Free the node
    free(current);

    // Move to the next node
    current = current->next;
  }

  // Set the head to NULL
  head = NULL;
}

// The main function
int main() {
  // Insert some names and numbers into the linked list
  insert("Donald Knuth", "1-800-KNUTH");
  insert("Grace Hopper", "1-800-HOPPER");
  insert("Alan Turing", "1-800-TURING");
  insert("Ada Lovelace", "1-800-LOVELACE");

  // Search for a name in the linked list
  node_t* found = search("Grace Hopper");
  if (found != NULL) {
    printf("Found Grace Hopper: %s\n", found->number);
  } else {
    printf("Grace Hopper not found\n");
  }

  // Print the linked list
  print_list();

  // Free the linked list
  free_list();

  return 0;
}