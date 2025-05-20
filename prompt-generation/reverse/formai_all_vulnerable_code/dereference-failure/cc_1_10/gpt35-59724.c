//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

typedef struct Node {
  int x, y;
  int f, g, h;
  char type;
  struct Node *parent;
} Node;

Node *openList[ROWS*COLS];
Node *closedList[ROWS*COLS];
int numOpen = 0, numClosed = 0;

int map[ROWS][COLS] = {
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
  { 1, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
  { 1, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
  { 1, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};

Node *createNode(int x, int y, int g, int h, Node *parent) {
  Node *node = (Node*) malloc(sizeof(Node));
  node->x = x;
  node->y = y;
  node->g = g;
  node->h = h;
  node->f = g+h;
  node->type = map[x][y];
  node->parent = parent;

  return node;
}

int isOnClosedList(int x, int y) {
  for (int i = 0; i < numClosed; i++) {
    if (closedList[i]->x == x && closedList[i]->y == y) {
      return i;
    }
  }

  return -1;
}

int isOnOpenList(int x, int y) {
  for (int i = 0; i < numOpen; i++) {
    if (openList[i]->x == x && openList[i]->y == y) {

      return i;
    }
  }

  return -1;
}

void removeFromOpenList(Node *node) {
  int index = isOnOpenList(node->x, node->y);

  for (int i = index; i < numOpen-1; i++) {
    openList[i] = openList[i+1];
  }

  numOpen--;
}

void printPath(Node *node) {
  if (node->parent != NULL) {
    printPath(node->parent);
  }

  printf("(%d, %d) ", node->x, node->y);
}

int main() {

  Node *start = createNode(1, 1, 0, 0, NULL);
  Node *end = createNode(8, 8, 0, 0, NULL);
  start->h = abs(start->x - end->x) + abs(start->y - end->y);
  openList[numOpen++] = start;

  while (numOpen > 0) {
    int lowest = 0;
    for (int i = 1; i < numOpen; i++) {
      if (openList[lowest]->f > openList[i]->f) {
        lowest = i;
      }
    }

    Node *current = openList[lowest];

    if (current->x == end->x && current->y == end->y) {
      printPath(current);
      printf("\n");
      break;
    }

    removeFromOpenList(current);
    closedList[numClosed++] = current;

    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        int x = current->x + i;
        int y = current->y + j;

        if ((i == 0 && j == 0) || x < 0 || y < 0 || x >= ROWS || y >= COLS) {
          continue;
        }

        if (map[x][y] == 1 || isOnClosedList(x, y) >= 0) {
          continue;
        }

        int g = current->g + 1;
        Node *successor = createNode(x, y, g, 0, current);
        successor->h = abs(successor->x - end->x) + abs(successor->y - end->y);

        int index = isOnOpenList(x, y);
        if (index >= 0) {
          if (openList[index]->g > g) {
            openList[index]->g = g;
            openList[index]->f = g + openList[index]->h;
            openList[index]->parent = current;
          }
          continue;
        }

        openList[numOpen++] = successor;
      }
    }
  }

  return 0;
}