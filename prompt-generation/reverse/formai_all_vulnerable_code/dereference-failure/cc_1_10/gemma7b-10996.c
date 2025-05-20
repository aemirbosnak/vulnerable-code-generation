//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define the Tic Tac Toe board
#define BOARD_SIZE 3

typedef struct Node {
  int data;
  struct Node* next;
} Node;

// Function to insert a move into the Tic Tac Toe board
void insertMove(Node* head, int move) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = move;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    newNode->next = head;
    head = newNode;
  }
}

// Function to check if the player has won
int checkWin(Node* head) {
  // Check for rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (head->data == i + 1) {
      return 1;
    }
  }

  // Check for columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (head->data == j + 1) {
      return 1;
    }
  }

  // Check for diagonals
  if (head->data == 1 && head->next->data == 3 && head->next->next->data == 5) {
    return 1;
  }

  // If no win, return 0
  return 0;
}

// Function to play the Tic Tac Toe game
int main() {
  // Create the Tic Tac Toe board
  Node* head = NULL;

  // Get the player's move
  int move;

  // Play until the player wins or it's a draw
  while (!checkWin(head) && move != -1) {
    // Get the player's move
    printf("Enter your move (1-9): ");
    scanf("%d", &move);

    // Insert the move into the board
    insertMove(head, move);
  }

  // Check if the player has won or it's a draw
  if (checkWin(head) == 1) {
    printf("You win!");
  } else if (move == -1) {
    printf("It's a draw!");
  }

  return 0;
}