//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: lively
#include <stdlib.h>
#include <stdio.h>

#define MAZE_SIZE 20

typedef struct Node {
  int x;
  int y;
  struct Node* next;
} Node;

Node* createNode(int x, int y) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->x = x;
  node->y = y;
  node->next = NULL;
  return node;
}

void generateMaze(Node* head) {
  srand(time(NULL));
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      if (rand() % 2 == 0) {
        head->next = createNode(i, j);
        head = head->next;
      }
    }
  }
}

void printMaze(Node* head) {
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      if (head->x == i && head->y == j) {
        printf("O ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
}

int main() {
  Node* head = createNode(0, 0);
  generateMaze(head);
  printMaze(head);
  return 0;
}