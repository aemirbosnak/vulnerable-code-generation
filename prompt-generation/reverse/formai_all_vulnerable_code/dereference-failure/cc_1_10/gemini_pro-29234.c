//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void push(struct Node **head_ref, int new_data) {
  struct Node *new_node = malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = *head_ref;
  *head_ref = new_node;
}

void insertAfter(struct Node *prev_node, int new_data) {
  if (prev_node == NULL) {
    printf("The given previous node cannot be NULL");
    return;
  }
  struct Node *new_node = malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

void append(struct Node **head_ref, int new_data) {
  struct Node *new_node = malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = NULL;
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  struct Node *last_node = *head_ref;
  while (last_node->next != NULL) {
    last_node = last_node->next;
  }
  last_node->next = new_node;
}

void printList(struct Node *node) {
  while (node != NULL) {
    printf(" %d ", node->data);
    node = node->next;
  }
}

int main() {
  struct Node *head = NULL;
  int choice, data;

  while (1) {
    printf("\n1. Push\n2. Insert after\n3. Append\n4. Print list\n5. Exit\n\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter the data to push: ");
      scanf("%d", &data);
      push(&head, data);
      break;
    case 2:
      printf("Enter the data to insert after: ");
      scanf("%d", &data);
      struct Node *prev_node = head;
      while (prev_node != NULL && prev_node->data != data) {
        prev_node = prev_node->next;
      }
      if (prev_node == NULL) {
        printf("The given data is not present in the list\n");
        break;
      }
      printf("Enter the data to insert: ");
      scanf("%d", &data);
      insertAfter(prev_node, data);
      break;
    case 3:
      printf("Enter the data to append: ");
      scanf("%d", &data);
      append(&head, data);
      break;
    case 4:
      printf("The linked list is: ");
      printList(head);
      break;
    case 5:
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }

  return 0;
}