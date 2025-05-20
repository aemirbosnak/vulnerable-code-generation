//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

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

int IsBoardFull(Node* head) {
  while (head) {
    if (head->x == -1) {
      return 0;
    }
    head = head->next;
  }
  return 1;
}

int CheckWin(Node* head, int player) {
  // Check rows
  for (int r = 0; r < BOARD_SIZE; r++) {
    if (head->x == r && head->y == 0) {
      Node* current = head;
      int win = 1;
      while (current) {
        if (current->x != r || current->y != 0) {
          win = 0;
          break;
        }
        current = current->next;
      }
      if (win) {
        return player;
      }
    }
  }

  // Check columns
  for (int c = 0; c < BOARD_SIZE; c++) {
    if (head->x == 0 && head->y == c) {
      Node* current = head;
      int win = 1;
      while (current) {
        if (current->x != 0 || current->y != c) {
          win = 0;
          break;
        }
        current = current->next;
      }
      if (win) {
        return player;
      }
    }
  }

  // Check diagonals
  if (head->x == head->y) {
    Node* current = head;
    int win = 1;
    while (current) {
      if (current->x != current->y) {
          win = 0;
          break;
      }
      current = current->next;
    }
    if (win) {
      return player;
    }
  }

  return -1;
}

int main() {
  // Create the game board
  Node* head = CreateNode(0, 0);
  head->next = CreateNode(1, 0);
  head->next->next = CreateNode(2, 0);
  head->next->next->next = CreateNode(0, 1);
  head->next->next->next->next = CreateNode(1, 1);
  head->next->next->next->next->next = CreateNode(2, 1);
  head->next->next->next->next->next->next = CreateNode(0, 2);
  head->next->next->next->next->next->next->next = CreateNode(1, 2);
  head->next->next->next->next->next->next->next->next = CreateNode(2, 2);

  // Play the game
  int player = 1;
  while (!IsBoardFull(head) && CheckWin(head, player) == -1) {
    // Get the player's move
    int move_x, move_y;
    printf("Enter your move (x, y): ");
    scanf("%d %d", &move_x, &move_y);

    // Place the move
    Node* new_node = CreateNode(move_x, move_y);
    new_node->next = head;
    head = new_node;

    // Switch players
    player = (player == 1) ? 2 : 1;
  }

  // Check if the player won or if the board is full
  if (CheckWin(head, player) != -1) {
    printf("Congratulations, %d, you won!\n", player);
  } else {
    printf("It's a draw!\n");
  }

  return 0;
}