//Gemma-7B DATASET v1.0 Category: Chess AI ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 64

typedef struct Node {
  int move_made;
  struct Node* next;
} Node;

void make_move(Node* current, int move) {
  current->move_made = move;
  current->next = malloc(sizeof(Node));
  current = current->next;
  current->move_made = -1;
  current->next = NULL;
}

int evaluate_board(Node* current) {
  int board[BOARD_SIZE] = {0};
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (current->move_made & (1 << i)) {
      board[i] = 1;
    }
  }
  int score = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i] == 1) {
      score++;
    }
  }
  return score;
}

int main() {
  time_t t = time(NULL);
  Node* root = malloc(sizeof(Node));
  root->move_made = -1;
  root->next = NULL;
  make_move(root, 1);
  make_move(root, 3);
  make_move(root, 5);
  make_move(root, 6);
  make_move(root, 9);
  make_move(root, 11);
  make_move(root, 14);
  make_move(root, 16);
  int score = evaluate_board(root);
  printf("Score: %d", score);
  return 0;
}