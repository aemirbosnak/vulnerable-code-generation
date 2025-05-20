//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* createNode(int x, int y) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->x = x;
  newNode->y = y;
  newNode->next = NULL;
  return newNode;
}

void playGame() {
  int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  };

  Node* head = createNode(0, 0);
  head->next = createNode(1, 0);
  head->next->next = createNode(2, 0);
  head->next->next->next = createNode(0, 1);
  head->next->next->next->next = createNode(1, 1);
  head->next->next->next->next->next = createNode(2, 1);
  head->next->next->next->next->next->next = createNode(0, 2);
  head->next->next->next->next->next->next->next = createNode(1, 2);
  head->next->next->next->next->next->next->next->next = createNode(2, 2);

  srand(time(NULL));

  int player = rand() % 2 + 1;
  int moveMade = 0;

  while (!moveMade) {
    int x = rand() % BOARD_SIZE;
    int y = rand() % BOARD_SIZE;

    if (board[x][y] == 0) {
      board[x][y] = player;
      moveMade = 1;
    }
  }

  int winner = checkWinner(board);

  if (winner == player) {
    printf("You won!");
  } else if (winner == 0) {
    printf("It's a draw!");
  } else {
    printf("You lost!");
  }
}

int checkWinner(int** board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != 0) {
      return board[0][i];
    }
  }

  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] != 0) {
      return board[j][0];
    }
  }

  if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0) {
    return board[0][0];
  }

  return 0;
}

int main() {
  playGame();

  return 0;
}