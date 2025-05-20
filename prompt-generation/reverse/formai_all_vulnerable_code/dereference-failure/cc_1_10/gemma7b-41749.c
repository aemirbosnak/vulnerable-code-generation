//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: scientific
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 50
#define MAZE_HEIGHT 50

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

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
  for (int x = 0; x < MAZE_WIDTH; x++) {
    for (int y = 0; y < MAZE_HEIGHT; y++) {
      if (rand() % 2 == 0) {
        head->next = CreateNode(x, y);
        head = head->next;
      }
    }
  }
}

void DrawMaze(Node* head) {
  for (int x = 0; x < MAZE_WIDTH; x++) {
    for (int y = 0; y < MAZE_HEIGHT; y++) {
      if (head->x == x && head->y == y) {
        printf("%c", EMPTY_CHAR);
      } else {
        printf("%c", WALL_CHAR);
      }
      head = head->next;
    }
    printf("\n");
  }
}

int main() {
  Node* head = CreateNode(0, 0);
  GenerateMaze(head);
  DrawMaze(head);

  return 0;
}