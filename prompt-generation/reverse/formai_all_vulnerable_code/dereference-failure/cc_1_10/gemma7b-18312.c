//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: puzzling
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* createNode(int x, int y) {
  Node* node = malloc(sizeof(struct Node));
  node->x = x;
  node->y = y;
  node->next = NULL;
  return node;
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

  srand(time(NULL));
  int move = rand() % BOARD_SIZE * BOARD_SIZE;
  Node* current = head;
  for (int i = 0; i < move; i++) {
    current = current->next;
  }

  current->next = createNode(rand() % BOARD_SIZE, rand() % BOARD_SIZE);
  head = current->next;
  printf("Move: (%d, %d)\n", head->x, head->y);
  printf("Board:\n");
  for (current = head; current; current = current->next) {
    printf("(%d, %d) ", current->x, current->y);
  }
  printf("\n");
}

int main() {
  playTicTacToe();
  return 0;
}