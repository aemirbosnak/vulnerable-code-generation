//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: protected
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define WALL 1
#define EMPTY 0

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* CreateMaze(int w, int h) {
  Node* head = NULL;
  srand(time(NULL));

  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      int r = rand() % 2;
      Node* newNode = malloc(sizeof(Node));
      newNode->x = x;
      newNode->y = y;
      newNode->next = NULL;

      if (r == EMPTY) {
        head = newNode;
      } else {
        if (head) {
          head->next = newNode;
          head = newNode;
        }
      }
    }
  }

  return head;
}

void DrawMaze(Node* head) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      Node* current = head;
      while (current) {
        if (current->x == x && current->y == y) {
          printf("%c", WALL);
        } else {
          printf("%c", EMPTY);
        }
      }
      printf("\n");
    }
  }
}

int main() {
  Node* head = CreateMaze(WIDTH, HEIGHT);
  DrawMaze(head);

  return 0;
}