//FormAI DATASET v1.0 Category: Memory management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

/*
This program demonstrates dynamic memory allocation in C programming language. 
It creates a linked list of integers, adds new elements to the list, and finally, frees the memory.
*/

// Linked list structure
struct node {
  int data;
  struct node *next;
};

int main() {
  // Define a pointer to the head of the linked list
  struct node *head = NULL;

  // Allocate the first node of the linked list
  head = (struct node*)malloc(sizeof(struct node));
  if (head == NULL) {
    printf("Error: unable to allocate memory for the first node.\n");
    return 1;
  }

  // Set the data of the first node
  head->data = 1;
  head->next = NULL;

  // Allocate a new node and add it to the end of the linked list
  struct node *second = (struct node*)malloc(sizeof(struct node));
  if (second == NULL) {
    printf("Error: unable to allocate memory for the second node.\n");
    return 1;
  }
  second->data = 2;
  second->next = NULL;
  head->next = second;

  // Add a third node to the end of the linked list
  struct node *third = (struct node*)malloc(sizeof(struct node));
  if (third == NULL) {
    printf("Error: unable to allocate memory for the third node.\n");
    return 1;
  }
  third->data = 3;
  third->next = NULL;
  second->next = third;

  // Print the linked list
  printf("Linked list:\n");
  struct node *current_node = head;
  while (current_node != NULL) {
    printf("%d\n", current_node->data);
    current_node = current_node->next;
  }

  // Free the memory of the linked list
  current_node = head;
  while (current_node != NULL) {
    struct node *next_node = current_node->next;
    free(current_node);
    current_node = next_node;
  }

  return 0;
}