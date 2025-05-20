//FormAI DATASET v1.0 Category: Linked list operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

void print_list(Node *head) {
  if (head != NULL) {
    printf("%d -> ", head->data);
    print_list(head->next);
  } else {
    printf("NULL");
  }
}

Node *insert_end(Node *head, int data) {
  Node *new_node = malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;

  if (head == NULL) {
    return new_node;
  }

  Node *current = head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new_node;
  return head;
}

Node *delete_end(Node *head) {
  if (head == NULL || head->next == NULL) {
    free(head);
    return NULL;
  }

  Node *current = head;
  Node *prev = NULL;

  while (current->next != NULL) {
    prev = current;
    current = current->next;
  }

  free(current);
  prev->next = NULL;

  return head;
}

Node *search_and_delete(Node *head, int data) {
  if (head == NULL) {
    return NULL;
  }

  if (head->data == data) {
    Node *temp = head->next;
    free(head);
    return temp;
  }

  Node *current = head;
  Node *prev = NULL;

  while (current != NULL && current->data != data) {
    prev = current;
    current = current->next;
  }

  if (current != NULL) {
    prev->next = current->next;
    free(current);
  }

  return head;
}

int main() {
  Node *head = NULL;

  // Insert data at the end
  head = insert_end(head, 10);
  head = insert_end(head, 20);
  head = insert_end(head, 30);
  head = insert_end(head, 40);

  printf("Linked List after insertions: ");
  print_list(head); // Output: 10 -> 20 -> 30 -> 40 -> NULL

  // Delete data from the end
  head = delete_end(head);
  head = delete_end(head);

  printf("\nLinked List after deletions: ");
  print_list(head); // Output: 10 -> 20 -> NULL

  // Delete specific element
  head = search_and_delete(head, 10);

  printf("\nLinked List after deletion of 10: ");
  print_list(head); // Output: 20 -> NULL

  return 0;
}