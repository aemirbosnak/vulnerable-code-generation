//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node_t;

node_t *create_node(int data) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  if (new_node == NULL) {
    perror("Error allocating memory for new node");
    exit(1);
  }
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void insert_at_head(node_t **head, int data) {
  node_t *new_node = create_node(data);
  new_node->next = *head;
  *head = new_node;
}

void insert_at_tail(node_t **head, int data) {
  node_t *new_node = create_node(data);
  if (*head == NULL) {
    *head = new_node;
  } else {
    node_t *curr = *head;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = new_node;
  }
}

void insert_at_index(node_t **head, int data, int index) {
  if (index == 0) {
    insert_at_head(head, data);
  } else {
    node_t *new_node = create_node(data);
    node_t *curr = *head;
    for (int i = 0; i < index - 1; i++) {
      if (curr->next == NULL) {
        printf("Error: Index is out of bounds\n");
        free(new_node);
        return;
      }
      curr = curr->next;
    }
    new_node->next = curr->next;
    curr->next = new_node;
  }
}

void delete_at_head(node_t **head) {
  if (*head == NULL) {
    printf("Error: List is empty\n");
    return;
  }
  node_t *temp = *head;
  *head = (*head)->next;
  free(temp);
}

void delete_at_tail(node_t **head) {
  if (*head == NULL) {
    printf("Error: List is empty\n");
    return;
  }
  if ((*head)->next == NULL) {
    free(*head);
    *head = NULL;
    return;
  }
  node_t *curr = *head;
  while (curr->next->next != NULL) {
    curr = curr->next;
  }
  free(curr->next);
  curr->next = NULL;
}

void delete_at_index(node_t **head, int index) {
  if (*head == NULL) {
    printf("Error: List is empty\n");
    return;
  }
  if (index == 0) {
    delete_at_head(head);
  } else {
    node_t *curr = *head;
    for (int i = 0; i < index - 1; i++) {
      if (curr->next == NULL) {
        printf("Error: Index is out of bounds\n");
        return;
      }
      curr = curr->next;
    }
    node_t *temp = curr->next;
    curr->next = temp->next;
    free(temp);
  }
}

void print_list(node_t *head) {
  printf("List: ");
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  node_t *head = NULL;

  insert_at_head(&head, 10);
  insert_at_tail(&head, 20);
  insert_at_index(&head, 30, 1);
  insert_at_tail(&head, 40);
  insert_at_index(&head, 50, 2);

  print_list(head);

  delete_at_head(&head);
  delete_at_tail(&head);
  delete_at_index(&head, 1);
  delete_at_tail(&head);

  print_list(head);

  return 0;
}