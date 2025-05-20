//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* CreateNode(int x, int y) {
  Node* node = malloc(sizeof(Node));
  node->x = x;
  node->y = y;
  node->next = NULL;
  return node;
}

void GenerateMaze(Node* head) {
  srand(time(NULL));
  int x, y, i, j;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      x = rand() % WIDTH;
      y = rand() % HEIGHT;
      Node* newNode = CreateNode(x, y);
      newNode->next = head;
      head = newNode;
    }
  }
}

void PrintMaze(Node* head) {
  int i, j;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      Node* current = head;
      while (current) {
        if (current->x == j && current->y == i) {
          printf("X ");
        } else {
          printf("O ");
        }
      }
      printf("\n");
    }
  }
}

int main() {
  Node* head = CreateNode(0, 0);
  GenerateMaze(head);
  PrintMaze(head);
  return 0;
}