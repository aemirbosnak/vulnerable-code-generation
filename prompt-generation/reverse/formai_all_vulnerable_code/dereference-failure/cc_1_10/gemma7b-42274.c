//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY_SPACE ' '
#define PLAYER_X 'X'
#define PLAYER_O 'O'

typedef struct Node {
  char symbol;
  struct Node* next;
} Node;

Node* createNode(char symbol) {
  Node* node = malloc(sizeof(struct Node));
  node->symbol = symbol;
  node->next = NULL;
  return node;
}

void insertNode(Node* head, char symbol) {
  Node* newNode = createNode(symbol);
  if (head == NULL) {
    head = newNode;
  } else {
    newNode->next = head;
    head = newNode;
  }
}

int evaluateBoard(Node* head) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (head->symbol == head->next->symbol && head->next->symbol == head->next->next->symbol) {
      return head->symbol;
    }
    head = head->next;
  }

  // Check columns
  head = createNode(EMPTY_SPACE);
  insertNode(head, head->next->symbol);
  insertNode(head, head->next->next->symbol);

  for (int i = 0; i < BOARD_SIZE; i++) {
    if (head->symbol == head->next->symbol && head->next->symbol == head->next->next->symbol) {
      return head->symbol;
    }
    head = head->next;
  }

  // Check diagonals
  head = createNode(EMPTY_SPACE);
  insertNode(head, head->next->symbol);
  insertNode(head, head->next->next->symbol);

  for (int i = 0; i < BOARD_SIZE; i++) {
    if (head->symbol == head->next->symbol && head->next->symbol == head->next->next->symbol) {
      return head->symbol;
    }
    head = head->next;
  }

  // If all rows, columns, and diagonals are empty, it's a draw
  return EMPTY_SPACE;
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create the game board
  Node* head = createNode(EMPTY_SPACE);
  insertNode(head, EMPTY_SPACE);
  insertNode(head, EMPTY_SPACE);

  // Play the game
  int game_status = evaluateBoard(head);

  // Print the game result
  switch (game_status) {
    case PLAYER_X:
      printf("Player X won!");
      break;
    case PLAYER_O:
      printf("Player O won!");
      break;
    case EMPTY_SPACE:
      printf("It's a draw!");
      break;
  }

  return 0;
}