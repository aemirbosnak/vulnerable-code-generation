//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
  int data;
  struct node *next;
} node;

// Linked list operations
void insert_at_beginning(node **head, int data) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
}

void insert_at_end(node **head, int data) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;

  if (*head == NULL) {
    *head = new_node;
  } else {
    node *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

void insert_at_position(node **head, int data, int position) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;

  if (position == 1) {
    new_node->next = *head;
    *head = new_node;
  } else {
    node *current = *head;
    int i = 1;
    while (current != NULL && i < position - 1) {
      current = current->next;
      i++;
    }

    if (current != NULL) {
      new_node->next = current->next;
      current->next = new_node;
    } else {
      printf("Invalid position!\n");
    }
  }
}

void delete_at_beginning(node **head) {
  if (*head == NULL) {
    printf("Linked list is empty!\n");
    return;
  }

  node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

void delete_at_end(node **head) {
  if (*head == NULL) {
    printf("Linked list is empty!\n");
    return;
  }

  if ((*head)->next == NULL) {
    free(*head);
    *head = NULL;
  } else {
    node *current = *head;
    while (current->next->next != NULL) {
      current = current->next;
    }
    free(current->next);
    current->next = NULL;
  }
}

void delete_at_position(node **head, int position) {
  if (*head == NULL) {
    printf("Linked list is empty!\n");
    return;
  }

  if (position == 1) {
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
  } else {
    node *current = *head;
    int i = 1;
    while (current != NULL && i < position - 1) {
      current = current->next;
      i++;
    }

    if (current != NULL && current->next != NULL) {
      node *temp = current->next;
      current->next = current->next->next;
      free(temp);
    } else {
      printf("Invalid position!\n");
    }
  }
}

void print_linked_list(node *head) {
  if (head == NULL) {
    printf("Linked list is empty!\n");
    return;
  }

  node *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }

  printf("\n");
}

int main() {
  node *head = NULL;

  // Insert elements at the beginning
  insert_at_beginning(&head, 10);
  insert_at_beginning(&head, 20);
  insert_at_beginning(&head, 30);

  // Insert elements at the end
  insert_at_end(&head, 40);
  insert_at_end(&head, 50);
  insert_at_end(&head, 60);

  // Insert elements at specific positions
  insert_at_position(&head, 70, 3);
  insert_at_position(&head, 80, 6);

  // Print the linked list
  printf("Linked list: ");
  print_linked_list(head);

  // Delete elements at the beginning
  delete_at_beginning(&head);
  delete_at_beginning(&head);

  // Delete elements at the end
  delete_at_end(&head);
  delete_at_end(&head);

  // Delete elements at specific positions
  delete_at_position(&head, 3);
  delete_at_position(&head, 6);

  // Print the linked list after deletions
  printf("Linked list after deletions: ");
  print_linked_list(head);

  return 0;
}