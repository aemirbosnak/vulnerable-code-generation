//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
  int data;
  struct node *next;
};

// Linked list structure
struct linked_list {
  struct node *head;
  struct node *tail;
  int size;
};

// Function to add a node to the head of the linked list
void push(struct linked_list *list, int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = list->head;
  if (list->head == NULL) {
    list->tail = new_node;
  }
  list->head = new_node;
  list->size++;
}

// Function to add a node to the tail of the linked list
void append(struct linked_list *list, int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  if (list->tail == NULL) {
    list->head = new_node;
  } else {
    list->tail->next = new_node;
  }
  list->tail = new_node;
  list->size++;
}

// Function to print the linked list
void print(struct linked_list *list) {
  struct node *current = list->head;
  while (current!= NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  struct linked_list list;
  list.head = NULL;
  list.tail = NULL;
  list.size = 0;

  push(&list, 10);
  push(&list, 20);
  push(&list, 30);
  append(&list, 40);
  append(&list, 50);
  print(&list);
  return 0;
}