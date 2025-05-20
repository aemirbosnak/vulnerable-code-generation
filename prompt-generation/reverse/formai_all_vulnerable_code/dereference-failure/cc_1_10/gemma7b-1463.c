//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: intelligent
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define WALL 1
#define EMPTY 0

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

void GenerateMaze(int** maze, int width, int height) {
  time_t t = time(NULL);
  srand(t);

  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      maze[x][y] = EMPTY;
    }
  }

  int numWalls = rand() % (width * height / 2);

  for (int i = 0; i < numWalls; i++) {
    int x = rand() % width;
    int y = rand() % height;

    if (maze[x][y] == EMPTY) {
      maze[x][y] = WALL;
    }
  }
}

void DrawMaze(int** maze, int width, int height) {
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      if (maze[x][y] == WALL) {
        printf("W");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

int main() {
  int** maze = NULL;
  maze = malloc(MAZE_WIDTH * sizeof(int*));
  for (int i = 0; i < MAZE_WIDTH; i++) {
    maze[i] = malloc(MAZE_HEIGHT * sizeof(int));
  }

  GenerateMaze(maze, MAZE_WIDTH, MAZE_HEIGHT);
  DrawMaze(maze, MAZE_WIDTH, MAZE_HEIGHT);

  return 0;
}