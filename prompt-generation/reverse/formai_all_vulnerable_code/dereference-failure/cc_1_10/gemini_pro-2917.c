//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define a node for a linked list
struct node {
  int data;
  struct node *next;
};

// Define a linked list
struct linked_list {
  struct node *head;
  struct node *tail;
};

// Create a new node
struct node *create_node(int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Insert a node at the beginning of the linked list
void insert_at_head(struct linked_list *list, struct node *new_node) {
  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    new_node->next = list->head;
    list->head = new_node;
  }
}

// Insert a node at the end of the linked list
void insert_at_tail(struct linked_list *list, struct node *new_node) {
  if (list->tail == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }
}

// Delete a node from the linked list
void delete_node(struct linked_list *list, struct node *node) {
  if (node == list->head) {
    list->head = node->next;
    if (list->head == NULL) {
      list->tail = NULL;
    }
  } else {
    struct node *temp = list->head;
    while (temp->next != node) {
      temp = temp->next;
    }
    temp->next = node->next;
    if (node == list->tail) {
      list->tail = temp;
    }
  }
  free(node);
}

// Print the linked list
void print_list(struct linked_list *list) {
  struct node *temp = list->head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  // Create a new linked list
  struct linked_list *list = (struct linked_list *)malloc(sizeof(struct linked_list));
  list->head = NULL;
  list->tail = NULL;

  // Insert some nodes into the linked list
  insert_at_head(list, create_node(1));
  insert_at_head(list, create_node(2));
  insert_at_head(list, create_node(3));
  insert_at_tail(list, create_node(4));
  insert_at_tail(list, create_node(5));
  insert_at_tail(list, create_node(6));

  // Print the linked list
  printf("Linked list: ");
  print_list(list);

  // Delete a node from the linked list
  delete_node(list, list->head);

  // Print the linked list
  printf("Linked list after deleting the first node: ");
  print_list(list);

  // Free the linked list
  struct node *temp = list->head;
  while (temp != NULL) {
    struct node *next = temp->next;
    free(temp);
    temp = next;
  }
  free(list);

  return 0;
}