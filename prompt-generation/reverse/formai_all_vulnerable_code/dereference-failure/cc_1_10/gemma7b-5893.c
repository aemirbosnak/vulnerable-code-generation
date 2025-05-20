//Gemma-7B DATASET v1.0 Category: Memory management ; Style: multiplayer
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
  struct Node* next;
  int data;
} Node;

Node* insert(Node* head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void freeList(Node* head) {
  Node* current = head;
  Node* next = NULL;

  while (current) {
    next = current->next;
    free(current);
    current = next;
  }
}

int main() {
  Node* head = NULL;

  // Multiplayer game loop
  while (1) {
    // Get the player's move
    int move = rand() % MAX_SIZE;

    // Insert the move into the linked list
    head = insert(head, move);

    // Check if the player has won
    if (head->data == MAX_SIZE - 1) {
      freeList(head);
      printf("Player won!");
      break;
    }
  }

  // Free the linked list
  freeList(head);

  return 0;
}