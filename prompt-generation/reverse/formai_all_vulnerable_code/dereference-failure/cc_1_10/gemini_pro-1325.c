//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Celestial bodies - nodes of the Linked List
struct Node {
  int data;
  struct Node *next;
};

// The grand dance begins - Linked List operations
void createList(struct Node **head, int n) {
  // Summon the celestial bodies and link them
  for (int i = 0; i < n; i++) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = rand() % 100;
    newNode->next = NULL;
    if (*head == NULL)
      *head = newNode;
    else {
      struct Node *temp = *head;
      while (temp->next != NULL)
        temp = temp->next;
      temp->next = newNode;
    }
  }
}

void displayList(struct Node *head) {
  // Behold the celestial procession
  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

void insertAtBeginning(struct Node **head, int data) {
  // A new star emerges in the celestial tapestry
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = *head;
  *head = newNode;
}

void insertAtEnd(struct Node **head, int data) {
  // A distant star takes its place in the cosmic choir
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  if (*head == NULL)
    *head = newNode;
  else {
    struct Node *temp = *head;
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = newNode;
  }
}

void insertAtPosition(struct Node **head, int data, int pos) {
  // A celestial body finds its orbital slot
  if (pos == 1) {
    insertAtBeginning(head, data);
  } else {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node *temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }
}

void deleteAtBeginning(struct Node **head) {
  // A celestial body fades into cosmic dust
  if (*head != NULL) {
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
  }
}

void deleteAtEnd(struct Node **head) {
  // A distant star blinks out of existence
  if (*head != NULL) {
    struct Node *temp = *head;
    struct Node *prev = NULL;
    while (temp->next != NULL) {
      prev = temp;
      temp = temp->next;
    }
    if (prev != NULL) {
      prev->next = NULL;
      free(temp);
    } else {
      *head = NULL;
      free(temp);
    }
  }
}

void deleteAtPosition(struct Node **head, int pos) {
  // A celestial body vanishes from its orbit
  if (head != NULL) {
    struct Node *temp = *head;
    struct Node *prev = NULL;
    for (int i = 1; i < pos && temp != NULL; i++) {
      prev = temp;
      temp = temp->next;
    }
    if (pos == 1) {
      *head = (*head)->next;
      free(temp);
    } else if (temp != NULL) {
      prev->next = temp->next;
      free(temp);
    }
  }
}

int main() {
  // The celestial dance takes shape
  struct Node *head = NULL;
  createList(&head, 10);
  displayList(head);
  printf("Inserting 15 at the beginning...\n");
  insertAtBeginning(&head, 15);
  displayList(head);
  printf("Inserting 20 at the end...\n");
  insertAtEnd(&head, 20);
  displayList(head);
  printf("Inserting 25 at position 3...\n");
  insertAtPosition(&head, 25, 3);
  displayList(head);
  printf("Deleting from the beginning...\n");
  deleteAtBeginning(&head);
  displayList(head);
  printf("Deleting from the end...\n");
  deleteAtEnd(&head);
  displayList(head);
  printf("Deleting at position 3...\n");
  deleteAtPosition(&head, 3);
  displayList(head);
  return 0;
}