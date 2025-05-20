//FormAI DATASET v1.0 Category: Linked list operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

// function to create a new node
struct node *create_node(int data) {
  struct node *new_node = (struct node*) malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// function to insert a node
void insert_node(struct node **head_ref, int data) {
  struct node *new_node = create_node(data);
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  struct node *current_node = *head_ref;
  while (current_node->next != NULL) {
    current_node = current_node->next;
  }
  current_node->next = new_node;
}

// function to delete a node
void delete_node(struct node **head_ref, int key) {
  struct node *current_node = *head_ref, *prev = NULL;
  if (current_node != NULL && current_node->data == key) {
    *head_ref = current_node->next;
    free(current_node);
    return;
  }
  while (current_node != NULL && current_node->data != key) {
    prev = current_node;
    current_node = current_node->next;
  }
  if (current_node == NULL) {
    return;
  }
  prev->next = current_node->next;
  free(current_node);
}

// function to display the linked list
void display_list(struct node *head_ref) {
  struct node *current_node = head_ref;
  while(current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }
  printf("\n");
}

// function to find the length of the linked list
int list_length(struct node *head_ref) {
  int count = 0;
  struct node *current_node = head_ref;
  while(current_node != NULL) {
    count++;
    current_node = current_node->next;
  }
  return count;
}

int main() {
  struct node *head = NULL;
  insert_node(&head, 1);
  insert_node(&head, 2);
  insert_node(&head, 3);
  insert_node(&head, 4);
  display_list(head);
  delete_node(&head, 3);
  display_list(head);
  int length = list_length(head);
  printf("The length of the linked list is %d\n", length);
  return 0;
}