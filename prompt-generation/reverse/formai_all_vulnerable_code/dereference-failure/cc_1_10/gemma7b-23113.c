//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* createNode(int x, int y) {
  Node* node = malloc(sizeof(Node));
  node->x = x;
  node->y = y;
  node->next = NULL;
  return node;
}

void playTicTacToe(Node* board) {
  int move_count = 0;
  char current_player = 'X';

  while (move_count < BOARD_SIZE * BOARD_SIZE) {
    int x, y;
    printf("Enter your move (x, y): ");
    scanf("%d %d", &x, &y);

    if (board->x == x && board->y == y) {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    Node* new_node = createNode(x, y);
    board->next = new_node;

    move_count++;

    if (current_player == 'X') {
      current_player = 'O';
    } else {
      current_player = 'X';
    }
  }

  printf("Game over! The winner is: %c\n", current_player);
}

int main() {
  Node* board = createNode(0, 0);
  playTicTacToe(board);

  return 0;
}