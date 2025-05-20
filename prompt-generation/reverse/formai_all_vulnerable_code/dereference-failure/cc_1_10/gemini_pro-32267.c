//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Define a custom memory allocator
void *my_malloc(size_t size) {
  // Allocate a block of memory with a header
  void *block = malloc(size + sizeof(size_t));
  if (!block) return NULL;
  // Store the size of the block in the header
  *((size_t*)block) = size;
  // Return a pointer to the data area
  return block + sizeof(size_t);
}

// Define a custom memory deallocator
void my_free(void *ptr) {
  // Get the pointer to the block header
  void *block = ptr - sizeof(size_t);
  // Free the block of memory
  free(block);
}

// Define a macro to simplify memory allocation
#define MALLOC(type) (type*)my_malloc(sizeof(type))
#define FREE(ptr) my_free(ptr)

// A simple linked list node
typedef struct node {
  int data;
  struct node *next;
} node_t;

// Create a new node
node_t *create_node(int data) {
  node_t *node = MALLOC(node_t);
  node->data = data;
  node->next = NULL;
  return node;
}

// Insert a node into a linked list
void insert_node(node_t **head, node_t *node) {
  if (!head) {
    *head = node;
  } else {
    node->next = *head;
    *head = node;
  }
}

// Delete a node from a linked list
void delete_node(node_t **head, node_t *node) {
  if (*head == node) {
    *head = node->next;
  } else {
    node_t *prev = *head;
    while (prev->next != node) prev = prev->next;
    prev->next = node->next;
  }
  FREE(node);
}

// Print a linked list
void print_list(node_t *head) {
  while (head) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

// Free a linked list
void free_list(node_t *head) {
  while (head) {
    node_t *next = head->next;
    FREE(head);
    head = next;
  }
}

// Main function
int main() {
  // Create a linked list
  node_t *head = NULL;
  for (int i = 0; i < 10; i++) insert_node(&head, create_node(i));

  // Print the linked list
  print_list(head);

  // Delete a node from the linked list
  delete_node(&head, head->next);

  // Print the linked list
  print_list(head);

  // Free the linked list
  free_list(head);

  return 0;
}