//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int move;
  struct Node* next;
} Node;

void makeMove(Node* node, int move) {
  node->move = move;
  node->next = malloc(sizeof(Node));
  node->next->move = -1;
  node->next->next = NULL;
}

void playTicTacToe() {
  Node* head = NULL;
  int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}};

  int player = 1;
  while (!boardFull(board)) {
    int move = getRandomMove(board, head);
    makeMove(head, move);
    board[move / BOARD_SIZE][move % BOARD_SIZE] = player;
    player *= -1;
  }

  if (board[0][0] == head->move) {
    printf("Player 1 won!\n");
  } else {
    printf("Player 2 won!\n");
  }
}

int boardFull(int** board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == 0) {
        return 0;
      }
    }
  }

  return 1;
}

int getRandomMove(int** board, Node* head) {
  int moves[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  int availableMoves = 0;

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == 0) {
        availableMoves++;
      }
    }
  }

  if (availableMoves == 0) {
    return -1;
  }

  srand(time(NULL));
  return moves[rand() % availableMoves] + 1;
}

int main() {
  playTicTacToe();

  return 0;
}