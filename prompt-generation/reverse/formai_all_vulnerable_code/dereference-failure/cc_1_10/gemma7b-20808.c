//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    ((*head)->next = newNode);
    *head = newNode;
  }
}

int checkWin(Node* head, int player) {
  // Check rows
  for (int i = 0; i < MAX_SIZE; i++) {
    Node* current = head;
    for (int j = 0; j < MAX_SIZE; j++) {
      if (current->data == player && current->next->data == player && current->next->next->data == player) {
        return 1;
      }
      current = current->next;
    }
  }

  // Check columns
  for (int i = 0; i < MAX_SIZE; i++) {
    Node* current = head;
    for (int j = 0; j < MAX_SIZE; j++) {
      if (current->data == player && current->next->data == player && current->next->next->data == player) {
        return 1;
      }
      current = current->next;
    }
  }

  // Check diagonals
  Node* current = head;
  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      if (current->data == player && current->next->data == player && current->next->next->data == player) {
        return 1;
      }
      current = current->next;
    }
  }

  return 0;
}

int main() {
  Node* head = NULL;
  insertAtTail(&head, 1);
  insertAtTail(&head, 2);
  insertAtTail(&head, 3);
  insertAtTail(&head, 4);
  insertAtTail(&head, 5);
  insertAtTail(&head, 6);
  insertAtTail(&head, 7);
  insertAtTail(&head, 8);
  insertAtTail(&head, 9);

  if (checkWin(head, 1) == 1) {
    printf("Player 1 won!");
  } else if (checkWin(head, 2) == 1) {
    printf("Player 2 won!");
  } else {
    printf("It's a draw!");
  }

  return 0;
}