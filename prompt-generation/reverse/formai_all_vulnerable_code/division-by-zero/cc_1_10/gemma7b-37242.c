//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void createMaze(int** maze, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      maze[i][j] = rand() % MAX_CHAR;
    }
  }
}

int main() {
  int n, m;
  scanf("Enter the number of rows: ", &n);
  scanf("Enter the number of columns: ", &m);

  int** maze = (int**)malloc(n * sizeof(int*));
  for (int i = 0; i < n; i++) {
    maze[i] = (int*)malloc(m * sizeof(int));
  }

  createMaze(maze, n, m);

  // The C maze route finder algorithm begins here

  Node* head = NULL;
  Node* tail = NULL;

  int currentX = 0;
  int currentY = 0;
  int targetX = rand() % n;
  int targetY = rand() % m;

  while (currentX != targetX || currentY != targetY) {
    int direction = rand() % 4;

    switch (direction) {
      case 0:
        currentY++;
        break;
      case 1:
        currentY--;
        break;
      case 2:
        currentX++;
        break;
      case 3:
        currentX--;
        break;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = currentX;
    newNode->y = currentY;
    newNode->next = NULL;

    if (head == NULL) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  // The C maze route finder algorithm ends here

  printf("The route found is: ");

  Node* current = head;
  while (current) {
    printf("(%d, %d) ", current->x, current->y);
    current = current->next;
  }

  printf("\n");

  return 0;
}