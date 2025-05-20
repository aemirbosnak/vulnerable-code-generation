//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 20

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

void generateMaze(Node* head) {
  for (int x = 0; x < MAP_SIZE; x++) {
    for (int y = 0; y < MAP_SIZE; y++) {
      Node* newNode = malloc(sizeof(Node));
      newNode->x = x;
      newNode->y = y;
      newNode->next = NULL;

      if (head == NULL) {
        head = newNode;
      } else {
        head->next = newNode;
        head = newNode;
      }
    }
  }
}

void printMaze(Node* head) {
  for (int x = 0; x < MAP_SIZE; x++) {
    for (int y = 0; y < MAP_SIZE; y++) {
      Node* current = head;
      while (current) {
        if (current->x == x && current->y == y) {
          printf("%c ", current->x + 1 + current->y);
        } else {
          printf(" ");
        }
      }
      printf("\n");
    }
  }
}

int main() {
  Node* head = NULL;
  generateMaze(head);
  printMaze(head);

  return 0;
}