//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

int main() {
  srand(time(NULL));

  Node* gameBoard = insertAtTail(NULL, 0);
  insertAtTail(gameBoard, 1);
  insertAtTail(gameBoard, 2);
  insertAtTail(gameBoard, 3);
  insertAtTail(gameBoard, 4);
  insertAtTail(gameBoard, 5);
  insertAtTail(gameBoard, 6);
  insertAtTail(gameBoard, 7);
  insertAtTail(gameBoard, 8);
  insertAtTail(gameBoard, 9);

  int playerTurn = rand() % 2;

  // Game loop
  while (gameBoard->next != NULL) {
    int move = rand() % 9;

    // Check if move is valid
    if (gameBoard->next->data == move) {
      // Make move
      gameBoard->next->data = playerTurn + 1;

      // Change player turn
      playerTurn = (playerTurn + 1) % 2;
    }
  }

  // Game over
  printf("Game over! The winner is: ");

  // Check who won
  if (playerTurn == 0) {
    printf("Player 1\n");
  } else {
    printf("Player 2\n");
  }

  return 0;
}