//Gemma-7B DATASET v1.0 Category: Chess AI ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BOARD_SIZE 64

typedef struct Node {
  struct Node* next;
  char piece;
  int x, y;
} Node;

Node* insertNode(Node* head, char piece, int x, int y) {
  Node* newNode = malloc(sizeof(Node));
  newNode->next = head;
  newNode->piece = piece;
  newNode->x = x;
  newNode->y = y;
  head = newNode;
  return head;
}

void printBoard(Node* head) {
  for (int i = 0; i < MAX_BOARD_SIZE; i++) {
    for (int j = 0; j < MAX_BOARD_SIZE; j++) {
      Node* current = head;
      while (current) {
        if (current->x == i && current->y == j) {
          printf("%c ", current->piece);
        } else {
          printf("  ");
        }
      }
    }
    printf("\n");
  }
}

int main() {
  Node* head = NULL;
  head = insertNode(head, 'a', 0, 0);
  head = insertNode(head, 'b', 1, 0);
  head = insertNode(head, 'c', 2, 0);
  head = insertNode(head, 'd', 3, 0);
  head = insertNode(head, 'e', 4, 0);
  head = insertNode(head, 'f', 5, 0);
  head = insertNode(head, 'g', 6, 0);
  head = insertNode(head, 'h', 7, 0);

  printBoard(head);

  return 0;
}