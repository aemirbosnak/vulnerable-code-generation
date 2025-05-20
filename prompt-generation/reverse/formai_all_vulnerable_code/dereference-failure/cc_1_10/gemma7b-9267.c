//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int data;
  struct Node* next;
} Node;

int main() {
  srand(time(NULL));

  // Create a linked list to store the board
  Node* head = NULL;
  for (int i = 0; i < BOARD_SIZE; i++) {
    head = newNode(head, i);
  }

  // Initialize the board
  for (int i = 0; i < BOARD_SIZE; i++) {
    head->data = 0;
    head = head->next;
  }

  // Play the game
  int player = 1;
  while (!isBoardFull(head) && !hasWon(head, player)) {
    // Get the move
    int move = getRandomMove(head);

    // Place the move
    head->data = player;
    head = head->next;

    // Switch player
    player *= -1;
  }

  // Check if the game has been won or it's a draw
  if (hasWon(head, player) || isBoardFull(head)) {
    printf("Game Over!\n");
  } else {
    printf("Draw!\n");
  }

  return 0;
}

int newNode(Node* head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = head;
  return newNode;
}

int isBoardFull(Node* head) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (head->data == 0) {
      return 0;
    }
    head = head->next;
  }
  return 1;
}

int hasWon(Node* head, int player) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (head->data == player && head->next->data == player && head->next->next->data == player) {
      return 1;
    }
    head = head->next;
  }

  // Check columns
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (head->data == player && head->next->next->data == player && head->next->data == player) {
      return 1;
    }
    head = head->next;
  }

  // Check diagonals
  if (head->data == player && head->next->next->data == player && head->next->data == player) {
    return 1;
  }

  return 0;
}

int getRandomMove(Node* head) {
  int moves[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  srand(time(NULL));
  return moves[rand() % 9];
}