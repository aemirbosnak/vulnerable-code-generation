//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

#define EMPTY 0
#define WALL 1
#define START 2
#define END 3

#define MAX_GENERATIONS 100

typedef struct Cell {
  int x;
  int y;
  int state;
  struct Cell* next;
} Cell;

Cell* generateMaze(int width, int height) {
  Cell* head = malloc(sizeof(Cell));
  head->x = 0;
  head->y = 0;
  head->state = START;

  srand(time(NULL));

  for (int i = 0; i < width * height; i++) {
    Cell* newCell = malloc(sizeof(Cell));
    newCell->x = rand() % width;
    newCell->y = rand() % height;
    newCell->state = EMPTY;

    head->next = newCell;
    head = newCell;
  }

  return head;
}

void printMaze(Cell* head) {
  for (int y = 0; y < MAZE_HEIGHT; y++) {
    for (int x = 0; x < MAZE_WIDTH; x++) {
      Cell* currentCell = head;
      while (currentCell) {
        if (currentCell->x == x && currentCell->y == y) {
          switch (currentCell->state) {
            case START:
              printf("S ");
              break;
            case END:
              printf("E ");
              break;
            case WALL:
              printf("# ");
              break;
            case EMPTY:
              printf(" ");
              break;
          }
        }
        currentCell = currentCell->next;
      }
    }
    printf("\n");
  }
}

int main() {
  Cell* maze = generateMaze(MAZE_WIDTH, MAZE_HEIGHT);
  printMaze(maze);

  return 0;
}