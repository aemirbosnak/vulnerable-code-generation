//FormAI DATASET v1.0 Category: Linked list operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

void add_node(struct node **head, int data) {
  struct node *new_node = (struct node*) malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  
  if (*head == NULL) {
    *head = new_node;
  } else {
    struct node *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

void delete_node(struct node **head, int data) {
  if (*head == NULL) {
    return;
  }
  
  struct node *current = *head;
  struct node *prev = NULL;
  
  while (current != NULL) {
    if (current->data == data) {
      if (prev == NULL) {
        *head = current->next;
      } else {
        prev->next = current->next;
      }
      free(current);
      return;
    }
    prev = current;
    current = current->next;
  }
}

void print_list(struct node *head) {
  if (head == NULL) {
    printf("The list is empty.\n");
    return;
  }
  
  struct node *current = head;
  
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  struct node *head = NULL;
  
  add_node(&head, 1);
  add_node(&head, 2);
  add_node(&head, 3);
  add_node(&head, 4);
  printf("Current list:\n");
  print_list(head);
  
  delete_node(&head, 2);
  printf("List after deleting 2:\n");
  print_list(head);
  
  delete_node(&head, 1);
  printf("List after deleting 1:\n");
  print_list(head);
  
  delete_node(&head, 4);
  printf("List after deleting 4:\n");
  print_list(head);
  
  add_node(&head, 5);
  add_node(&head, 6);
  printf("Current list:\n");
  print_list(head);
  
  return 0;
}