//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: retro
// retro-style linked list operations example program
#include <stdio.h>
#include <stdlib.h>

// define node structure
struct node {
  int data;
  struct node *next;
};

// define linked list
struct node *head = NULL;

// function to insert a node at the beginning of the list
void insert_start(int data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = head;
  head = new_node;
}

// function to insert a node at the end of the list
void insert_end(int data) {
  struct node *current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = malloc(sizeof(struct node));
  current->next->data = data;
  current->next->next = NULL;
}

// function to print the list
void print_list() {
  struct node *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  // insert some nodes
  insert_start(1);
  insert_start(2);
  insert_start(3);
  insert_end(4);
  insert_end(5);

  // print the list
  print_list();

  return 0;
}