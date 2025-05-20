//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: future-proof
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

typedef struct Node {
  struct Node* next;
  int x;
  int y;
} Node;

Node* createNode(int x, int y) {
  Node* node = malloc(sizeof(struct Node));
  node->next = NULL;
  node->x = x;
  node->y = y;
  return node;
}

void generateMaze(int** maze, int width, int height) {
  srand(time(NULL));

  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      maze[x][y] = EMPTY_CHAR;
    }
  }

  int numWalls = rand() % (width * height);

  for (int i = 0; i < numWalls; i++) {
    int x = rand() % width;
    int y = rand() % height;

    if (maze[x][y] != EMPTY_CHAR) {
      continue;
    }

    maze[x][y] = WALL_CHAR;
  }
}

int main() {
  int** maze = malloc(sizeof(int*) * MAZE_WIDTH);
  for (int i = 0; i < MAZE_WIDTH; i++) {
    maze[i] = malloc(sizeof(int) * MAZE_HEIGHT);
  }

  generateMaze(maze, MAZE_WIDTH, MAZE_HEIGHT);

  for (int x = 0; x < MAZE_WIDTH; x++) {
    for (int y = 0; y < MAZE_HEIGHT; y++) {
      printf("%c ", maze[x][y]);
    }
    printf("\n");
  }

  free(maze);
  return 0;
}