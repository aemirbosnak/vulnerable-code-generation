//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGHT 10
#define MAX_WIDTH 10

typedef struct Node {
  int x;
  int y;
  struct Node* next;
} Node;

void createMaze(int** maze, int l, int w) {
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < w; j++) {
      maze[i][j] = rand() % 2;
    }
  }
}

void printMaze(int** maze, int l, int w) {
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < w; j++) {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }
}

void findPath(Node* node, int** maze, int l, int w) {
  if (node->x == l - 1 && node->y == w - 1) {
    return;
  }

  int dx[] = {0, 1, 0, -1};
  int dy[] = {1, 0, -1, 0};

  for (int i = 0; i < 4; i++) {
    int x = node->x + dx[i];
    int y = node->y + dy[i];

    if (x >= 0 && x < l && y >= 0 && y < w && maze[x][y] == 0) {
      Node* newNode = malloc(sizeof(Node));
      newNode->x = x;
      newNode->y = y;
      newNode->next = NULL;
      findPath(newNode, maze, l, w);
    }
  }
}

int main() {
  int l = MAX_LENGHT;
  int w = MAX_WIDTH;

  int** maze = (int**)malloc(l * sizeof(int*));
  for (int i = 0; i < l; i++) {
    maze[i] = (int*)malloc(w * sizeof(int));
  }

  createMaze(maze, l, w);
  printMaze(maze, l, w);

  Node* node = malloc(sizeof(Node));
  node->x = 0;
  node->y = 0;
  node->next = NULL;

  findPath(node, maze, l, w);

  return 0;
}