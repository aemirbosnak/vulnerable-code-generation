//Gemma-7B DATASET v1.0 Category: Chess AI ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOARD_SIZE 64

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

typedef struct Move {
  int from_x, from_y, to_x, to_y;
  struct Move* next;
} Move;

void make_move(Move** head, int from_x, int from_y, int to_x, int to_y) {
  Move* new_move = malloc(sizeof(Move));
  new_move->from_x = from_x;
  new_move->from_y = from_y;
  new_move->to_x = to_x;
  new_move->to_y = to_y;
  new_move->next = NULL;

  if (*head == NULL) {
    *head = new_move;
  } else {
    (*head)->next = new_move;
  }
}

int main() {
  Node* board = NULL;
  Move* moves = NULL;

  make_move(&moves, 0, 0, 1, 0);
  make_move(&moves, 1, 0, 2, 0);
  make_move(&moves, 2, 0, 3, 0);

  make_move(&moves, 0, 1, 1, 1);
  make_move(&moves, 1, 1, 2, 1);

  make_move(&moves, 0, 2, 1, 2);

  for (Move* move = moves; move; move = move->next) {
    printf("From: (%d, %d) To: (%d, %d)\n", move->from_x, move->from_y, move->to_x, move->to_y);
  }

  return 0;
}