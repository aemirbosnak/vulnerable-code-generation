//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

struct Node {
  char *data;
  struct Node *next;
};

struct Node *createNode(char *data) {
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void insertAtHead(struct Node **head, char *data) {
  struct Node *newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
}

void insertAtTail(struct Node **head, char *data) {
  struct Node *newNode = createNode(data);
  if (*head == NULL) {
    *head = newNode;
  } else {
    struct Node *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
}

void insertAtIndex(struct Node **head, char *data, int index) {
  if (index == 0) {
    insertAtHead(head, data);
  } else {
    struct Node *newNode = createNode(data);
    struct Node *current = *head;
    for (int i = 0; i < index - 1 && current->next != NULL; i++) {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
  }
}

void deleteAtHead(struct Node **head) {
  if (*head == NULL) {
    return;
  }
  struct Node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

void deleteAtTail(struct Node **head) {
  if (*head == NULL) {
    return;
  }
  struct Node *current = *head;
  struct Node *prev = NULL;
  while (current->next != NULL) {
    prev = current;
    current = current->next;
  }
  if (prev == NULL) {
    *head = NULL;
  } else {
    prev->next = NULL;
  }
  free(current);
}

void deleteAtIndex(struct Node **head, int index) {
  if (index == 0) {
    deleteAtHead(head);
  } else {
    struct Node *current = *head;
    struct Node *prev = NULL;
    for (int i = 0; i < index && current->next != NULL; i++) {
      prev = current;
      current = current->next;
    }
    if (prev == NULL) {
      *head = NULL;
    } else {
      prev->next = current->next;
    }
    free(current);
  }
}

void printList(struct Node *head) {
  struct Node *current = head;
  while (current != NULL) {
    printf("%s ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  struct Node *head = NULL;

  insertAtHead(&head, "ACCESS");
  insertAtHead(&head, "GRANTED");
  insertAtTail(&head, "USER");
  insertAtIndex(&head, "LEVEL", 1);
  insertAtIndex(&head, "SEVEN", 2);

  printf("Original List: ");
  printList(head);

  deleteAtHead(&head);
  deleteAtTail(&head);
  deleteAtIndex(&head, 1);

  printf("Modified List: ");
  printList(head);

  return 0;
}