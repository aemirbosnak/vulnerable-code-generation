//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MAZE_SIZE 10

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* generateMaze(int size) {
  Node* head = NULL;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      Node* newNode = malloc(sizeof(Node));
      newNode->x = i;
      newNode->y = j;
      newNode->next = head;
      head = newNode;
    }
  }
  return head;
}

int main() {
  srand(time(NULL));
  int mazeSize = MAX_MAZE_SIZE;
  Node* maze = generateMaze(mazeSize);

  // Traverse the maze and find the exit
  for (Node* current = maze; current; current = current->next) {
    // Randomly move in one of the four directions
    int direction = rand() % 4;
    switch (direction) {
      case 0:
        current->x--;
        break;
      case 1:
        current->x++;
        break;
      case 2:
        current->y--;
        break;
      case 3:
        current->y++;
        break;
    }

    // If the cell is the exit, stop
    if (current->x == mazeSize - 1 && current->y == mazeSize - 1) {
      printf("Exit found!\n");
      break;
    }
  }

  return 0;
}