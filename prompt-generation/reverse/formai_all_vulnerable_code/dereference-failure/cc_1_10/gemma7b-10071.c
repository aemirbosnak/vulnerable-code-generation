//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: calm
#include <stdlib.h>
#include <stdio.h>
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

void playTicTacToe() {
  Node* head = createNode(0, 0);
  head->next = createNode(1, 0);
  head->next->next = createNode(2, 0);
  head->next->next->next = createNode(0, 1);
  head->next->next->next->next = createNode(1, 1);
  head->next->next->next->next->next = createNode(2, 1);
  head->next->next->next->next->next->next = createNode(0, 2);
  head->next->next->next->next->next->next->next = createNode(1, 2);
  head->next->next->next->next->next->next->next->next = createNode(2, 2);

  int board[BOARD_SIZE][BOARD_SIZE] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  };

  int player = 1;
  int move = 0;

  while (!board[2][2] && move < 9) {
    int x, y;

    printf("Enter your move (x, y): ");
    scanf("%d %d", &x, &y);

    if (board[x][y] != 0) {
      printf("Invalid move.\n");
      continue;
    }

    board[x][y] = player;
    move++;

    int winner = checkWin(board, player);

    if (winner) {
      printf("You won!\n");
      break;
    } else if (move == 9) {
      printf("It's a draw.\n");
      break;
    }

    player *= -1;
  }
}

int checkWin(int** board, int player) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return 1;
    }
  }

  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[j][0] == player && board[j][1] == player && board[j][2] == player) {
      return 1;
    }
  }

  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return 1;
  }

  return 0;
}

int main() {
  playTicTacToe();

  return 0;
}