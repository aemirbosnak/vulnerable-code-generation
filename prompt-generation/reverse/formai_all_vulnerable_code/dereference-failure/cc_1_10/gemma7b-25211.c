//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: ultraprecise
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define MAZE_SIZE 100

typedef struct Node {
  struct Node* up, *down, *left, *right;
  int x, y;
} Node;

Node** generateMaze(int size) {
  srand(time(NULL));
  Node** maze = (Node**)malloc(size * sizeof(Node*));
  for (int i = 0; i < size; i++) {
    maze[i] = (Node*)malloc(sizeof(Node));
    maze[i]->up = maze[i]->down = maze[i]->left = maze[i]->right = NULL;
    maze[i]->x = maze[i]->y = -1;
  }

  for (int i = 0; i < size; i++) {
    maze[i]->x = rand() % WIDTH;
    maze[i]->y = rand() % HEIGHT;
  }

  return maze;
}

void drawMaze(Node** maze) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      for (int i = 0; i < MAZE_SIZE; i++) {
        if (maze[i]->x == x && maze[i]->y == y) {
          printf("X ");
        } else {
          printf("  ");
        }
      }
      printf("\n");
    }
  }
}

int main() {
  Node** maze = generateMaze(MAZE_SIZE);
  drawMaze(maze);

  return 0;
}