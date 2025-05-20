//FormAI DATASET v1.0 Category: Linked list operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

typedef struct node Node;

// initialize an empty linked list
void initializeList(Node **head) {
  *head = NULL;
}

// check if linked list is empty
int isListEmpty(Node *head) {
  return head == NULL;
}

// insert node at the beginning of the linked list
void insertAtBeginning(Node **head, int data) {
  Node *newNode = (Node*) malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = *head;
  *head = newNode;
}

// insert node at the end of the linked list
void insertAtEnd(Node **head, int data) {
  Node *newNode = (Node*) malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  // if linked list is empty, make newnode the head
  if (*head == NULL) {
    *head = newNode;
    return;
  }

  // traverse the linked list and add the node to the end
  Node *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = newNode;
}

// insert node at a specific position in the linked list
void insertAtPosition(Node **head, int data, int position) {
  Node *newNode = (Node*) malloc(sizeof(Node));
  newNode->data = data;
  
  // if linked list is empty, make newnode the head
  if (*head == NULL) {
    *head = newNode;
    return;
  }

  // traverse the linked list and add the node at the given position
  Node *current = *head;
  for (int i=1; i<position-1; i++) {
    if (current->next == NULL) {
      printf("Invalid position\n");
      return;
    }
    current = current->next;
  }
  newNode->next = current->next;
  current->next = newNode;
}

// delete node from the beginning of the linked list
void deleteFromBeginning(Node **head) {
  if (*head == NULL) {
    printf("List is already empty\n");
    return;
  }
  Node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

// delete node from the end of the linked list
void deleteFromEnd(Node **head) {
  if (*head == NULL) {
    printf("List is already empty\n");
    return;
  }
  if ((*head)->next == NULL) {
    free(*head);
    *head = NULL;
    return;
  }
  Node *current = *head;
  while (current->next->next != NULL) {
    current = current->next;
  }
  free(current->next);
  current->next = NULL;
}

// delete node from a specific position in the linked list
void deleteFromPosition(Node **head, int position) {
  if (*head == NULL) {
    printf("List is already empty\n");
    return;
  }
  Node *current = *head;
  if (position == 1) {
    *head = (*head)->next;
    free(current);
    return;
  }
  for (int i=1; i<position-1; i++) {
    if (current->next == NULL) {
      printf("Invalid position\n");
      return;
    }
    current = current->next;
  }
  Node *temp = current->next;
  current->next = current->next->next;
  free(temp);
}

// display linked list
void displayList(Node *head) {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  Node *head;
  initializeList(&head);
  
  insertAtBeginning(&head, 3);
  insertAtEnd(&head, 5);
  insertAtBeginning(&head, 2);
  insertAtEnd(&head, 7);
  insertAtPosition(&head, 4, 3);
  displayList(head);

  deleteFromBeginning(&head);
  deleteFromEnd(&head);
  deleteFromPosition(&head, 2);
  displayList(head);

  return 0;
}