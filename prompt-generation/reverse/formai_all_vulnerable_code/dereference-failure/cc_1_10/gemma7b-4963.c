//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BOARD_SIZE 3

typedef struct Node {
  char symbol;
  struct Node* next;
} Node;

Node* createNode(char symbol) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->symbol = symbol;
  node->next = NULL;
  return node;
}

void insertAtTail(Node* head, char symbol) {
  Node* newNode = createNode(symbol);
  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }
  head = newNode;
}

int checkWin(Node* head) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (head->symbol == head->next->symbol && head->next->symbol == head->next->next->symbol) {
      return 1;
    }
    head = head->next;
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (head->symbol == head->next->symbol && head->next->symbol == head->next->next->symbol) {
      return 1;
    }
    head = head->next;
  }

  // Check diagonals
  if (head->symbol == head->next->next->symbol) {
    return 1;
  }

  return 0;
}

int main() {
  Node* head = NULL;

  // Game loop
  while (1) {
    // Get the player's move
    char move = getchar();

    // Insert the move into the board
    insertAtTail(head, move);

    // Check if the player has won
    if (checkWin(head) == 1) {
      printf("You have won!\n");
      break;
    }

    // Check if the board is full
    if (head->next == NULL) {
      printf("It's a draw!\n");
      break;
    }
  }

  return 0;
}