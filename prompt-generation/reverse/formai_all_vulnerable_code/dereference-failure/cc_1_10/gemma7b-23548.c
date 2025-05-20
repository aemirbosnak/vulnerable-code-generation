//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* createNode(int x, int y) {
  Node* newNode = malloc(sizeof(Node));
  newNode->x = x;
  newNode->y = y;
  newNode->next = NULL;
  return newNode;
}

void placeMove(Node* board, int move) {
  switch (move) {
    case 0:
      board->x = 0;
      board->y = 0;
      break;
    case 1:
      board->x = 0;
      board->y = 1;
      break;
    case 2:
      board->x = 0;
      board->y = 2;
      break;
    case 3:
      board->x = 1;
      board->y = 0;
      break;
    case 4:
      board->x = 1;
      board->y = 1;
      break;
    case 5:
      board->x = 1;
      board->y = 2;
      break;
    case 6:
      board->x = 2;
      board->y = 0;
      break;
    case 7:
      board->x = 2;
      board->y = 1;
      break;
    case 8:
      board->x = 2;
      board->y = 2;
      break;
  }
}

int checkWin(Node* board) {
  // Horizontal win
  if (board->x == board->next->x && board->x == board->next->next->x) {
    return 1;
  }

  // Vertical win
  if (board->y == board->next->y && board->y == board->next->next->y) {
    return 1;
  }

  // Diagonal win
  if (board->x - board->y == board->next->x - board->next->y && board->x - board->y == board->next->next->x - board->next->next->y) {
    return 1;
  }

  // No win
  return 0;
}

int main() {
  Node* board = createNode(0, 0);
  placeMove(board, 0);
  placeMove(board, 2);
  placeMove(board, 4);
  placeMove(board, 6);
  placeMove(board, 8);

  if (checkWin(board) == 1) {
    printf("Player won!");
  } else {
    printf("No winner");
  }

  return 0;
}