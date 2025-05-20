//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

#define EMPTY 0
#define WALL 1
#define PLAYER 2
#define GOAL 3

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* CreateNode(int x, int y) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->x = x;
  node->y = y;
  node->next = NULL;
  return node;
}

void GenerateMaze(int** maze, int w, int h) {
  srand(time(NULL));
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      maze[y][x] = EMPTY;
    }
  }

  int numWalls = rand() % (w * h);
  for (int i = 0; i < numWalls; i++) {
    int x = rand() % w;
    int y = rand() % h;
    maze[y][x] = WALL;
  }

  maze[0][0] = PLAYER;
  maze[h - 1][w - 1] = GOAL;
}

void DrawMaze(int** maze, int w, int h) {
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      switch (maze[y][x]) {
        case EMPTY:
          printf(" ");
          break;
        case WALL:
          printf("#");
          break;
        case PLAYER:
          printf("P");
          break;
        case GOAL:
          printf("G");
          break;
      }
    }
    printf("\n");
  }
}

int main() {
  int** maze = (int**)malloc(MAZE_HEIGHT * sizeof(int*));
  for (int i = 0; i < MAZE_HEIGHT; i++) {
    maze[i] = (int*)malloc(MAZE_WIDTH * sizeof(int));
  }

  GenerateMaze(maze, MAZE_WIDTH, MAZE_HEIGHT);
  DrawMaze(maze, MAZE_WIDTH, MAZE_HEIGHT);

  free(maze);
  return 0;
}