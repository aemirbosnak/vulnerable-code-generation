//FormAI DATASET v1.0 Category: Memory management ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

/* Define struct for our doubly linked list node */
struct node_t {
  int data;
  struct node_t* prev;
  struct node_t* next;
};

/* Define function for adding a new node to the beginning of the list */
struct node_t* add_node(struct node_t* head, int data) {
  /* Allocate memory for new node */
  struct node_t* new_node = (struct node_t*) malloc(sizeof(struct node_t));
  new_node->data = data;
  new_node->prev = NULL;
  
  /* If the list is empty, set the new node as the head */
  if (head == NULL) {
    new_node->next = NULL;
    return new_node;
  }
  
  /* Otherwise, add the new node to the beginning of the list */
  new_node->next = head;
  head->prev = new_node;
  
  return new_node;
}

/* Define function for removing a node from the list */
void remove_node(struct node_t* node) {
  if (node->prev != NULL) {
    node->prev->next = node->next;
  }
  if (node->next != NULL) {
    node->next->prev = node->prev;
  }
  free(node);
}

/* Define main function */
int main() {
  /* Initialize head of list to NULL */
  struct node_t* head = NULL;

  /* Add some nodes to the list */
  head = add_node(head, 4);
  head = add_node(head, 7);
  head = add_node(head, 12);
  head = add_node(head, 23);

  /* Remove the second node from the list */
  remove_node(head->next);

  /* Print the remaining nodes in the list */
  struct node_t* current_node = head;
  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }
  
  /* Free memory allocated for remaining nodes in the list */
  current_node = head;
  while (current_node != NULL) {
    struct node_t* temp = current_node;
    current_node = current_node->next;
    free(temp);
  }
  
  return 0;
}