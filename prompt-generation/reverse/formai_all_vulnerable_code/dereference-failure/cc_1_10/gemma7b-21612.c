//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Node {
  int data;
  struct Node* next;
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

int checkWin(Node* head) {
  // Check for horizontal win
  for (int i = 0; i < BOARD_SIZE; i++) {
    Node* current = head;
    int rowWin = 0;
    while (current) {
      if (current->data == i + 1) {
        rowWin++;
      }
      current = current->next;
    }
    if (rowWin == BOARD_SIZE) {
      return 1;
    }
  }

  // Check for vertical win
  for (int i = 0; i < BOARD_SIZE; i++) {
    Node* current = head;
    int columnWin = 0;
    while (current) {
      if (current->data == i + 1) {
        columnWin++;
      }
      current = current->next;
    }
    if (columnWin == BOARD_SIZE) {
      return 1;
    }
  }

  // Check for diagonal win
  Node* current = head;
  int diagonalWin = 0;
  while (current) {
    if (current->data == 1) {
      diagonalWin++;
    }
    current = current->next;
  }
  if (diagonalWin == BOARD_SIZE) {
    return 1;
  }

  return 0;
}

int main() {
  Node* head = NULL;

  // Play the game
  for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
    // Get the player's move
    int move = rand() % BOARD_SIZE + 1;

    // Insert the move into the board
    head = insert(head, move);

    // Check if the player has won
    if (checkWin(head) == 1) {
      printf("You have won!\n");
      break;
    }
  }

  // If the game has ended, print the winner
  if (checkWin(head) == 0) {
    printf("It's a draw!\n");
  }

  return 0;
}